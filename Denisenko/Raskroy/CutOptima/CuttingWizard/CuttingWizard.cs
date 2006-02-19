using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;

namespace Denisenko.Cutting.CutOptima.CuttingWizard
{
	class CuttingWizard
	{
		private Mediator m_mediator;

		public CuttingWizard()
		{
		}

		internal Boolean Execute(IWin32Window owner)
		{
			m_mediator = new Mediator();
			m_mediator.Execute(owner);
			return m_mediator.Finished;
		}

		public Int32[] DetailsListsIDs { get { return m_mediator.DetailsListsIDs; } }
		public Int32[] SheetsIDs { get { return m_mediator.SheetsIDs; } }
	}
}
