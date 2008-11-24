namespace Denisenko.Cutting.CutOptima
{
	partial class WizardForm
	{
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
            this.finishButton = new System.Windows.Forms.Button();
            this.nextButton = new System.Windows.Forms.Button();
            this.backButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // finishButton
            // 
            this.finishButton.Enabled = false;
            this.finishButton.Location = new System.Drawing.Point(529, 386);
            this.finishButton.Margin = new System.Windows.Forms.Padding(4);
            this.finishButton.Name = "finishButton";
            this.finishButton.Size = new System.Drawing.Size(100, 28);
            this.finishButton.TabIndex = 0;
            this.finishButton.Text = "Готово";
            this.finishButton.UseVisualStyleBackColor = true;
            this.finishButton.Click += new System.EventHandler(this.finishButton_Click);
            // 
            // nextButton
            // 
            this.nextButton.Enabled = false;
            this.nextButton.Location = new System.Drawing.Point(421, 386);
            this.nextButton.Margin = new System.Windows.Forms.Padding(4);
            this.nextButton.Name = "nextButton";
            this.nextButton.Size = new System.Drawing.Size(100, 28);
            this.nextButton.TabIndex = 1;
            this.nextButton.Text = "Далее";
            this.nextButton.UseVisualStyleBackColor = true;
            this.nextButton.Click += new System.EventHandler(this.nextButton_Click);
            // 
            // backButton
            // 
            this.backButton.Enabled = false;
            this.backButton.Location = new System.Drawing.Point(313, 386);
            this.backButton.Margin = new System.Windows.Forms.Padding(4);
            this.backButton.Name = "backButton";
            this.backButton.Size = new System.Drawing.Size(100, 28);
            this.backButton.TabIndex = 2;
            this.backButton.Text = "Назад";
            this.backButton.UseVisualStyleBackColor = true;
            this.backButton.Click += new System.EventHandler(this.backButton_Click);
            // 
            // WizardForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.White;
            this.ClientSize = new System.Drawing.Size(645, 430);
            this.Controls.Add(this.backButton);
            this.Controls.Add(this.nextButton);
            this.Controls.Add(this.finishButton);
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "WizardForm";
            this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.Button finishButton;
		private System.Windows.Forms.Button nextButton;
        private System.Windows.Forms.Button backButton;
	}
}