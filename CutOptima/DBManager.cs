using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Data;
using System.Data.SqlClient;
using System.Diagnostics;
using System.IO;
using System.Text;
using System.Windows.Forms;
using System.Threading;

using Denisenko.Cutting.CutOptima.Properties;

namespace Denisenko.Cutting.CutOptima
{
    public enum LocationType
    {
        Path,
        Name,
    }

    internal class DBManager
	{
		private static DBManager m_instance;
	
		public static DBManager Instance
		{
			get
			{
				if (m_instance == null)
				{
					m_instance = new DBManager();
				}
				return m_instance;
			}
		}

        public void CmdRemoveDb(IWin32Window owner, int dbIndex)
        {
            if (MessageBox.Show(owner, "Убрать базу из списка? База не будет удалена физически.",
                "Запрос", MessageBoxButtons.OKCancel, MessageBoxIcon.Question) == DialogResult.Cancel)
            {
                return;
            }
            Settings.Default.Bases.RemoveAt(dbIndex);
            Settings.Default.Save();
        }

        private void UseDb(SqlConnection conn, string dbName)
        {
            using (SqlCommand cmd = conn.CreateCommand())
            {
                cmd.CommandText = "USE [" + dbName + "]";
                cmd.CommandType = CommandType.Text;
                cmd.ExecuteNonQuery();
            }
        }

        private void DetachDb(SqlConnection conn, string dbName)
        {
            using (SqlCommand cmd = conn.CreateCommand())
            {
                cmd.CommandText = "sp_detach_db";
                cmd.CommandType = CommandType.StoredProcedure;
                cmd.Parameters.AddWithValue("@dbname", dbName);
                cmd.ExecuteNonQuery();
            }
        }

		public void CmdNewDatabase(IWin32Window owner)
		{
			NewDatabaseForm newDbDialog = new NewDatabaseForm();
			if (newDbDialog.ShowDialog(owner) != DialogResult.OK)
				return;

            if (!CmdCheckDuplicates(owner, newDbDialog.Server, newDbDialog.LocationType,
                newDbDialog.DbLocation))
            {
                return;
            }

            ProgressForm progressFrm = new ProgressForm(null);
            progressFrm.Text = "Создается база";
            progressFrm.Status = "Подключаемся к серверу";
            progressFrm.Show(owner);
            progressFrm.Update();

			SqlConnectionStringBuilder builder = new SqlConnectionStringBuilder();
			builder.DataSource = newDbDialog.Server;
			builder.IntegratedSecurity = true;
            SqlConnection connection = new SqlConnection(builder.ConnectionString);
			SqlCommand cmd = connection.CreateCommand();
            bool createOk = false;
            bool dbCreated = false;
            String dbName = "";
            DialogResult dr;
            try
			{
                while (true)
                {

                    try
                    {
                        connection.Open();
                        break;
                    }
                    catch (SqlException ex)
                    {
                        dr = MessageBox.Show(owner, "Ошибка при подключении к серверу: " + ex.Message, null,
                            MessageBoxButtons.RetryCancel, MessageBoxIcon.Error);
                        switch (dr)
                        {
                            case DialogResult.Retry:
                                continue;
                            case DialogResult.Cancel:
                                return;
                            default:
                                Debug.Fail("Invalid case: " + dr);
                                return;
                        }
                    }
                }
                progressFrm.Progress = 10;
                progressFrm.Status = "Создание базы";
                progressFrm.Update();

				// создание новой базы
				//
				if (newDbDialog.LocationType == LocationType.Name)
				{
					dbName = newDbDialog.DbLocation;
					cmd.CommandText = String.Format("CREATE DATABASE [{0}]", dbName);
				}
				else if (newDbDialog.LocationType == LocationType.Path)
				{
					dbName = Path.GetFileNameWithoutExtension(newDbDialog.DbLocation);
					// TODO: Check for " [ ] symbols in dbName
					String fileName = dbName;
					// TODO: Check for ' symbol in fileName
					String dbPath = Path.GetFullPath(newDbDialog.DbLocation);
					// TODO: Check for ' symbol in dbPath
					String logName = Path.GetFileNameWithoutExtension(newDbDialog.DbLocation) + "_log";
					// TODO: Check for ' symbol in logName
					String logPath = Path.GetDirectoryName(newDbDialog.DbLocation) + '\\' +
						logName + ".LDF";
					// TODO: Check for ' symbol in logPath
					cmd.CommandText = String.Format("CREATE DATABASE [{0}] ON PRIMARY " +
						"(NAME = N'{1}', FILENAME = N'{2}') " +
						"LOG ON " +
						"(NAME = N'{3}', FILENAME = N'{4}')", dbName, fileName, dbPath,
						logName, logPath);
				}
                while (true)
                {
                    try
                    {
                        cmd.ExecuteNonQuery();
                        break;
                    }
                    catch (SqlException ex)
                    {
                        dr = MessageBox.Show(owner, "Ошибка при создании базы данных: " + ex.Message, null,
                            MessageBoxButtons.RetryCancel, MessageBoxIcon.Error);
                        switch (dr)
                        {
                            case DialogResult.Retry:
                                continue;
                            case DialogResult.Cancel:
                                return;
                            default:
                                Debug.Fail("Invalid case: " + dr);
                                return;
                        }
                    }
                }
                dbCreated = true;
                progressFrm.Progress = 50;
                progressFrm.Update();

                try
                {
                    UseDb(connection, dbName);
                }
                catch (SqlException ex)
                {
                    MessageBox.Show(owner, "Ошибка при активации базы данных: " + ex.Message, null,
                        MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }
                progressFrm.Progress = 55;
                progressFrm.Update();

				// выполнение пакета создания схемы
				//
				string[] statements = Properties.Resources.CreateDB.Split(new string[] { "GO" },
					StringSplitOptions.RemoveEmptyEntries);
                int delta = 45 / statements.Length;
				foreach (string stmt in statements)
				{
					cmd.CommandText = stmt;
                    try
                    {
                        cmd.ExecuteNonQuery();
                    }
                    catch (SqlException ex)
                    {
                        MessageBox.Show(owner, "Ошибка при создании схемы базы данных: " + ex.Message, null,
                            MessageBoxButtons.OK, MessageBoxIcon.Error);
                        return;
                    }
                    progressFrm.Progress += delta;
                    progressFrm.Update();
                }
                UseDb(connection, "master");
                DetachDb(connection, dbName);
                progressFrm.Progress = 100;
                progressFrm.Update();
                createOk = true;
			}
            finally
            {
                progressFrm.Close();
                if (!createOk && dbCreated)
                {
                    cmd.CommandText = "USE master DROP DATABASE [" + dbName + "]";
                }
                connection.Close();
            }
			AddDatabase(newDbDialog.Server, newDbDialog.DbLocation);
            MessageBox.Show(owner, "База данных успешно создана", "Успех", MessageBoxButtons.OK, MessageBoxIcon.Information);
		}

        public class MyWizard
        {
            public MyWizard(UserControl[] pages)
            {
                m_pages = pages;
            }

            UserControl[] m_pages;
        }

		public void CmdAddDatabase(IWin32Window owner)
		{
			/*
			 * Можно использовать стандартное окно для формирования строки подключения
			 * 
			 * Сохранить полученную строку подключения в списке строк подключения
			 * Отобразить новую строку подключения в окне выбора строк подключения
			 */

			// TODO: Change dialog caption from New Database to Locate Database
            AddDatabaseForm dialog = new AddDatabaseForm();
			if (dialog.ShowDialog(owner) != DialogResult.OK)
				return;
			AddDatabase(dialog.Server, dialog.DbLocation);
		}

        public bool CheckConnectionString(IWin32Window owner, string connStr)
        {
            SqlConnection conn = new SqlConnection();
            conn.ConnectionString = connStr;
            try
            {
                conn.Open(); // throws exception if cannot open connection
                conn.Close();
                return true;
            }
            catch (SqlException ex)
            {
                MessageBox.Show(owner, "Ошибка соединения: " + ex.Message, null,
                    MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
        }

        public bool CmdCheckConnection(IWin32Window owner, String server, LocationType locType, String dbLocation)
        {
            SqlConnectionStringBuilder builder = new SqlConnectionStringBuilder();
            builder.DataSource = server;
            builder.IntegratedSecurity = true;
            builder.AsynchronousProcessing = true;
            switch (locType)
            {
                case LocationType.Name:
                    builder.InitialCatalog = dbLocation;
                    break;
                case LocationType.Path:
                    builder.AttachDBFilename = dbLocation;
                    break;
                default:
                    Debug.Fail("Invalid case: " + locType.ToString());
                    break;
            }
            return CheckConnectionString(owner, builder.ToString());
        }

		public bool CmdCheckConnection(IWin32Window owner, String connectionInfo)
		{
            return CheckConnectionString(owner, BuildConnectionString(connectionInfo));
		}

		private String BuildConnectionString(String connectionInfo)
		{
			SqlConnectionStringBuilder builder = new SqlConnectionStringBuilder();
			String[] parts = connectionInfo.Split(new Char[] { '|' });
			builder.DataSource = parts[0];
			if (parts[1][1] == ':' || parts[1][1] == '\\')
			{
				builder.AttachDBFilename = parts[1];
			}
			else
			{
				builder.InitialCatalog = parts[1];
			}
			builder.IntegratedSecurity = true;
			return builder.ConnectionString;
		}

		public void AddDatabase(String server, String location)
		{
			if (Settings.Default.Bases == null)
			{
				Settings.Default.Bases = new StringCollection();
			}
			String baseInfo = String.Join("|", new String[] { server, location });
			Settings.Default.Bases.Add(baseInfo);
			Settings.Default.Save();
		}

		public void SelectDB(Form owner)
		{
            DBSelectionForm selectionDialog = new DBSelectionForm();
			if (Settings.Default.Bases == null)
			{
				Settings.Default.Bases = new StringCollection();
			}
			selectionDialog.Databases = Settings.Default.Bases;
			if (selectionDialog.ShowDialog(owner) != DialogResult.OK)
				return;
			/*if(MessageBox.Show("Сделать выбранную базу базой по умолчанию?", "", MessageBoxButtons.YesNo)== DialogResult.Yes)
			{
			}*/
			Settings.Default["DefaultCutOptimaConnectionString"] =
				Settings.Default.CutOptimaConnectionString = BuildConnectionString(
					Settings.Default.Bases[selectionDialog.CurrentDB]);
			Settings.Default.Save();
		}

		public void Startup(Form owner)
		{
			if (Settings.Default.CutOptimaConnectionString != "")
			{
				Settings.Default["DefaultCutOptimaConnectionString"] =
					Settings.Default.CutOptimaConnectionString;
				return;
			}
			SelectDB(owner);
		}

        internal bool CmdCheckDuplicates(IWin32Window owner, string server, LocationType locationType, string location)
        {
            String baseInfo = String.Join("|", new String[] { server, location }).ToLower();
            foreach (string conn in Settings.Default.Bases)
            {
                if (conn.ToLower() == baseInfo)
                {
                    MessageBox.Show(owner, "База с такими параметрами уже есть в списке", null, MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                    return false;
                }
            }
            return true;
        }
    }
}
