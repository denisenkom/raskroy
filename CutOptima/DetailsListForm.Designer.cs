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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(DetailsListForm));
            System.Windows.Forms.Label remarksLabel;
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle4 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle5 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle6 = new System.Windows.Forms.DataGridViewCellStyle();
            this.detailsListsBindingNavigator = new System.Windows.Forms.BindingNavigator(this.components);
            this.bindingNavigatorAddNewItem = new System.Windows.Forms.ToolStripButton();
            this.detailsListsBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.dataSet = new Denisenko.Cutting.CutOptima.DataSet();
            this.bindingNavigatorDeleteItem = new System.Windows.Forms.ToolStripButton();
            this.detailsListsBindingNavigatorSaveItem = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.optimizeButton = new System.Windows.Forms.ToolStripButton();
            this.orderIDTextBox = new System.Windows.Forms.TextBox();
            this.remarksTextBox = new System.Windows.Forms.TextBox();
            this.detailsListsDetailsDataGridView = new System.Windows.Forms.DataGridView();
            this.materialsBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.detailsListsDetailsBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.detailsListsTableAdapter = new Denisenko.Cutting.CutOptima.DataSetTableAdapters.DetailsListsTableAdapter();
            this.detailsListsDetailsTableAdapter = new Denisenko.Cutting.CutOptima.DataSetTableAdapters.DetailsListsDetailsTableAdapter();
            this.materialsTableAdapter = new Denisenko.Cutting.CutOptima.DataSetTableAdapters.MaterialsTableAdapter();
            this.dataGridViewTextBoxColumn3 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn4 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn5 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn6 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn7 = new System.Windows.Forms.DataGridViewComboBoxColumn();
            this.dataGridViewTextBoxColumn8 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.TopEdge = new System.Windows.Forms.DataGridViewTextBoxColumn();
            orderIDLabel = new System.Windows.Forms.Label();
            remarksLabel = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.detailsListsBindingNavigator)).BeginInit();
            this.detailsListsBindingNavigator.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.detailsListsBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.detailsListsDetailsDataGridView)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.materialsBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.detailsListsDetailsBindingSource)).BeginInit();
            this.SuspendLayout();
            // 
            // orderIDLabel
            // 
            orderIDLabel.AccessibleDescription = null;
            orderIDLabel.AccessibleName = null;
            resources.ApplyResources(orderIDLabel, "orderIDLabel");
            orderIDLabel.Font = null;
            orderIDLabel.Name = "orderIDLabel";
            // 
            // remarksLabel
            // 
            remarksLabel.AccessibleDescription = null;
            remarksLabel.AccessibleName = null;
            resources.ApplyResources(remarksLabel, "remarksLabel");
            remarksLabel.Font = null;
            remarksLabel.Name = "remarksLabel";
            // 
            // detailsListsBindingNavigator
            // 
            this.detailsListsBindingNavigator.AccessibleDescription = null;
            this.detailsListsBindingNavigator.AccessibleName = null;
            this.detailsListsBindingNavigator.AddNewItem = this.bindingNavigatorAddNewItem;
            resources.ApplyResources(this.detailsListsBindingNavigator, "detailsListsBindingNavigator");
            this.detailsListsBindingNavigator.BackgroundImage = null;
            this.detailsListsBindingNavigator.BindingSource = this.detailsListsBindingSource;
            this.detailsListsBindingNavigator.CountItem = null;
            this.detailsListsBindingNavigator.DeleteItem = this.bindingNavigatorDeleteItem;
            this.detailsListsBindingNavigator.Font = null;
            this.detailsListsBindingNavigator.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.bindingNavigatorAddNewItem,
            this.bindingNavigatorDeleteItem,
            this.detailsListsBindingNavigatorSaveItem,
            this.toolStripSeparator1,
            this.optimizeButton});
            this.detailsListsBindingNavigator.MoveFirstItem = null;
            this.detailsListsBindingNavigator.MoveLastItem = null;
            this.detailsListsBindingNavigator.MoveNextItem = null;
            this.detailsListsBindingNavigator.MovePreviousItem = null;
            this.detailsListsBindingNavigator.Name = "detailsListsBindingNavigator";
            this.detailsListsBindingNavigator.PositionItem = null;
            // 
            // bindingNavigatorAddNewItem
            // 
            this.bindingNavigatorAddNewItem.AccessibleDescription = null;
            this.bindingNavigatorAddNewItem.AccessibleName = null;
            resources.ApplyResources(this.bindingNavigatorAddNewItem, "bindingNavigatorAddNewItem");
            this.bindingNavigatorAddNewItem.BackgroundImage = null;
            this.bindingNavigatorAddNewItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorAddNewItem.Name = "bindingNavigatorAddNewItem";
            // 
            // detailsListsBindingSource
            // 
            this.detailsListsBindingSource.DataMember = "DetailsLists";
            this.detailsListsBindingSource.DataSource = this.dataSet;
            // 
            // dataSet
            // 
            this.dataSet.DataSetName = "DataSet";
            this.dataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // bindingNavigatorDeleteItem
            // 
            this.bindingNavigatorDeleteItem.AccessibleDescription = null;
            this.bindingNavigatorDeleteItem.AccessibleName = null;
            resources.ApplyResources(this.bindingNavigatorDeleteItem, "bindingNavigatorDeleteItem");
            this.bindingNavigatorDeleteItem.BackgroundImage = null;
            this.bindingNavigatorDeleteItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorDeleteItem.Name = "bindingNavigatorDeleteItem";
            // 
            // detailsListsBindingNavigatorSaveItem
            // 
            this.detailsListsBindingNavigatorSaveItem.AccessibleDescription = null;
            this.detailsListsBindingNavigatorSaveItem.AccessibleName = null;
            resources.ApplyResources(this.detailsListsBindingNavigatorSaveItem, "detailsListsBindingNavigatorSaveItem");
            this.detailsListsBindingNavigatorSaveItem.BackgroundImage = null;
            this.detailsListsBindingNavigatorSaveItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.detailsListsBindingNavigatorSaveItem.Name = "detailsListsBindingNavigatorSaveItem";
            this.detailsListsBindingNavigatorSaveItem.Click += new System.EventHandler(this.detailsListsBindingNavigatorSaveItem_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.AccessibleDescription = null;
            this.toolStripSeparator1.AccessibleName = null;
            resources.ApplyResources(this.toolStripSeparator1, "toolStripSeparator1");
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            // 
            // optimizeButton
            // 
            this.optimizeButton.AccessibleDescription = null;
            this.optimizeButton.AccessibleName = null;
            resources.ApplyResources(this.optimizeButton, "optimizeButton");
            this.optimizeButton.BackgroundImage = null;
            this.optimizeButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.optimizeButton.Name = "optimizeButton";
            this.optimizeButton.Click += new System.EventHandler(this.optimizeButton_Click);
            // 
            // orderIDTextBox
            // 
            this.orderIDTextBox.AccessibleDescription = null;
            this.orderIDTextBox.AccessibleName = null;
            resources.ApplyResources(this.orderIDTextBox, "orderIDTextBox");
            this.orderIDTextBox.BackgroundImage = null;
            this.orderIDTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.detailsListsBindingSource, "OrderID", true));
            this.orderIDTextBox.Font = null;
            this.orderIDTextBox.Name = "orderIDTextBox";
            // 
            // remarksTextBox
            // 
            this.remarksTextBox.AccessibleDescription = null;
            this.remarksTextBox.AccessibleName = null;
            resources.ApplyResources(this.remarksTextBox, "remarksTextBox");
            this.remarksTextBox.BackgroundImage = null;
            this.remarksTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.detailsListsBindingSource, "Remarks", true));
            this.remarksTextBox.Font = null;
            this.remarksTextBox.Name = "remarksTextBox";
            // 
            // detailsListsDetailsDataGridView
            // 
            this.detailsListsDetailsDataGridView.AccessibleDescription = null;
            this.detailsListsDetailsDataGridView.AccessibleName = null;
            resources.ApplyResources(this.detailsListsDetailsDataGridView, "detailsListsDetailsDataGridView");
            this.detailsListsDetailsDataGridView.AutoGenerateColumns = false;
            this.detailsListsDetailsDataGridView.BackgroundImage = null;
            dataGridViewCellStyle4.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
            dataGridViewCellStyle4.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle4.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            dataGridViewCellStyle4.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle4.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle4.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle4.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.detailsListsDetailsDataGridView.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle4;
            this.detailsListsDetailsDataGridView.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dataGridViewTextBoxColumn3,
            this.dataGridViewTextBoxColumn4,
            this.dataGridViewTextBoxColumn5,
            this.dataGridViewTextBoxColumn6,
            this.dataGridViewTextBoxColumn7,
            this.dataGridViewTextBoxColumn8,
            this.TopEdge});
            this.detailsListsDetailsDataGridView.DataSource = this.detailsListsDetailsBindingSource;
            dataGridViewCellStyle5.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
            dataGridViewCellStyle5.BackColor = System.Drawing.SystemColors.Window;
            dataGridViewCellStyle5.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            dataGridViewCellStyle5.ForeColor = System.Drawing.SystemColors.ControlText;
            dataGridViewCellStyle5.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle5.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle5.WrapMode = System.Windows.Forms.DataGridViewTriState.False;
            this.detailsListsDetailsDataGridView.DefaultCellStyle = dataGridViewCellStyle5;
            this.detailsListsDetailsDataGridView.Font = null;
            this.detailsListsDetailsDataGridView.Name = "detailsListsDetailsDataGridView";
            dataGridViewCellStyle6.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
            dataGridViewCellStyle6.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle6.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            dataGridViewCellStyle6.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle6.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle6.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle6.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.detailsListsDetailsDataGridView.RowHeadersDefaultCellStyle = dataGridViewCellStyle6;
            this.detailsListsDetailsDataGridView.Enter += new System.EventHandler(this.detailsListsDetailsDataGridView_Enter);
            this.detailsListsDetailsDataGridView.CellEndEdit += new System.Windows.Forms.DataGridViewCellEventHandler(this.detailsListsDetailsDataGridView_CellEndEdit);
            this.detailsListsDetailsDataGridView.DataError += new System.Windows.Forms.DataGridViewDataErrorEventHandler(this.detailsListsDetailsDataGridView_DataError);
            this.detailsListsDetailsDataGridView.KeyDown += new System.Windows.Forms.KeyEventHandler(this.detailsListsDetailsDataGridView_KeyDown);
            // 
            // materialsBindingSource
            // 
            this.materialsBindingSource.DataMember = "Materials";
            this.materialsBindingSource.DataSource = this.dataSet;
            // 
            // detailsListsDetailsBindingSource
            // 
            this.detailsListsDetailsBindingSource.DataMember = "FK_DetailsListsDetails_DetailsLists";
            this.detailsListsDetailsBindingSource.DataSource = this.detailsListsBindingSource;
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
            resources.ApplyResources(this.dataGridViewTextBoxColumn3, "dataGridViewTextBoxColumn3");
            this.dataGridViewTextBoxColumn3.Name = "dataGridViewTextBoxColumn3";
            // 
            // dataGridViewTextBoxColumn4
            // 
            this.dataGridViewTextBoxColumn4.DataPropertyName = "Length";
            resources.ApplyResources(this.dataGridViewTextBoxColumn4, "dataGridViewTextBoxColumn4");
            this.dataGridViewTextBoxColumn4.Name = "dataGridViewTextBoxColumn4";
            // 
            // dataGridViewTextBoxColumn5
            // 
            this.dataGridViewTextBoxColumn5.DataPropertyName = "Width";
            resources.ApplyResources(this.dataGridViewTextBoxColumn5, "dataGridViewTextBoxColumn5");
            this.dataGridViewTextBoxColumn5.Name = "dataGridViewTextBoxColumn5";
            // 
            // dataGridViewTextBoxColumn6
            // 
            this.dataGridViewTextBoxColumn6.DataPropertyName = "Amount";
            resources.ApplyResources(this.dataGridViewTextBoxColumn6, "dataGridViewTextBoxColumn6");
            this.dataGridViewTextBoxColumn6.Name = "dataGridViewTextBoxColumn6";
            // 
            // dataGridViewTextBoxColumn7
            // 
            this.dataGridViewTextBoxColumn7.DataPropertyName = "MaterialID";
            this.dataGridViewTextBoxColumn7.DataSource = this.materialsBindingSource;
            this.dataGridViewTextBoxColumn7.DisplayMember = "Name";
            resources.ApplyResources(this.dataGridViewTextBoxColumn7, "dataGridViewTextBoxColumn7");
            this.dataGridViewTextBoxColumn7.Name = "dataGridViewTextBoxColumn7";
            this.dataGridViewTextBoxColumn7.Resizable = System.Windows.Forms.DataGridViewTriState.True;
            this.dataGridViewTextBoxColumn7.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.Automatic;
            this.dataGridViewTextBoxColumn7.ValueMember = "MaterialID";
            // 
            // dataGridViewTextBoxColumn8
            // 
            this.dataGridViewTextBoxColumn8.DataPropertyName = "LeftEdge";
            resources.ApplyResources(this.dataGridViewTextBoxColumn8, "dataGridViewTextBoxColumn8");
            this.dataGridViewTextBoxColumn8.Name = "dataGridViewTextBoxColumn8";
            // 
            // TopEdge
            // 
            this.TopEdge.DataPropertyName = "TopEdge";
            resources.ApplyResources(this.TopEdge, "TopEdge");
            this.TopEdge.Name = "TopEdge";
            // 
            // DetailsListForm
            // 
            this.AccessibleDescription = null;
            this.AccessibleName = null;
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = null;
            this.Controls.Add(this.detailsListsDetailsDataGridView);
            this.Controls.Add(remarksLabel);
            this.Controls.Add(this.remarksTextBox);
            this.Controls.Add(orderIDLabel);
            this.Controls.Add(this.orderIDTextBox);
            this.Controls.Add(this.detailsListsBindingNavigator);
            this.Font = null;
            this.Icon = null;
            this.Name = "DetailsListForm";
            this.Load += new System.EventHandler(this.DetailsListForm_Load);
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.DetailsListForm_FormClosing);
            ((System.ComponentModel.ISupportInitialize)(this.detailsListsBindingNavigator)).EndInit();
            this.detailsListsBindingNavigator.ResumeLayout(false);
            this.detailsListsBindingNavigator.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.detailsListsBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.detailsListsDetailsDataGridView)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.materialsBindingSource)).EndInit();
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
		private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripButton optimizeButton;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn3;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn4;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn5;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn6;
        private System.Windows.Forms.DataGridViewComboBoxColumn dataGridViewTextBoxColumn7;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn8;
        private System.Windows.Forms.DataGridViewTextBoxColumn TopEdge;
	}
}