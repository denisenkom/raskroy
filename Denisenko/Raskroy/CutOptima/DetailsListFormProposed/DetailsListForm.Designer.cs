namespace Denisenko.Cutting.CutOptima
{
	partial class DetailsListForm
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
			System.Windows.Forms.Label orderIDLabel;
			System.Windows.Forms.Label remarksLabel;
			this.dataSet = new Denisenko.Cutting.CutOptima.DataSet();
			this.materialsBindingSource = new System.Windows.Forms.BindingSource(this.components);
			this.materialsTableAdapter = new Denisenko.Cutting.CutOptima.DataSetTableAdapters.MaterialsTableAdapter();
			this.detailsListBindingSource = new System.Windows.Forms.BindingSource(this.components);
			this.orderIDTextBox = new System.Windows.Forms.TextBox();
			this.descriptionTextBox = new System.Windows.Forms.TextBox();
			this.detailBindingSource = new System.Windows.Forms.BindingSource(this.components);
			this.detailDataGridView = new System.Windows.Forms.DataGridView();
			this.dataGridViewTextBoxColumn12 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.dataGridViewTextBoxColumn14 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.dataGridViewTextBoxColumn13 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.dataGridViewTextBoxColumn1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.dataGridViewTextBoxColumn2 = new System.Windows.Forms.DataGridViewComboBoxColumn();
			this.dataGridViewTextBoxColumn15 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			orderIDLabel = new System.Windows.Forms.Label();
			remarksLabel = new System.Windows.Forms.Label();
			((System.ComponentModel.ISupportInitialize)(this.dataSet)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.materialsBindingSource)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.detailsListBindingSource)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.detailBindingSource)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.detailDataGridView)).BeginInit();
			this.SuspendLayout();
			// 
			// orderIDLabel
			// 
			orderIDLabel.AutoSize = true;
			orderIDLabel.Location = new System.Drawing.Point(12, 9);
			orderIDLabel.Name = "orderIDLabel";
			orderIDLabel.Size = new System.Drawing.Size(83, 13);
			orderIDLabel.TabIndex = 1;
			orderIDLabel.Text = "Номер заказа:";
			// 
			// remarksLabel
			// 
			remarksLabel.AutoSize = true;
			remarksLabel.Location = new System.Drawing.Point(12, 35);
			remarksLabel.Name = "remarksLabel";
			remarksLabel.Size = new System.Drawing.Size(90, 13);
			remarksLabel.TabIndex = 3;
			remarksLabel.Text = "Дополнительно:";
			// 
			// dataSet
			// 
			this.dataSet.DataSetName = "DataSet";
			this.dataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
			// 
			// materialsBindingSource
			// 
			this.materialsBindingSource.DataMember = "Materials";
			this.materialsBindingSource.DataSource = this.dataSet;
			// 
			// materialsTableAdapter
			// 
			this.materialsTableAdapter.ClearBeforeFill = true;
			// 
			// detailsListBindingSource
			// 
			this.detailsListBindingSource.DataSource = typeof(Denisenko.Cutting.CutOptima.DetailsList);
			// 
			// orderIDTextBox
			// 
			this.orderIDTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.detailsListBindingSource, "OrderID", true));
			this.orderIDTextBox.Location = new System.Drawing.Point(108, 6);
			this.orderIDTextBox.Name = "orderIDTextBox";
			this.orderIDTextBox.Size = new System.Drawing.Size(100, 20);
			this.orderIDTextBox.TabIndex = 7;
			// 
			// descriptionTextBox
			// 
			this.descriptionTextBox.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
						| System.Windows.Forms.AnchorStyles.Right)));
			this.descriptionTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.detailsListBindingSource, "Description", true));
			this.descriptionTextBox.Location = new System.Drawing.Point(108, 32);
			this.descriptionTextBox.Multiline = true;
			this.descriptionTextBox.Name = "descriptionTextBox";
			this.descriptionTextBox.Size = new System.Drawing.Size(658, 66);
			this.descriptionTextBox.TabIndex = 8;
			// 
			// detailBindingSource
			// 
			this.detailBindingSource.DataSource = typeof(Denisenko.Cutting.CutOptima.Detail);
			// 
			// detailDataGridView
			// 
			this.detailDataGridView.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
						| System.Windows.Forms.AnchorStyles.Left)
						| System.Windows.Forms.AnchorStyles.Right)));
			this.detailDataGridView.AutoGenerateColumns = false;
			this.detailDataGridView.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dataGridViewTextBoxColumn12,
            this.dataGridViewTextBoxColumn14,
            this.dataGridViewTextBoxColumn13,
            this.dataGridViewTextBoxColumn1,
            this.dataGridViewTextBoxColumn2,
            this.dataGridViewTextBoxColumn15});
			this.detailDataGridView.DataSource = this.detailBindingSource;
			this.detailDataGridView.Location = new System.Drawing.Point(12, 104);
			this.detailDataGridView.Name = "detailDataGridView";
			this.detailDataGridView.Size = new System.Drawing.Size(754, 352);
			this.detailDataGridView.TabIndex = 8;
			this.detailDataGridView.CellEndEdit += new System.Windows.Forms.DataGridViewCellEventHandler(this.detailDataGridView_CellEndEdit);
			this.detailDataGridView.DataError += new System.Windows.Forms.DataGridViewDataErrorEventHandler(this.detailDataGridView_DataError);
			// 
			// dataGridViewTextBoxColumn12
			// 
			this.dataGridViewTextBoxColumn12.DataPropertyName = "Name";
			this.dataGridViewTextBoxColumn12.HeaderText = "Название";
			this.dataGridViewTextBoxColumn12.Name = "dataGridViewTextBoxColumn12";
			// 
			// dataGridViewTextBoxColumn14
			// 
			this.dataGridViewTextBoxColumn14.DataPropertyName = "SizeA";
			this.dataGridViewTextBoxColumn14.HeaderText = "Размер А";
			this.dataGridViewTextBoxColumn14.Name = "dataGridViewTextBoxColumn14";
			// 
			// dataGridViewTextBoxColumn13
			// 
			this.dataGridViewTextBoxColumn13.DataPropertyName = "SizeB";
			this.dataGridViewTextBoxColumn13.HeaderText = "Размер B";
			this.dataGridViewTextBoxColumn13.Name = "dataGridViewTextBoxColumn13";
			// 
			// dataGridViewTextBoxColumn1
			// 
			this.dataGridViewTextBoxColumn1.DataPropertyName = "Amount";
			this.dataGridViewTextBoxColumn1.HeaderText = "Кол-во";
			this.dataGridViewTextBoxColumn1.Name = "dataGridViewTextBoxColumn1";
			// 
			// dataGridViewTextBoxColumn2
			// 
			this.dataGridViewTextBoxColumn2.DataPropertyName = "MaterialID";
			this.dataGridViewTextBoxColumn2.DataSource = this.materialsBindingSource;
			this.dataGridViewTextBoxColumn2.DisplayMember = "Name";
			this.dataGridViewTextBoxColumn2.HeaderText = "Материал";
			this.dataGridViewTextBoxColumn2.Name = "dataGridViewTextBoxColumn2";
			this.dataGridViewTextBoxColumn2.Resizable = System.Windows.Forms.DataGridViewTriState.True;
			this.dataGridViewTextBoxColumn2.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.Automatic;
			this.dataGridViewTextBoxColumn2.ValueMember = "MaterialID";
			// 
			// dataGridViewTextBoxColumn15
			// 
			this.dataGridViewTextBoxColumn15.DataPropertyName = "Edges";
			this.dataGridViewTextBoxColumn15.HeaderText = "Торцовка";
			this.dataGridViewTextBoxColumn15.Name = "dataGridViewTextBoxColumn15";
			// 
			// DetailsListForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(778, 468);
			this.Controls.Add(this.detailDataGridView);
			this.Controls.Add(this.descriptionTextBox);
			this.Controls.Add(this.orderIDTextBox);
			this.Controls.Add(remarksLabel);
			this.Controls.Add(orderIDLabel);
			this.Name = "DetailsListForm";
			this.Text = "Список деталей";
			this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.DetailsListForm_FormClosing);
			this.Load += new System.EventHandler(this.DetailsListForm_Load);
			((System.ComponentModel.ISupportInitialize)(this.dataSet)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.materialsBindingSource)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.detailsListBindingSource)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.detailBindingSource)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.detailDataGridView)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private DataSet dataSet;
		private System.Windows.Forms.BindingSource materialsBindingSource;
		private Denisenko.Cutting.CutOptima.DataSetTableAdapters.MaterialsTableAdapter materialsTableAdapter;
		private System.Windows.Forms.BindingSource detailsListBindingSource;
		private System.Windows.Forms.TextBox orderIDTextBox;
		private System.Windows.Forms.TextBox descriptionTextBox;
		private System.Windows.Forms.BindingSource detailBindingSource;
		private System.Windows.Forms.DataGridView detailDataGridView;
		private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn12;
		private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn14;
		private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn13;
		private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn1;
		private System.Windows.Forms.DataGridViewComboBoxColumn dataGridViewTextBoxColumn2;
		private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn15;
	}
}