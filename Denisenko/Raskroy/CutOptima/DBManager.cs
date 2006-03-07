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

			if (Settings.Default.Bases == null)
			{
				Settings.Default.Bases = new StringCollection();
			}
			Settings.Default.Bases.Add(String.Join("|",
				new String[] { newDbDialog.Server, newDbDialog.Location }));
			Settings.Default.Save();
		}

		public void SelectDB(Form owner)
		{
			_owner = owner;
			DBSelectionDialog selectionDialog = new DBSelectionDialog();
			if (Settings.Default.Bases == null)
			{
				Settings.Default.Bases = new StringCollection();
			}
			selectionDialog.Databases = new String[Settings.Default.Bases.Count];
			Settings.Default.Bases.CopyTo(selectionDialog.Databases, 0);
			selectionDialog.OnNewDatabase += SelectionDialog_OnNewDatabase;
			if (selectionDialog.ShowDialog(owner) != DialogResult.OK)
				return;
			/*if(MessageBox.Show("Сделать выбранную базу базой по умолчанию?", "", MessageBoxButtons.YesNo)== DialogResult.Yes)
			{
			}*/
			SqlConnectionStringBuilder builder = new SqlConnectionStringBuilder();
			String[] parts = Settings.Default.Bases[selectionDialog.CurrentDB].Split(new Char[] { '|' });
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
			Settings.Default.CutOptimaConnectionString =
				Settings.Default.DefaultCutOptimaConnectionString = builder.ConnectionString;
			Settings.Default.Save();
		}

		public void Startup(Form owner)
		{
			_owner = owner;
			if (Settings.Default.DefaultCutOptimaConnectionString != "")
			{
				return;
			}
			SelectDB(owner);
		}
	}
}
