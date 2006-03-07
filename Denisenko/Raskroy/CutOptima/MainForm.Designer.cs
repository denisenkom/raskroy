namespace Denisenko.Cutting.CutOptima
{
	partial class MainForm
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
			System.Windows.Forms.ToolStripMenuItem operationsToolStripMenuItem;
			System.Windows.Forms.ToolStripMenuItem referencesToolStripMenuItem;
			this.detailsListsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.optimizeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.loadCuttingToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.exitMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.materialsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.sheetsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.stdDetailsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.cuttingParametersToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.BottomToolStripPanel = new System.Windows.Forms.ToolStripPanel();
			this.TopToolStripPanel = new System.Windows.Forms.ToolStripPanel();
			this.RightToolStripPanel = new System.Windows.Forms.ToolStripPanel();
			this.LeftToolStripPanel = new System.Windows.Forms.ToolStripPanel();
			this.ContentPanel = new System.Windows.Forms.ToolStripContentPanel();
			this.mainMenuStrip = new System.Windows.Forms.MenuStrip();
			this.settingsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.windowsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.baseSelectionToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			operationsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			referencesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.mainMenuStrip.SuspendLayout();
			this.SuspendLayout();
			// 
			// operationsToolStripMenuItem
			// 
			operationsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.detailsListsToolStripMenuItem,
            this.optimizeToolStripMenuItem,
            this.loadCuttingToolStripMenuItem,
            this.exitMenuItem});
			operationsToolStripMenuItem.Name = "operationsToolStripMenuItem";
			operationsToolStripMenuItem.Size = new System.Drawing.Size(76, 20);
			operationsToolStripMenuItem.Text = "Операции";
			// 
			// detailsListsToolStripMenuItem
			// 
			this.detailsListsToolStripMenuItem.Name = "detailsListsToolStripMenuItem";
			this.detailsListsToolStripMenuItem.Size = new System.Drawing.Size(190, 22);
			this.detailsListsToolStripMenuItem.Text = "Списки деталей";
			this.detailsListsToolStripMenuItem.Click += new System.EventHandler(this.detailsListsToolStripMenuItem_Click);
			// 
			// optimizeToolStripMenuItem
			// 
			this.optimizeToolStripMenuItem.Name = "optimizeToolStripMenuItem";
			this.optimizeToolStripMenuItem.Size = new System.Drawing.Size(190, 22);
			this.optimizeToolStripMenuItem.Text = "Оптимизация";
			this.optimizeToolStripMenuItem.Click += new System.EventHandler(this.optimizeToolStripMenuItem_Click);
			// 
			// loadCuttingToolStripMenuItem
			// 
			this.loadCuttingToolStripMenuItem.MergeIndex = 1;
			this.loadCuttingToolStripMenuItem.Name = "loadCuttingToolStripMenuItem";
			this.loadCuttingToolStripMenuItem.Size = new System.Drawing.Size(190, 22);
			this.loadCuttingToolStripMenuItem.Text = "Загрузить раскрой";
			this.loadCuttingToolStripMenuItem.Click += new System.EventHandler(this.loadCuttingToolStripMenuItem_Click);
			// 
			// exitMenuItem
			// 
			this.exitMenuItem.Name = "exitMenuItem";
			this.exitMenuItem.Size = new System.Drawing.Size(190, 22);
			this.exitMenuItem.Text = "Выход";
			this.exitMenuItem.Click += new System.EventHandler(this.exitMenuItem_Click);
			// 
			// referencesToolStripMenuItem
			// 
			referencesToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.materialsToolStripMenuItem,
            this.sheetsToolStripMenuItem,
            this.stdDetailsToolStripMenuItem,
            this.cuttingParametersToolStripMenuItem});
			referencesToolStripMenuItem.Name = "referencesToolStripMenuItem";
			referencesToolStripMenuItem.Size = new System.Drawing.Size(93, 20);
			referencesToolStripMenuItem.Text = "Справочники";
			// 
			// materialsToolStripMenuItem
			// 
			this.materialsToolStripMenuItem.Name = "materialsToolStripMenuItem";
			this.materialsToolStripMenuItem.Size = new System.Drawing.Size(204, 22);
			this.materialsToolStripMenuItem.Text = "Материалы";
			this.materialsToolStripMenuItem.Click += new System.EventHandler(this.materialsToolStripMenuItem_Click);
			// 
			// sheetsToolStripMenuItem
			// 
			this.sheetsToolStripMenuItem.Name = "sheetsToolStripMenuItem";
			this.sheetsToolStripMenuItem.Size = new System.Drawing.Size(204, 22);
			this.sheetsToolStripMenuItem.Text = "Листы";
			this.sheetsToolStripMenuItem.Click += new System.EventHandler(this.sheetsToolStripMenuItem_Click);
			// 
			// stdDetailsToolStripMenuItem
			// 
			this.stdDetailsToolStripMenuItem.Name = "stdDetailsToolStripMenuItem";
			this.stdDetailsToolStripMenuItem.Size = new System.Drawing.Size(204, 22);
			this.stdDetailsToolStripMenuItem.Text = "Стандартные детали";
			this.stdDetailsToolStripMenuItem.Click += new System.EventHandler(this.stdDetailsToolStripMenuItem_Click);
			// 
			// cuttingParametersToolStripMenuItem
			// 
			this.cuttingParametersToolStripMenuItem.Name = "cuttingParametersToolStripMenuItem";
			this.cuttingParametersToolStripMenuItem.Size = new System.Drawing.Size(204, 22);
			this.cuttingParametersToolStripMenuItem.Text = "Параметры раскроя";
			this.cuttingParametersToolStripMenuItem.Click += new System.EventHandler(this.cuttingParametersToolStripMenuItem_Click);
			// 
			// BottomToolStripPanel
			// 
			this.BottomToolStripPanel.Location = new System.Drawing.Point(0, 0);
			this.BottomToolStripPanel.Name = "BottomToolStripPanel";
			this.BottomToolStripPanel.Orientation = System.Windows.Forms.Orientation.Horizontal;
			this.BottomToolStripPanel.RowMargin = new System.Windows.Forms.Padding(3, 0, 0, 0);
			this.BottomToolStripPanel.Size = new System.Drawing.Size(0, 0);
			// 
			// TopToolStripPanel
			// 
			this.TopToolStripPanel.Location = new System.Drawing.Point(0, 0);
			this.TopToolStripPanel.Name = "TopToolStripPanel";
			this.TopToolStripPanel.Orientation = System.Windows.Forms.Orientation.Horizontal;
			this.TopToolStripPanel.RowMargin = new System.Windows.Forms.Padding(3, 0, 0, 0);
			this.TopToolStripPanel.Size = new System.Drawing.Size(0, 0);
			// 
			// RightToolStripPanel
			// 
			this.RightToolStripPanel.Location = new System.Drawing.Point(0, 0);
			this.RightToolStripPanel.Name = "RightToolStripPanel";
			this.RightToolStripPanel.Orientation = System.Windows.Forms.Orientation.Horizontal;
			this.RightToolStripPanel.RowMargin = new System.Windows.Forms.Padding(3, 0, 0, 0);
			this.RightToolStripPanel.Size = new System.Drawing.Size(0, 0);
			// 
			// LeftToolStripPanel
			// 
			this.LeftToolStripPanel.Location = new System.Drawing.Point(0, 0);
			this.LeftToolStripPanel.Name = "LeftToolStripPanel";
			this.LeftToolStripPanel.Orientation = System.Windows.Forms.Orientation.Horizontal;
			this.LeftToolStripPanel.RowMargin = new System.Windows.Forms.Padding(3, 0, 0, 0);
			this.LeftToolStripPanel.Size = new System.Drawing.Size(0, 0);
			// 
			// ContentPanel
			// 
			this.ContentPanel.Size = new System.Drawing.Size(150, 175);
			// 
			// mainMenuStrip
			// 
			this.mainMenuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            operationsToolStripMenuItem,
            referencesToolStripMenuItem,
            this.settingsToolStripMenuItem,
            this.windowsToolStripMenuItem});
			this.mainMenuStrip.Location = new System.Drawing.Point(0, 0);
			this.mainMenuStrip.MdiWindowListItem = this.windowsToolStripMenuItem;
			this.mainMenuStrip.Name = "mainMenuStrip";
			this.mainMenuStrip.Size = new System.Drawing.Size(663, 24);
			this.mainMenuStrip.TabIndex = 1;
			this.mainMenuStrip.Text = "menuStrip1";
			// 
			// settingsToolStripMenuItem
			// 
			this.settingsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.baseSelectionToolStripMenuItem});
			this.settingsToolStripMenuItem.Name = "settingsToolStripMenuItem";
			this.settingsToolStripMenuItem.Size = new System.Drawing.Size(79, 20);
			this.settingsToolStripMenuItem.Text = "Настройки";
			// 
			// windowsToolStripMenuItem
			// 
			this.windowsToolStripMenuItem.Name = "windowsToolStripMenuItem";
			this.windowsToolStripMenuItem.Size = new System.Drawing.Size(47, 20);
			this.windowsToolStripMenuItem.Text = "Окна";
			// 
			// baseSelectionToolStripMenuItem
			// 
			this.baseSelectionToolStripMenuItem.Name = "baseSelectionToolStripMenuItem";
			this.baseSelectionToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
			this.baseSelectionToolStripMenuItem.Text = "Выбор базы";
			this.baseSelectionToolStripMenuItem.Click += new System.EventHandler(this.baseSelectionToolStripMenuItem_Click);
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(663, 420);
			this.Controls.Add(this.mainMenuStrip);
			this.IsMdiContainer = true;
			this.MainMenuStrip = this.mainMenuStrip;
			this.Name = "MainForm";
			this.Text = "CutOptima";
			this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
			this.Load += new System.EventHandler(this.MainForm_Load);
			this.mainMenuStrip.ResumeLayout(false);
			this.mainMenuStrip.PerformLayout();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.ToolStripPanel BottomToolStripPanel;
		private System.Windows.Forms.ToolStripPanel TopToolStripPanel;
		private System.Windows.Forms.ToolStripPanel RightToolStripPanel;
		private System.Windows.Forms.ToolStripPanel LeftToolStripPanel;
		private System.Windows.Forms.ToolStripContentPanel ContentPanel;
		private System.Windows.Forms.MenuStrip mainMenuStrip;
		private System.Windows.Forms.ToolStripMenuItem detailsListsToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem optimizeToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem loadCuttingToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem materialsToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem sheetsToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem stdDetailsToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem settingsToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem windowsToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem cuttingParametersToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem exitMenuItem;
		private System.Windows.Forms.ToolStripMenuItem baseSelectionToolStripMenuItem;

	}
}