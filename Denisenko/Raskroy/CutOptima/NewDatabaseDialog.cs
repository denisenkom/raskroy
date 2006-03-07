using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;

namespace Denisenko.Cutting.CutOptima
{
	public enum LocationType
	{
		Path,
		Name,
	}

	public class NewDatabaseDialog
	{
		private Denisenko.Cutting.CutOptima.NewDatabaseForm _newDatabaseForm;
		private String _server;
		private String _location;
		private LocationType _locationType;
	
		public String Server
		{
			get
			{
				return _server;
			}
			set
			{
				_server = value;
			}
		}

		public string Location
		{
			get
			{
				return _location;
			}
			set
			{
				_location = value;
			}
		}

		public LocationType LocationType
		{
			get
			{
				return _locationType;
			}
			set
			{
				_locationType = value;
			}
		}
	
		public DialogResult ShowDialog(IWin32Window owner)
		{
			_newDatabaseForm = new NewDatabaseForm(this);
			return _newDatabaseForm.ShowDialog(owner);
		}
	}
}
