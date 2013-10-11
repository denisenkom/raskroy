namespace Denisenko.Cutting.CutOptima.CuttingWizard
{
	partial class BaseWizardForm
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
			this.stepDescriptionLabel = new System.Windows.Forms.Label();
			this.SuspendLayout();
			// 
			// finishButton
			// 
			this.finishButton.Location = new System.Drawing.Point(397, 314);
			this.finishButton.Name = "finishButton";
			this.finishButton.Size = new System.Drawing.Size(75, 23);
			this.finishButton.TabIndex = 0;
			this.finishButton.Text = "Готово";
			this.finishButton.UseVisualStyleBackColor = true;
			this.finishButton.Click += new System.EventHandler(this.finishButton_Click);
			// 
			// nextButton
			// 
			this.nextButton.Location = new System.Drawing.Point(316, 314);
			this.nextButton.Name = "nextButton";
			this.nextButton.Size = new System.Drawing.Size(75, 23);
			this.nextButton.TabIndex = 1;
			this.nextButton.Text = "Далее";
			this.nextButton.UseVisualStyleBackColor = true;
			this.nextButton.Click += new System.EventHandler(this.nextButton_Click);
			// 
			// backButton
			// 
			this.backButton.Location = new System.Drawing.Point(235, 314);
			this.backButton.Name = "backButton";
			this.backButton.Size = new System.Drawing.Size(75, 23);
			this.backButton.TabIndex = 2;
			this.backButton.Text = "Назад";
			this.backButton.UseVisualStyleBackColor = true;
			this.backButton.Click += new System.EventHandler(this.backButton_Click);
			// 
			// stepDescriptionLabel
			// 
			this.stepDescriptionLabel.Location = new System.Drawing.Point(12, 9);
			this.stepDescriptionLabel.Name = "stepDescriptionLabel";
			this.stepDescriptionLabel.Size = new System.Drawing.Size(460, 57);
			this.stepDescriptionLabel.TabIndex = 3;
			// 
			// BaseWizardForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(484, 349);
			this.Controls.Add(this.stepDescriptionLabel);
			this.Controls.Add(this.backButton);
			this.Controls.Add(this.nextButton);
			this.Controls.Add(this.finishButton);
			this.Name = "BaseWizardForm";
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.Button finishButton;
		private System.Windows.Forms.Button nextButton;
		private System.Windows.Forms.Button backButton;
		private System.Windows.Forms.Label stepDescriptionLabel;
	}
}