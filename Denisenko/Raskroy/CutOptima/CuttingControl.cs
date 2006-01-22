using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using Denisenko.Cutting;

namespace Raskroy
{
	public partial class CuttingControl : Control
	{
		private class Section
		{
			public Single X;
			public Single Y;
			public Single Width;
			public Single Height;
			public CuttingSection CuttingSection;
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
			m_scale = 0.2f;
			m_margin = 50.0f;
			InitializeComponent();
		}

		protected override void OnPaint(PaintEventArgs pe)
		{
			pe.Graphics.FillRectangle(Brushes.DimGray, 0, 0, Width, Height);
			if (m_cutting != null)
			{
				pe.Graphics.ScaleTransform(m_scale, m_scale);
				pe.Graphics.FillRectangle(Brushes.Black, m_sheetRect.X + 20, m_sheetRect.Y + 20,
					m_sheetRect.Width, m_sheetRect.Height);
				pe.Graphics.FillRectangle(Brushes.White, m_sheetRect.X, m_sheetRect.Y,
					m_sheetRect.Width, m_sheetRect.Height);
				foreach (Section section in m_sections)
				{
					switch(section.CuttingSection.SectionType)
					{
						case CuttingSectionType.Element:
							pe.Graphics.DrawRectangle(new Pen(Color.Black, 0.1f),
								section.X, section.Y, section.Width, section.Height);
							break;
						case CuttingSectionType.Remain:
							pe.Graphics.DrawRectangle(new Pen(Color.Black, 0.1f),
								section.X, section.Y, section.Width, section.Height);
							break;
						case CuttingSectionType.Scrap:
							pe.Graphics.DrawRectangle(new Pen(Color.Black, 0.1f),
								section.X, section.Y, section.Width, section.Height);
							break;
					}
				}
			}

			// Calling the base class OnPaint
			base.OnPaint(pe);
		}

		private void LoadSections(CuttingSectionsCollection sections, Single x, Single y, Single width, Single height, Boolean transpose)
		{
			Single pinx = x;
			Single piny = y;
			foreach (CuttingSection section in sections)
			{
				Section sec = new Section();
				sec.X = pinx;
				sec.Y = piny;
				if (transpose)
				{
					sec.Width = width;
					sec.Height = section.Size.ToSingle();
				}
				else
				{
					sec.Width = section.Size.ToSingle();
					sec.Height = height;
				}
				sec.CuttingSection = section;
				m_sections.Add(sec);

				LoadSections(section, sec.X, sec.Y, sec.Width, sec.Height, !transpose);

				if (transpose)
				{
					piny += section.Size.ToSingle();
				}
				else
				{
					pinx += section.Size.ToSingle();
				}
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
						if (m_cutting.Width.Scaled < m_cutting.Height.Scaled)
						{
							m_sheetRect.X = m_margin;
							m_sheetRect.Y = m_margin;
							m_sheetRect.Width = m_cutting.Height.ToSingle();
							m_sheetRect.Height = m_cutting.Width.ToSingle();
							LoadSections(m_cutting, m_sheetRect.X, m_sheetRect.Y,
								m_sheetRect.Width, m_sheetRect.Height, true);
						}
						else
						{
							m_sheetRect.X = m_margin;
							m_sheetRect.Y = m_margin;
							m_sheetRect.Width = m_cutting.Width.ToSingle();
							m_sheetRect.Height = m_cutting.Height.ToSingle();
							LoadSections(m_cutting, m_sheetRect.X, m_sheetRect.Y,
								m_sheetRect.Width, m_sheetRect.Height, false);
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
	}
}
