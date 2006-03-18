using System;
using System.Collections.Generic;
using System.Text;

namespace Denisenko.Cutting.CutOptima
{
	class Detail
	{
		private String _name;

		public String Name
		{
			get { return _name; }
			set { _name = value; }
		}
		private Decimal? _sizeA;

		public Decimal? SizeA
		{
			get { return _sizeA; }
			set { _sizeA = value; }
		}
		private Decimal? _sizeB;

		public Decimal? SizeB
		{
			get { return _sizeB; }
			set { _sizeB = value; }
		}
		private Int32 _amount;

		public Int32 Amount
		{
			get { return _amount; }
			set { _amount = value; }
		}
		private Int32 _materialID;

		public Int32 MaterialID
		{
			get { return _materialID; }
			set { _materialID = value; }
		}
		private String _edges;

		public String Edges
		{
			get { return _edges; }
			set { _edges = value; }
		}
	}
}
