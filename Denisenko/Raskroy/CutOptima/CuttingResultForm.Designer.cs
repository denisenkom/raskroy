namespace Denisenko.Cutting.CutOptima
{
	partial class CuttingResultForm
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
			this.tabControl = new System.Windows.Forms.TabControl();
			this.menuStrip1 = new System.Windows.Forms.MenuStrip();
			this.operationsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.saveToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
			this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
			this.exportLC4ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.menuStrip1.SuspendLayout();
			this.SuspendLayout();
			// 
			// tabControl
			// 
			this.tabControl.Dock = System.Windows.Forms.DockStyle.Fill;
			this.tabControl.Location = new System.Drawing.Point(0, 24);
			this.tabControl.Name = "tabControl";
			this.tabControl.SelectedIndex = 0;
			this.tabControl.Size = new System.Drawing.Size(621, 408);
			this.tabControl.TabIndex = 0;
			// 
			// menuStrip1
			// 
			this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.operationsToolStripMenuItem});
			this.menuStrip1.Location = new System.Drawing.Point(0, 0);
			this.menuStrip1.Name = "menuStrip1";
			this.menuStrip1.Size = new System.Drawing.Size(621, 24);
			this.menuStrip1.TabIndex = 1;
			this.menuStrip1.Text = "menuStrip1";
			this.menuStrip1.Visible = false;
			// 
			// operationsToolStripMenuItem
			// 
			this.operationsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripSeparator1,
            this.saveToolStripMenuItem,
            this.exportLC4ToolStripMenuItem,
            this.toolStripSeparator2});
			this.operationsToolStripMenuItem.MergeAction = System.Windows.Forms.MergeAction.MatchOnly;
			this.operationsToolStripMenuItem.Name = "operationsToolStripMenuItem";
			this.operationsToolStripMenuItem.Size = new System.Drawing.Size(76, 20);
			this.operationsToolStripMenuItem.Text = "Операции";
			// 
			// saveToolStripMenuItem
			// 
			this.saveToolStripMenuItem.MergeAction = System.Windows.Forms.MergeAction.Insert;
			this.saveToolStripMenuItem.MergeIndex = 4;
			this.saveToolStripMenuItem.Name = "saveToolStripMenuItem";
			this.saveToolStripMenuItem.Size = new System.Drawing.Size(195, 22);
			this.saveToolStripMenuItem.Text = "Сохранить раскрой";
			this.saveToolStripMenuItem.Click += new System.EventHandler(this.saveToolStripMenuItem_Click);
			// 
			// toolStripSeparator1
			// 
			this.toolStripSeparator1.MergeAction = System.Windows.Forms.MergeAction.Insert;
			this.toolStripSeparator1.MergeIndex = 3;
			this.toolStripSeparator1.Name = "toolStripSeparator1";
			this.toolStripSeparator1.Size = new System.Drawing.Size(192, 6);
			// 
			// toolStripSeparator2
			// 
			this.toolStripSeparator2.MergeAction = System.Windows.Forms.MergeAction.Insert;
			this.toolStripSeparator2.MergeIndex = 6;
			this.toolStripSeparator2.Name = "toolStripSeparator2";
			this.toolStripSeparator2.Size = new System.Drawing.Size(192, 6);
			// 
			// exportLC4ToolStripMenuItem
			// 
			this.exportLC4ToolStripMenuItem.MergeAction = System.Windows.Forms.MergeAction.Insert;
			this.exportLC4ToolStripMenuItem.MergeIndex = 5;
			this.exportLC4ToolStripMenuItem.Name = "exportLC4ToolStripMenuItem";
			this.exportLC4ToolStripMenuItem.Size = new System.Drawing.Size(195, 22);
			this.exportLC4ToolStripMenuItem.Text = "Экспорт в LC4";
			this.exportLC4ToolStripMenuItem.Click += new System.EventHandler(this.exportLC4ToolStripMenuItem_Click);
			// 
			// CuttingResultForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(621, 432);
			this.Controls.Add(this.tabControl);
			this.Controls.Add(this.menuStrip1);
			this.Name = "CuttingResultForm";
			this.Text = "Результат раскроя";
			this.menuStrip1.ResumeLayout(false);
			this.menuStrip1.PerformLayout();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.TabControl tabControl;
		private System.Windows.Forms.MenuStrip menuStrip1;
		private System.Windows.Forms.ToolStripMenuItem operationsToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem saveToolStripMenuItem;
		private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
		private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
		private System.Windows.Forms.ToolStripMenuItem exportLC4ToolStripMenuItem;
	}
}