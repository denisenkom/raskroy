namespace Denisenko.Cutting.CutOptima
{
    partial class AddDbNewPage
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

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.textBoxName = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.textBoxServer = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.radioButtonDbName = new System.Windows.Forms.RadioButton();
            this.radioButtonFile = new System.Windows.Forms.RadioButton();
            this.textBoxFileName = new System.Windows.Forms.TextBox();
            this.buttonBrowse = new System.Windows.Forms.Button();
            this.comboBoxDatabases = new System.Windows.Forms.ComboBox();
            this.errorProvider = new System.Windows.Forms.ErrorProvider(this.components);
            this.labelConnecting = new System.Windows.Forms.Label();
            this.openFileDialog = new System.Windows.Forms.OpenFileDialog();
            ((System.ComponentModel.ISupportInitialize)(this.errorProvider)).BeginInit();
            this.SuspendLayout();
            // 
            // textBoxName
            // 
            this.textBoxName.Location = new System.Drawing.Point(15, 32);
            this.textBoxName.Name = "textBoxName";
            this.textBoxName.Size = new System.Drawing.Size(400, 22);
            this.textBoxName.TabIndex = 0;
            this.textBoxName.Validated += new System.EventHandler(this.textBoxName_Validated);
            this.textBoxName.Validating += new System.ComponentModel.CancelEventHandler(this.textBoxName_Validating);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 12);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(124, 17);
            this.label1.TabIndex = 1;
            this.label1.Text = "Имя базы данных";
            // 
            // textBoxServer
            // 
            this.textBoxServer.Location = new System.Drawing.Point(78, 82);
            this.textBoxServer.Name = "textBoxServer";
            this.textBoxServer.Size = new System.Drawing.Size(183, 22);
            this.textBoxServer.TabIndex = 1;
            this.textBoxServer.Validated += new System.EventHandler(this.textBoxServer_Validated);
            this.textBoxServer.Validating += new System.ComponentModel.CancelEventHandler(this.textBoxServer_Validating);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 85);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(60, 17);
            this.label2.TabIndex = 3;
            this.label2.Text = "Сервер:";
            // 
            // radioButtonDbName
            // 
            this.radioButtonDbName.AutoSize = true;
            this.radioButtonDbName.Checked = true;
            this.radioButtonDbName.Location = new System.Drawing.Point(15, 110);
            this.radioButtonDbName.Name = "radioButtonDbName";
            this.radioButtonDbName.Size = new System.Drawing.Size(80, 21);
            this.radioButtonDbName.TabIndex = 2;
            this.radioButtonDbName.TabStop = true;
            this.radioButtonDbName.Text = "Имя БД";
            this.radioButtonDbName.UseVisualStyleBackColor = true;
            this.radioButtonDbName.Click += new System.EventHandler(this.radioButtonDbName_Click);
            // 
            // radioButtonFile
            // 
            this.radioButtonFile.AutoSize = true;
            this.radioButtonFile.Location = new System.Drawing.Point(15, 139);
            this.radioButtonFile.Name = "radioButtonFile";
            this.radioButtonFile.Size = new System.Drawing.Size(66, 21);
            this.radioButtonFile.TabIndex = 3;
            this.radioButtonFile.TabStop = true;
            this.radioButtonFile.Text = "Файл";
            this.radioButtonFile.UseVisualStyleBackColor = true;
            this.radioButtonFile.Click += new System.EventHandler(this.radioButtonFile_Click);
            // 
            // textBoxFileName
            // 
            this.textBoxFileName.AutoCompleteMode = System.Windows.Forms.AutoCompleteMode.Suggest;
            this.textBoxFileName.AutoCompleteSource = System.Windows.Forms.AutoCompleteSource.FileSystem;
            this.textBoxFileName.Location = new System.Drawing.Point(101, 138);
            this.textBoxFileName.Name = "textBoxFileName";
            this.textBoxFileName.Size = new System.Drawing.Size(314, 22);
            this.textBoxFileName.TabIndex = 5;
            this.textBoxFileName.TabStop = false;
            this.textBoxFileName.Click += new System.EventHandler(this.textBoxFileName_Click);
            this.textBoxFileName.Leave += new System.EventHandler(this.textBoxFileName_Leave);
            // 
            // buttonBrowse
            // 
            this.buttonBrowse.Location = new System.Drawing.Point(421, 134);
            this.buttonBrowse.Name = "buttonBrowse";
            this.buttonBrowse.Size = new System.Drawing.Size(96, 30);
            this.buttonBrowse.TabIndex = 6;
            this.buttonBrowse.TabStop = false;
            this.buttonBrowse.Text = "Обзор...";
            this.buttonBrowse.UseVisualStyleBackColor = true;
            this.buttonBrowse.Click += new System.EventHandler(this.buttonBrowse_Click);
            // 
            // comboBoxDatabases
            // 
            this.comboBoxDatabases.FormattingEnabled = true;
            this.comboBoxDatabases.Location = new System.Drawing.Point(101, 109);
            this.comboBoxDatabases.Name = "comboBoxDatabases";
            this.comboBoxDatabases.Size = new System.Drawing.Size(160, 24);
            this.comboBoxDatabases.TabIndex = 4;
            this.comboBoxDatabases.Leave += new System.EventHandler(this.comboBoxDatabases_Leave);
            this.comboBoxDatabases.Click += new System.EventHandler(this.comboBoxDatabases_Click);
            // 
            // errorProvider
            // 
            this.errorProvider.ContainerControl = this;
            // 
            // labelConnecting
            // 
            this.labelConnecting.AutoSize = true;
            this.labelConnecting.Location = new System.Drawing.Point(267, 85);
            this.labelConnecting.Name = "labelConnecting";
            this.labelConnecting.Size = new System.Drawing.Size(0, 17);
            this.labelConnecting.TabIndex = 11;
            // 
            // openFileDialog
            // 
            this.openFileDialog.DefaultExt = "mdf";
            this.openFileDialog.Filter = "Файлы Mdf|*.mdf|Все файлы|*.*";
            this.openFileDialog.RestoreDirectory = true;
            this.openFileDialog.Title = "Выберите файл базы данных";
            // 
            // AddDbNewPage
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.labelConnecting);
            this.Controls.Add(this.comboBoxDatabases);
            this.Controls.Add(this.buttonBrowse);
            this.Controls.Add(this.textBoxFileName);
            this.Controls.Add(this.radioButtonFile);
            this.Controls.Add(this.radioButtonDbName);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.textBoxServer);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBoxName);
            this.Name = "AddDbNewPage";
            this.Activate += new Denisenko.Cutting.CutOptima.ActivateHandler(this.AddDbNewPage_Activate);
            ((System.ComponentModel.ISupportInitialize)(this.errorProvider)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBoxName;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBoxServer;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.RadioButton radioButtonDbName;
        private System.Windows.Forms.RadioButton radioButtonFile;
        private System.Windows.Forms.TextBox textBoxFileName;
        private System.Windows.Forms.Button buttonBrowse;
        private System.Windows.Forms.ComboBox comboBoxDatabases;
        private System.Windows.Forms.ErrorProvider errorProvider;
        private System.Windows.Forms.Label labelConnecting;
        private System.Windows.Forms.OpenFileDialog openFileDialog;
    }
}
