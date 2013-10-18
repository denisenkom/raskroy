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
            this.username_tb = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.password_tb = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            this.sql_auth_cb = new System.Windows.Forms.RadioButton();
            this.windows_auth_cb = new System.Windows.Forms.RadioButton();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // serverTextBox
            // 
            resources.ApplyResources(this.serverTextBox, "serverTextBox");
            this.serverTextBox.Name = "serverTextBox";
            // 
            // label1
            // 
            resources.ApplyResources(this.label1, "label1");
            this.label1.Name = "label1";
            // 
            // dbNameRadioButton
            // 
            resources.ApplyResources(this.dbNameRadioButton, "dbNameRadioButton");
            this.dbNameRadioButton.Checked = true;
            this.dbNameRadioButton.Name = "dbNameRadioButton";
            this.dbNameRadioButton.TabStop = true;
            this.dbNameRadioButton.UseVisualStyleBackColor = true;
            this.dbNameRadioButton.CheckedChanged += new System.EventHandler(this.dbNamePathRadioButton_CheckedChanged);
            // 
            // dbPathRadioButton
            // 
            resources.ApplyResources(this.dbPathRadioButton, "dbPathRadioButton");
            this.dbPathRadioButton.Name = "dbPathRadioButton";
            this.dbPathRadioButton.UseVisualStyleBackColor = true;
            this.dbPathRadioButton.CheckedChanged += new System.EventHandler(this.dbNamePathRadioButton_CheckedChanged);
            // 
            // dbNameTextBox
            // 
            resources.ApplyResources(this.dbNameTextBox, "dbNameTextBox");
            this.dbNameTextBox.Name = "dbNameTextBox";
            // 
            // dbPathTextBox
            // 
            resources.ApplyResources(this.dbPathTextBox, "dbPathTextBox");
            this.dbPathTextBox.Name = "dbPathTextBox";
            // 
            // browseButton
            // 
            resources.ApplyResources(this.browseButton, "browseButton");
            this.browseButton.Name = "browseButton";
            this.browseButton.UseVisualStyleBackColor = true;
            this.browseButton.Click += new System.EventHandler(this.browseButton_Click);
            // 
            // OKbutton
            // 
            this.OKbutton.DialogResult = System.Windows.Forms.DialogResult.OK;
            resources.ApplyResources(this.OKbutton, "OKbutton");
            this.OKbutton.Name = "OKbutton";
            this.OKbutton.UseVisualStyleBackColor = true;
            this.OKbutton.Click += new System.EventHandler(this.OKbutton_Click);
            // 
            // cancelButton
            // 
            this.cancelButton.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            resources.ApplyResources(this.cancelButton, "cancelButton");
            this.cancelButton.Name = "cancelButton";
            this.cancelButton.UseVisualStyleBackColor = true;
            // 
            // saveFileDialog
            // 
            this.saveFileDialog.AddExtension = false;
            this.saveFileDialog.DefaultExt = "mdf";
            resources.ApplyResources(this.saveFileDialog, "saveFileDialog");
            // 
            // username_tb
            // 
            resources.ApplyResources(this.username_tb, "username_tb");
            this.username_tb.Name = "username_tb";
            // 
            // label2
            // 
            resources.ApplyResources(this.label2, "label2");
            this.label2.Name = "label2";
            // 
            // label3
            // 
            resources.ApplyResources(this.label3, "label3");
            this.label3.Name = "label3";
            // 
            // password_tb
            // 
            resources.ApplyResources(this.password_tb, "password_tb");
            this.password_tb.Name = "password_tb";
            // 
            // label4
            // 
            resources.ApplyResources(this.label4, "label4");
            this.label4.Name = "label4";
            // 
            // label5
            // 
            resources.ApplyResources(this.label5, "label5");
            this.label5.Name = "label5";
            // 
            // label6
            // 
            resources.ApplyResources(this.label6, "label6");
            this.label6.Name = "label6";
            // 
            // button1
            // 
            resources.ApplyResources(this.button1, "button1");
            this.button1.Name = "button1";
            this.button1.UseVisualStyleBackColor = true;
            // 
            // textBox3
            // 
            resources.ApplyResources(this.textBox3, "textBox3");
            this.textBox3.Name = "textBox3";
            // 
            // label7
            // 
            resources.ApplyResources(this.label7, "label7");
            this.label7.Name = "label7";
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.sql_auth_cb);
            this.panel1.Controls.Add(this.windows_auth_cb);
            resources.ApplyResources(this.panel1, "panel1");
            this.panel1.Name = "panel1";
            // 
            // sql_auth_cb
            // 
            resources.ApplyResources(this.sql_auth_cb, "sql_auth_cb");
            this.sql_auth_cb.Name = "sql_auth_cb";
            this.sql_auth_cb.UseVisualStyleBackColor = true;
            this.sql_auth_cb.CheckedChanged += new System.EventHandler(this.sql_auth_cb_CheckedChanged);
            // 
            // windows_auth_cb
            // 
            resources.ApplyResources(this.windows_auth_cb, "windows_auth_cb");
            this.windows_auth_cb.Checked = true;
            this.windows_auth_cb.Name = "windows_auth_cb";
            this.windows_auth_cb.TabStop = true;
            this.windows_auth_cb.UseVisualStyleBackColor = true;
            this.windows_auth_cb.CheckedChanged += new System.EventHandler(this.windows_auth_cb_CheckedChanged);
            // 
            // NewDatabaseForm
            // 
            this.AcceptButton = this.OKbutton;
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.CancelButton = this.cancelButton;
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.textBox3);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.password_tb);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.username_tb);
            this.Controls.Add(this.cancelButton);
            this.Controls.Add(this.OKbutton);
            this.Controls.Add(this.browseButton);
            this.Controls.Add(this.dbPathTextBox);
            this.Controls.Add(this.dbNameTextBox);
            this.Controls.Add(this.dbPathRadioButton);
            this.Controls.Add(this.dbNameRadioButton);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.serverTextBox);
            this.MaximizeBox = false;
            this.Name = "NewDatabaseForm";
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
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
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.Label label7;
        public System.Windows.Forms.TextBox username_tb;
        public System.Windows.Forms.TextBox password_tb;
        private System.Windows.Forms.Panel panel1;
        public System.Windows.Forms.RadioButton sql_auth_cb;
        public System.Windows.Forms.RadioButton windows_auth_cb;
	}
}