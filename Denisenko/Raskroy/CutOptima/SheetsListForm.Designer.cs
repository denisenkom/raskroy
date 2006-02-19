namespace Denisenko.Cutting.CutOptima
{
	partial class SheetsListForm
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
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(SheetsListForm));
			this.dataSet = new Denisenko.Cutting.CutOptima.DataSet();
			this.sheetsBindingSource = new System.Windows.Forms.BindingSource(this.components);
			this.sheetsTableAdapter = new Denisenko.Cutting.CutOptima.DataSetTableAdapters.SheetsTableAdapter();
			this.sheetsBindingNavigator = new System.Windows.Forms.BindingNavigator(this.components);
			this.bindingNavigatorAddNewItem = new System.Windows.Forms.ToolStripButton();
			this.bindingNavigatorCountItem = new System.Windows.Forms.ToolStripLabel();
			this.bindingNavigatorDeleteItem = new System.Windows.Forms.ToolStripButton();
			this.bindingNavigatorMoveFirstItem = new System.Windows.Forms.ToolStripButton();
			this.bindingNavigatorMovePreviousItem = new System.Windows.Forms.ToolStripButton();
			this.bindingNavigatorSeparator = new System.Windows.Forms.ToolStripSeparator();
			this.bindingNavigatorPositionItem = new System.Windows.Forms.ToolStripTextBox();
			this.bindingNavigatorSeparator1 = new System.Windows.Forms.ToolStripSeparator();
			this.bindingNavigatorMoveNextItem = new System.Windows.Forms.ToolStripButton();
			this.bindingNavigatorMoveLastItem = new System.Windows.Forms.ToolStripButton();
			this.bindingNavigatorSeparator2 = new System.Windows.Forms.ToolStripSeparator();
			this.sheetsBindingNavigatorSaveItem = new System.Windows.Forms.ToolStripButton();
			this.sheetsDataGridView = new System.Windows.Forms.DataGridView();
			this.materialsBindingSource = new System.Windows.Forms.BindingSource(this.components);
			this.materialsTableAdapter = new Denisenko.Cutting.CutOptima.DataSetTableAdapters.MaterialsTableAdapter();
			this.dataGridViewTextBoxColumn2 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.dataGridViewTextBoxColumn3 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.dataGridViewTextBoxColumn4 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.dataGridViewTextBoxColumn5 = new System.Windows.Forms.DataGridViewComboBoxColumn();
			((System.ComponentModel.ISupportInitialize)(this.dataSet)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.sheetsBindingSource)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.sheetsBindingNavigator)).BeginInit();
			this.sheetsBindingNavigator.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.sheetsDataGridView)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.materialsBindingSource)).BeginInit();
			this.SuspendLayout();
			// 
			// dataSet
			// 
			this.dataSet.DataSetName = "DataSet";
			this.dataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
			// 
			// sheetsBindingSource
			// 
			this.sheetsBindingSource.DataMember = "Sheets";
			this.sheetsBindingSource.DataSource = this.dataSet;
			// 
			// sheetsTableAdapter
			// 
			this.sheetsTableAdapter.ClearBeforeFill = true;
			// 
			// sheetsBindingNavigator
			// 
			this.sheetsBindingNavigator.AddNewItem = this.bindingNavigatorAddNewItem;
			this.sheetsBindingNavigator.BindingSource = this.sheetsBindingSource;
			this.sheetsBindingNavigator.CountItem = this.bindingNavigatorCountItem;
			this.sheetsBindingNavigator.DeleteItem = this.bindingNavigatorDeleteItem;
			this.sheetsBindingNavigator.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.bindingNavigatorMoveFirstItem,
            this.bindingNavigatorMovePreviousItem,
            this.bindingNavigatorSeparator,
            this.bindingNavigatorPositionItem,
            this.bindingNavigatorCountItem,
            this.bindingNavigatorSeparator1,
            this.bindingNavigatorMoveNextItem,
            this.bindingNavigatorMoveLastItem,
            this.bindingNavigatorSeparator2,
            this.bindingNavigatorAddNewItem,
            this.bindingNavigatorDeleteItem,
            this.sheetsBindingNavigatorSaveItem});
			this.sheetsBindingNavigator.Location = new System.Drawing.Point(0, 0);
			this.sheetsBindingNavigator.MoveFirstItem = this.bindingNavigatorMoveFirstItem;
			this.sheetsBindingNavigator.MoveLastItem = this.bindingNavigatorMoveLastItem;
			this.sheetsBindingNavigator.MoveNextItem = this.bindingNavigatorMoveNextItem;
			this.sheetsBindingNavigator.MovePreviousItem = this.bindingNavigatorMovePreviousItem;
			this.sheetsBindingNavigator.Name = "sheetsBindingNavigator";
			this.sheetsBindingNavigator.PositionItem = this.bindingNavigatorPositionItem;
			this.sheetsBindingNavigator.Size = new System.Drawing.Size(638, 25);
			this.sheetsBindingNavigator.TabIndex = 0;
			this.sheetsBindingNavigator.Text = "bindingNavigator1";
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
			// bindingNavigatorCountItem
			// 
			this.bindingNavigatorCountItem.Name = "bindingNavigatorCountItem";
			this.bindingNavigatorCountItem.Size = new System.Drawing.Size(41, 22);
			this.bindingNavigatorCountItem.Text = "of {0}";
			this.bindingNavigatorCountItem.ToolTipText = "Total number of items";
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
			// bindingNavigatorMoveFirstItem
			// 
			this.bindingNavigatorMoveFirstItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
			this.bindingNavigatorMoveFirstItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMoveFirstItem.Image")));
			this.bindingNavigatorMoveFirstItem.Name = "bindingNavigatorMoveFirstItem";
			this.bindingNavigatorMoveFirstItem.RightToLeftAutoMirrorImage = true;
			this.bindingNavigatorMoveFirstItem.Size = new System.Drawing.Size(23, 22);
			this.bindingNavigatorMoveFirstItem.Text = "Move first";
			// 
			// bindingNavigatorMovePreviousItem
			// 
			this.bindingNavigatorMovePreviousItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
			this.bindingNavigatorMovePreviousItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMovePreviousItem.Image")));
			this.bindingNavigatorMovePreviousItem.Name = "bindingNavigatorMovePreviousItem";
			this.bindingNavigatorMovePreviousItem.RightToLeftAutoMirrorImage = true;
			this.bindingNavigatorMovePreviousItem.Size = new System.Drawing.Size(23, 22);
			this.bindingNavigatorMovePreviousItem.Text = "Move previous";
			// 
			// bindingNavigatorSeparator
			// 
			this.bindingNavigatorSeparator.Name = "bindingNavigatorSeparator";
			this.bindingNavigatorSeparator.Size = new System.Drawing.Size(6, 25);
			// 
			// bindingNavigatorPositionItem
			// 
			this.bindingNavigatorPositionItem.AccessibleName = "Position";
			this.bindingNavigatorPositionItem.AutoSize = false;
			this.bindingNavigatorPositionItem.Name = "bindingNavigatorPositionItem";
			this.bindingNavigatorPositionItem.Size = new System.Drawing.Size(50, 22);
			this.bindingNavigatorPositionItem.Text = "0";
			this.bindingNavigatorPositionItem.ToolTipText = "Current position";
			// 
			// bindingNavigatorSeparator1
			// 
			this.bindingNavigatorSeparator1.Name = "bindingNavigatorSeparator1";
			this.bindingNavigatorSeparator1.Size = new System.Drawing.Size(6, 25);
			// 
			// bindingNavigatorMoveNextItem
			// 
			this.bindingNavigatorMoveNextItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
			this.bindingNavigatorMoveNextItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMoveNextItem.Image")));
			this.bindingNavigatorMoveNextItem.Name = "bindingNavigatorMoveNextItem";
			this.bindingNavigatorMoveNextItem.RightToLeftAutoMirrorImage = true;
			this.bindingNavigatorMoveNextItem.Size = new System.Drawing.Size(23, 22);
			this.bindingNavigatorMoveNextItem.Text = "Move next";
			// 
			// bindingNavigatorMoveLastItem
			// 
			this.bindingNavigatorMoveLastItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
			this.bindingNavigatorMoveLastItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMoveLastItem.Image")));
			this.bindingNavigatorMoveLastItem.Name = "bindingNavigatorMoveLastItem";
			this.bindingNavigatorMoveLastItem.RightToLeftAutoMirrorImage = true;
			this.bindingNavigatorMoveLastItem.Size = new System.Drawing.Size(23, 22);
			this.bindingNavigatorMoveLastItem.Text = "Move last";
			// 
			// bindingNavigatorSeparator2
			// 
			this.bindingNavigatorSeparator2.Name = "bindingNavigatorSeparator2";
			this.bindingNavigatorSeparator2.Size = new System.Drawing.Size(6, 25);
			// 
			// sheetsBindingNavigatorSaveItem
			// 
			this.sheetsBindingNavigatorSaveItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
			this.sheetsBindingNavigatorSaveItem.Image = ((System.Drawing.Image)(resources.GetObject("sheetsBindingNavigatorSaveItem.Image")));
			this.sheetsBindingNavigatorSaveItem.Name = "sheetsBindingNavigatorSaveItem";
			this.sheetsBindingNavigatorSaveItem.Size = new System.Drawing.Size(23, 22);
			this.sheetsBindingNavigatorSaveItem.Text = "Save Data";
			this.sheetsBindingNavigatorSaveItem.Click += new System.EventHandler(this.sheetsBindingNavigatorSaveItem_Click);
			// 
			// sheetsDataGridView
			// 
			this.sheetsDataGridView.AutoGenerateColumns = false;
			this.sheetsDataGridView.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dataGridViewTextBoxColumn2,
            this.dataGridViewTextBoxColumn3,
            this.dataGridViewTextBoxColumn4,
            this.dataGridViewTextBoxColumn5});
			this.sheetsDataGridView.DataSource = this.sheetsBindingSource;
			this.sheetsDataGridView.Dock = System.Windows.Forms.DockStyle.Fill;
			this.sheetsDataGridView.Location = new System.Drawing.Point(0, 25);
			this.sheetsDataGridView.Name = "sheetsDataGridView";
			this.sheetsDataGridView.Size = new System.Drawing.Size(638, 373);
			this.sheetsDataGridView.TabIndex = 1;
			this.sheetsDataGridView.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.sheetsDataGridView_CellContentClick);
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
			// dataGridViewTextBoxColumn2
			// 
			this.dataGridViewTextBoxColumn2.DataPropertyName = "Name";
			this.dataGridViewTextBoxColumn2.HeaderText = "Название";
			this.dataGridViewTextBoxColumn2.Name = "dataGridViewTextBoxColumn2";
			// 
			// dataGridViewTextBoxColumn3
			// 
			this.dataGridViewTextBoxColumn3.DataPropertyName = "Length";
			this.dataGridViewTextBoxColumn3.HeaderText = "Длина";
			this.dataGridViewTextBoxColumn3.Name = "dataGridViewTextBoxColumn3";
			// 
			// dataGridViewTextBoxColumn4
			// 
			this.dataGridViewTextBoxColumn4.DataPropertyName = "Width";
			this.dataGridViewTextBoxColumn4.HeaderText = "Ширина";
			this.dataGridViewTextBoxColumn4.Name = "dataGridViewTextBoxColumn4";
			// 
			// dataGridViewTextBoxColumn5
			// 
			this.dataGridViewTextBoxColumn5.DataPropertyName = "MaterialID";
			this.dataGridViewTextBoxColumn5.DataSource = this.materialsBindingSource;
			this.dataGridViewTextBoxColumn5.DisplayMember = "Name";
			this.dataGridViewTextBoxColumn5.HeaderText = "Материал";
			this.dataGridViewTextBoxColumn5.Name = "dataGridViewTextBoxColumn5";
			this.dataGridViewTextBoxColumn5.Resizable = System.Windows.Forms.DataGridViewTriState.True;
			this.dataGridViewTextBoxColumn5.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.Automatic;
			this.dataGridViewTextBoxColumn5.ValueMember = "MaterialID";
			// 
			// SheetsListForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(638, 398);
			this.Controls.Add(this.sheetsDataGridView);
			this.Controls.Add(this.sheetsBindingNavigator);
			this.Name = "SheetsListForm";
			this.Text = "Список листов";
			this.Load += new System.EventHandler(this.SheetsListForm_Load);
			((System.ComponentModel.ISupportInitialize)(this.dataSet)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.sheetsBindingSource)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.sheetsBindingNavigator)).EndInit();
			this.sheetsBindingNavigator.ResumeLayout(false);
			this.sheetsBindingNavigator.PerformLayout();
			((System.ComponentModel.ISupportInitialize)(this.sheetsDataGridView)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.materialsBindingSource)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private DataSet dataSet;
		private System.Windows.Forms.BindingSource sheetsBindingSource;
		private Denisenko.Cutting.CutOptima.DataSetTableAdapters.SheetsTableAdapter sheetsTableAdapter;
		private System.Windows.Forms.BindingNavigator sheetsBindingNavigator;
		private System.Windows.Forms.ToolStripButton bindingNavigatorAddNewItem;
		private System.Windows.Forms.ToolStripLabel bindingNavigatorCountItem;
		private System.Windows.Forms.ToolStripButton bindingNavigatorDeleteItem;
		private System.Windows.Forms.ToolStripButton bindingNavigatorMoveFirstItem;
		private System.Windows.Forms.ToolStripButton bindingNavigatorMovePreviousItem;
		private System.Windows.Forms.ToolStripSeparator bindingNavigatorSeparator;
		private System.Windows.Forms.ToolStripTextBox bindingNavigatorPositionItem;
		private System.Windows.Forms.ToolStripSeparator bindingNavigatorSeparator1;
		private System.Windows.Forms.ToolStripButton bindingNavigatorMoveNextItem;
		private System.Windows.Forms.ToolStripButton bindingNavigatorMoveLastItem;
		private System.Windows.Forms.ToolStripSeparator bindingNavigatorSeparator2;
		private System.Windows.Forms.ToolStripButton sheetsBindingNavigatorSaveItem;
		private System.Windows.Forms.DataGridView sheetsDataGridView;
		private System.Windows.Forms.BindingSource materialsBindingSource;
		private Denisenko.Cutting.CutOptima.DataSetTableAdapters.MaterialsTableAdapter materialsTableAdapter;
		private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn2;
		private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn3;
		private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn4;
		private System.Windows.Forms.DataGridViewComboBoxColumn dataGridViewTextBoxColumn5;
	}
}