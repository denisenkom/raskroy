using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;

namespace Denisenko.Cutting.CutOptima
{
    public delegate WizardPage NextClickHandler(WizardPage sender);
    public delegate void ActivateHandler(WizardPage sender);

	public partial class WizardPage : UserControl
	{

		public WizardPage()
		{
			InitializeComponent();
		}

        public event NextClickHandler NextClick;
        public event ActivateHandler Activate;

        internal WizardPage FireNextClick() { return NextClick != null ? NextClick(this) : null; }
        internal void FireActivate() { if (Activate != null) Activate(this); }

        internal WizardForm WizardForm
        {
            get { return m_wizardForm; }
            set { m_wizardForm = value; }
        }

        private WizardForm m_wizardForm = null;
	}
}
