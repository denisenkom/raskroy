using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;

namespace Denisenko.Cutting.CutOptima
{
    public partial class AddDbModePage : WizardPage
    {
        public AddDbModePage()
        {
            InitializeComponent();
        }

        private WizardPage AddDbModePage_NextClick(WizardPage sender)
        {
            return new AddDbNewPage();
        }

        private void AddDbModePage_Activate(WizardPage sender)
        {
            WizardForm.NextAllowed = true;
        }
    }
}
