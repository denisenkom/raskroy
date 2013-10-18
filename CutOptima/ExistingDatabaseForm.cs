using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Denisenko.Cutting.CutOptima
{
    public partial class ExistingDatabaseForm : Form
    {
        public ExistingDatabaseForm()
        {
            InitializeComponent();
        }

        private void windows_auth_cb_CheckedChanged(object sender, EventArgs e)
        {
            username_tb.Enabled = false;
            password_tb.Enabled = false;
        }

        private void sql_auth_cb_CheckedChanged(object sender, EventArgs e)
        {
            username_tb.Enabled = true;
            password_tb.Enabled = true;
        }

        private void test_connection_btn_Click(object sender, EventArgs e)
        {
            var bldr = new System.Data.SqlClient.SqlConnectionStringBuilder();
            bldr.DataSource = serverTextBox.Text;
            bldr.InitialCatalog = dbNameTextBox.Text;
            bldr.IntegratedSecurity = windows_auth_cb.Checked;
            if (sql_auth_cb.Checked)
            {
                bldr.UserID = username_tb.Text;
                bldr.Password = password_tb.Text;
            }
            bldr.ConnectTimeout = 5;
            var conn = new System.Data.SqlClient.SqlConnection(bldr.ConnectionString);
            var success = false;
            try
            {
                conn.Open();
                var cmd = conn.CreateCommand();
                cmd.CommandText = "select 1";
                cmd.ExecuteScalar();
                success = true;
            }
            catch (Exception ex)
            {
                MessageBox.Show("Test connection failed because of an error in initializing provider. " + ex.Message,
                                "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            if (success)
            {
                MessageBox.Show("Test connection succeeded.", "CutOptima",
                                MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }
    }
}
