namespace Denisenko.Cutting.CutOptima
{
    public partial class AddDbModePage
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
            this.radioButtonNew = new System.Windows.Forms.RadioButton();
            this.radioButtonExisting = new System.Windows.Forms.RadioButton();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // radioButtonNew
            // 
            this.radioButtonNew.AutoSize = true;
            this.radioButtonNew.Checked = true;
            this.radioButtonNew.Location = new System.Drawing.Point(63, 44);
            this.radioButtonNew.Name = "radioButtonNew";
            this.radioButtonNew.Size = new System.Drawing.Size(161, 21);
            this.radioButtonNew.TabIndex = 0;
            this.radioButtonNew.TabStop = true;
            this.radioButtonNew.Text = "Создать новую базу";
            this.radioButtonNew.UseVisualStyleBackColor = true;
            // 
            // radioButtonExisting
            // 
            this.radioButtonExisting.AutoSize = true;
            this.radioButtonExisting.Location = new System.Drawing.Point(63, 106);
            this.radioButtonExisting.Name = "radioButtonExisting";
            this.radioButtonExisting.Size = new System.Drawing.Size(223, 21);
            this.radioButtonExisting.TabIndex = 1;
            this.radioButtonExisting.Text = "Выбрать существующую базу";
            this.radioButtonExisting.UseVisualStyleBackColor = true;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(85, 68);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(250, 17);
            this.label1.TabIndex = 2;
            this.label1.Text = "Создать новую, пустую, базу данных";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(85, 130);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(442, 17);
            this.label2.TabIndex = 3;
            this.label2.Text = "Подключить существующую базу данных в файле или на сервере";
            // 
            // AddDbModePage
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.radioButtonExisting);
            this.Controls.Add(this.radioButtonNew);
            this.Name = "AddDbModePage";
            this.Activate += new Denisenko.Cutting.CutOptima.ActivateHandler(this.AddDbModePage_Activate);
            this.NextClick += new Denisenko.Cutting.CutOptima.NextClickHandler(this.AddDbModePage_NextClick);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.RadioButton radioButtonNew;
        private System.Windows.Forms.RadioButton radioButtonExisting;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
    }
}
