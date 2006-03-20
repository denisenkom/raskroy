using System;
using System.Collections.Specialized;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Denisenko.Cutting.CutOptima
{
	internal partial class DBSelectionForm : Form
	{
		private DBSelectionDialog _dialog;

		public DBSelectionForm(DBSelectionDialog dialog)
		{
			_dialog = dialog;
			InitializeComponent();
		}

		private void DBSelectionForm_Load(object sender, EventArgs e)
		{
			databasesListBox.DataSource = _dialog.Databases;
			/*foreach(String db in _dialog.Databases)
			{
				databasesListBox.Items.Add(db);
			}*/
			databasesListBox.SelectedIndex = _dialog.CurrentDB;
		}

		private void okButton_Click(object sender, EventArgs e)
		{
			_dialog.CurrentDB = databasesListBox.SelectedIndex;
		}

		private void newButton_Click(object sender, EventArgs e)
		{
			_dialog.FireNewDatabase(e);
		}

		private void databasesListBox_DoubleClick(object sender, EventArgs e)
		{
			_dialog.CurrentDB = databasesListBox.SelectedIndex;
			this.DialogResult = DialogResult.OK;
			Close();
		}

		private void addButton_Click(object sender, EventArgs e)
		{
			_dialog.FireAddDatabase(e);
		}

		public void InvalidateDatabasesListView()
		{
			databasesListBox.Invalidate();
		}

		public StringCollection Databases
		{
			set 
			{
				databasesListBox.DataSource = value;
			}
		}

		public Int32 CurrentDB
		{
			set
			{
				databasesListBox.SelectedIndex = value;
			}
		}
	}
}