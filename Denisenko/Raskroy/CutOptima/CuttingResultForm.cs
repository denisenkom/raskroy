using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Text;
using System.Windows.Forms;
using System.Runtime.Serialization.Formatters;
using System.Runtime.Serialization.Formatters.Binary;

using Denisenko.Cutting.CutOptima.DataSetTableAdapters;

namespace Denisenko.Cutting.CutOptima
{
	public partial class CuttingResultForm : Form
	{
		private List<CuttingScheme> m_dataSource;

        private interface IState
        {
            void MouseMove(MouseEventArgs e);
            void MouseClick(MouseEventArgs e);
        }

        private class DefaultState : IState
        {
            CuttingResultForm _link;

            public DefaultState(CuttingResultForm link)
            {
                _link = link;
            }

            public void MouseMove(MouseEventArgs e)
            {
            }

            public void MouseClick(MouseEventArgs e)
            {
            }
        }

        private class ShoosingCutState : IState
        {
            CuttingResultForm _link;
            CuttingControl.CutFantom _fantom = new CuttingControl.CutFantom();
            Cut _horz;
            Cut _vert;
            float _cx, _cy;
            CutType _choosenCut;
            AddingDetailState _prevState;

            public ShoosingCutState(CuttingResultForm link, AddingDetailState prevState, Cut horz, Cut vert)
            {
                _link = link;
                _prevState = prevState;
                _horz = horz;
                _vert = vert;
                _cx = _vert.X + _vert.Width / 2;
                _cy = _horz.Y + _horz.Height / 2;
            }

            public void MouseMove(MouseEventArgs e)
            {
                _fantom.BelongsTo = _link.CurrentCutting;

                CuttingControl.PointInfo pi = _link.CurrentCutting.QueryPointInfo(e.X, e.Y);
                bool loDiag = pi.TransX - pi.TransY - _cx + _cy < 0;
                bool loRevDiag = -pi.TransX - pi.TransY + _cx + _cy < 0;
                if (loDiag && loRevDiag || !loDiag && !loRevDiag)
                {
                    _fantom.X = _vert.X;
                    _fantom.Y = _vert.Y;
                    _fantom.Width = _vert.Width;
                    _fantom.Height = _vert.Height;
                    _choosenCut = CutType.Vertical;
                }
                else
                {
                    _fantom.X = _horz.X;
                    _fantom.Y = _horz.Y;
                    _fantom.Width = _horz.Width;
                    _fantom.Height = _horz.Height;
                    _choosenCut = CutType.Horizontal;
                }
                _link.CurrentCutting.CurrentCutFantom = _fantom;
            }

            public void MouseClick(MouseEventArgs e)
            {
                if (e.Button == MouseButtons.Left)
                {
                    _link.CurrentCutting.CurrentCutFantom = null;
                    _prevState.ChoosenCut(_choosenCut);
                }
                else if (e.Button == MouseButtons.Right)
                {
                    _link.CurrentCutting.CurrentCutFantom = null;
                    _link._state = _prevState;
                }
            }
        }

        private struct Cut
        {
            public float X;
            public float Y;
            public float Width;
            public float Height;
        }

        private class AddingDetailState : IState
        {
            private CuttingResultForm _link;
            private CuttingControl.DetailFantom _fantom = new CuttingControl.DetailFantom();
            private IState _prevState;

            // 2 варианта реза, из которых нужно будет выбрать
            private Cut _horzCut;
            private Cut _vertCut;
            private bool _needChooseCut;

            private Section _currentSection;
            private bool _loX;
            private bool _loY;

            public AddingDetailState(CuttingResultForm link, IState prevState)
            {
                _link = link;
                _prevState = prevState;
            }

            public void MouseMove(MouseEventArgs e)
            {
                decimal detailx = 290;
                decimal detaily = 600;
                bool detailcanrotate = true;

                CuttingControl.PointInfo pi = _link.CurrentCutting.QueryPointInfo(e.X, e.Y);
                if (pi.Section == null || pi.Section.SectionType != SectionType.Free)
                {
                    goto notFit;
                }

                Section.CanFitInfo cfi = pi.Section.CanFit(detailx, detaily, detailcanrotate);
                if (!cfi.CanFit)
                {
                    goto notFit;
                }

                if (cfi.NeedRotate)
                {
                    decimal t = detailx;
                    detailx = detaily;
                    detaily = t;
                }

                _fantom.BelongsTo = _link.CurrentCutting;
                _currentSection = pi.Section;

                // для поворачиваемых деталей выбираем какой стороной расположить, в зависимости от
                // положения указателя над или под диагоналями, т.е. более длинная сторона распологается
                // вдоль той стороны свободной секции, ближе к которой находится указатель
                bool canRotate = cfi.CanRotate && detailx != detaily; // есть смысл в повороте?
                if (canRotate)
                {
                    float detailLonger;
                    float detailShorter;
                    bool loDiag = (float)pi.Section.Width * pi.SecY - (float)pi.Section.Height * pi.SecX < 0;
                    bool loRevDiag = (float)pi.Section.Width * pi.SecY + (float)pi.Section.Height * pi.SecX - (float)(pi.Section.Width * pi.Section.Height) < 0;
                    if (detailx > detaily)
                    {
                        detailLonger = (float)detailx;
                        detailShorter = (float)detaily;
                    }
                    else
                    {
                        detailLonger = (float)detaily;
                        detailShorter = (float)detailx;
                    }
                    if (loDiag && loRevDiag || !loDiag && !loRevDiag)
                    {
                        _fantom.Width = detailLonger;
                        _fantom.Height = detailShorter;
                    }
                    else
                    {
                        _fantom.Width = detailShorter;
                        _fantom.Height = detailLonger;
                    }
                }
                else
                {
                    _fantom.Width = (float)detailx;
                    _fantom.Height = (float)detaily;
                }

                _needChooseCut = _fantom.Width < (float)pi.Section.Width && _fantom.Height < (float)pi.Section.Height;

                // выбираем угол, возле которого расположить деталь - угол к которому ближе всего указатель
                // и одновременно определяем 2 возможных основых реза, из которых потом нужно будет выбрать
                _loX = pi.SecX < (float)(pi.Section.Width / 2); // перед вертикальной серединой
                _loY = pi.SecY < (float)(pi.Section.Height / 2); // под горизонтальной серединой
                if (_loX && _loY)
                {
                    _fantom.X = (float)pi.Section.X;
                    _fantom.Y = (float)pi.Section.Y;

                    if (_needChooseCut)
                    {
                        _vertCut.X = _fantom.X + _fantom.Width;
                        _vertCut.Y = _fantom.Y;
                        _vertCut.Width = 4; /*TODO*/
                        _vertCut.Height = (float)pi.Section.Height;
                        _horzCut.X = _fantom.X;
                        _horzCut.Y = _fantom.Y + _fantom.Height;
                        _horzCut.Width = (float)pi.Section.Width;
                        _horzCut.Height = 4; /*TODO*/
                    }
                }
                else if (_loX && !_loY)
                {
                    _fantom.X = (float)pi.Section.X;
                    _fantom.Y = (float)(pi.Section.Y + pi.Section.Height) - _fantom.Height;

                    if (_needChooseCut)
                    {
                        _vertCut.X = _fantom.X + _fantom.Width;
                        _vertCut.Y = (float)pi.Section.Y;
                        _vertCut.Width = 4; /*TODO*/
                        _vertCut.Height = (float)pi.Section.Height;
                        _horzCut.X = _fantom.X;
                        _horzCut.Y = _fantom.Y - 4;
                        _horzCut.Width = (float)pi.Section.Width;
                        _horzCut.Height = 4; /*TODO*/
                    }
                }
                else if (!_loX && !_loY)
                {
                    _fantom.X = (float)(pi.Section.X + pi.Section.Width) - _fantom.Width;
                    _fantom.Y = (float)(pi.Section.Y + pi.Section.Height) - _fantom.Height;

                    if (_needChooseCut)
                    {
                        _vertCut.X = _fantom.X - 4;
                        _vertCut.Y = (float)pi.Section.Y;
                        _vertCut.Width = 4; /*TODO*/
                        _vertCut.Height = (float)pi.Section.Height;
                        _horzCut.X = (float)pi.Section.X;
                        _horzCut.Y = _fantom.Y - 4;
                        _horzCut.Width = (float)pi.Section.Width;
                        _horzCut.Height = 4; /*TODO*/
                    }
                }
                else if (!_loX && _loY)
                {
                    _fantom.X = (float)(pi.Section.X + pi.Section.Width) - _fantom.Width;
                    _fantom.Y = (float)pi.Section.Y;

                    if (_needChooseCut)
                    {
                        _vertCut.X = _fantom.X - 4;
                        _vertCut.Y = (float)pi.Section.Y;
                        _vertCut.Width = 4; /*TODO*/
                        _vertCut.Height = (float)pi.Section.Height;
                        _horzCut.X = (float)pi.Section.X;
                        _horzCut.Y = _fantom.Y + _fantom.Height;
                        _horzCut.Width = (float)pi.Section.Width;
                        _horzCut.Height = 4; /*TODO*/
                    }
                }

                _link.CurrentCutting.CurrentDetailFantom = _fantom;
                _link.CurrentCutting.Cursor = null;
                goto exit;

                notFit:
                    _link.CurrentCutting.Cursor = Cursors.No;
                    _link.CurrentCutting.CurrentDetailFantom = null;

                exit:
                    ;
            }

            public void MouseClick(MouseEventArgs e)
            {
                if (e.Button == MouseButtons.Left)
                {
                    if (_needChooseCut)
                    {
                        ShoosingCutState shooseCut = new ShoosingCutState(_link, this, _horzCut, _vertCut);
                        _link._state = shooseCut;
                    }
                    else
                    {
                        decimal cutLength;
                        CutType cutType;
                        bool takeCutted;
                        if ((decimal)_fantom.Height == _currentSection.Height)
                        {
                            cutType = CutType.Vertical;
                            if (_loX)
                            {
                                takeCutted = true;
                                cutLength = (decimal)_fantom.Width;
                            }
                            else
                            {
                                takeCutted = false;
                                cutLength = _currentSection.Width - (decimal)_fantom.Width - 4;
                            }
                        }
                        else
                        {
                            cutType = CutType.Horizontal;
                            if (_loY)
                            {
                                takeCutted = true;
                                cutLength = (decimal)_fantom.Height;
                            }
                            else
                            {
                                takeCutted = false;
                                cutLength = _currentSection.Height - (decimal)_fantom.Height - 4;
                            }
                        }
                        Section remain;
                        Section cutted = _link.CurrentCutting.DataSource.Cut(_currentSection, cutLength, cutType, out remain);
                        if (takeCutted)
                        {
                            cutted.SectionType = SectionType.Element;
                        }
                        else
                        {
                            remain.SectionType = SectionType.Element;
                        }
                    }
                }
                else if (e.Button == MouseButtons.Right)
                {
                    _link.CurrentCutting.CurrentDetailFantom = null;
                    _link._state = _prevState;
                }
            }

            public void ChoosenCut(CutType cutType)
            {
                decimal cutLength;
                decimal cut2Length;
                bool takeCutted;
                bool take2Cutted;
                if (cutType == CutType.Horizontal)
                {
                    if (_loY)
                    {
                        cutLength = (decimal)_fantom.Height;
                        takeCutted = true;
                    }
                    else
                    {
                        cutLength = _currentSection.Height - (decimal)_fantom.Height - 4;
                        takeCutted = false;
                    }
                    if (_loX)
                    {
                        cut2Length = (decimal)_fantom.Width;
                        take2Cutted = true;
                    }
                    else
                    {
                        cut2Length = _currentSection.Width - (decimal)_fantom.Width - 4;
                        take2Cutted = false;
                    }
                }
                else
                {
                    if (_loX)
                    {
                        cutLength = (decimal)_fantom.Width;
                        takeCutted = true;
                    }
                    else
                    {
                        cutLength = _currentSection.Width - (decimal)_fantom.Width - 4;
                        takeCutted = false;
                    }
                    if (_loY)
                    {
                        cut2Length = (decimal)_fantom.Height;
                        take2Cutted = true;
                    }
                    else
                    {
                        cut2Length = _currentSection.Height - (decimal)_fantom.Height - 4;
                        take2Cutted = false;
                    }
                }
                Section remain;
                Section cutted = _link.CurrentCutting.DataSource.Cut(_currentSection, cutLength, cutType, out remain);
                Section secondCutSec;
                if (takeCutted)
                {
                    secondCutSec = cutted;
                }
                else
                {
                    secondCutSec = remain;
                }
                cutted = _link.CurrentCutting.DataSource.Cut(secondCutSec, cut2Length, Utils.RotateCut(cutType), out remain);
                if (take2Cutted)
                {
                    cutted.SectionType = SectionType.Element;
                }
                else
                {
                    remain.SectionType = SectionType.Element;
                }
                _link._state = this;
            }
        }

        private IState _state;

		public CuttingResultForm()
		{
			InitializeComponent();
            _state = new DefaultState(this);
		}

        public CuttingControl CurrentCutting
        {
            get
            {
                Control.ControlCollection controls = tabControl.TabPages[tabControl.SelectedIndex].Controls;
                foreach (Control ctrl in controls)
                {
                    if (ctrl is CuttingControl)
                    {
                        return ctrl as CuttingControl;
                    }
                }
                Debug.Fail("Не найден контрол на вкладке TabPage, хотя должен был быть, может забыли добавить?");
                return null;
            }
        }

		public List<CuttingScheme> DataSource
		{
			get
			{
				return m_dataSource;
			}
			set
			{
				m_dataSource = value;
				tabControl.TabPages.Clear();
				Int32 index = 0;
				foreach (CuttingScheme scheme in value)
				{
					TabPage tabPage = new TabPage((index + 1).ToString());

					Label label = new Label();
					label.Text = String.Format("Схема: {0}  разм.: {1:0.0} x {2:0.0}  группа мат.: {3}", index + 1, scheme.Width, scheme.Height, scheme.Material.Name);
					label.Dock = DockStyle.Top;

					CuttingControl cuttingControl = new CuttingControl();
					cuttingControl.DataSource = scheme;
					cuttingControl.Dock = DockStyle.Fill;

                    cuttingControl.MouseMove += CuttingControl_MouseMove;
                    cuttingControl.MouseClick += CuttingControl_MouseClick;

					tabPage.Controls.Add(label);
					tabPage.Controls.Add(cuttingControl);
					tabControl.TabPages.Add(tabPage);
					index++;
				}
			}
		}

		private void saveToolStripMenuItem_Click(object sender, EventArgs e)
		{
			Mediator.Instance.SaveCuttingCommand(DataSource);
		}

		private void exportLC4ToolStripMenuItem_Click(object sender, EventArgs e)
		{
			Mediator.Instance.ExportLC4Command(DataSource);
		}

        private void CuttingControl_MouseMove(object sender, MouseEventArgs e)
        {
            _state.MouseMove(e);
        }

        private void CuttingControl_MouseClick(object sender, MouseEventArgs e)
        {
            _state.MouseClick(e);
        }

        internal void BeginAddDetail()
        {
            _state = new AddingDetailState(this, _state);
        }

        internal void Undo()
        {
            CurrentCutting.DataSource.Undo();
        }

        internal void Redo()
        {
            CurrentCutting.DataSource.Redo();
        }
    }
}