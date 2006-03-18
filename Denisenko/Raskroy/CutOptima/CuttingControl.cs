using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using Denisenko;
using Denisenko.Cutting;

namespace Denisenko.Cutting.CutOptima
{
	public partial class CuttingControl : Control
	{
		private class Section
		{
			public Single X;
			public Single Y;
			public Single Width;
			public Single Height;
			public Brush Brush;
			public Denisenko.Cutting.Section SourceSection;
		}

		private List<Section> m_sections;

		private struct SheetRect
		{
			public Single X;
			public Single Y;
			public Single Width;
			public Single Height;
		}

		private SheetRect m_sheetRect;

		public CuttingControl()
		{
			m_sections = new List<Section>();
			m_scale = 0.4f;
			m_margin = 50.0f;
			m_autoScale = true;
			InitializeComponent();
		}

		protected override void OnPaint(PaintEventArgs pe)
		{
			pe.Graphics.FillRectangle(Brushes.DimGray, 0, 0, Width, Height);
			if (m_cutting != null)
			{
				pe.Graphics.TranslateTransform(m_margin, m_margin);
				pe.Graphics.ScaleTransform(m_scale, m_scale);
				pe.Graphics.FillRectangle(Brushes.Black, m_sheetRect.X + 20, m_sheetRect.Y + 20,
					m_sheetRect.Width, m_sheetRect.Height);
				pe.Graphics.FillRectangle(Brushes.Silver, m_sheetRect.X, m_sheetRect.Y,
					m_sheetRect.Width, m_sheetRect.Height);
				foreach (Section section in m_sections)
				{
					if(section.Brush != null)
						pe.Graphics.FillRectangle(section.Brush, section.X, section.Y, section.Width, section.Height);
					if (section.SourceSection.SectionType == SectionType.Element)
					{
						String str1 = "Элементы";
						String str2 = String.Format("{0:0.0} x {1:0.0}", section.Width, section.Height);
						Font font = new Font("Arial", 20);
						// выравнивание по центру
						SizeF size1 = pe.Graphics.MeasureString(str1, font);
						SizeF size2 = pe.Graphics.MeasureString(str2, font);
						Single x1 = section.X + section.Width / 2.0f - size1.Width / 2.0f;
						Single y1 = section.Y + section.Height / 2.0f - (size1.Height + size2.Height) / 2.0f;
						Single x2 = section.X + section.Width / 2.0f - size2.Width / 2.0f;
						Single y2 = section.Y + section.Height / 2.0f - (size1.Height + size2.Height) / 2.0f + size1.Height;
						pe.Graphics.DrawString(str1, font, Brushes.Black, x1, y1);
						pe.Graphics.DrawString(str2, font, Brushes.Black, x2, y2);
					}
				}
			}

			// Calling the base class OnPaint
			base.OnPaint(pe);
		}

		private void RecursiveLoadSections(List<Denisenko.Cutting.Section> sections, Boolean transpose)
		{
			foreach (Denisenko.Cutting.Section section in sections)
			{
				Section sec = new Section();

				switch (section.SectionType)
				{
					case SectionType.Element:
						sec.Brush = Brushes.SlateBlue;
						break;
					case SectionType.Remain:
						sec.Brush = Brushes.Red;
						break;
					case SectionType.Scrap:
						break;
					case SectionType.Undefined:
						break;
					case SectionType.Cut:
						if(section.Width > section.Height)
							sec.Brush = Brushes.DarkCyan;
						else
							sec.Brush = Brushes.Cyan;
						break;
				}

				if (transpose)
				{
					sec.X = (Single)section.Y;
					sec.Y = (Single)section.X;
					sec.Width = (Single)section.Height;
					sec.Height = (Single)section.Width;
				}
				else
				{
					sec.X = (Single)section.X;
					sec.Y = (Single)section.Y;
					sec.Width = (Single)section.Width;
					sec.Height = (Single)section.Height;
				}
				sec.SourceSection = section;
				m_sections.Add(sec);
				RecursiveLoadSections(section.NestedSections, transpose);
			}
		}

		private void ClearSections()
		{
			m_sections.Clear();
		}

		public CuttingScheme DataSource
		{
			get { return m_cutting; }
			set
			{
				if (m_cutting != value)
				{
					m_cutting = value;
					if (m_cutting != null)
					{
						Boolean transpose = m_cutting.Width < m_cutting.Height;
						m_sheetRect.X = 0;
						m_sheetRect.Y = 0;
						if (transpose)
						{
							m_sheetRect.Width = (Single)m_cutting.Height;
							m_sheetRect.Height = (Single)m_cutting.Width;
						}
						else
						{
							m_sheetRect.Width = (Single)m_cutting.Width;
							m_sheetRect.Height = (Single)m_cutting.Height;
						}
						RecursiveLoadSections(m_cutting.RootSection.NestedSections, transpose);

						if (m_autoScale)
						{
							float scalex = (this.Width - m_margin * 2) / m_sheetRect.Width;
							float scaley = (this.Height - m_margin * 2) / m_sheetRect.Height;
							m_scale = Math.Min(scalex, scaley);
						}
					}
					else
						ClearSections();
					Invalidate();
				}
			}
		}

		private CuttingScheme m_cutting;
		private Single m_scale;
		private Single m_margin;
		private Boolean m_autoScale;

		private void CuttingControl_Resize(object sender, EventArgs e)
		{
			if (m_autoScale)
			{
				float scalex = (this.Width - m_margin * 2) / m_sheetRect.Width;
				float scaley = (this.Height - m_margin * 2) / m_sheetRect.Height;
				m_scale = Math.Min(scalex, scaley);
			}

		}
	}
}
