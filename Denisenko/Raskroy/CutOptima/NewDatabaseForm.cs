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
		private NewDatabaseDialog _dialog;

		public NewDatabaseForm(NewDatabaseDialog dialog)
		{
			_dialog = dialog;
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

		private void NewDatabaseDialog_Load(object sender, EventArgs e)
		{
			this.serverTextBox.Text = _dialog.Server;
			if (_dialog.LocationType == LocationType.Name)
			{
				dbNameRadioButton.Checked = true;
				dbNameTextBox.Text = _dialog.Location;
				dbPathTextBox.Text = "";
			}
			else if(_dialog.LocationType == LocationType.Path)
			{
				dbPathRadioButton.Checked = true;
				dbNameTextBox.Text = "";
				saveFileDialog.FileName = dbPathTextBox.Text = _dialog.Location;
			}
		}

		private void OKbutton_Click(object sender, EventArgs e)
		{
			_dialog.Server = serverTextBox.Text;
			if (dbNameRadioButton.Checked)
			{
				_dialog.LocationType = LocationType.Name;
				_dialog.Location = dbNameTextBox.Text;
			}
			else if (dbPathRadioButton.Checked)
			{
				_dialog.LocationType = LocationType.Path;
				_dialog.Location = dbPathTextBox.Text;
			}
		}
	}
}