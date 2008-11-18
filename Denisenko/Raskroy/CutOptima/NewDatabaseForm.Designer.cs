namespace Denisenko.Cutting.CutOptima
{
	internal partial class NewDatabaseForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(NewDatabaseForm));
            this.serverTextBox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.dbNameRadioButton = new System.Windows.Forms.RadioButton();
            this.dbPathRadioButton = new System.Windows.Forms.RadioButton();
            this.dbNameTextBox = new System.Windows.Forms.TextBox();
            this.dbPathTextBox = new System.Windows.Forms.TextBox();
            this.browseButton = new System.Windows.Forms.Button();
            this.OKbutton = new System.Windows.Forms.Button();
            this.cancelButton = new System.Windows.Forms.Button();
            this.saveFileDialog = new System.Windows.Forms.SaveFileDialog();
            this.SuspendLayout();
            // 
            // serverTextBox
            // 
            this.serverTextBox.AccessibleDescription = null;
            this.serverTextBox.AccessibleName = null;
            resources.ApplyResources(this.serverTextBox, "serverTextBox");
            this.serverTextBox.BackgroundImage = null;
            this.serverTextBox.Font = null;
            this.serverTextBox.Name = "serverTextBox";
            // 
            // label1
            // 
            this.label1.AccessibleDescription = null;
            this.label1.AccessibleName = null;
            resources.ApplyResources(this.label1, "label1");
            this.label1.Font = null;
            this.label1.Name = "label1";
            // 
            // dbNameRadioButton
            // 
            this.dbNameRadioButton.AccessibleDescription = null;
            this.dbNameRadioButton.AccessibleName = null;
            resources.ApplyResources(this.dbNameRadioButton, "dbNameRadioButton");
            this.dbNameRadioButton.BackgroundImage = null;
            this.dbNameRadioButton.Checked = true;
            this.dbNameRadioButton.Font = null;
            this.dbNameRadioButton.Name = "dbNameRadioButton";
            this.dbNameRadioButton.TabStop = true;
            this.dbNameRadioButton.UseVisualStyleBackColor = true;
            this.dbNameRadioButton.CheckedChanged += new System.EventHandler(this.dbNamePathRadioButton_CheckedChanged);
            // 
            // dbPathRadioButton
            // 
            this.dbPathRadioButton.AccessibleDescription = null;
            this.dbPathRadioButton.AccessibleName = null;
            resources.ApplyResources(this.dbPathRadioButton, "dbPathRadioButton");
            this.dbPathRadioButton.BackgroundImage = null;
            this.dbPathRadioButton.Font = null;
            this.dbPathRadioButton.Name = "dbPathRadioButton";
            this.dbPathRadioButton.UseVisualStyleBackColor = true;
            this.dbPathRadioButton.CheckedChanged += new System.EventHandler(this.dbNamePathRadioButton_CheckedChanged);
            // 
            // dbNameTextBox
            // 
            this.dbNameTextBox.AccessibleDescription = null;
            this.dbNameTextBox.AccessibleName = null;
            resources.ApplyResources(this.dbNameTextBox, "dbNameTextBox");
            this.dbNameTextBox.BackgroundImage = null;
            this.dbNameTextBox.Font = null;
            this.dbNameTextBox.Name = "dbNameTextBox";
            // 
            // dbPathTextBox
            // 
            this.dbPathTextBox.AccessibleDescription = null;
            this.dbPathTextBox.AccessibleName = null;
            resources.ApplyResources(this.dbPathTextBox, "dbPathTextBox");
            this.dbPathTextBox.BackgroundImage = null;
            this.dbPathTextBox.Font = null;
            this.dbPathTextBox.Name = "dbPathTextBox";
            // 
            // browseButton
            // 
            this.browseButton.AccessibleDescription = null;
            this.browseButton.AccessibleName = null;
            resources.ApplyResources(this.browseButton, "browseButton");
            this.browseButton.BackgroundImage = null;
            this.browseButton.Font = null;
            this.browseButton.Name = "browseButton";
            this.browseButton.UseVisualStyleBackColor = true;
            this.browseButton.Click += new System.EventHandler(this.browseButton_Click);
            // 
            // OKbutton
            // 
            this.OKbutton.AccessibleDescription = null;
            this.OKbutton.AccessibleName = null;
            resources.ApplyResources(this.OKbutton, "OKbutton");
            this.OKbutton.BackgroundImage = null;
            this.OKbutton.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.OKbutton.Font = null;
            this.OKbutton.Name = "OKbutton";
            this.OKbutton.UseVisualStyleBackColor = true;
            this.OKbutton.Click += new System.EventHandler(this.OKbutton_Click);
            // 
            // cancelButton
            // 
            this.cancelButton.AccessibleDescription = null;
            this.cancelButton.AccessibleName = null;
            resources.ApplyResources(this.cancelButton, "cancelButton");
            this.cancelButton.BackgroundImage = null;
            this.cancelButton.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.cancelButton.Font = null;
            this.cancelButton.Name = "cancelButton";
            this.cancelButton.UseVisualStyleBackColor = true;
            // 
            // saveFileDialog
            // 
            this.saveFileDialog.AddExtension = false;
            this.saveFileDialog.DefaultExt = "mdf";
            resources.ApplyResources(this.saveFileDialog, "saveFileDialog");
            // 
            // NewDatabaseForm
            // 
            this.AccessibleDescription = null;
            this.AccessibleName = null;
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = null;
            this.Controls.Add(this.cancelButton);
            this.Controls.Add(this.OKbutton);
            this.Controls.Add(this.browseButton);
            this.Controls.Add(this.dbPathTextBox);
            this.Controls.Add(this.dbNameTextBox);
            this.Controls.Add(this.dbPathRadioButton);
            this.Controls.Add(this.dbNameRadioButton);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.serverTextBox);
            this.Font = null;
            this.Icon = null;
            this.MaximizeBox = false;
            this.Name = "NewDatabaseForm";
            this.ResumeLayout(false);
            this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.TextBox serverTextBox;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.RadioButton dbNameRadioButton;
		private System.Windows.Forms.RadioButton dbPathRadioButton;
		private System.Windows.Forms.TextBox dbNameTextBox;
		private System.Windows.Forms.TextBox dbPathTextBox;
		private System.Windows.Forms.Button browseButton;
		private System.Windows.Forms.Button OKbutton;
		private System.Windows.Forms.Button cancelButton;
		private System.Windows.Forms.SaveFileDialog saveFileDialog;
	}
}