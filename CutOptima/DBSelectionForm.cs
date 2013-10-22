using System;
using System.Collections.Specialized;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Denisenko.Cutting.CutOptima
{
	internal partial class DBSelectionForm : Form
	{
		private bool m_abortOk;
        private int m_currentDB;

		public DBSelectionForm()
		{
			m_abortOk = false;
			InitializeComponent();
		}

        public StringCollection Databases
        {
            get { return (StringCollection)databasesListBox.DataSource; }
            set { databasesListBox.DataSource = value; }
        }

        public Int32 CurrentDB
        {
            get { return databasesListBox.SelectedIndex; }
            set { m_currentDB = databasesListBox.SelectedIndex = value; }
        }

		private void okButton_Click(object sender, EventArgs e)
		{
			if (m_currentDB != databasesListBox.SelectedIndex)
			{
				try
				{
                    DBManager.Instance.CmdCheckConnection(this, Databases[databasesListBox.SelectedIndex]);
					m_currentDB = databasesListBox.SelectedIndex;
				}
				catch (Exception ex)
				{
					if (MessageBox.Show(ex.Message + Environment.NewLine +
						strings.Continue + "?", strings.Error, MessageBoxButtons.YesNo,
						MessageBoxIcon.Error) == DialogResult.Yes)
					{
						m_currentDB = databasesListBox.SelectedIndex;
						m_abortOk = false;
					}
					else
					{
						m_abortOk = true;
					}
				}
			}
		}

		private void databasesListBox_DoubleClick(object sender, EventArgs e)
		{
			try
			{
                DBManager.Instance.CmdCheckConnection(this, Databases[databasesListBox.SelectedIndex]);
				m_currentDB = databasesListBox.SelectedIndex;
				this.DialogResult = DialogResult.OK;
				Close();
			}
			catch (Exception ex)
			{
				if (MessageBox.Show(ex.Message + Environment.NewLine +
					strings.Continue + "?", strings.Error, MessageBoxButtons.YesNo,
					MessageBoxIcon.Error) == DialogResult.No)
				{
					return;
				}
				else
				{
					m_currentDB = databasesListBox.SelectedIndex;
					this.DialogResult = DialogResult.OK;
					Close();
					return;
				}
			}
		}

        private void buttonCancel_Click(object sender, EventArgs e)
        {
            DialogResult = DialogResult.Cancel;
        }

		private void DBSelectionForm_FormClosing(object sender, FormClosingEventArgs e)
		{
			e.Cancel = m_abortOk;
			m_abortOk = false;
		}

		private void newButton_Click(object sender, EventArgs e)
		{
            DBManager.Instance.CmdNewDatabase(this);
            UpdateDatabasesListBox();
        }

		private void addButton_Click(object sender, EventArgs e)
		{
            ExistingDatabaseForm form = new ExistingDatabaseForm();
            if (form.ShowDialog(this) == DialogResult.OK)
            {
                SqlConnectionStringBuilder bldr = new SqlConnectionStringBuilder();
                bldr.DataSource = form.serverTextBox.Text;
                bldr.InitialCatalog = form.dbNameTextBox.Text;
                bldr.IntegratedSecurity = form.windows_auth_cb.Checked;
                if (form.sql_auth_cb.Checked)
                {
                    bldr.UserID = form.username_tb.Text;
                    bldr.Password = form.password_tb.Text;
                }
                bldr.ConnectTimeout = 5;
                DBManager.Instance.AddDatabase(bldr.ConnectionString);
                //Properties.Settings.Default.Bases.Add(bldr.ToString());
                UpdateDatabasesListBox();
            }
        }

        private void buttonRemove_Click(object sender, EventArgs e)
        {
            DBManager.Instance.CmdRemoveDb(this, m_currentDB);
            UpdateDatabasesListBox();
        }

        private void UpdateDatabasesListBox()
        {
            databasesListBox.DataSource = null;
            databasesListBox.DataSource = Properties.Settings.Default.Bases;
        }
    }

}