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
    public interface IProgressJob
    {
        float PercentCompleted
        {
            get;
        }
    }

	public delegate void ProgressFormEventHandler(ProgressForm sender);

	public partial class ProgressForm : Form
	{
		private Boolean _paused = false;
        private IProgressJob _job;

        public ProgressForm(IProgressJob job)
		{
            _job = job;
			InitializeComponent();
            progressTimer.Enabled = _job != null;
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
            if (_job != null)
			    progressBar.Value = (Int32)_job.PercentCompleted;
		}

		private void ProgressForm_Load(object sender, EventArgs e)
		{
			progressTimer.Enabled = true;
		}

        public int Progress
        {
            set { progressBar.Value = value; }
            get { return progressBar.Value; }
        }

        public string Status
        {
            set { labelStatus.Text = value; }
            get { return labelStatus.Text; }
        }
	}
}