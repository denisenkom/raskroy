namespace Denisenko.Cutting.CutOptima
{
	partial class AddDatabaseForm
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
			this.serverTextBox = new System.Windows.Forms.TextBox();
			this.label1 = new System.Windows.Forms.Label();
			this.catalogTextBox = new System.Windows.Forms.TextBox();
			this.dbFileTextBox = new System.Windows.Forms.TextBox();
			this.catalogRadioButton = new System.Windows.Forms.RadioButton();
			this.dbFileRadioButton = new System.Windows.Forms.RadioButton();
			this.okButton = new System.Windows.Forms.Button();
			this.cancelButton = new System.Windows.Forms.Button();
			this.browseButton = new System.Windows.Forms.Button();
			this.openFileDialog = new System.Windows.Forms.OpenFileDialog();
			this.SuspendLayout();
			// 
			// serverTextBox
			// 
			this.serverTextBox.Location = new System.Drawing.Point(65, 12);
			this.serverTextBox.Name = "serverTextBox";
			this.serverTextBox.Size = new System.Drawing.Size(100, 20);
			this.serverTextBox.TabIndex = 0;
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(12, 15);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(47, 13);
			this.label1.TabIndex = 1;
			this.label1.Text = "Сервер:";
			// 
			// catalogTextBox
			// 
			this.catalogTextBox.Location = new System.Drawing.Point(108, 37);
			this.catalogTextBox.Name = "catalogTextBox";
			this.catalogTextBox.Size = new System.Drawing.Size(100, 20);
			this.catalogTextBox.TabIndex = 2;
			// 
			// dbFileTextBox
			// 
			this.dbFileTextBox.Location = new System.Drawing.Point(108, 60);
			this.dbFileTextBox.Name = "dbFileTextBox";
			this.dbFileTextBox.Size = new System.Drawing.Size(230, 20);
			this.dbFileTextBox.TabIndex = 3;
			// 
			// catalogRadioButton
			// 
			this.catalogRadioButton.AutoSize = true;
			this.catalogRadioButton.Location = new System.Drawing.Point(12, 38);
			this.catalogRadioButton.Name = "catalogRadioButton";
			this.catalogRadioButton.Size = new System.Drawing.Size(90, 17);
			this.catalogRadioButton.TabIndex = 4;
			this.catalogRadioButton.TabStop = true;
			this.catalogRadioButton.Text = "База данных";
			this.catalogRadioButton.UseVisualStyleBackColor = true;
			// 
			// dbFileRadioButton
			// 
			this.dbFileRadioButton.AutoSize = true;
			this.dbFileRadioButton.Location = new System.Drawing.Point(12, 61);
			this.dbFileRadioButton.Name = "dbFileRadioButton";
			this.dbFileRadioButton.Size = new System.Drawing.Size(73, 17);
			this.dbFileRadioButton.TabIndex = 5;
			this.dbFileRadioButton.TabStop = true;
			this.dbFileRadioButton.Text = "Файл БД";
			this.dbFileRadioButton.UseVisualStyleBackColor = true;
			// 
			// okButton
			// 
			this.okButton.DialogResult = System.Windows.Forms.DialogResult.OK;
			this.okButton.Location = new System.Drawing.Point(344, 115);
			this.okButton.Name = "okButton";
			this.okButton.Size = new System.Drawing.Size(75, 23);
			this.okButton.TabIndex = 6;
			this.okButton.Text = "OK";
			this.okButton.UseVisualStyleBackColor = true;
			this.okButton.Click += new System.EventHandler(this.okButton_Click);
			// 
			// cancelButton
			// 
			this.cancelButton.DialogResult = System.Windows.Forms.DialogResult.Cancel;
			this.cancelButton.Location = new System.Drawing.Point(263, 115);
			this.cancelButton.Name = "cancelButton";
			this.cancelButton.Size = new System.Drawing.Size(75, 23);
			this.cancelButton.TabIndex = 7;
			this.cancelButton.Text = "Отмена";
			this.cancelButton.UseVisualStyleBackColor = true;
			// 
			// browseButton
			// 
			this.browseButton.Location = new System.Drawing.Point(344, 58);
			this.browseButton.Name = "browseButton";
			this.browseButton.Size = new System.Drawing.Size(75, 23);
			this.browseButton.TabIndex = 8;
			this.browseButton.Text = "Обзор...";
			this.browseButton.UseVisualStyleBackColor = true;
			this.browseButton.Click += new System.EventHandler(this.browseButton_Click);
			// 
			// openFileDialog
			// 
			this.openFileDialog.DefaultExt = "*.mdf";
			this.openFileDialog.Filter = "Файлы баз данных|*.mdf|Все файлы|*.*";
			// 
			// AddDatabaseForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(429, 144);
			this.Controls.Add(this.browseButton);
			this.Controls.Add(this.cancelButton);
			this.Controls.Add(this.okButton);
			this.Controls.Add(this.dbFileRadioButton);
			this.Controls.Add(this.catalogRadioButton);
			this.Controls.Add(this.dbFileTextBox);
			this.Controls.Add(this.catalogTextBox);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.serverTextBox);
			this.Name = "AddDatabaseForm";
			this.Text = "Добавление существующей базы";
			this.Load += new System.EventHandler(this.AddDatabaseForm_Load);
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.TextBox serverTextBox;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.TextBox catalogTextBox;
		private System.Windows.Forms.TextBox dbFileTextBox;
		private System.Windows.Forms.RadioButton catalogRadioButton;
		private System.Windows.Forms.RadioButton dbFileRadioButton;
		private System.Windows.Forms.Button okButton;
		private System.Windows.Forms.Button cancelButton;
		private System.Windows.Forms.Button browseButton;
		private System.Windows.Forms.OpenFileDialog openFileDialog;
	}
}