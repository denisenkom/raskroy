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
		private AddDatabaseDialog _dialog;

		public AddDatabaseForm(AddDatabaseDialog dialog)
		{
			_dialog = dialog;
			InitializeComponent();
		}

		private void browseButton_Click(object sender, EventArgs e)
		{
			if (openFileDialog.ShowDialog(this) == DialogResult.OK)
			{
				dbFileTextBox.Text = openFileDialog.FileName;
			}
		}

		private void AddDatabaseForm_Load(object sender, EventArgs e)
		{
			serverTextBox.Text = _dialog.Server;
			if (_dialog.LocationType == LocationType.Name)
			{
				catalogRadioButton.Checked = true;
				catalogTextBox.Text = _dialog.Location;
			}
			else if (_dialog.LocationType == LocationType.Path)
			{
				dbFileRadioButton.Checked = true;
				dbFileTextBox.Text = _dialog.Location;
			}
		}

		private void okButton_Click(object sender, EventArgs e)
		{
			_dialog.Server = serverTextBox.Text;
			if (catalogRadioButton.Checked)
			{
				_dialog.LocationType = LocationType.Name;
				_dialog.Location = catalogTextBox.Text;
			}
			else if (dbFileRadioButton.Checked)
			{
				_dialog.LocationType = LocationType.Path;
				_dialog.Location = dbFileTextBox.Text;
			}
		}
	}
}