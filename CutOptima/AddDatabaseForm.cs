using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Denisenko.Cutting.CutOptima
{
	public partial class AddDatabaseForm : Form
	{
        private String _location;
        private LocationType _locationType;
        private String _server;

        public AddDatabaseForm()
		{
			InitializeComponent();
            serverTextBox.Text = @".\SQLEXPRESS";
            catalogRadioButton.Checked = true;
		}

		private void browseButton_Click(object sender, EventArgs e)
		{
            dbFileRadioButton.Checked = true;
            if (openFileDialog.ShowDialog(this) == DialogResult.OK)
				dbFileTextBox.Text = openFileDialog.FileName;
        }

		private void okButton_Click(object sender, EventArgs e)
		{
            if (catalogRadioButton.Checked && catalogTextBox.Text == "")
            {
                MessageBox.Show(this, "Нужно указать каталог",
                    "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            if (dbFileRadioButton.Checked && dbFileTextBox.Text == "")
            {
                MessageBox.Show(this, "Нужно указать путь к БД",
                    "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            LocationType locationType = catalogRadioButton.Checked ? LocationType.Name : LocationType.Path;
            string location = catalogRadioButton.Checked ? catalogTextBox.Text : dbFileTextBox.Text;

            if (!DBManager.Instance.CmdCheckDuplicates(this, serverTextBox.Text,
                locationType, location))
            {
                return;
            }
            if (!DBManager.Instance.CmdCheckConnection(this, serverTextBox.Text,
                locationType, location))
            {
                return;
            }
			_server = serverTextBox.Text;
			if (catalogRadioButton.Checked)
			{
				_locationType = LocationType.Name;
				_location = catalogTextBox.Text;
			}
			else if (dbFileRadioButton.Checked)
			{
				_locationType = LocationType.Path;
				_location = dbFileTextBox.Text;
			}
            DialogResult = DialogResult.OK;
		}

        private void catalogTextBox_Enter(object sender, EventArgs e)
        {
            catalogRadioButton.Checked = true;
        }

        private void dbFileTextBox_Enter(object sender, EventArgs e)
        {
            dbFileRadioButton.Checked = true;
        }

        public String DbLocation
        {
            get { return _location; }
        }

        public LocationType LocationType
        {
            get { return _locationType; }
        }

        public String Server
        {
            get { return _server; }
        }
    }
}