namespace Denisenko.Cutting.CutOptima
{
	partial class DBSelectionForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(DBSelectionForm));
            this.newButton = new System.Windows.Forms.Button();
            this.okButton = new System.Windows.Forms.Button();
            this.databasesListBox = new System.Windows.Forms.ListBox();
            this.addButton = new System.Windows.Forms.Button();
            this.buttonCancel = new System.Windows.Forms.Button();
            this.buttonRemove = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // newButton
            // 
            this.newButton.AccessibleDescription = null;
            this.newButton.AccessibleName = null;
            resources.ApplyResources(this.newButton, "newButton");
            this.newButton.BackgroundImage = null;
            this.newButton.Font = null;
            this.newButton.Name = "newButton";
            this.newButton.UseVisualStyleBackColor = true;
            this.newButton.Click += new System.EventHandler(this.newButton_Click);
            // 
            // okButton
            // 
            this.okButton.AccessibleDescription = null;
            this.okButton.AccessibleName = null;
            resources.ApplyResources(this.okButton, "okButton");
            this.okButton.BackgroundImage = null;
            this.okButton.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.okButton.Font = null;
            this.okButton.Name = "okButton";
            this.okButton.UseVisualStyleBackColor = true;
            this.okButton.Click += new System.EventHandler(this.okButton_Click);
            // 
            // databasesListBox
            // 
            this.databasesListBox.AccessibleDescription = null;
            this.databasesListBox.AccessibleName = null;
            resources.ApplyResources(this.databasesListBox, "databasesListBox");
            this.databasesListBox.BackgroundImage = null;
            this.databasesListBox.Font = null;
            this.databasesListBox.FormattingEnabled = true;
            this.databasesListBox.Name = "databasesListBox";
            this.databasesListBox.DoubleClick += new System.EventHandler(this.databasesListBox_DoubleClick);
            // 
            // addButton
            // 
            this.addButton.AccessibleDescription = null;
            this.addButton.AccessibleName = null;
            resources.ApplyResources(this.addButton, "addButton");
            this.addButton.BackgroundImage = null;
            this.addButton.Cursor = System.Windows.Forms.Cursors.Arrow;
            this.addButton.Font = null;
            this.addButton.Name = "addButton";
            this.addButton.UseVisualStyleBackColor = true;
            this.addButton.Click += new System.EventHandler(this.addButton_Click);
            // 
            // buttonCancel
            // 
            this.buttonCancel.AccessibleDescription = null;
            this.buttonCancel.AccessibleName = null;
            resources.ApplyResources(this.buttonCancel, "buttonCancel");
            this.buttonCancel.BackgroundImage = null;
            this.buttonCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.buttonCancel.Font = null;
            this.buttonCancel.Name = "buttonCancel";
            this.buttonCancel.UseVisualStyleBackColor = true;
            this.buttonCancel.Click += new System.EventHandler(this.buttonCancel_Click);
            // 
            // buttonRemove
            // 
            this.buttonRemove.AccessibleDescription = null;
            this.buttonRemove.AccessibleName = null;
            resources.ApplyResources(this.buttonRemove, "buttonRemove");
            this.buttonRemove.BackgroundImage = null;
            this.buttonRemove.Font = null;
            this.buttonRemove.Name = "buttonRemove";
            this.buttonRemove.UseVisualStyleBackColor = true;
            this.buttonRemove.Click += new System.EventHandler(this.buttonRemove_Click);
            // 
            // DBSelectionForm
            // 
            this.AcceptButton = this.okButton;
            this.AccessibleDescription = null;
            this.AccessibleName = null;
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = null;
            this.CancelButton = this.buttonCancel;
            this.Controls.Add(this.buttonRemove);
            this.Controls.Add(this.buttonCancel);
            this.Controls.Add(this.addButton);
            this.Controls.Add(this.okButton);
            this.Controls.Add(this.newButton);
            this.Controls.Add(this.databasesListBox);
            this.Font = null;
            this.Icon = null;
            this.Name = "DBSelectionForm";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.DBSelectionForm_FormClosing);
            this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.Button newButton;
		private System.Windows.Forms.Button okButton;
		private System.Windows.Forms.ListBox databasesListBox;
		private System.Windows.Forms.Button addButton;
        private System.Windows.Forms.Button buttonCancel;
        private System.Windows.Forms.Button buttonRemove;
	}
}