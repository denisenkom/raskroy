using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Denisenko.Cutting.CutOptima.CuttingWizard
{
	internal partial class BaseWizardForm : Form
	{
		private List<BasePage> m_pages = new List<BasePage>();
		private Int32 m_currentPageIndex;
		private Mediator m_mediator;

		public BaseWizardForm(Mediator mediator)
		{
			m_mediator = mediator;
			InitializeComponent();
			m_pages.Add(new SelectDetailsPage(mediator));
			m_pages.Add(new SelectSheetsPage(mediator));

			foreach (BasePage page in m_pages)
			{
				this.Controls.Add(page);
				page.Left = 12;
				page.Top = 78;
				page.Visible = false;
			}
			m_currentPageIndex = 0;
			m_pages[m_currentPageIndex].Visible = true;
			stepDescriptionLabel.Text = m_pages[m_currentPageIndex].Description;
			backButton.Enabled = false;
		}

		private void Navigate(Int32 pageIndex)
		{
			if (pageIndex == m_currentPageIndex)
				return;
			if (pageIndex < 0 || pageIndex > m_pages.Count - 1)
				throw new ArgumentOutOfRangeException("pageIndex", pageIndex, "Выбрана не правильная страница");

			m_pages[m_currentPageIndex].Visible = false;
			m_currentPageIndex = pageIndex;
			m_pages[m_currentPageIndex].Visible = true;
			stepDescriptionLabel.Text = m_pages[m_currentPageIndex].Description;
			backButton.Enabled = m_currentPageIndex > 0;
			nextButton.Enabled = m_currentPageIndex < m_pages.Count - 1;
		}

		private void backButton_Click(object sender, EventArgs e)
		{
			Navigate(m_currentPageIndex - 1);
		}

		private void nextButton_Click(object sender, EventArgs e)
		{
			Navigate(m_currentPageIndex + 1);
		}

		private void finishButton_Click(object sender, EventArgs e)
		{
			m_mediator.Finish();
		}

		public Boolean NextAllowed
		{
			get
			{
				return nextButton.Enabled;
			}
			set
			{
				nextButton.Enabled = value;
			}
		}

		internal BasePage GetPage(int index)
		{
			return m_pages[index];
		}
	}
}