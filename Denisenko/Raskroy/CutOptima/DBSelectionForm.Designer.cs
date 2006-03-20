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
			this.newButton = new System.Windows.Forms.Button();
			this.okButton = new System.Windows.Forms.Button();
			this.databasesListBox = new System.Windows.Forms.ListBox();
			this.addButton = new System.Windows.Forms.Button();
			this.SuspendLayout();
			// 
			// newButton
			// 
			this.newButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
			this.newButton.Location = new System.Drawing.Point(255, 231);
			this.newButton.Name = "newButton";
			this.newButton.Size = new System.Drawing.Size(75, 23);
			this.newButton.TabIndex = 1;
			this.newButton.Text = "Новая...";
			this.newButton.UseVisualStyleBackColor = true;
			this.newButton.Click += new System.EventHandler(this.newButton_Click);
			// 
			// okButton
			// 
			this.okButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
			this.okButton.DialogResult = System.Windows.Forms.DialogResult.OK;
			this.okButton.Location = new System.Drawing.Point(336, 231);
			this.okButton.Name = "okButton";
			this.okButton.Size = new System.Drawing.Size(75, 23);
			this.okButton.TabIndex = 2;
			this.okButton.Text = "ОК";
			this.okButton.UseVisualStyleBackColor = true;
			this.okButton.Click += new System.EventHandler(this.okButton_Click);
			// 
			// databasesListBox
			// 
			this.databasesListBox.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
						| System.Windows.Forms.AnchorStyles.Left)
						| System.Windows.Forms.AnchorStyles.Right)));
			this.databasesListBox.FormattingEnabled = true;
			this.databasesListBox.Location = new System.Drawing.Point(12, 12);
			this.databasesListBox.Name = "databasesListBox";
			this.databasesListBox.Size = new System.Drawing.Size(399, 199);
			this.databasesListBox.TabIndex = 0;
			this.databasesListBox.DoubleClick += new System.EventHandler(this.databasesListBox_DoubleClick);
			// 
			// addButton
			// 
			this.addButton.Cursor = System.Windows.Forms.Cursors.Arrow;
			this.addButton.Location = new System.Drawing.Point(174, 231);
			this.addButton.Name = "addButton";
			this.addButton.Size = new System.Drawing.Size(75, 23);
			this.addButton.TabIndex = 3;
			this.addButton.Text = "Добавить...";
			this.addButton.UseVisualStyleBackColor = true;
			this.addButton.Click += new System.EventHandler(this.addButton_Click);
			// 
			// DBSelectionForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(423, 266);
			this.Controls.Add(this.addButton);
			this.Controls.Add(this.okButton);
			this.Controls.Add(this.newButton);
			this.Controls.Add(this.databasesListBox);
			this.Name = "DBSelectionForm";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
			this.Text = "Выберите базу";
			this.Load += new System.EventHandler(this.DBSelectionForm_Load);
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.Button newButton;
		private System.Windows.Forms.Button okButton;
		private System.Windows.Forms.ListBox databasesListBox;
		private System.Windows.Forms.Button addButton;
	}
}