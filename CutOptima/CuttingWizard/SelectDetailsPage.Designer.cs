namespace Denisenko.Cutting.CutOptima.CuttingWizard
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
			this.dataSet = new Denisenko.Cutting.CutOptima.CuttingWizard.DataSet();
			this.returnAllButton = new System.Windows.Forms.Button();
			this.returnButton = new System.Windows.Forms.Button();
			this.issueAllButton = new System.Windows.Forms.Button();
			this.issueButton = new System.Windows.Forms.Button();
			this.detailsListsTableAdapter = new Denisenko.Cutting.CutOptima.CuttingWizard.DataSetTableAdapters.DetailsListsTableAdapter();
			((System.ComponentModel.ISupportInitialize)(this.detailsListsBindingSource)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.dataSetBindingSource)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.dataSet)).BeginInit();
			this.SuspendLayout();
			// 
			// destListBox
			// 
			this.destListBox.FormattingEnabled = true;
			this.destListBox.Location = new System.Drawing.Point(273, 0);
			this.destListBox.Name = "destListBox";
			this.destListBox.Size = new System.Drawing.Size(185, 212);
			this.destListBox.TabIndex = 8;
			// 
			// sourceListBox
			// 
			this.sourceListBox.DataSource = this.detailsListsBindingSource;
			this.sourceListBox.DisplayMember = "OrderID";
			this.sourceListBox.FormattingEnabled = true;
			this.sourceListBox.Location = new System.Drawing.Point(0, 0);
			this.sourceListBox.Name = "sourceListBox";
			this.sourceListBox.Size = new System.Drawing.Size(185, 212);
			this.sourceListBox.TabIndex = 7;
			this.sourceListBox.ValueMember = "DetailsListID";
			// 
			// detailsListsBindingSource
			// 
			this.detailsListsBindingSource.DataMember = "DetailsLists";
			this.detailsListsBindingSource.DataSource = this.dataSetBindingSource;
			// 
			// dataSetBindingSource
			// 
			this.dataSetBindingSource.DataSource = this.dataSet;
			this.dataSetBindingSource.Position = 0;
			// 
			// dataSet
			// 
			this.dataSet.DataSetName = "DataSet";
			this.dataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
			// 
			// returnAllButton
			// 
			this.returnAllButton.Location = new System.Drawing.Point(192, 140);
			this.returnAllButton.Name = "returnAllButton";
			this.returnAllButton.Size = new System.Drawing.Size(75, 23);
			this.returnAllButton.TabIndex = 11;
			this.returnAllButton.Text = "<<";
			this.returnAllButton.UseVisualStyleBackColor = true;
			this.returnAllButton.Click += new System.EventHandler(this.returnAllButton_Click);
			// 
			// returnButton
			// 
			this.returnButton.Location = new System.Drawing.Point(192, 111);
			this.returnButton.Name = "returnButton";
			this.returnButton.Size = new System.Drawing.Size(75, 23);
			this.returnButton.TabIndex = 12;
			this.returnButton.Text = "<";
			this.returnButton.UseVisualStyleBackColor = true;
			this.returnButton.Click += new System.EventHandler(this.returnButton_Click);
			// 
			// issueAllButton
			// 
			this.issueAllButton.Location = new System.Drawing.Point(192, 53);
			this.issueAllButton.Name = "issueAllButton";
			this.issueAllButton.Size = new System.Drawing.Size(75, 23);
			this.issueAllButton.TabIndex = 9;
			this.issueAllButton.Text = ">>";
			this.issueAllButton.UseVisualStyleBackColor = true;
			this.issueAllButton.Click += new System.EventHandler(this.issueAllButton_Click);
			// 
			// issueButton
			// 
			this.issueButton.Location = new System.Drawing.Point(192, 82);
			this.issueButton.Name = "issueButton";
			this.issueButton.Size = new System.Drawing.Size(75, 23);
			this.issueButton.TabIndex = 10;
			this.issueButton.Text = ">";
			this.issueButton.UseVisualStyleBackColor = true;
			this.issueButton.Click += new System.EventHandler(this.issueButton_Click);
			// 
			// detailsListsTableAdapter
			// 
			this.detailsListsTableAdapter.ClearBeforeFill = true;
			// 
			// SelectDetailsPage
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.Controls.Add(this.destListBox);
			this.Controls.Add(this.sourceListBox);
			this.Controls.Add(this.returnAllButton);
			this.Controls.Add(this.returnButton);
			this.Controls.Add(this.issueAllButton);
			this.Controls.Add(this.issueButton);
			this.Name = "SelectDetailsPage";
			this.Size = new System.Drawing.Size(458, 217);
			this.Load += new System.EventHandler(this.SelectDetailsPage_Load);
			((System.ComponentModel.ISupportInitialize)(this.detailsListsBindingSource)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.dataSetBindingSource)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.dataSet)).EndInit();
			this.ResumeLayout(false);

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
		private DataSet dataSet;
		private Denisenko.Cutting.CutOptima.CuttingWizard.DataSetTableAdapters.DetailsListsTableAdapter detailsListsTableAdapter;
	}
}
