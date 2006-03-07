using System;
using System.Collections.Generic;
using System.Windows.Forms;
using System.Text;

namespace Denisenko.Cutting.CutOptima
{
	class DBSelectionDialog
	{
		private String[] _databases = new String[0];
		private Int32 _currentDB = -1;

		public DBSelectionDialog()
		{
		}

		public DialogResult ShowDialog(IWin32Window owner)
		{
			DBSelectionForm form = new DBSelectionForm(this);
			return form.ShowDialog(owner);
		}

		public String[] Databases
		{
			get { return _databases; }
			set { _databases = value; }
		}

		public Int32 CurrentDB
		{
			get { return _currentDB; }
			set { _currentDB = value; }
		}

		internal void FireNewDatabase(EventArgs e)
		{
			if (OnNewDatabase != null)
				OnNewDatabase(this, e);
		}

		public event EventHandler OnNewDatabase;
	}
}
