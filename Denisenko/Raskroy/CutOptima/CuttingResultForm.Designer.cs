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
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(CuttingResultForm));
			this.tabControl = new System.Windows.Forms.TabControl();
			this.toolStrip1 = new System.Windows.Forms.ToolStrip();
			this.saveButton = new System.Windows.Forms.ToolStripButton();
			this.menuStrip = new System.Windows.Forms.MenuStrip();
			this.operationsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.exportLC4ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.toolStrip1.SuspendLayout();
			this.menuStrip.SuspendLayout();
			this.SuspendLayout();
			// 
			// tabControl
			// 
			this.tabControl.Dock = System.Windows.Forms.DockStyle.Fill;
			this.tabControl.Location = new System.Drawing.Point(0, 0);
			this.tabControl.Name = "tabControl";
			this.tabControl.SelectedIndex = 0;
			this.tabControl.Size = new System.Drawing.Size(621, 432);
			this.tabControl.TabIndex = 0;
			// 
			// toolStrip1
			// 
			this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.saveButton});
			this.toolStrip1.Location = new System.Drawing.Point(0, 24);
			this.toolStrip1.Name = "toolStrip1";
			this.toolStrip1.Size = new System.Drawing.Size(621, 25);
			this.toolStrip1.TabIndex = 1;
			this.toolStrip1.Text = "toolStrip1";
			// 
			// saveButton
			// 
			this.saveButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
			this.saveButton.Image = ((System.Drawing.Image)(resources.GetObject("saveButton.Image")));
			this.saveButton.ImageTransparentColor = System.Drawing.Color.Magenta;
			this.saveButton.Name = "saveButton";
			this.saveButton.Size = new System.Drawing.Size(23, 22);
			this.saveButton.Text = "toolStripButton1";
			this.saveButton.Click += new System.EventHandler(this.saveButton_Click);
			// 
			// menuStrip
			// 
			this.menuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.operationsToolStripMenuItem});
			this.menuStrip.Location = new System.Drawing.Point(0, 0);
			this.menuStrip.Name = "menuStrip";
			this.menuStrip.Size = new System.Drawing.Size(621, 24);
			this.menuStrip.TabIndex = 2;
			this.menuStrip.Text = "menuStrip1";
			// 
			// operationsToolStripMenuItem
			// 
			this.operationsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.exportLC4ToolStripMenuItem});
			this.operationsToolStripMenuItem.Name = "operationsToolStripMenuItem";
			this.operationsToolStripMenuItem.Size = new System.Drawing.Size(76, 20);
			this.operationsToolStripMenuItem.Text = "Операции";
			// 
			// exportLC4ToolStripMenuItem
			// 
			this.exportLC4ToolStripMenuItem.Name = "exportLC4ToolStripMenuItem";
			this.exportLC4ToolStripMenuItem.Size = new System.Drawing.Size(156, 22);
			this.exportLC4ToolStripMenuItem.Text = "Экспорт LC4";
			this.exportLC4ToolStripMenuItem.Click += new System.EventHandler(this.exportLC4ToolStripMenuItem_Click);
			// 
			// CuttingResultForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(621, 432);
			this.Controls.Add(this.toolStrip1);
			this.Controls.Add(this.menuStrip);
			this.Controls.Add(this.tabControl);
			this.MainMenuStrip = this.menuStrip;
			this.Name = "CuttingResultForm";
			this.Text = "Результат раскроя";
			this.toolStrip1.ResumeLayout(false);
			this.toolStrip1.PerformLayout();
			this.menuStrip.ResumeLayout(false);
			this.menuStrip.PerformLayout();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.TabControl tabControl;
		private System.Windows.Forms.ToolStrip toolStrip1;
		private System.Windows.Forms.ToolStripButton saveButton;
		private System.Windows.Forms.MenuStrip menuStrip;
		private System.Windows.Forms.ToolStripMenuItem operationsToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem exportLC4ToolStripMenuItem;
	}
}