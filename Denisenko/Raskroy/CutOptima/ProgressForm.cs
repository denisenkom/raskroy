using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Denisenko.Cutting.CutOptima
{
	public delegate void ProgressFormEventHandler(ProgressForm sender);

	public partial class ProgressForm : Form
	{
		private Boolean _paused = false;

		public ProgressForm()
		{
			InitializeComponent();
		}

		internal void UpdateProgress(Int32 progress)
		{
			progressBar.Value = progress;
		}

		internal event ProgressFormEventHandler Pause;
		internal event ProgressFormEventHandler Resume;
		internal event ProgressFormEventHandler Cancel;

		private void pauseResumeButton_Click(object sender, EventArgs e)
		{
			if (_paused)
			{
				pauseResumeButton.Text = "Пауза";
				if (Resume != null)
					Resume(this);
			}
			else
			{
				pauseResumeButton.Text = "Продолжить";
				if (Pause != null)
					Pause(this);
			}
		}

		private void cancelButton_Click(object sender, EventArgs e)
		{
			if (Cancel != null)
				Cancel(this);
		}
	}
}