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
			this.mainMenuStrip = new System.Windows.Forms.MenuStrip();
			this.операцииToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.referenceDetailsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.detailsListsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.optimizeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.настройкиToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.mainMenuStrip.SuspendLayout();
			this.SuspendLayout();
			// 
			// mainMenuStrip
			// 
			this.mainMenuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.операцииToolStripMenuItem,
            this.настройкиToolStripMenuItem});
			this.mainMenuStrip.Location = new System.Drawing.Point(0, 0);
			this.mainMenuStrip.Name = "mainMenuStrip";
			this.mainMenuStrip.Size = new System.Drawing.Size(663, 24);
			this.mainMenuStrip.TabIndex = 1;
			this.mainMenuStrip.Text = "menuStrip1";
			// 
			// операцииToolStripMenuItem
			// 
			this.операцииToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.referenceDetailsToolStripMenuItem,
            this.detailsListsToolStripMenuItem,
            this.optimizeToolStripMenuItem});
			this.операцииToolStripMenuItem.Name = "операцииToolStripMenuItem";
			this.операцииToolStripMenuItem.Size = new System.Drawing.Size(76, 20);
			this.операцииToolStripMenuItem.Text = "Операции";
			// 
			// referenceDetailsToolStripMenuItem
			// 
			this.referenceDetailsToolStripMenuItem.Name = "referenceDetailsToolStripMenuItem";
			this.referenceDetailsToolStripMenuItem.Size = new System.Drawing.Size(204, 22);
			this.referenceDetailsToolStripMenuItem.Text = "Списки стд. деталей";
			this.referenceDetailsToolStripMenuItem.Click += new System.EventHandler(this.referenceDetailsToolStripMenuItem_Click);
			// 
			// detailsListsToolStripMenuItem
			// 
			this.detailsListsToolStripMenuItem.Name = "detailsListsToolStripMenuItem";
			this.detailsListsToolStripMenuItem.Size = new System.Drawing.Size(204, 22);
			this.detailsListsToolStripMenuItem.Text = "Списки деталей";
			this.detailsListsToolStripMenuItem.Click += new System.EventHandler(this.detailsListsToolStripMenuItem_Click);
			// 
			// optimizeToolStripMenuItem
			// 
			this.optimizeToolStripMenuItem.Name = "optimizeToolStripMenuItem";
			this.optimizeToolStripMenuItem.Size = new System.Drawing.Size(204, 22);
			this.optimizeToolStripMenuItem.Text = "Оптимизация";
			// 
			// настройкиToolStripMenuItem
			// 
			this.настройкиToolStripMenuItem.Name = "настройкиToolStripMenuItem";
			this.настройкиToolStripMenuItem.Size = new System.Drawing.Size(79, 20);
			this.настройкиToolStripMenuItem.Text = "Настройки";
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
			this.mainMenuStrip.ResumeLayout(false);
			this.mainMenuStrip.PerformLayout();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.MenuStrip mainMenuStrip;
		private System.Windows.Forms.ToolStripMenuItem операцииToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem referenceDetailsToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem detailsListsToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem настройкиToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem optimizeToolStripMenuItem;
	}
}