using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Text;
using System.Windows.Forms;

namespace Denisenko.Cutting.CutOptima
{
	internal partial class NewDatabaseForm : Form
	{
        private String _server;
        private String _location;
        private LocationType _locationType;

		public NewDatabaseForm()
		{
			InitializeComponent();
        }

		private void browseButton_Click(object sender, EventArgs e)
		{
			if (saveFileDialog.ShowDialog() == DialogResult.OK)
			{
				dbPathTextBox.Text = saveFileDialog.FileName;
			}
		}

		private void dbNamePathRadioButton_CheckedChanged(object sender, EventArgs e)
		{
			dbPathTextBox.Enabled = dbPathRadioButton.Checked;
			browseButton.Enabled = dbPathRadioButton.Checked;
			dbNameTextBox.Enabled = dbNameRadioButton.Checked;
        }

		private void OKbutton_Click(object sender, EventArgs e)
		{
			_server = serverTextBox.Text;
			if (dbNameRadioButton.Checked)
			{
				_locationType = LocationType.Name;
				_location = dbNameTextBox.Text;
			}
			else if (dbPathRadioButton.Checked)
			{
				_locationType = LocationType.Path;
				_location = dbPathTextBox.Text;
			}
		}

        public String Server
        {
            get { return _server; }
            set { _server = value; }
        }

        public string DbLocation
        {
            get { return _location; }
            set { _location = value; }
        }

        public LocationType LocationType
        {
            get { return _locationType; }
            set { _locationType = value; }
        }
	}
}