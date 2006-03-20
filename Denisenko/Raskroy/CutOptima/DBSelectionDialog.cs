using System;
using System.Collections.Specialized;
using System.Collections.Generic;
using System.Windows.Forms;
using System.Text;

namespace Denisenko.Cutting.CutOptima
{
	class DBSelectionDialog
	{
		private StringCollection _databases;
		private Int32 _currentDB = -1;
		private DBSelectionForm _form;

		public DBSelectionDialog()
		{
		}

		public DialogResult ShowDialog(IWin32Window owner)
		{
			_form = new DBSelectionForm(this);
			return _form.ShowDialog(owner);
		}

		public StringCollection Databases
		{
			get
			{
				return _databases;
			}
			set
			{
				_databases = value;
				if (_form != null)
				{
					_form.Databases = value;
				}
			}
		}

		public Int32 CurrentDB
		{
			get
			{
				return _currentDB;
			}
			set
			{
				_form.CurrentDB = _currentDB = value;
			}
		}

		internal void FireNewDatabase(EventArgs e)
		{
			if (OnNewDatabase != null)
			{
				OnNewDatabase(this, e);
			}
		}

		public event EventHandler OnNewDatabase;
		public event EventHandler OnAddDatabase;

		internal void FireAddDatabase(EventArgs e)
		{
			if (OnAddDatabase != null)
			{
				OnAddDatabase(this, e);
			}
		}

		public void InvalidateDatabasesListView()
		{
			_form.InvalidateDatabasesListView();
		}
	}
}
