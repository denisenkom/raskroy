using System;
using System.Collections.Generic;
using System.Text;
using System.Xml.Serialization;

namespace Denisenko.Cutting.LC4
{
    public enum TextureDirection
    {
        DontCare = 0,
        Care = 1,
        BySize1 = 2, // продольный (в длинну)
        BySize2 = 3, // поперечный
    }
    
    public class PlateBase
    {
        [XmlAttribute("length")]
        public LC4Numeric Length;

        [XmlAttribute("width")]
        public LC4Numeric Width;

        [XmlAttribute("thickness")]
        public LC4Numeric Thickness;

        [XmlAttribute("name")]
        public String Name;

        [XmlAttribute("remarks")]
        public String Remarks;

        [XmlAttribute("material")]
        public String Material;

        [XmlAttribute("amount")]
        public Int32 Amount;

        [XmlAttribute("amountInWork")]
        public Int32 AmountInWork;

        [XmlAttribute("textureDirection")]
        public TextureDirection TextureDirection;

        [XmlAttribute("isKeepSafe")]
        public bool IsKeepSafe; // IsSchonplatte

        [XmlElement("variables")]
        public VariablesList Variables; // ZusatzInfos

        [XmlAttribute("inVerwendung")]
        bool InVerwendung;

        public PlateBase()
        {
            InVerwendung = false;
            IsKeepSafe = false;
            Variables = new VariablesList();
        }


        internal void BaseRead(LC4Formatter fmtr)
        {
            ushort version;
            fmtr.Read(out version);
            fmtr.Read(out Name);
            fmtr.Read(out Remarks);
            fmtr.Read(out Material);
            fmtr.Read(out Length);
            fmtr.Read(out Width);
            fmtr.Read(out Thickness);
            fmtr.Read(out Amount);
            fmtr.Read(out AmountInWork);
            fmtr.Read(out TextureDirection);
            fmtr.Read(out IsKeepSafe);
            fmtr.Read(out Variables);
            fmtr.Read(out InVerwendung);
        }

        internal void BaseWrite(LC4Formatter fmtr)
        {
            fmtr.Write((ushort)2);
            fmtr.Write(Name);
            fmtr.Write(Remarks);
            fmtr.Write(Material);
            fmtr.Write(Length);
            fmtr.Write(Width);
            fmtr.Write(Thickness);
            fmtr.Write(Amount);
            fmtr.Write(AmountInWork);
            fmtr.Write(TextureDirection);
            fmtr.Write(IsKeepSafe);
            fmtr.Write(Variables);
            fmtr.Write(InVerwendung);
        }
    }

    public class Sheet : PlateBase, ILC4Serializable
	{
		public Sheet()
		{
			Amount = 1;
			AmountInWork = 0;
			Name = "";
			Remarks = "";
			Material = "";
		}

        #region ILC4Serializable Members

        public void Read(LC4Formatter fmtr)
        {
            ushort version;
            fmtr.Read(out version);
            BaseRead(fmtr);
        }

        public void Write(LC4Formatter fmtr)
        {
            fmtr.Write((ushort)1);
            BaseWrite(fmtr);
        }

        #endregion
    }

    public class SheetsList : List<Sheet>, ILC4Serializable
    {
        #region ILC4Serializable Members

        public void Read(LC4Formatter fmtr)
        {
            fmtr.GenericCollRead<SheetsList, Sheet>(this);
        }

        public void Write(LC4Formatter fmtr)
        {
            fmtr.GenericCollWrite<SheetsList, Sheet>(this);
        }

        #endregion
    }

    public class Detail : PlateBase, ILC4Serializable
    {
        #region ILC4Serializable Members

        public void Read(LC4Formatter fmtr)
        {
            ushort version;
            fmtr.Read(out version);
            BaseRead(fmtr);
        }

        public void Write(LC4Formatter fmtr)
        {
            fmtr.Write((ushort)1);
            BaseWrite(fmtr);
        }

        #endregion
    }

    public class DetailsList : List<Detail>, ILC4Serializable
    {
        #region ILC4Serializable Members

        public void Read(LC4Formatter fmtr)
        {
            fmtr.GenericCollRead<DetailsList, Detail>(this);
        }

        public void Write(LC4Formatter fmtr)
        {
            fmtr.GenericCollWrite<DetailsList, Detail>(this);
        }

        #endregion
    }

    public class Remain : PlateBase, ILC4Serializable
    {
        #region ILC4Serializable Members

        public void Read(LC4Formatter fmtr)
        {
            ushort version;
            fmtr.Read(out version);
            BaseRead(fmtr);
        }

        public void Write(LC4Formatter fmtr)
        {
            fmtr.Write((ushort)1);
            BaseWrite(fmtr);
        }

        #endregion
    }

    public class RemainsList : List<Remain>, ILC4Serializable
    {
        #region ILC4Serializable Members

        public void Read(LC4Formatter fmtr)
        {
            fmtr.GenericCollRead<RemainsList, Remain>(this);
        }

        public void Write(LC4Formatter fmtr)
        {
            fmtr.GenericCollWrite<RemainsList, Remain>(this);
        }

        #endregion
    }

    public class Kante : ILC4Serializable
    {
        public string Code;
        public string Identifier;
        public string Material;
        public int FunctionCode;
        public LC4Numeric Allowance; // Zugabe
        public bool Maserung;
        public LC4Numeric Thickness;
        public bool KanteVorSchneidenAufgebracht;

        #region ILC4Serializable Members

        public void Read(LC4Formatter fmtr)
        {
            ushort prefix;
            fmtr.Read(out prefix);
            fmtr.Read(out Code);
            fmtr.Read(out Identifier);
            fmtr.Read(out Material);
            fmtr.Read(out Thickness);
            fmtr.Read(out Allowance);
            fmtr.Read(out FunctionCode);
            fmtr.Read(out Maserung);
            fmtr.Read(out KanteVorSchneidenAufgebracht);
        }

        public void Write(LC4Formatter fmtr)
        {
            fmtr.Write((ushort)1);
            fmtr.Write(Code);
            fmtr.Write(Identifier);
            fmtr.Write(Material);
            fmtr.Write(Thickness);
            fmtr.Write(Allowance);
            fmtr.Write(FunctionCode);
            fmtr.Write(Maserung);
            fmtr.Write(KanteVorSchneidenAufgebracht);
        }

        #endregion
    }

    public class KantesList : List<Kante>, ILC4Serializable
    {
        #region ILC4Serializable Members

        public void Read(LC4Formatter fmtr)
        {
            fmtr.GenericCollRead<KantesList, Kante>(this);
        }

        public void Write(LC4Formatter fmtr)
        {
            fmtr.GenericCollWrite<KantesList, Kante>(this);
        }

        #endregion
    }
}
