namespace Denisenko.Cutting.CutOptima
{
    partial class ExistingDatabaseForm
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
            this.panel1 = new System.Windows.Forms.Panel();
            this.sql_auth_cb = new System.Windows.Forms.RadioButton();
            this.windows_auth_cb = new System.Windows.Forms.RadioButton();
            this.label7 = new System.Windows.Forms.Label();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.test_connection_btn = new System.Windows.Forms.Button();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.password_tb = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.username_tb = new System.Windows.Forms.TextBox();
            this.cancelButton = new System.Windows.Forms.Button();
            this.OKbutton = new System.Windows.Forms.Button();
            this.browseButton = new System.Windows.Forms.Button();
            this.dbPathTextBox = new System.Windows.Forms.TextBox();
            this.dbNameTextBox = new System.Windows.Forms.TextBox();
            this.dbPathRadioButton = new System.Windows.Forms.RadioButton();
            this.dbNameRadioButton = new System.Windows.Forms.RadioButton();
            this.label1 = new System.Windows.Forms.Label();
            this.serverTextBox = new System.Windows.Forms.TextBox();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.sql_auth_cb);
            this.panel1.Controls.Add(this.windows_auth_cb);
            this.panel1.Location = new System.Drawing.Point(27, 92);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(268, 46);
            this.panel1.TabIndex = 23;
            // 
            // sql_auth_cb
            // 
            this.sql_auth_cb.AutoSize = true;
            this.sql_auth_cb.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.sql_auth_cb.Location = new System.Drawing.Point(9, 26);
            this.sql_auth_cb.Name = "sql_auth_cb";
            this.sql_auth_cb.Size = new System.Drawing.Size(216, 17);
            this.sql_auth_cb.TabIndex = 1;
            this.sql_auth_cb.Text = "&Use a specific user name and password:";
            this.sql_auth_cb.UseVisualStyleBackColor = true;
            this.sql_auth_cb.CheckedChanged += new System.EventHandler(this.sql_auth_cb_CheckedChanged);
            // 
            // windows_auth_cb
            // 
            this.windows_auth_cb.AutoSize = true;
            this.windows_auth_cb.Checked = true;
            this.windows_auth_cb.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.windows_auth_cb.Location = new System.Drawing.Point(9, 3);
            this.windows_auth_cb.Name = "windows_auth_cb";
            this.windows_auth_cb.Size = new System.Drawing.Size(199, 17);
            this.windows_auth_cb.TabIndex = 1;
            this.windows_auth_cb.TabStop = true;
            this.windows_auth_cb.Text = "Use &Windows NT Integrated security";
            this.windows_auth_cb.UseVisualStyleBackColor = true;
            this.windows_auth_cb.CheckedChanged += new System.EventHandler(this.windows_auth_cb_CheckedChanged);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.label7.Location = new System.Drawing.Point(58, 286);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(97, 13);
            this.label7.TabIndex = 40;
            this.label7.Text = "Using the &filename:";
            // 
            // textBox3
            // 
            this.textBox3.Location = new System.Drawing.Point(61, 263);
            this.textBox3.Name = "textBox3";
            this.textBox3.Size = new System.Drawing.Size(239, 20);
            this.textBox3.TabIndex = 29;
            // 
            // test_connection_btn
            // 
            this.test_connection_btn.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.test_connection_btn.Location = new System.Drawing.Point(180, 328);
            this.test_connection_btn.Name = "test_connection_btn";
            this.test_connection_btn.Size = new System.Drawing.Size(120, 23);
            this.test_connection_btn.TabIndex = 34;
            this.test_connection_btn.Text = "&Test Connection";
            this.test_connection_btn.UseVisualStyleBackColor = true;
            this.test_connection_btn.Click += new System.EventHandler(this.test_connection_btn_Click);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.label6.Location = new System.Drawing.Point(12, 9);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(255, 13);
            this.label6.TabIndex = 39;
            this.label6.Text = "Specify the following to connect to SQL Server data:";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.label5.Location = new System.Drawing.Point(24, 76);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(207, 13);
            this.label5.TabIndex = 38;
            this.label5.Text = "2. Enter information to log on to the server:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.label4.Location = new System.Drawing.Point(24, 193);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(16, 13);
            this.label4.TabIndex = 37;
            this.label4.Text = "3.";
            // 
            // password_tb
            // 
            this.password_tb.Enabled = false;
            this.password_tb.Location = new System.Drawing.Point(127, 161);
            this.password_tb.Name = "password_tb";
            this.password_tb.PasswordChar = '*';
            this.password_tb.Size = new System.Drawing.Size(172, 20);
            this.password_tb.TabIndex = 25;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.label3.Location = new System.Drawing.Point(58, 164);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(56, 13);
            this.label3.TabIndex = 36;
            this.label3.Text = "&Password:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.label2.Location = new System.Drawing.Point(57, 141);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(61, 13);
            this.label2.TabIndex = 35;
            this.label2.Text = "User &name:";
            // 
            // username_tb
            // 
            this.username_tb.Enabled = false;
            this.username_tb.Location = new System.Drawing.Point(127, 138);
            this.username_tb.Name = "username_tb";
            this.username_tb.Size = new System.Drawing.Size(173, 20);
            this.username_tb.TabIndex = 24;
            // 
            // cancelButton
            // 
            this.cancelButton.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.cancelButton.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.cancelButton.Location = new System.Drawing.Point(224, 370);
            this.cancelButton.Name = "cancelButton";
            this.cancelButton.Size = new System.Drawing.Size(75, 23);
            this.cancelButton.TabIndex = 33;
            this.cancelButton.Text = "Cancel";
            this.cancelButton.UseVisualStyleBackColor = true;
            // 
            // OKbutton
            // 
            this.OKbutton.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.OKbutton.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.OKbutton.Location = new System.Drawing.Point(143, 370);
            this.OKbutton.Name = "OKbutton";
            this.OKbutton.Size = new System.Drawing.Size(75, 23);
            this.OKbutton.TabIndex = 31;
            this.OKbutton.Text = "ОК";
            this.OKbutton.UseVisualStyleBackColor = true;
            // 
            // browseButton
            // 
            this.browseButton.Enabled = false;
            this.browseButton.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.browseButton.Location = new System.Drawing.Point(276, 299);
            this.browseButton.Name = "browseButton";
            this.browseButton.Size = new System.Drawing.Size(24, 23);
            this.browseButton.TabIndex = 32;
            this.browseButton.Text = "...";
            this.browseButton.UseVisualStyleBackColor = true;
            // 
            // dbPathTextBox
            // 
            this.dbPathTextBox.Enabled = false;
            this.dbPathTextBox.Location = new System.Drawing.Point(60, 302);
            this.dbPathTextBox.Name = "dbPathTextBox";
            this.dbPathTextBox.Size = new System.Drawing.Size(210, 20);
            this.dbPathTextBox.TabIndex = 30;
            // 
            // dbNameTextBox
            // 
            this.dbNameTextBox.Location = new System.Drawing.Point(61, 214);
            this.dbNameTextBox.Name = "dbNameTextBox";
            this.dbNameTextBox.Size = new System.Drawing.Size(239, 20);
            this.dbNameTextBox.TabIndex = 28;
            // 
            // dbPathRadioButton
            // 
            this.dbPathRadioButton.AutoSize = true;
            this.dbPathRadioButton.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.dbPathRadioButton.Location = new System.Drawing.Point(43, 240);
            this.dbPathRadioButton.Name = "dbPathRadioButton";
            this.dbPathRadioButton.Size = new System.Drawing.Size(221, 17);
            this.dbPathRadioButton.TabIndex = 26;
            this.dbPathRadioButton.Text = "Attac&h a database file as database name:";
            this.dbPathRadioButton.UseVisualStyleBackColor = true;
            // 
            // dbNameRadioButton
            // 
            this.dbNameRadioButton.AutoSize = true;
            this.dbNameRadioButton.Checked = true;
            this.dbNameRadioButton.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.dbNameRadioButton.Location = new System.Drawing.Point(43, 191);
            this.dbNameRadioButton.Name = "dbNameRadioButton";
            this.dbNameRadioButton.Size = new System.Drawing.Size(188, 17);
            this.dbNameRadioButton.TabIndex = 27;
            this.dbNameRadioButton.TabStop = true;
            this.dbNameRadioButton.Text = "Select the &database on the server:";
            this.dbNameRadioButton.UseVisualStyleBackColor = true;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.label1.Location = new System.Drawing.Point(24, 30);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(161, 13);
            this.label1.TabIndex = 22;
            this.label1.Text = "1. Select or enter a s&erver name:";
            // 
            // serverTextBox
            // 
            this.serverTextBox.Location = new System.Drawing.Point(40, 46);
            this.serverTextBox.Name = "serverTextBox";
            this.serverTextBox.Size = new System.Drawing.Size(260, 20);
            this.serverTextBox.TabIndex = 21;
            this.serverTextBox.Text = ".\\SQLEXPRESS";
            // 
            // ExistingDatabaseForm
            // 
            this.AcceptButton = this.OKbutton;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.CancelButton = this.cancelButton;
            this.ClientSize = new System.Drawing.Size(319, 407);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.textBox3);
            this.Controls.Add(this.test_connection_btn);
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
            this.Name = "ExistingDatabaseForm";
            this.Text = "ExistingDatabaseForm";
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        public System.Windows.Forms.RadioButton sql_auth_cb;
        public System.Windows.Forms.RadioButton windows_auth_cb;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Button test_connection_btn;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        public System.Windows.Forms.TextBox password_tb;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        public System.Windows.Forms.TextBox username_tb;
        private System.Windows.Forms.Button cancelButton;
        private System.Windows.Forms.Button OKbutton;
        private System.Windows.Forms.Button browseButton;
        private System.Windows.Forms.Label label1;
        public System.Windows.Forms.TextBox textBox3;
        public System.Windows.Forms.TextBox dbPathTextBox;
        public System.Windows.Forms.TextBox dbNameTextBox;
        public System.Windows.Forms.RadioButton dbPathRadioButton;
        public System.Windows.Forms.RadioButton dbNameRadioButton;
        public System.Windows.Forms.TextBox serverTextBox;

    }
}