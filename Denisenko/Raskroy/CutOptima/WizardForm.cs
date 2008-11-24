using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Denisenko.Cutting.CutOptima
{
	internal partial class WizardForm : Form
	{
        private Stack<WizardPage> m_pagesStack = new Stack<WizardPage>();
        private Boolean m_finished = false;

		public WizardForm(WizardPage startPage)
		{
			InitializeComponent();
            BindPage(startPage);
            m_pagesStack.Push(startPage);
        }

        public Boolean NextAllowed
        {
            get { return nextButton.Enabled; }
            set { nextButton.Enabled = value; }
        }

        public Boolean FinishAllowed
        {
            get { return finishButton.Enabled; }
            set { finishButton.Enabled = value; }
        }

        private void backButton_Click(object sender, EventArgs e)
		{
            if (m_pagesStack.Count == 1)
                return;
            UnbindPage(m_pagesStack.Pop());
            BindPage(m_pagesStack.Peek());
            backButton.Enabled = m_pagesStack.Count > 1;
		}

		private void nextButton_Click(object sender, EventArgs e)
		{
            WizardPage nextPage = m_pagesStack.Peek().FireNextClick();
            if (nextPage == null)
                return;
            UnbindPage(m_pagesStack.Peek());
            NextAllowed = false;
            FinishAllowed = false;
            BindPage(nextPage);
            m_pagesStack.Push(nextPage);
            backButton.Enabled = true;
        }

		private void finishButton_Click(object sender, EventArgs e)
		{
            Close();
            m_finished = true;
		}

        private void BindPage(WizardPage page)
        {
            page.WizardForm = this;
            this.Controls.Add(page);
            page.FireActivate();
        }

        private void UnbindPage(WizardPage page)
        {
            this.Controls.Remove(page);
            page.WizardForm = null;
        }

        public Boolean Finished { get { return m_finished; } }
    }
}