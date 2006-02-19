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
			System.Windows.Forms.Label remarksLabel;
			System.Windows.Forms.Label orderIDLabel;
			this.dataSet = new Denisenko.Cutting.CutOptima.DataSet();
			this.bindingSource = new System.Windows.Forms.BindingSource(this.components);
			this.detailsListsTableAdapter = new Denisenko.Cutting.CutOptima.DataSetTableAdapters.DetailsListsTableAdapter();
			this.remarksTextBox = new System.Windows.Forms.TextBox();
			this.orderIDComboBox = new System.Windows.Forms.ComboBox();
			this.detailsListsContentsBindingSource = new System.Windows.Forms.BindingSource(this.components);
			this.detailsListsContentsTableAdapter = new Denisenko.Cutting.CutOptima.DataSetTableAdapters.DetailsListsContentsTableAdapter();
			this.detailsListsContentsDataGridView = new System.Windows.Forms.DataGridView();
			this.dataGridViewTextBoxColumn3 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.dataGridViewTextBoxColumn4 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.dataGridViewTextBoxColumn5 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.dataGridViewTextBoxColumn6 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.dataGridViewTextBoxColumn7 = new System.Windows.Forms.DataGridViewComboBoxColumn();
			this.dataGridViewTextBoxColumn8 = new System.Windows.Forms.DataGridViewComboBoxColumn();
			this.dataGridViewTextBoxColumn9 = new System.Windows.Forms.DataGridViewComboBoxColumn();
			this.dataGridViewTextBoxColumn10 = new System.Windows.Forms.DataGridViewComboBoxColumn();
			this.dataGridViewTextBoxColumn11 = new System.Windows.Forms.DataGridViewComboBoxColumn();
			remarksLabel = new System.Windows.Forms.Label();
			orderIDLabel = new System.Windows.Forms.Label();
			((System.ComponentModel.ISupportInitialize)(this.dataSet)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.bindingSource)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.detailsListsContentsBindingSource)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.detailsListsContentsDataGridView)).BeginInit();
			this.SuspendLayout();
			// 
			// remarksLabel
			// 
			remarksLabel.AutoSize = true;
			remarksLabel.Location = new System.Drawing.Point(12, 15);
			remarksLabel.Name = "remarksLabel";
			remarksLabel.Size = new System.Drawing.Size(80, 13);
			remarksLabel.TabIndex = 0;
			remarksLabel.Text = "Комментарий:";
			// 
			// orderIDLabel
			// 
			orderIDLabel.AutoSize = true;
			orderIDLabel.Location = new System.Drawing.Point(14, 41);
			orderIDLabel.Name = "orderIDLabel";
			orderIDLabel.Size = new System.Drawing.Size(41, 13);
			orderIDLabel.TabIndex = 2;
			orderIDLabel.Text = "Заказ:";
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
			// remarksTextBox
			// 
			this.remarksTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.bindingSource, "Remarks", true));
			this.remarksTextBox.Location = new System.Drawing.Point(98, 12);
			this.remarksTextBox.Name = "remarksTextBox";
			this.remarksTextBox.Size = new System.Drawing.Size(350, 20);
			this.remarksTextBox.TabIndex = 1;
			// 
			// orderIDComboBox
			// 
			this.orderIDComboBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.bindingSource, "OrderID", true));
			this.orderIDComboBox.FormattingEnabled = true;
			this.orderIDComboBox.Location = new System.Drawing.Point(98, 38);
			this.orderIDComboBox.Name = "orderIDComboBox";
			this.orderIDComboBox.Size = new System.Drawing.Size(137, 21);
			this.orderIDComboBox.TabIndex = 3;
			// 
			// detailsListsContentsBindingSource
			// 
			this.detailsListsContentsBindingSource.DataMember = "DetailsListsContents";
			this.detailsListsContentsBindingSource.DataSource = this.dataSet;
			// 
			// detailsListsContentsTableAdapter
			// 
			this.detailsListsContentsTableAdapter.ClearBeforeFill = true;
			// 
			// detailsListsContentsDataGridView
			// 
			this.detailsListsContentsDataGridView.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
						| System.Windows.Forms.AnchorStyles.Left)
						| System.Windows.Forms.AnchorStyles.Right)));
			this.detailsListsContentsDataGridView.AutoGenerateColumns = false;
			this.detailsListsContentsDataGridView.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dataGridViewTextBoxColumn3,
            this.dataGridViewTextBoxColumn4,
            this.dataGridViewTextBoxColumn5,
            this.dataGridViewTextBoxColumn6,
            this.dataGridViewTextBoxColumn7,
            this.dataGridViewTextBoxColumn8,
            this.dataGridViewTextBoxColumn9,
            this.dataGridViewTextBoxColumn10,
            this.dataGridViewTextBoxColumn11});
			this.detailsListsContentsDataGridView.DataSource = this.detailsListsContentsBindingSource;
			this.detailsListsContentsDataGridView.Location = new System.Drawing.Point(12, 71);
			this.detailsListsContentsDataGridView.Name = "detailsListsContentsDataGridView";
			this.detailsListsContentsDataGridView.Size = new System.Drawing.Size(549, 311);
			this.detailsListsContentsDataGridView.TabIndex = 4;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this.dataGridViewTextBoxColumn3.DataPropertyName = "Name";
			this.dataGridViewTextBoxColumn3.HeaderText = "Название";
			this.dataGridViewTextBoxColumn3.Name = "dataGridViewTextBoxColumn3";
			// 
			// dataGridViewTextBoxColumn4
			// 
			this.dataGridViewTextBoxColumn4.DataPropertyName = "Height";
			this.dataGridViewTextBoxColumn4.HeaderText = "Высота";
			this.dataGridViewTextBoxColumn4.Name = "dataGridViewTextBoxColumn4";
			// 
			// dataGridViewTextBoxColumn5
			// 
			this.dataGridViewTextBoxColumn5.DataPropertyName = "Width";
			this.dataGridViewTextBoxColumn5.HeaderText = "Ширина";
			this.dataGridViewTextBoxColumn5.Name = "dataGridViewTextBoxColumn5";
			// 
			// dataGridViewTextBoxColumn6
			// 
			this.dataGridViewTextBoxColumn6.DataPropertyName = "Quantity";
			this.dataGridViewTextBoxColumn6.HeaderText = "Кол-во";
			this.dataGridViewTextBoxColumn6.Name = "dataGridViewTextBoxColumn6";
			// 
			// dataGridViewTextBoxColumn7
			// 
			this.dataGridViewTextBoxColumn7.DataPropertyName = "MaterialID";
			this.dataGridViewTextBoxColumn7.HeaderText = "Материал";
			this.dataGridViewTextBoxColumn7.Name = "dataGridViewTextBoxColumn7";
			this.dataGridViewTextBoxColumn7.Resizable = System.Windows.Forms.DataGridViewTriState.True;
			this.dataGridViewTextBoxColumn7.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.Automatic;
			// 
			// dataGridViewTextBoxColumn8
			// 
			this.dataGridViewTextBoxColumn8.DataPropertyName = "LeftEdgeID";
			this.dataGridViewTextBoxColumn8.HeaderText = "Л";
			this.dataGridViewTextBoxColumn8.Name = "dataGridViewTextBoxColumn8";
			this.dataGridViewTextBoxColumn8.Resizable = System.Windows.Forms.DataGridViewTriState.True;
			this.dataGridViewTextBoxColumn8.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.Automatic;
			// 
			// dataGridViewTextBoxColumn9
			// 
			this.dataGridViewTextBoxColumn9.DataPropertyName = "RightEdgeID";
			this.dataGridViewTextBoxColumn9.HeaderText = "П";
			this.dataGridViewTextBoxColumn9.Name = "dataGridViewTextBoxColumn9";
			this.dataGridViewTextBoxColumn9.Resizable = System.Windows.Forms.DataGridViewTriState.True;
			this.dataGridViewTextBoxColumn9.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.Automatic;
			// 
			// dataGridViewTextBoxColumn10
			// 
			this.dataGridViewTextBoxColumn10.DataPropertyName = "TopEdgeID";
			this.dataGridViewTextBoxColumn10.HeaderText = "В";
			this.dataGridViewTextBoxColumn10.Name = "dataGridViewTextBoxColumn10";
			this.dataGridViewTextBoxColumn10.Resizable = System.Windows.Forms.DataGridViewTriState.True;
			this.dataGridViewTextBoxColumn10.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.Automatic;
			// 
			// dataGridViewTextBoxColumn11
			// 
			this.dataGridViewTextBoxColumn11.DataPropertyName = "BottomEdgeID";
			this.dataGridViewTextBoxColumn11.HeaderText = "Н";
			this.dataGridViewTextBoxColumn11.Name = "dataGridViewTextBoxColumn11";
			this.dataGridViewTextBoxColumn11.Resizable = System.Windows.Forms.DataGridViewTriState.True;
			this.dataGridViewTextBoxColumn11.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.Automatic;
			// 
			// DetailsListForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(573, 394);
			this.Controls.Add(this.detailsListsContentsDataGridView);
			this.Controls.Add(orderIDLabel);
			this.Controls.Add(this.orderIDComboBox);
			this.Controls.Add(remarksLabel);
			this.Controls.Add(this.remarksTextBox);
			this.Name = "DetailsListForm";
			this.Text = "Список деталей";
			this.Load += new System.EventHandler(this.DetailsListForm_Load);
			((System.ComponentModel.ISupportInitialize)(this.dataSet)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.bindingSource)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.detailsListsContentsBindingSource)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.detailsListsContentsDataGridView)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private DataSet dataSet;
		private System.Windows.Forms.BindingSource bindingSource;
		private Denisenko.Cutting.CutOptima.DataSetTableAdapters.DetailsListsTableAdapter detailsListsTableAdapter;
		private System.Windows.Forms.TextBox remarksTextBox;
		private System.Windows.Forms.ComboBox orderIDComboBox;
		private System.Windows.Forms.BindingSource detailsListsContentsBindingSource;
		private Denisenko.Cutting.CutOptima.DataSetTableAdapters.DetailsListsContentsTableAdapter detailsListsContentsTableAdapter;
		private System.Windows.Forms.DataGridView detailsListsContentsDataGridView;
		private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn3;
		private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn4;
		private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn5;
		private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn6;
		private System.Windows.Forms.DataGridViewComboBoxColumn dataGridViewTextBoxColumn7;
		private System.Windows.Forms.DataGridViewComboBoxColumn dataGridViewTextBoxColumn8;
		private System.Windows.Forms.DataGridViewComboBoxColumn dataGridViewTextBoxColumn9;
		private System.Windows.Forms.DataGridViewComboBoxColumn dataGridViewTextBoxColumn10;
		private System.Windows.Forms.DataGridViewComboBoxColumn dataGridViewTextBoxColumn11;
	}
}