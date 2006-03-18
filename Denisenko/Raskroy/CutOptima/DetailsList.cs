using System;
using System.Collections.Generic;
using System.Text;

namespace Denisenko.Cutting.CutOptima
{
	class DetailsList
	{
		private Int32? _detailsListID;

		public Int32? DetailsListID
		{
			get { return _detailsListID; }
			set { _detailsListID = value; }
		}

		private String _orderID;

		public String OrderID
		{
			get { return _orderID; }
			set { _orderID = value; }
		}

		private String _description;

		public String Description
		{
			get { return _description; }
			set { _description = value; }
		}
	}

	class DetailsListReflector
	{
		private static DetailsListReflector _instance = null;

		private DetailsListReflector()
		{
			throw new NotImplementedException();
		}

		public static DetailsListReflector Instance
		{
			get
			{
				throw new NotImplementedException();
			}
		}

		public void Insert(DetailsList detailsList)
		{
			throw new NotImplementedException();
		}

		public void Update(DetailsList detailsList)
		{
			throw new NotImplementedException();
		}

		public void Delete(Int32 detailsListID)
		{
			throw new NotImplementedException();
		}

		public DetailsList Load(Int32 detailsListID)
		{
			throw new NotImplementedException();
		}
	}
}
