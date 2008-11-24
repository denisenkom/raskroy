namespace Denisenko.Cutting.CutOptima
{
	partial class SelectDetailsPage
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
            this.destListBox = new System.Windows.Forms.ListBox();
            this.sourceListBox = new System.Windows.Forms.ListBox();
            this.detailsListsBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.dataSetBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.dataSet = new Denisenko.Cutting.CutOptima.WizDataSet();
            this.returnAllButton = new System.Windows.Forms.Button();
            this.returnButton = new System.Windows.Forms.Button();
            this.issueAllButton = new System.Windows.Forms.Button();
            this.issueButton = new System.Windows.Forms.Button();
            this.detailsListsTableAdapter = new Denisenko.Cutting.CutOptima.WizDataSetTableAdapters.WizDetailsListsTableAdapter();
            this.label1 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.detailsListsBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataSetBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataSet)).BeginInit();
            this.SuspendLayout();
            // 
            // destListBox
            // 
            this.destListBox.FormattingEnabled = true;
            this.destListBox.ItemHeight = 16;
            this.destListBox.Location = new System.Drawing.Point(396, 66);
            this.destListBox.Margin = new System.Windows.Forms.Padding(4);
            this.destListBox.Name = "destListBox";
            this.destListBox.Size = new System.Drawing.Size(245, 260);
            this.destListBox.TabIndex = 8;
            // 
            // sourceListBox
            // 
            this.sourceListBox.DataSource = this.detailsListsBindingSource;
            this.sourceListBox.DisplayMember = "OrderID";
            this.sourceListBox.FormattingEnabled = true;
            this.sourceListBox.ItemHeight = 16;
            this.sourceListBox.Location = new System.Drawing.Point(4, 66);
            this.sourceListBox.Margin = new System.Windows.Forms.Padding(4);
            this.sourceListBox.Name = "sourceListBox";
            this.sourceListBox.Size = new System.Drawing.Size(245, 260);
            this.sourceListBox.TabIndex = 7;
            this.sourceListBox.ValueMember = "DetailsListID";
            // 
            // detailsListsBindingSource
            // 
            this.detailsListsBindingSource.DataMember = "WizDetailsLists";
            this.detailsListsBindingSource.DataSource = this.dataSetBindingSource;
            // 
            // dataSetBindingSource
            // 
            this.dataSetBindingSource.DataSource = this.dataSet;
            this.dataSetBindingSource.Position = 0;
            // 
            // dataSet
            // 
            this.dataSet.DataSetName = "WizDataSet";
            this.dataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // returnAllButton
            // 
            this.returnAllButton.Location = new System.Drawing.Point(272, 238);
            this.returnAllButton.Margin = new System.Windows.Forms.Padding(4);
            this.returnAllButton.Name = "returnAllButton";
            this.returnAllButton.Size = new System.Drawing.Size(100, 28);
            this.returnAllButton.TabIndex = 11;
            this.returnAllButton.Text = "<<";
            this.returnAllButton.UseVisualStyleBackColor = true;
            this.returnAllButton.Click += new System.EventHandler(this.returnAllButton_Click);
            // 
            // returnButton
            // 
            this.returnButton.Location = new System.Drawing.Point(272, 203);
            this.returnButton.Margin = new System.Windows.Forms.Padding(4);
            this.returnButton.Name = "returnButton";
            this.returnButton.Size = new System.Drawing.Size(100, 28);
            this.returnButton.TabIndex = 12;
            this.returnButton.Text = "<";
            this.returnButton.UseVisualStyleBackColor = true;
            this.returnButton.Click += new System.EventHandler(this.returnButton_Click);
            // 
            // issueAllButton
            // 
            this.issueAllButton.Location = new System.Drawing.Point(272, 131);
            this.issueAllButton.Margin = new System.Windows.Forms.Padding(4);
            this.issueAllButton.Name = "issueAllButton";
            this.issueAllButton.Size = new System.Drawing.Size(100, 28);
            this.issueAllButton.TabIndex = 9;
            this.issueAllButton.Text = ">>";
            this.issueAllButton.UseVisualStyleBackColor = true;
            this.issueAllButton.Click += new System.EventHandler(this.issueAllButton_Click);
            // 
            // issueButton
            // 
            this.issueButton.Location = new System.Drawing.Point(272, 167);
            this.issueButton.Margin = new System.Windows.Forms.Padding(4);
            this.issueButton.Name = "issueButton";
            this.issueButton.Size = new System.Drawing.Size(100, 28);
            this.issueButton.TabIndex = 10;
            this.issueButton.Text = ">";
            this.issueButton.UseVisualStyleBackColor = true;
            this.issueButton.Click += new System.EventHandler(this.issueButton_Click);
            // 
            // detailsListsTableAdapter
            // 
            this.detailsListsTableAdapter.ClearBeforeFill = true;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(3, 20);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(438, 18);
            this.label1.TabIndex = 13;
            this.label1.Text = "Выберите списки деталей, которые нужно разложить.";
            // 
            // SelectDetailsPage
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.label1);
            this.Controls.Add(this.destListBox);
            this.Controls.Add(this.sourceListBox);
            this.Controls.Add(this.returnAllButton);
            this.Controls.Add(this.returnButton);
            this.Controls.Add(this.issueAllButton);
            this.Controls.Add(this.issueButton);
            this.Margin = new System.Windows.Forms.Padding(5);
            this.Name = "SelectDetailsPage";
            this.Size = new System.Drawing.Size(645, 330);
            this.Load += new System.EventHandler(this.SelectDetailsPage_Load);
            this.Activate += new Denisenko.Cutting.CutOptima.ActivateHandler(this.SelectDetailsPage_Activate);
            ((System.ComponentModel.ISupportInitialize)(this.detailsListsBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataSetBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataSet)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.ListBox destListBox;
		private System.Windows.Forms.ListBox sourceListBox;
		private System.Windows.Forms.Button returnAllButton;
		private System.Windows.Forms.Button returnButton;
		private System.Windows.Forms.Button issueAllButton;
		private System.Windows.Forms.Button issueButton;
		private System.Windows.Forms.BindingSource detailsListsBindingSource;
		private System.Windows.Forms.BindingSource dataSetBindingSource;
		private WizDataSet dataSet;
		private Denisenko.Cutting.CutOptima.WizDataSetTableAdapters.WizDetailsListsTableAdapter detailsListsTableAdapter;
        private System.Windows.Forms.Label label1;
	}
}
