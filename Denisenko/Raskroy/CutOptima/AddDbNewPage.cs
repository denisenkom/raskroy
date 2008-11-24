using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Data.SqlClient;
using System.Text;
using System.Threading;
using System.Windows.Forms;

namespace Denisenko.Cutting.CutOptima
{
    public partial class AddDbNewPage : WizardPage
    {
        private delegate void OpenConnectionDoneDelegate(SqlException ex, bool statusOk);
        private SqlConnection m_connection = null;
        private bool m_nameOk = false;
        private bool m_serverOk = false;
        private bool m_dbNameOk = false;
        private bool m_dbFileOk = false;

        public AddDbNewPage()
        {
            InitializeComponent();
        }

        private void UpdateNextButton()
        {
            WizardForm.NextAllowed = m_nameOk && m_serverOk && ((radioButtonDbName.Checked && m_dbNameOk) ||
                (radioButtonFile.Checked && m_dbFileOk));
        }

        private void CheckTagName(string name, out string message)
        {
            m_nameOk = name.Length != 0;
            if (m_nameOk)
                message = "";
            else
                message = "Имя базы данных должно быть заполнено";
        }

        private void textBoxName_Validating(object sender, CancelEventArgs e)
        {
            string message;
            CheckTagName(textBoxName.Text, out message);
            if (!m_nameOk)
            {
                e.Cancel = true;
                textBoxName.SelectAll();
                errorProvider.SetError(textBoxName, message);
            }
            UpdateNextButton();
        }

        private void textBoxName_Validated(object sender, EventArgs e)
        {
            errorProvider.SetError(textBoxName, "");
        }

        private void CheckServerName(string name, out string message)
        {
            m_serverOk = name.Length != 0;
            if (m_serverOk)
                message = "";
            else
                message = "Имя сервера должно быть заполнено";
        }

        private void textBoxServer_Validating(object sender, CancelEventArgs e)
        {
            string message;
            CheckServerName(textBoxServer.Text, out message);
            if (!m_serverOk)
            {
                e.Cancel = true;
                textBoxServer.SelectAll();
                errorProvider.SetError(textBoxServer, message);
            }
            UpdateNextButton();
        }

        private void OpenConnection(object conn)
        {
            SqlException excep = null;
            try
            {
                ((SqlConnection)conn).Open();
            }
            catch (SqlException ex)
            {
                excep = ex;
            }
            if (!object.ReferenceEquals(conn, m_connection))
                return;
            this.Invoke((OpenConnectionDoneDelegate)OpenConnectionDone, excep, excep == null);
        }

        private void OpenConnectionDone(SqlException ex, bool statusOk)
        {
            m_serverOk = statusOk;
            if (statusOk)
            {
                using (SqlCommand cmd = m_connection.CreateCommand())
                {
                    cmd.CommandText = "select name from sys.databases order by name";
                    cmd.CommandType = CommandType.Text;
                    using (SqlDataReader rdr = cmd.ExecuteReader())
                    {
                        comboBoxDatabases.Items.Clear();
                        while (rdr.Read())
                            comboBoxDatabases.Items.Add(rdr.GetString(0));
                    }
                }
            }
            else
            {
                errorProvider.SetError(textBoxServer, ex.Message);
            }
            UpdateNextButton();
        }

        private void textBoxServer_Validated(object sender, EventArgs e)
        {
            errorProvider.SetError(textBoxServer, "");
            if (m_connection != null)
                m_connection.Dispose();
            m_connection = new SqlConnection();
            SqlConnectionStringBuilder bldr = new SqlConnectionStringBuilder();
            bldr.DataSource = textBoxServer.Text;
            bldr.IntegratedSecurity = true;
            bldr.ConnectTimeout = 5;
            m_connection.ConnectionString = bldr.ToString();
            ThreadPool.QueueUserWorkItem(OpenConnection, m_connection);
        }

        private void comboBoxDatabases_Click(object sender, EventArgs e)
        {
            radioButtonDbName.Checked = true;
        }

        private void textBoxFileName_Click(object sender, EventArgs e)
        {
            radioButtonFile.Checked = true;
        }

        private void AddDbNewPage_Activate(WizardPage sender)
        {
            textBoxName.Focus();
        }

        private void radioButtonDbName_Click(object sender, EventArgs e)
        {
            comboBoxDatabases.TabStop = true;
            textBoxFileName.TabStop = false;
            buttonBrowse.TabStop = false;
            UpdateNextButton();
        }

        private void radioButtonFile_Click(object sender, EventArgs e)
        {
            comboBoxDatabases.TabStop = false;
            textBoxFileName.TabStop = true;
            buttonBrowse.TabStop = true;
            UpdateNextButton();
        }

        private void comboBoxDatabases_Leave(object sender, EventArgs e)
        {
            m_dbNameOk = comboBoxDatabases.Text.Length != 0;
            UpdateNextButton();
        }

        private void textBoxFileName_Leave(object sender, EventArgs e)
        {
            m_dbFileOk = textBoxFileName.Text.Length != 0;
            UpdateNextButton();
        }

        private void buttonBrowse_Click(object sender, EventArgs e)
        {
            if (openFileDialog.ShowDialog() != DialogResult.OK)
                return;
            radioButtonFile.Checked = true;
            textBoxFileName.Text = openFileDialog.FileName;
            m_dbFileOk = textBoxFileName.Text.Length != 0;
            UpdateNextButton();
        }
    }
}
