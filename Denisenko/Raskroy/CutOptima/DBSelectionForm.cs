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
		private bool _abortOk;

		public DBSelectionForm(DBSelectionDialog dialog)
		{
			_abortOk = false;
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
			if (_dialog.CurrentDB != databasesListBox.SelectedIndex)
			{
				CheckConnectionEventArgs eventArgs = new CheckConnectionEventArgs();
				eventArgs.ConnectionInfo =
					_dialog.Databases[databasesListBox.SelectedIndex];
				try
				{
					_dialog.FireCheckConnection(eventArgs);
					_dialog.CurrentDB = databasesListBox.SelectedIndex;
				}
				catch (Exception ex)
				{
					if (MessageBox.Show(ex.Message + Environment.NewLine +
						"Продолжить?", "Ошибка", MessageBoxButtons.YesNo,
						MessageBoxIcon.Error) == DialogResult.Yes)
					{
						_dialog.CurrentDB = databasesListBox.SelectedIndex;
						_abortOk = false;
					}
					else
					{
						_abortOk = true;
					}
				}
			}
		}

		private void databasesListBox_DoubleClick(object sender, EventArgs e)
		{
			CheckConnectionEventArgs eventArgs = new CheckConnectionEventArgs();
			eventArgs.ConnectionInfo =
				_dialog.Databases[databasesListBox.SelectedIndex];
			try
			{
				_dialog.FireCheckConnection(eventArgs);
				_dialog.CurrentDB = databasesListBox.SelectedIndex;
				this.DialogResult = DialogResult.OK;
				Close();
			}
			catch (Exception ex)
			{
				if (MessageBox.Show(ex.Message + Environment.NewLine +
					"Продолжить?", "Ошибка", MessageBoxButtons.YesNo,
					MessageBoxIcon.Error) == DialogResult.No)
				{
					return;
				}
				else
				{
					_dialog.CurrentDB = databasesListBox.SelectedIndex;
					this.DialogResult = DialogResult.OK;
					Close();
					return;
				}
			}
		}

		private void DBSelectionForm_FormClosing(object sender, FormClosingEventArgs e)
		{
			e.Cancel = _abortOk;
			_abortOk = false;
		}

		private void newButton_Click(object sender, EventArgs e)
		{
			_dialog.FireNewDatabase(e);
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