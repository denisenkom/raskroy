using System.Collections.Generic;

namespace Denisenko.Cutting.LC4
{
    public class Cut
    {
        public List<Cut> DependentCutList;
        public LC4Numeric Depth;
        public bool ExactScPosition;
        public bool FullCutHeight;
        public Cut MasterCut;
        public bool Produce;
        public Rectangle Rectangle;
        public bool Recut;
        public bool Selectable;
        public bool Visible;
    }

    public class CutInfoDescription : ILC4Serializable
    {
        public CutInfo Parent;

        public enum VertexReference
        {
            upperleft = 0,
            upperright = 1,
            lowerleft = 2,
            lowerright = 3,
            center = 4,
        }

        public enum EdgeReference
        {
            top = 0,
            down = 1,
            left = 2,
            right = 3,
        }
        public enum CutReference
        {
            center = 0,
            inneredge = 1,
            outeredge = 2,
        }
        public enum DepthReference
        {
            none = 0,
            surface = 1,
            ground = 2,
        }
        public enum DistanceReference
        {
            edge = 0,
            center = 1,
        }
        public enum CalculationType
        {
            fixedcount = 0,
            roundup = 1,
            rounddown = 2,
            moveprimary = 3,
            movesecondary = 4,
            moveboth = 5,
        }
        public enum CutOutDepthReference
        {
            onsurface = 0,
            onbottom = 1,
        }
        public enum SinglePartWorkMode
        {
            normal = 0,
            laser_align_rip = 1,
            laser_align_cross = 2,
            laser_align_rip_and_cross = 3,
        }

        #region ILC4Serializable Members

        public virtual void Read(LC4Formatter fmtr)
        {
            Parent = null;
            ushort version;
            fmtr.Read(out version);
        }

        public virtual void Write(LC4Formatter fmtr)
        {
            fmtr.Write((ushort)1);
        }

        protected void Read_CutInfoDescription(LC4Formatter serHelper)
        {
            ushort version;
            serHelper.Read(out version);
        }

        protected void Write_CutInfoDescription(LC4Formatter serHelper)
        {
            serHelper.Write((ushort)1);
        }

        #endregion
    }

    //public class CutOutDescription
    //{
    //    public CutInfoDescription.VertexReference CutOutReference;
    //    public LC4Numeric Length;
    //    public CutInfoDescription.VertexReference MeasurementReference;
    //}

    public class CutInfo : ILC4Serializable
    {
        public CutInfoDescription CutInfoDescription;
        public List<Cut> CutList;

        #region ILC4Serializable Members

        public void Read(LC4Formatter fmtr)
        {
            ushort version;
            fmtr.Read(out version);
            fmtr.Read(out CutInfoDescription);
            CutInfoDescription.Parent = this;
            CutList = null;
        }

        public void Write(LC4Formatter fmtr)
        {
            fmtr.Write((ushort)1);
            fmtr.Write(CutInfoDescription);
        }

        #endregion
    }

    public class CutInfoList : List<CutInfo>, ILC4Serializable
    {
        #region ILC4Serializable Members

        public void Read(LC4Formatter fmtr)
        {
            fmtr.GenericCollRead<CutInfoList, CutInfo>(this);
        }

        public void Write(LC4Formatter fmtr)
        {
            fmtr.GenericCollWrite<CutInfoList, CutInfo>(this);
        }

        #endregion
    }

    public class GrooveDescription : CutInfoDescription, ILC4Serializable
    {
        public CutInfoDescription.EdgeReference m_EdgeReference;
        public CutInfoDescription.CutReference m_CutReference;
        public LC4Numeric m_PrimaryDistance;
        public LC4Numeric m_Width;
        public LC4Numeric m_Depth;
        public LC4Numeric m_StepWidth;
        public CutInfoDescription.DepthReference m_InsertMode;
        public LC4Numeric m_EnteringPosition;
        public LC4Numeric m_LeavingPosition;
        public GrooveDescription()
            : base()
        {
        }
        //protected GrooveDescription(GrooveDescription pGroove)
        //{
        //    // Evaluation version.
        //}
        //public override object Clone()
        //{
        //    return new GrooveDescription(this);
        //}
        protected void Write_GrooveDescription(LC4Formatter serHelper)
        {
            base.Write_CutInfoDescription(serHelper);
            serHelper.Write((ushort)1);
            serHelper.Write(this.m_EdgeReference);
            serHelper.Write(this.m_CutReference);
            serHelper.Write(this.m_PrimaryDistance);
            serHelper.Write(this.m_Width);
            serHelper.Write(this.m_Depth);
            serHelper.Write(this.m_StepWidth);
            serHelper.Write(this.m_InsertMode);
            serHelper.Write(this.m_EnteringPosition);
            serHelper.Write(this.m_LeavingPosition);
        }
        protected void Read_GrooveDescription(LC4Formatter serHelper)
        {
            ushort version;
            base.Read_CutInfoDescription(serHelper);
            serHelper.Read(out version);
            serHelper.Read(out this.m_EdgeReference);
            serHelper.Read(out this.m_CutReference);
            serHelper.Read(out this.m_PrimaryDistance);
            serHelper.Read(out this.m_Width);
            serHelper.Read(out this.m_Depth);
            serHelper.Read(out this.m_StepWidth);
            serHelper.Read(out this.m_InsertMode);
            serHelper.Read(out this.m_EnteringPosition);
            serHelper.Read(out this.m_LeavingPosition);
        }
        new void Write(LC4Formatter serHelper)
        {
            base.Write_CutInfoDescription(serHelper);
        }
        new void Read(LC4Formatter serHelper)
        {
            Read_GrooveDescription(serHelper);
        }
    }
    public class SingleGroove : GrooveDescription, ILC4Serializable
    {
        public SingleGroove()
            : base()
        {
        }
        //protected SingleGroove(SingleGroove pSingleGroove)
        //{
        //    // Evaluation version.
        //}
        //public override object Clone()
        //{
        //    return new SingleGroove(this);
        //}
        protected void Write_SingleGroove(LC4Formatter serHelper)
        {
            base.Write_GrooveDescription(serHelper);
            serHelper.Write((ushort)1);
        }
        protected void Read_SingleGroove(LC4Formatter serHelper)
        {
            ushort version;
            base.Read_GrooveDescription(serHelper);
            serHelper.Read(out version);
        }
        new void Write(LC4Formatter serHelper)
        {
            Write_SingleGroove(serHelper);
        }
        new void Read(LC4Formatter serHelper)
        {
            Read_SingleGroove(serHelper);
        }
    }
    public class DistancedGroove : GrooveDescription, ILC4Serializable
    {
        public LC4Numeric m_Distance;
        public int m_Count;
        public CutInfoDescription.DistanceReference m_DistanceReference;
        public CutInfoDescription.CutReference m_AdditionalCutReference;
        //public DistancedGroove()
        //{
        //    // Evaluation version.
        //}
        //protected DistancedGroove(DistancedGroove pGroove)
        //    : base(pGroove)
        //{
        //    this.m_Distance = pGroove.m_Distance;
        //    this.m_Count = pGroove.m_Count;
        //    this.m_DistanceReference = pGroove.m_DistanceReference;
        //    this.m_AdditionalCutReference = pGroove.m_AdditionalCutReference;
        //}
        //public override object Clone()
        //{
        //    // Evaluation version.
        //}
        protected void Write_DistancedGroove(LC4Formatter serHelper)
        {
            base.Write_GrooveDescription(serHelper);
            serHelper.Write((ushort)1);
            serHelper.Write(this.m_Distance);
            serHelper.Write(this.m_Count);
            serHelper.Write(this.m_DistanceReference);
            serHelper.Write(this.m_AdditionalCutReference);
        }
        protected void Read_DistancedGroove(LC4Formatter serHelper)
        {
            ushort version;
            base.Read_GrooveDescription(serHelper);
            serHelper.Read(out version);
            serHelper.Read(out this.m_Distance);
            serHelper.Read(out this.m_Count);
            serHelper.Read(out this.m_DistanceReference);
            serHelper.Read(out this.m_AdditionalCutReference);
        }
        new void Write(LC4Formatter serHelper)
        {
            Write_DistancedGroove(serHelper);
        }
        new void Read(LC4Formatter serHelper)
        {
            Read_DistancedGroove(serHelper);
        }
    }
    public class FilledGroove : GrooveDescription, ILC4Serializable
    {
        protected LC4Numeric m_SecondaryDistance;
        protected LC4Numeric m_Distance;
        protected int m_Count;
        protected CutInfoDescription.CalculationType m_CalculationType;
        public FilledGroove()
            : base()
        {
        }
        //protected FilledGroove(FilledGroove pGroove)
        //{
        //    // Evaluation version.
        //}
        //public override object Clone()
        //{
        //    return new FilledGroove(this);
        //}
        protected void Write_FilledGroove(LC4Formatter serHelper)
        {
            base.Write_GrooveDescription(serHelper);
            serHelper.Write((ushort)1);
            serHelper.Write(this.m_SecondaryDistance);
            serHelper.Write(this.m_Distance);
            serHelper.Write(this.m_Count);
            serHelper.Write(this.m_CalculationType);
        }
        protected void Read_FilledGroove(LC4Formatter serHelper)
        {
            ushort usht;
            base.Read_GrooveDescription(serHelper);
            serHelper.Read(out usht);
            serHelper.Read(out this.m_SecondaryDistance);
            serHelper.Read(out this.m_Distance);
            serHelper.Read(out this.m_Count);
            serHelper.Read(out this.m_CalculationType);
        }
        new void Write(LC4Formatter serHelper)
        {
            Write_FilledGroove(serHelper);
        }
        new void Read(LC4Formatter serHelper)
        {
            Read_FilledGroove(serHelper);
        }
    }
    public class CutOutDescription : CutInfoDescription, ILC4Serializable
    {
        public LC4Numeric m_X;
        public LC4Numeric m_Y;
        public LC4Numeric m_Width;
        public LC4Numeric m_Length;
        public CutInfoDescription.VertexReference m_VertexReference;
        public CutInfoDescription.VertexReference m_CutOutReference;
        public LC4Numeric m_VertexDisctance;
        public CutInfoDescription.DepthReference m_MeasurementReference;
        public CutOutDescription()
            : base()
        {
        }
        //protected CutOutDescription(CutOutDescription pCutOutDescription)
        //{
        //    // Evaluation version.
        //}
        //public override object Clone()
        //{
        //    return new CutOutDescription(this);
        //}
        protected void Write_CutOutDescription(LC4Formatter serHelper)
        {
            base.Read_CutInfoDescription(serHelper);
            serHelper.Write((ushort)1);
            serHelper.Write(this.m_X);
            serHelper.Write(this.m_Y);
            serHelper.Write(this.m_Width);
            serHelper.Write(this.m_Length);
            serHelper.Write(this.m_VertexReference);
            serHelper.Write(this.m_CutOutReference);
            serHelper.Write(this.m_VertexDisctance);
            serHelper.Write(this.m_MeasurementReference);
        }
        protected void Read_CutOutDescription(LC4Formatter serHelper)
        {
            ushort version;
            base.Read_CutInfoDescription(serHelper);
            serHelper.Read(out version);
            serHelper.Read(out this.m_X);
            serHelper.Read(out this.m_Y);
            serHelper.Read(out this.m_Width);
            serHelper.Read(out this.m_Length);
            serHelper.Read(out this.m_VertexReference);
            serHelper.Read(out this.m_CutOutReference);
            serHelper.Read(out this.m_VertexDisctance);
            serHelper.Read(out this.m_MeasurementReference);
        }
        new void Write(LC4Formatter serHelper)
        {
            Write_CutOutDescription(serHelper);
        }
        new void Read(LC4Formatter serHelper)
        {
            Read_CutOutDescription(serHelper);
        }
        //public CutInfoDescription.CutOutDepthReference MeasurementReference
        //{
        //    get
        //    {
        //        switch (this.m_MeasurementReference)
        //        {
        //            case CutInfoDescription.e_DepthReference.none:
        //            case CutInfoDescription.e_DepthReference.surface:
        //                return CutInfoDescription.CutOutDepthReference.onsurface;

        //            case CutInfoDescription.e_DepthReference.ground:
        //                return CutInfoDescription.CutOutDepthReference.onbottom;

        //            default:
        //                return CutInfoDescription.CutOutDepthReference.onsurface;
        //        }
        //    }
        //    set
        //    {
        //        // Evaluation version.
        //    }
        //}
    }
    public class SinglePartArrayDescription : CutInfoDescription, ILC4Serializable
    {
        protected LC4Numeric m_Length;
        protected int m_LengthCount;
        protected LC4Numeric m_Width;
        protected int m_WidthCount;
        protected LC4Numeric m_TrimCutRip;
        protected LC4Numeric m_TrimCutCross;
        protected CutInfoDescription.SinglePartWorkMode m_Workmode;
        protected bool m_CalculateBoardDim;
        public SinglePartArrayDescription()
            : base()
        {
        }
        protected void Write_SinglePartArrayDescription(LC4Formatter serHelper)
        {
            base.Write_CutInfoDescription(serHelper);
            serHelper.Write((ushort)1);
            serHelper.Write(this.m_Length);
            serHelper.Write(this.m_LengthCount);
            serHelper.Write(this.m_Width);
            serHelper.Write(this.m_WidthCount);
            serHelper.Write(this.m_TrimCutRip);
            serHelper.Write(this.m_TrimCutCross);
            serHelper.Write(this.m_Workmode);
            serHelper.Write(this.m_CalculateBoardDim);
        }
        protected void Read_SinglePartArrayDescription(LC4Formatter serHelper)
        {
            base.Read_CutInfoDescription(serHelper);
            ushort version;
            serHelper.Read(out version);
            serHelper.Read(out this.m_Length);
            serHelper.Read(out this.m_LengthCount);
            serHelper.Read(out this.m_Width);
            serHelper.Read(out this.m_WidthCount);
            serHelper.Read(out this.m_TrimCutRip);
            serHelper.Read(out this.m_TrimCutCross);
            serHelper.Read(out this.m_Workmode);
            serHelper.Read(out this.m_CalculateBoardDim);
        }
        public override void Write(LC4Formatter serHelper)
        {
            Write_SinglePartArrayDescription(serHelper);
        }
        public override void Read(LC4Formatter serHelper)
        {
            Read_SinglePartArrayDescription(serHelper);
        }
    }
    public class AngularCutDescription : CutInfoDescription, ILC4Serializable
    {
        public AngularCutDescription()
        {
            // Evaluation version.
        }
        protected void Write_AngularCutDescription(LC4Formatter serHelper)
        {
            base.Write_CutInfoDescription(serHelper);
            serHelper.Write((ushort)1);
        }
        protected void Read_AngularCutDescription(LC4Formatter serHelper)
        {
            ushort version;
            base.Read_CutInfoDescription(serHelper);
            serHelper.Read(out version);
        }
        new void Write(LC4Formatter serHelper)
        {
            Write_AngularCutDescription(serHelper);
        }
        new void Read(LC4Formatter serHelper)
        {
            Read_AngularCutDescription(serHelper);
        }
    }
}
