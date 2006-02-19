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
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(DetailsListForm));
			System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle1 = new System.Windows.Forms.DataGridViewCellStyle();
			System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle2 = new System.Windows.Forms.DataGridViewCellStyle();
			System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle3 = new System.Windows.Forms.DataGridViewCellStyle();
			this.detailsListsBindingNavigator = new System.Windows.Forms.BindingNavigator(this.components);
			this.bindingNavigatorAddNewItem = new System.Windows.Forms.ToolStripButton();
			this.bindingNavigatorDeleteItem = new System.Windows.Forms.ToolStripButton();
			this.detailsListsBindingNavigatorSaveItem = new System.Windows.Forms.ToolStripButton();
			this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
			this.optimizeButton = new System.Windows.Forms.ToolStripButton();
			this.orderIDTextBox = new System.Windows.Forms.TextBox();
			this.remarksTextBox = new System.Windows.Forms.TextBox();
			this.detailsListsDetailsDataGridView = new System.Windows.Forms.DataGridView();
			this.materialsBindingSource = new System.Windows.Forms.BindingSource(this.components);
			this.dataSet = new Denisenko.Cutting.CutOptima.DataSet();
			this.detailsListsBindingSource = new System.Windows.Forms.BindingSource(this.components);
			this.detailsListsTableAdapter = new Denisenko.Cutting.CutOptima.DataSetTableAdapters.DetailsListsTableAdapter();
			this.detailsListsDetailsTableAdapter = new Denisenko.Cutting.CutOptima.DataSetTableAdapters.DetailsListsDetailsTableAdapter();
			this.materialsTableAdapter = new Denisenko.Cutting.CutOptima.DataSetTableAdapters.MaterialsTableAdapter();
			this.dataGridViewTextBoxColumn3 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.dataGridViewTextBoxColumn4 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.dataGridViewTextBoxColumn5 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.dataGridViewTextBoxColumn6 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.dataGridViewTextBoxColumn7 = new System.Windows.Forms.DataGridViewComboBoxColumn();
			this.dataGridViewTextBoxColumn8 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.dataGridViewTextBoxColumn9 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.dataGridViewTextBoxColumn10 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.dataGridViewTextBoxColumn11 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.detailsListsDetailsBindingSource = new System.Windows.Forms.BindingSource(this.components);
			orderIDLabel = new System.Windows.Forms.Label();
			remarksLabel = new System.Windows.Forms.Label();
			((System.ComponentModel.ISupportInitialize)(this.detailsListsBindingNavigator)).BeginInit();
			this.detailsListsBindingNavigator.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.detailsListsDetailsDataGridView)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.materialsBindingSource)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.dataSet)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.detailsListsBindingSource)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.detailsListsDetailsBindingSource)).BeginInit();
			this.SuspendLayout();
			// 
			// orderIDLabel
			// 
			orderIDLabel.AutoSize = true;
			orderIDLabel.Location = new System.Drawing.Point(12, 31);
			orderIDLabel.Name = "orderIDLabel";
			orderIDLabel.Size = new System.Drawing.Size(83, 13);
			orderIDLabel.TabIndex = 1;
			orderIDLabel.Text = "Номер заказа:";
			// 
			// remarksLabel
			// 
			remarksLabel.AutoSize = true;
			remarksLabel.Location = new System.Drawing.Point(12, 57);
			remarksLabel.Name = "remarksLabel";
			remarksLabel.Size = new System.Drawing.Size(90, 13);
			remarksLabel.TabIndex = 3;
			remarksLabel.Text = "Дополнительно:";
			// 
			// detailsListsBindingNavigator
			// 
			this.detailsListsBindingNavigator.AddNewItem = this.bindingNavigatorAddNewItem;
			this.detailsListsBindingNavigator.BindingSource = this.detailsListsBindingSource;
			this.detailsListsBindingNavigator.CountItem = null;
			this.detailsListsBindingNavigator.DeleteItem = this.bindingNavigatorDeleteItem;
			this.detailsListsBindingNavigator.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.bindingNavigatorAddNewItem,
            this.bindingNavigatorDeleteItem,
            this.detailsListsBindingNavigatorSaveItem,
            this.toolStripSeparator1,
            this.optimizeButton});
			this.detailsListsBindingNavigator.Location = new System.Drawing.Point(0, 0);
			this.detailsListsBindingNavigator.MoveFirstItem = null;
			this.detailsListsBindingNavigator.MoveLastItem = null;
			this.detailsListsBindingNavigator.MoveNextItem = null;
			this.detailsListsBindingNavigator.MovePreviousItem = null;
			this.detailsListsBindingNavigator.Name = "detailsListsBindingNavigator";
			this.detailsListsBindingNavigator.PositionItem = null;
			this.detailsListsBindingNavigator.Size = new System.Drawing.Size(754, 25);
			this.detailsListsBindingNavigator.TabIndex = 0;
			this.detailsListsBindingNavigator.Text = "bindingNavigator1";
			// 
			// bindingNavigatorAddNewItem
			// 
			this.bindingNavigatorAddNewItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
			this.bindingNavigatorAddNewItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorAddNewItem.Image")));
			this.bindingNavigatorAddNewItem.Name = "bindingNavigatorAddNewItem";
			this.bindingNavigatorAddNewItem.RightToLeftAutoMirrorImage = true;
			this.bindingNavigatorAddNewItem.Size = new System.Drawing.Size(23, 22);
			this.bindingNavigatorAddNewItem.Text = "Add new";
			// 
			// bindingNavigatorDeleteItem
			// 
			this.bindingNavigatorDeleteItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
			this.bindingNavigatorDeleteItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorDeleteItem.Image")));
			this.bindingNavigatorDeleteItem.Name = "bindingNavigatorDeleteItem";
			this.bindingNavigatorDeleteItem.RightToLeftAutoMirrorImage = true;
			this.bindingNavigatorDeleteItem.Size = new System.Drawing.Size(23, 22);
			this.bindingNavigatorDeleteItem.Text = "Delete";
			// 
			// detailsListsBindingNavigatorSaveItem
			// 
			this.detailsListsBindingNavigatorSaveItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
			this.detailsListsBindingNavigatorSaveItem.Image = ((System.Drawing.Image)(resources.GetObject("detailsListsBindingNavigatorSaveItem.Image")));
			this.detailsListsBindingNavigatorSaveItem.Name = "detailsListsBindingNavigatorSaveItem";
			this.detailsListsBindingNavigatorSaveItem.Size = new System.Drawing.Size(23, 22);
			this.detailsListsBindingNavigatorSaveItem.Text = "Save Data";
			this.detailsListsBindingNavigatorSaveItem.Click += new System.EventHandler(this.detailsListsBindingNavigatorSaveItem_Click);
			// 
			// toolStripSeparator1
			// 
			this.toolStripSeparator1.Name = "toolStripSeparator1";
			this.toolStripSeparator1.Size = new System.Drawing.Size(6, 25);
			// 
			// optimizeButton
			// 
			this.optimizeButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
			this.optimizeButton.Image = ((System.Drawing.Image)(resources.GetObject("optimizeButton.Image")));
			this.optimizeButton.ImageTransparentColor = System.Drawing.Color.Magenta;
			this.optimizeButton.Name = "optimizeButton";
			this.optimizeButton.Size = new System.Drawing.Size(23, 22);
			this.optimizeButton.Text = "toolStripButton1";
			this.optimizeButton.Click += new System.EventHandler(this.optimizeButton_Click);
			// 
			// orderIDTextBox
			// 
			this.orderIDTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.detailsListsBindingSource, "OrderID", true));
			this.orderIDTextBox.Location = new System.Drawing.Point(108, 28);
			this.orderIDTextBox.Name = "orderIDTextBox";
			this.orderIDTextBox.Size = new System.Drawing.Size(100, 20);
			this.orderIDTextBox.TabIndex = 2;
			// 
			// remarksTextBox
			// 
			this.remarksTextBox.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
						| System.Windows.Forms.AnchorStyles.Right)));
			this.remarksTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.detailsListsBindingSource, "Remarks", true));
			this.remarksTextBox.Location = new System.Drawing.Point(108, 54);
			this.remarksTextBox.Multiline = true;
			this.remarksTextBox.Name = "remarksTextBox";
			this.remarksTextBox.Size = new System.Drawing.Size(634, 66);
			this.remarksTextBox.TabIndex = 4;
			// 
			// detailsListsDetailsDataGridView
			// 
			this.detailsListsDetailsDataGridView.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
						| System.Windows.Forms.AnchorStyles.Left)
						| System.Windows.Forms.AnchorStyles.Right)));
			this.detailsListsDetailsDataGridView.AutoGenerateColumns = false;
			dataGridViewCellStyle1.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
			dataGridViewCellStyle1.BackColor = System.Drawing.SystemColors.Control;
			dataGridViewCellStyle1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			dataGridViewCellStyle1.ForeColor = System.Drawing.SystemColors.WindowText;
			dataGridViewCellStyle1.SelectionBackColor = System.Drawing.SystemColors.Highlight;
			dataGridViewCellStyle1.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
			dataGridViewCellStyle1.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
			this.detailsListsDetailsDataGridView.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this.detailsListsDetailsDataGridView.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dataGridViewTextBoxColumn3,
            this.dataGridViewTextBoxColumn4,
            this.dataGridViewTextBoxColumn5,
            this.dataGridViewTextBoxColumn6,
            this.dataGridViewTextBoxColumn7,
            this.dataGridViewTextBoxColumn8,
            this.dataGridViewTextBoxColumn9,
            this.dataGridViewTextBoxColumn10,
            this.dataGridViewTextBoxColumn11});
			this.detailsListsDetailsDataGridView.DataSource = this.detailsListsDetailsBindingSource;
			dataGridViewCellStyle2.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
			dataGridViewCellStyle2.BackColor = System.Drawing.SystemColors.Window;
			dataGridViewCellStyle2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			dataGridViewCellStyle2.ForeColor = System.Drawing.SystemColors.ControlText;
			dataGridViewCellStyle2.SelectionBackColor = System.Drawing.SystemColors.Highlight;
			dataGridViewCellStyle2.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
			dataGridViewCellStyle2.WrapMode = System.Windows.Forms.DataGridViewTriState.False;
			this.detailsListsDetailsDataGridView.DefaultCellStyle = dataGridViewCellStyle2;
			this.detailsListsDetailsDataGridView.Location = new System.Drawing.Point(12, 126);
			this.detailsListsDetailsDataGridView.Name = "detailsListsDetailsDataGridView";
			dataGridViewCellStyle3.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
			dataGridViewCellStyle3.BackColor = System.Drawing.SystemColors.Control;
			dataGridViewCellStyle3.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			dataGridViewCellStyle3.ForeColor = System.Drawing.SystemColors.WindowText;
			dataGridViewCellStyle3.SelectionBackColor = System.Drawing.SystemColors.Highlight;
			dataGridViewCellStyle3.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
			dataGridViewCellStyle3.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
			this.detailsListsDetailsDataGridView.RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this.detailsListsDetailsDataGridView.Size = new System.Drawing.Size(730, 248);
			this.detailsListsDetailsDataGridView.TabIndex = 5;
			this.detailsListsDetailsDataGridView.CellEndEdit += new System.Windows.Forms.DataGridViewCellEventHandler(this.detailsListsDetailsDataGridView_CellEndEdit);
			// 
			// materialsBindingSource
			// 
			this.materialsBindingSource.DataMember = "Materials";
			this.materialsBindingSource.DataSource = this.dataSet;
			// 
			// dataSet
			// 
			this.dataSet.DataSetName = "DataSet";
			this.dataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
			// 
			// detailsListsBindingSource
			// 
			this.detailsListsBindingSource.DataMember = "DetailsLists";
			this.detailsListsBindingSource.DataSource = this.dataSet;
			// 
			// detailsListsTableAdapter
			// 
			this.detailsListsTableAdapter.ClearBeforeFill = true;
			// 
			// detailsListsDetailsTableAdapter
			// 
			this.detailsListsDetailsTableAdapter.ClearBeforeFill = true;
			// 
			// materialsTableAdapter
			// 
			this.materialsTableAdapter.ClearBeforeFill = true;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this.dataGridViewTextBoxColumn3.DataPropertyName = "Name";
			this.dataGridViewTextBoxColumn3.HeaderText = "Название";
			this.dataGridViewTextBoxColumn3.Name = "dataGridViewTextBoxColumn3";
			// 
			// dataGridViewTextBoxColumn4
			// 
			this.dataGridViewTextBoxColumn4.DataPropertyName = "Length";
			this.dataGridViewTextBoxColumn4.HeaderText = "Длина";
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
			this.dataGridViewTextBoxColumn6.DataPropertyName = "Amount";
			this.dataGridViewTextBoxColumn6.HeaderText = "Кол-во";
			this.dataGridViewTextBoxColumn6.Name = "dataGridViewTextBoxColumn6";
			// 
			// dataGridViewTextBoxColumn7
			// 
			this.dataGridViewTextBoxColumn7.DataPropertyName = "MaterialID";
			this.dataGridViewTextBoxColumn7.DataSource = this.materialsBindingSource;
			this.dataGridViewTextBoxColumn7.DisplayMember = "Name";
			this.dataGridViewTextBoxColumn7.HeaderText = "Материал";
			this.dataGridViewTextBoxColumn7.Name = "dataGridViewTextBoxColumn7";
			this.dataGridViewTextBoxColumn7.Resizable = System.Windows.Forms.DataGridViewTriState.True;
			this.dataGridViewTextBoxColumn7.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.Automatic;
			this.dataGridViewTextBoxColumn7.ValueMember = "MaterialID";
			// 
			// dataGridViewTextBoxColumn8
			// 
			this.dataGridViewTextBoxColumn8.DataPropertyName = "LeftEdge";
			this.dataGridViewTextBoxColumn8.HeaderText = "Л";
			this.dataGridViewTextBoxColumn8.Name = "dataGridViewTextBoxColumn8";
			this.dataGridViewTextBoxColumn8.Width = 30;
			// 
			// dataGridViewTextBoxColumn9
			// 
			this.dataGridViewTextBoxColumn9.DataPropertyName = "TopEdge";
			this.dataGridViewTextBoxColumn9.HeaderText = "В";
			this.dataGridViewTextBoxColumn9.Name = "dataGridViewTextBoxColumn9";
			this.dataGridViewTextBoxColumn9.Width = 30;
			// 
			// dataGridViewTextBoxColumn10
			// 
			this.dataGridViewTextBoxColumn10.DataPropertyName = "RightEdge";
			this.dataGridViewTextBoxColumn10.HeaderText = "П";
			this.dataGridViewTextBoxColumn10.Name = "dataGridViewTextBoxColumn10";
			this.dataGridViewTextBoxColumn10.Width = 30;
			// 
			// dataGridViewTextBoxColumn11
			// 
			this.dataGridViewTextBoxColumn11.DataPropertyName = "BottomEdge";
			this.dataGridViewTextBoxColumn11.HeaderText = "Н";
			this.dataGridViewTextBoxColumn11.Name = "dataGridViewTextBoxColumn11";
			this.dataGridViewTextBoxColumn11.Width = 30;
			// 
			// detailsListsDetailsBindingSource
			// 
			this.detailsListsDetailsBindingSource.DataMember = "FK_DetailsListsDetails_DetailsLists";
			this.detailsListsDetailsBindingSource.DataSource = this.detailsListsBindingSource;
			// 
			// DetailsListForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(754, 386);
			this.Controls.Add(this.detailsListsDetailsDataGridView);
			this.Controls.Add(remarksLabel);
			this.Controls.Add(this.remarksTextBox);
			this.Controls.Add(orderIDLabel);
			this.Controls.Add(this.orderIDTextBox);
			this.Controls.Add(this.detailsListsBindingNavigator);
			this.Name = "DetailsListForm";
			this.Text = "Список деталей";
			this.Load += new System.EventHandler(this.DetailsListForm_Load);
			((System.ComponentModel.ISupportInitialize)(this.detailsListsBindingNavigator)).EndInit();
			this.detailsListsBindingNavigator.ResumeLayout(false);
			this.detailsListsBindingNavigator.PerformLayout();
			((System.ComponentModel.ISupportInitialize)(this.detailsListsDetailsDataGridView)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.materialsBindingSource)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.dataSet)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.detailsListsBindingSource)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.detailsListsDetailsBindingSource)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private DataSet dataSet;
		private System.Windows.Forms.BindingSource detailsListsBindingSource;
		private Denisenko.Cutting.CutOptima.DataSetTableAdapters.DetailsListsTableAdapter detailsListsTableAdapter;
		private System.Windows.Forms.BindingNavigator detailsListsBindingNavigator;
		private System.Windows.Forms.ToolStripButton bindingNavigatorAddNewItem;
		private System.Windows.Forms.ToolStripButton bindingNavigatorDeleteItem;
		private System.Windows.Forms.ToolStripButton detailsListsBindingNavigatorSaveItem;
		private System.Windows.Forms.TextBox orderIDTextBox;
		private System.Windows.Forms.TextBox remarksTextBox;
		private System.Windows.Forms.BindingSource detailsListsDetailsBindingSource;
		private Denisenko.Cutting.CutOptima.DataSetTableAdapters.DetailsListsDetailsTableAdapter detailsListsDetailsTableAdapter;
		private System.Windows.Forms.DataGridView detailsListsDetailsDataGridView;
		private System.Windows.Forms.BindingSource materialsBindingSource;
		private Denisenko.Cutting.CutOptima.DataSetTableAdapters.MaterialsTableAdapter materialsTableAdapter;
		private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn3;
		private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn4;
		private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn5;
		private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn6;
		private System.Windows.Forms.DataGridViewComboBoxColumn dataGridViewTextBoxColumn7;
		private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn8;
		private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn9;
		private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn10;
		private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn11;
		private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
		private System.Windows.Forms.ToolStripButton optimizeButton;
	}
}