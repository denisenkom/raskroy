using System;
using System.Collections.Generic;
using System.Windows.Forms;
using System.Text;

namespace Denisenko.Cutting.CutOptima
{
	public class AddDatabaseDialog
	{
		private AddDatabaseForm _form;
		private String _location;

		public String Location
		{
			get { return _location; }
			set { _location = value; }
		}
		private LocationType _locationType;

		public LocationType LocationType
		{
			get { return _locationType; }
			set { _locationType = value; }
		}
		private String _server;

		public String Server
		{
			get { return _server; }
			set { _server = value; }
		}

		public DialogResult ShowDialog()
		{
			_form = new AddDatabaseForm(this);
			return _form.ShowDialog();
		}

		internal DialogResult ShowDialog(Form owner)
		{
			_form = new AddDatabaseForm(this);
			return _form.ShowDialog(owner);
		}
	}
}
