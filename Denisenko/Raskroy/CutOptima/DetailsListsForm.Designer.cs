namespace Denisenko.Cutting.CutOptima
{
	partial class DetailsListsForm
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
			this.components = new System.ComponentModel.Container();
			this.listBox = new System.Windows.Forms.ListBox();
			this.dataSet = new Denisenko.Cutting.CutOptima.DataSet();
			this.bindingSource = new System.Windows.Forms.BindingSource(this.components);
			this.detailsListsTableAdapter = new Denisenko.Cutting.CutOptima.DataSetTableAdapters.DetailsListsTableAdapter();
			((System.ComponentModel.ISupportInitialize)(this.dataSet)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.bindingSource)).BeginInit();
			this.SuspendLayout();
			// 
			// listBox
			// 
			this.listBox.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
						| System.Windows.Forms.AnchorStyles.Left)
						| System.Windows.Forms.AnchorStyles.Right)));
			this.listBox.DataSource = this.bindingSource;
			this.listBox.DisplayMember = "Remarks";
			this.listBox.FormattingEnabled = true;
			this.listBox.Location = new System.Drawing.Point(12, 12);
			this.listBox.Name = "listBox";
			this.listBox.Size = new System.Drawing.Size(530, 316);
			this.listBox.TabIndex = 0;
			this.listBox.ValueMember = "DetailsLists.DetailsListID";
			this.listBox.DoubleClick += new System.EventHandler(this.listBox_DoubleClick);
			// 
			// dataSet
			// 
			this.dataSet.DataSetName = "DataSet";
			this.dataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
			// 
			// bindingSource
			// 
			this.bindingSource.DataMember = "DetailsLists";
			this.bindingSource.DataSource = this.dataSet;
			// 
			// detailsListsTableAdapter
			// 
			this.detailsListsTableAdapter.ClearBeforeFill = true;
			// 
			// DetailsListsForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(554, 340);
			this.Controls.Add(this.listBox);
			this.Name = "DetailsListsForm";
			this.Text = "Списки";
			this.Load += new System.EventHandler(this.DetailsListsForm_Load);
			((System.ComponentModel.ISupportInitialize)(this.dataSet)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.bindingSource)).EndInit();
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.ListBox listBox;
		private DataSet dataSet;
		private System.Windows.Forms.BindingSource bindingSource;
		private Denisenko.Cutting.CutOptima.DataSetTableAdapters.DetailsListsTableAdapter detailsListsTableAdapter;
	}
}