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
            this.buttonCancel = new System.Windows.Forms.Button();
            this.buttonRemove = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // newButton
            // 
            this.newButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.newButton.Location = new System.Drawing.Point(237, 284);
            this.newButton.Margin = new System.Windows.Forms.Padding(4);
            this.newButton.Name = "newButton";
            this.newButton.Size = new System.Drawing.Size(100, 28);
            this.newButton.TabIndex = 2;
            this.newButton.Text = "Новая...";
            this.newButton.UseVisualStyleBackColor = true;
            this.newButton.Click += new System.EventHandler(this.newButton_Click);
            // 
            // okButton
            // 
            this.okButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.okButton.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.okButton.Location = new System.Drawing.Point(345, 284);
            this.okButton.Margin = new System.Windows.Forms.Padding(4);
            this.okButton.Name = "okButton";
            this.okButton.Size = new System.Drawing.Size(100, 28);
            this.okButton.TabIndex = 3;
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
            this.databasesListBox.ItemHeight = 16;
            this.databasesListBox.Location = new System.Drawing.Point(16, 15);
            this.databasesListBox.Margin = new System.Windows.Forms.Padding(4);
            this.databasesListBox.Name = "databasesListBox";
            this.databasesListBox.Size = new System.Drawing.Size(531, 244);
            this.databasesListBox.TabIndex = 0;
            this.databasesListBox.DoubleClick += new System.EventHandler(this.databasesListBox_DoubleClick);
            // 
            // addButton
            // 
            this.addButton.Cursor = System.Windows.Forms.Cursors.Arrow;
            this.addButton.Location = new System.Drawing.Point(129, 284);
            this.addButton.Margin = new System.Windows.Forms.Padding(4);
            this.addButton.Name = "addButton";
            this.addButton.Size = new System.Drawing.Size(100, 28);
            this.addButton.TabIndex = 1;
            this.addButton.Text = "Добавить...";
            this.addButton.UseVisualStyleBackColor = true;
            this.addButton.Click += new System.EventHandler(this.addButton_Click);
            // 
            // buttonCancel
            // 
            this.buttonCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.buttonCancel.Location = new System.Drawing.Point(452, 284);
            this.buttonCancel.Name = "buttonCancel";
            this.buttonCancel.Size = new System.Drawing.Size(100, 28);
            this.buttonCancel.TabIndex = 4;
            this.buttonCancel.Text = "Отмена";
            this.buttonCancel.UseVisualStyleBackColor = true;
            this.buttonCancel.Click += new System.EventHandler(this.buttonCancel_Click);
            // 
            // buttonRemove
            // 
            this.buttonRemove.Location = new System.Drawing.Point(22, 284);
            this.buttonRemove.Name = "buttonRemove";
            this.buttonRemove.Size = new System.Drawing.Size(100, 28);
            this.buttonRemove.TabIndex = 5;
            this.buttonRemove.Text = "Убрать";
            this.buttonRemove.UseVisualStyleBackColor = true;
            this.buttonRemove.Click += new System.EventHandler(this.buttonRemove_Click);
            // 
            // DBSelectionForm
            // 
            this.AcceptButton = this.okButton;
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.CancelButton = this.buttonCancel;
            this.ClientSize = new System.Drawing.Size(564, 327);
            this.Controls.Add(this.buttonRemove);
            this.Controls.Add(this.buttonCancel);
            this.Controls.Add(this.addButton);
            this.Controls.Add(this.okButton);
            this.Controls.Add(this.newButton);
            this.Controls.Add(this.databasesListBox);
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "DBSelectionForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Выберите базу";
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