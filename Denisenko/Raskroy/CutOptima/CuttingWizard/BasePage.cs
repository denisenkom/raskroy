using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;

namespace Denisenko.Cutting.CutOptima.CuttingWizard
{
	internal partial class BasePage : UserControl
	{
		protected Mediator m_mediator;

		public BasePage(Mediator mediator)
		{
				m_mediator = mediator;
			InitializeComponent();
		}

		public virtual String Description
		{
			get { return "NotImplemented"; }
		}
	}
}
