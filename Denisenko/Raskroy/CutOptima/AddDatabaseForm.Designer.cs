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
            this.serverTextBox.Location = new System.Drawing.Point(87, 15);
            this.serverTextBox.Margin = new System.Windows.Forms.Padding(4);
            this.serverTextBox.Name = "serverTextBox";
            this.serverTextBox.Size = new System.Drawing.Size(132, 22);
            this.serverTextBox.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(16, 18);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(60, 17);
            this.label1.TabIndex = 0;
            this.label1.Text = "Сервер:";
            // 
            // catalogTextBox
            // 
            this.catalogTextBox.Location = new System.Drawing.Point(144, 46);
            this.catalogTextBox.Margin = new System.Windows.Forms.Padding(4);
            this.catalogTextBox.Name = "catalogTextBox";
            this.catalogTextBox.Size = new System.Drawing.Size(132, 22);
            this.catalogTextBox.TabIndex = 3;
            this.catalogTextBox.Enter += new System.EventHandler(this.catalogTextBox_Enter);
            // 
            // dbFileTextBox
            // 
            this.dbFileTextBox.Location = new System.Drawing.Point(144, 74);
            this.dbFileTextBox.Margin = new System.Windows.Forms.Padding(4);
            this.dbFileTextBox.Name = "dbFileTextBox";
            this.dbFileTextBox.Size = new System.Drawing.Size(305, 22);
            this.dbFileTextBox.TabIndex = 5;
            this.dbFileTextBox.Enter += new System.EventHandler(this.dbFileTextBox_Enter);
            // 
            // catalogRadioButton
            // 
            this.catalogRadioButton.AutoSize = true;
            this.catalogRadioButton.Location = new System.Drawing.Point(16, 47);
            this.catalogRadioButton.Margin = new System.Windows.Forms.Padding(4);
            this.catalogRadioButton.Name = "catalogRadioButton";
            this.catalogRadioButton.Size = new System.Drawing.Size(113, 21);
            this.catalogRadioButton.TabIndex = 2;
            this.catalogRadioButton.TabStop = true;
            this.catalogRadioButton.Text = "База данных";
            this.catalogRadioButton.UseVisualStyleBackColor = true;
            // 
            // dbFileRadioButton
            // 
            this.dbFileRadioButton.AutoSize = true;
            this.dbFileRadioButton.Location = new System.Drawing.Point(16, 75);
            this.dbFileRadioButton.Margin = new System.Windows.Forms.Padding(4);
            this.dbFileRadioButton.Name = "dbFileRadioButton";
            this.dbFileRadioButton.Size = new System.Drawing.Size(90, 21);
            this.dbFileRadioButton.TabIndex = 4;
            this.dbFileRadioButton.TabStop = true;
            this.dbFileRadioButton.Text = "Файл БД";
            this.dbFileRadioButton.UseVisualStyleBackColor = true;
            // 
            // okButton
            // 
            this.okButton.Location = new System.Drawing.Point(351, 136);
            this.okButton.Margin = new System.Windows.Forms.Padding(4);
            this.okButton.Name = "okButton";
            this.okButton.Size = new System.Drawing.Size(100, 28);
            this.okButton.TabIndex = 7;
            this.okButton.Text = "OK";
            this.okButton.UseVisualStyleBackColor = true;
            this.okButton.Click += new System.EventHandler(this.okButton_Click);
            // 
            // cancelButton
            // 
            this.cancelButton.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.cancelButton.Location = new System.Drawing.Point(459, 136);
            this.cancelButton.Margin = new System.Windows.Forms.Padding(4);
            this.cancelButton.Name = "cancelButton";
            this.cancelButton.Size = new System.Drawing.Size(100, 28);
            this.cancelButton.TabIndex = 8;
            this.cancelButton.Text = "Отмена";
            this.cancelButton.UseVisualStyleBackColor = true;
            // 
            // browseButton
            // 
            this.browseButton.Location = new System.Drawing.Point(459, 71);
            this.browseButton.Margin = new System.Windows.Forms.Padding(4);
            this.browseButton.Name = "browseButton";
            this.browseButton.Size = new System.Drawing.Size(100, 28);
            this.browseButton.TabIndex = 6;
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
            this.AcceptButton = this.okButton;
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.CancelButton = this.cancelButton;
            this.ClientSize = new System.Drawing.Size(572, 177);
            this.Controls.Add(this.browseButton);
            this.Controls.Add(this.cancelButton);
            this.Controls.Add(this.okButton);
            this.Controls.Add(this.dbFileRadioButton);
            this.Controls.Add(this.catalogRadioButton);
            this.Controls.Add(this.dbFileTextBox);
            this.Controls.Add(this.catalogTextBox);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.serverTextBox);
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "AddDatabaseForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Добавление существующей базы";
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