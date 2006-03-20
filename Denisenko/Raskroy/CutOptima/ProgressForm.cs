using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

using Denisenko.Cutting.Optimizing;

namespace Denisenko.Cutting.CutOptima
{
	public delegate void ProgressFormEventHandler(ProgressForm sender);

	public partial class ProgressForm : Form
	{
		private Boolean _paused = false;
		private OptimizingJob _optimizingJob;

		public ProgressForm(OptimizingJob optimizingJob)
		{
			_optimizingJob = optimizingJob;
			InitializeComponent();
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

		private void progressTimer_Tick(object sender, EventArgs e)
		{
			progressBar.Value = (Int32)_optimizingJob.PercentCompleted;
		}

		private void ProgressForm_Load(object sender, EventArgs e)
		{
			progressTimer.Enabled = true;
		}
	}
}