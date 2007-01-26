using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Data;
using System.Data.SqlClient;
using System.IO;
using System.Text;
using System.Windows.Forms;
using System.Threading;

using Denisenko.Cutting.CutOptima.Properties;

namespace Denisenko.Cutting.CutOptima
{
	internal class DBManager
	{
		private static DBManager _instance;
		private Form _owner;
		private DBSelectionDialog _selectionDialog;
	
		public static DBManager Instance
		{
			get
			{
				if (_instance == null)
				{
					_instance = new DBManager();
				}
				return _instance;
			}
		}

		private void SelectionDialog_OnNewDatabase(Object sender, EventArgs e)
		{
			NewDatabaseDialog newDbDialog = new NewDatabaseDialog();
			newDbDialog.Location = Path.GetFullPath("CutOptima.mdf");
			newDbDialog.LocationType = LocationType.Path;
			newDbDialog.Server = @".\SQLEXPRESS";
			if (newDbDialog.ShowDialog(_owner) != DialogResult.OK)
			{
				return;
			}

			Form form = new Form();
			form.Owner = _owner;
			form.StartPosition = FormStartPosition.CenterParent;
			Label label = new Label();
			label.Text = "Создается база";
			form.Controls.Add(label);
			form.Show();

			SqlConnectionStringBuilder builder = new SqlConnectionStringBuilder();
			builder.DataSource = newDbDialog.Server;
			builder.IntegratedSecurity = true;
			builder.AsynchronousProcessing = true;
			using (SqlConnection connection = new SqlConnection(builder.ConnectionString))
			{
				connection.Open();
				SqlCommand cmd = connection.CreateCommand();

				// создание новой базы
				//
				String dbName = "";
				if (newDbDialog.LocationType == LocationType.Name)
				{
					dbName = newDbDialog.Location;
					cmd.CommandText = String.Format("CREATE DATABASE [{0}]", dbName);
				}
				else if (newDbDialog.LocationType == LocationType.Path)
				{
					dbName = Path.GetFileNameWithoutExtension(newDbDialog.Location);
					// TODO: Check for " [ ] symbols in dbName
					String fileName = dbName;
					// TODO: Check for ' symbol in fileName
					String dbPath = Path.GetFullPath(newDbDialog.Location);
					// TODO: Check for ' symbol in dbPath
					String logName = Path.GetFileNameWithoutExtension(newDbDialog.Location) + "_log";
					// TODO: Check for ' symbol in logName
					String logPath = Path.GetDirectoryName(newDbDialog.Location) + '\\' +
						logName + ".LDF";
					// TODO: Check for ' symbol in logPath
					cmd.CommandText = String.Format("CREATE DATABASE [{0}] ON PRIMARY " +
						"(NAME = N'{1}', FILENAME = N'{2}') " +
						"LOG ON " +
						"(NAME = N'{3}', FILENAME = N'{4}')", dbName, fileName, dbPath,
						logName, logPath);
				}
				IAsyncResult async = cmd.BeginExecuteNonQuery();
				while (!async.AsyncWaitHandle.WaitOne(500, true))
				{
					Application.DoEvents();
				}
				cmd.EndExecuteNonQuery(async);

				cmd.CommandText = String.Format("USE [{0}]", dbName);
				cmd.ExecuteNonQuery();

				// выполнение пакета создания схемы
				//
				string[] statements = Properties.Resources.CreateDB.Split(new string[] { "GO" },
					StringSplitOptions.RemoveEmptyEntries);
				foreach (string stmt in statements)
				{
					cmd.CommandText = stmt;
					async = cmd.BeginExecuteNonQuery();
					while (!async.AsyncWaitHandle.WaitOne(500, true))
					{
						Application.DoEvents();
					}
					cmd.EndExecuteNonQuery(async);
				}
				form.Close();
			}
			AddDatabase(newDbDialog.Server, newDbDialog.Location);
		}

		private void SelectionDialog_OnAddDatabase(Object sender, EventArgs e)
		{
			/*
			 * Можно использовать стандартное окно для формирования строки подключения
			 * 
			 * Сохранить полученную строку подключения в списке строк подключения
			 * Отобразить новую строку подключения в окне выбора строк подключения
			 */

			// TODO: Change dialog caption from New Database to Locate Database
			AddDatabaseDialog dialog = new AddDatabaseDialog();
			dialog.Server = @".\SQLEXPRESS";
			if (dialog.ShowDialog(_owner) != DialogResult.OK)
			{
				return;
			}
			SqlConnectionStringBuilder builder = new SqlConnectionStringBuilder();
			builder.DataSource = dialog.Server;
			builder.IntegratedSecurity = true;
			builder.AsynchronousProcessing = true;
			if(dialog.LocationType == LocationType.Path)
			{
				builder.AttachDBFilename = dialog.Location;
			}
			else if (dialog.LocationType == LocationType.Name)
			{
				builder.InitialCatalog = dialog.Location;
			}

			// checking connection
			using (SqlConnection conn = new SqlConnection())
			{
				conn.ConnectionString = builder.ConnectionString;
				conn.Open();
			}

			AddDatabase(dialog.Server, dialog.Location);
		}

		private void SelectionDialog_OnCheckConnection(Object sender,
			CheckConnectionEventArgs e)
		{
			SqlConnection conn = new SqlConnection();
			conn.ConnectionString = BuildConnectionString(e.ConnectionInfo);
            try
            {
                conn.Open(); // throws exception if cannot open connection
            }
            catch (SqlException ex)
            {
                MessageBox.Show("Ошибка соединения: " + ex.Message);
            }
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

		private void AddDatabase(String server, String location)
		{
			if (Settings.Default.Bases == null)
			{
				Settings.Default.Bases = new StringCollection();
			}
			String baseInfo = String.Join("|", new String[] { server, location });
			Settings.Default.Bases.Add(baseInfo);
			Settings.Default.Save();
			_selectionDialog.InvalidateDatabasesListView();
		}

		public void SelectDB(Form owner)
		{
			_owner = owner;
			_selectionDialog = new DBSelectionDialog();
			if (Settings.Default.Bases == null)
			{
				Settings.Default.Bases = new StringCollection();
			}
			_selectionDialog.Databases = Settings.Default.Bases;
			_selectionDialog.OnNewDatabase += SelectionDialog_OnNewDatabase;
			_selectionDialog.OnAddDatabase += SelectionDialog_OnAddDatabase;
			_selectionDialog.OnCheckConnection += SelectionDialog_OnCheckConnection;
			if (_selectionDialog.ShowDialog(owner) != DialogResult.OK)
				return;
			/*if(MessageBox.Show("Сделать выбранную базу базой по умолчанию?", "", MessageBoxButtons.YesNo)== DialogResult.Yes)
			{
			}*/
			Settings.Default["DefaultCutOptimaConnectionString"] =
				Settings.Default.CutOptimaConnectionString = BuildConnectionString(
					Settings.Default.Bases[_selectionDialog.CurrentDB]);
			Settings.Default.Save();
		}

		public void Startup(Form owner)
		{
			_owner = owner;
			if (Settings.Default.CutOptimaConnectionString != "")
			{
				Settings.Default["DefaultCutOptimaConnectionString"] =
					Settings.Default.CutOptimaConnectionString;
				return;
			}
			SelectDB(owner);
		}
	}
}
