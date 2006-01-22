namespace Raskroy
{
	partial class Form1
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
			this.detailsDataGridView = new System.Windows.Forms.DataGridView();
			this.nameDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.lengthDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.widthDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.quantityDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.detailsBindingSource = new System.Windows.Forms.BindingSource(this.components);
			this.dataSet = new Raskroy.DataSet();
			this.optimizeButton = new System.Windows.Forms.Button();
			this.cuttingControl = new Raskroy.CuttingControl();
			((System.ComponentModel.ISupportInitialize)(this.detailsDataGridView)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.detailsBindingSource)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.dataSet)).BeginInit();
			this.SuspendLayout();
			// 
			// detailsDataGridView
			// 
			this.detailsDataGridView.AutoGenerateColumns = false;
			this.detailsDataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
			this.detailsDataGridView.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.nameDataGridViewTextBoxColumn,
            this.lengthDataGridViewTextBoxColumn,
            this.widthDataGridViewTextBoxColumn,
            this.quantityDataGridViewTextBoxColumn});
			this.detailsDataGridView.DataSource = this.detailsBindingSource;
			this.detailsDataGridView.Location = new System.Drawing.Point(12, 12);
			this.detailsDataGridView.Name = "detailsDataGridView";
			this.detailsDataGridView.Size = new System.Drawing.Size(501, 152);
			this.detailsDataGridView.TabIndex = 0;
			this.detailsDataGridView.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellContentClick);
			// 
			// nameDataGridViewTextBoxColumn
			// 
			this.nameDataGridViewTextBoxColumn.DataPropertyName = "Name";
			this.nameDataGridViewTextBoxColumn.HeaderText = "Название";
			this.nameDataGridViewTextBoxColumn.Name = "nameDataGridViewTextBoxColumn";
			// 
			// lengthDataGridViewTextBoxColumn
			// 
			this.lengthDataGridViewTextBoxColumn.DataPropertyName = "Length";
			this.lengthDataGridViewTextBoxColumn.HeaderText = "Длина";
			this.lengthDataGridViewTextBoxColumn.Name = "lengthDataGridViewTextBoxColumn";
			// 
			// widthDataGridViewTextBoxColumn
			// 
			this.widthDataGridViewTextBoxColumn.DataPropertyName = "Width";
			this.widthDataGridViewTextBoxColumn.HeaderText = "Ширина";
			this.widthDataGridViewTextBoxColumn.Name = "widthDataGridViewTextBoxColumn";
			// 
			// quantityDataGridViewTextBoxColumn
			// 
			this.quantityDataGridViewTextBoxColumn.DataPropertyName = "Quantity";
			this.quantityDataGridViewTextBoxColumn.HeaderText = "Кол-во";
			this.quantityDataGridViewTextBoxColumn.Name = "quantityDataGridViewTextBoxColumn";
			// 
			// detailsBindingSource
			// 
			this.detailsBindingSource.DataMember = "Details";
			this.detailsBindingSource.DataSource = this.dataSet;
			// 
			// dataSet
			// 
			this.dataSet.DataSetName = "DataSet";
			this.dataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
			// 
			// optimizeButton
			// 
			this.optimizeButton.Location = new System.Drawing.Point(519, 12);
			this.optimizeButton.Name = "optimizeButton";
			this.optimizeButton.Size = new System.Drawing.Size(126, 23);
			this.optimizeButton.TabIndex = 1;
			this.optimizeButton.Text = "Оптимизировать";
			this.optimizeButton.UseVisualStyleBackColor = true;
			this.optimizeButton.Click += new System.EventHandler(this.optimizeButton_Click);
			// 
			// cuttingControl
			// 
			this.cuttingControl.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
						| System.Windows.Forms.AnchorStyles.Left)
						| System.Windows.Forms.AnchorStyles.Right)));
			this.cuttingControl.DataSource = null;
			this.cuttingControl.Location = new System.Drawing.Point(12, 170);
			this.cuttingControl.Name = "cuttingControl";
			this.cuttingControl.Size = new System.Drawing.Size(735, 309);
			this.cuttingControl.TabIndex = 2;
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(759, 491);
			this.Controls.Add(this.cuttingControl);
			this.Controls.Add(this.optimizeButton);
			this.Controls.Add(this.detailsDataGridView);
			this.Name = "Form1";
			this.Text = "Form1";
			((System.ComponentModel.ISupportInitialize)(this.detailsDataGridView)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.detailsBindingSource)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.dataSet)).EndInit();
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.DataGridView detailsDataGridView;
		private System.Windows.Forms.BindingSource detailsBindingSource;
		private DataSet dataSet;
		private System.Windows.Forms.DataGridViewTextBoxColumn nameDataGridViewTextBoxColumn;
		private System.Windows.Forms.DataGridViewTextBoxColumn lengthDataGridViewTextBoxColumn;
		private System.Windows.Forms.DataGridViewTextBoxColumn widthDataGridViewTextBoxColumn;
		private System.Windows.Forms.DataGridViewTextBoxColumn quantityDataGridViewTextBoxColumn;
		private System.Windows.Forms.Button optimizeButton;
		private CuttingControl cuttingControl;
	}
}

