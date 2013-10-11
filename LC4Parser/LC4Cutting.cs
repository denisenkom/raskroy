using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.Xml.Serialization;

namespace Denisenko.Cutting.LC4
{
    public enum SizeType
    {
        Changeable = 0, // Aenderbar
        Flexible = 1, // Flexibel
        AutoMinimal = 2, // AutoMinimal
        Fixed = 3, // Fest
        Automatic = 4, // Automatisch
        Undefined = 5, // Undefined
    }

    public interface ILC4JobSerializable
    {
        void Read(LC4Formatter fmtr, Job job);
        void Write(LC4Formatter fmtr, Job job);
    }

    public interface ILC4Serializable
    {
        void Read(LC4Formatter fmtr);
        void Write(LC4Formatter fmtr);
    }

    public enum e_LagenRefList
    {
        Unknown = 0,
        DetailsList = 1,
        RemainsList = 2,
        SheetsList = 3,
        ReadiesList = 4,
        RawsList = 5,
    }

    public class Lage : ILC4JobSerializable
    {
        public int Amount; // Anzahl
        public bool Postforming; // Gedreht
        public string Quality; // Qualitaet
        public bool IsFinishPart;
        public PlateBase BaseDetail; // BasisTeil
        private int m_ref_idx;
        private e_LagenRefList m_ref_list;

        #region ILC4Serializable Members

        public void Read(LC4Formatter fmtr, Job job)
        {
            ushort version;
            fmtr.Read(out version);
            fmtr.Read(out Amount);
            fmtr.Read(out Postforming);
            fmtr.Read(out Quality);
            if (version > 1)
            {
                fmtr.Read(out IsFinishPart);
            }
            bool haveRefs;
            fmtr.Read(out haveRefs);
            if (haveRefs)
            {
                fmtr.Read(out m_ref_list);
                fmtr.Read(out m_ref_idx);
                switch (m_ref_list)
                {
                    case e_LagenRefList.DetailsList:
                        BaseDetail = job.Details[m_ref_idx];
                        break;
                    case e_LagenRefList.SheetsList:
                        BaseDetail = job.Sheets[m_ref_idx];
                        break;
                    case e_LagenRefList.RemainsList:
                        BaseDetail = job.Remains[m_ref_idx];
                        break;
                    default:
                        throw new LC4FormatException("Неизвестный тип списка " + m_ref_list);
                }
                return;
            }
            else
            {
                BaseDetail = null;
            }
        }

        public void Write(LC4Formatter fmtr, Job job)
        {
            fmtr.Write((ushort)2);
            fmtr.Write(Amount);
            fmtr.Write(Postforming);
            fmtr.Write(Quality);
            fmtr.Write(IsFinishPart);
            if (BaseDetail != null)
            {
                fmtr.Write(true);
                e_LagenRefList refType;
                int i;
                if (BaseDetail is Detail)
                {
                    i = job.Details.IndexOf((Detail)BaseDetail);
                    refType = e_LagenRefList.DetailsList;
                }
                else if (BaseDetail is Sheet)
                {
                    i = job.Sheets.IndexOf((Sheet)BaseDetail);
                    refType = e_LagenRefList.SheetsList;
                }
                else if (BaseDetail is Remain)
                {
                    i = job.Remains.IndexOf((Remain)BaseDetail);
                    refType = e_LagenRefList.RemainsList;
                }
                else
                {
                    throw new LC4FormatException("BaseDetail имеет неизвестный тип");
                }
                if (i == -1)
                {
                    throw new LC4FormatException("BaseDetail не найден в списке");
                }
                fmtr.Write(refType);
                fmtr.Write(i);
            }
            else
            {
                fmtr.Write(false);
            }
        }

        #endregion
    }

    public class LagenList : List<Lage>
    {
        public void Read(LC4Formatter fmtr, Job job)
        {
            fmtr.GenericCollRead<LagenList, Lage>(this, job);
        }

        public void Write(LC4Formatter fmtr, Job job)
        {
            fmtr.GenericCollWrite<LagenList, Lage>(this, job);
        }

        public int GetLayerAmount(bool isSavePanel)
        {
            int result = 0;
            if (isSavePanel)
            {
                foreach (Lage layer in this)
                {
                    result += layer.Amount;
                }
            }
            else
            {
                foreach (Lage layer in this)
                {
                    if ((layer.BaseDetail != null) && (!layer.BaseDetail.IsKeepSafe))
                    {
                        result += layer.Amount;
                    }
                }
            }
            return result;
        }
    }

    public struct PlanInformation
    {
        /*
         * Статистика раскроя
         */
        [XmlAttribute("scrapsSquare")]
        public double ScrapsSquare; // AbfallFlaeche

        [XmlAttribute("totalSquare")]
        public double TotalSquare; // PlattenFlaeche

        [XmlAttribute("remainsCount")]
        public int RemainsCount; // ResteAnzahl

        [XmlAttribute("remainsSquare")]
        public double RemainsSquare; // ResteFlaeche

        [XmlAttribute("dustSquare")]
        public double DustSquare; // SchnittFlaeche

        [XmlAttribute("detailsCount")]
        public int DetailsCount; // TeileAnzahl

        [XmlAttribute("detailsSquare")]
        public double DetailsSquare; // TeileFlaeche

        [XmlAttribute("scrapPercent")]
        public double ScrapPercent; // Verschnitt
    }

    public class Plan : Lane, ILC4JobSerializable
	{
        [XmlElement("information")]
        public PlanInformation Information;

		/*
		 * Размер стороны, перпендикулярно к которой идет первое пиление
		 */
		[XmlAttribute("length")]
		public LC4Numeric Length;

		[XmlElement("variable")]
        private VariablesList m_variables;

        [XmlAttribute("totalAmount")]
        public int TotalAmount; // ProdSollTotal

        [XmlAttribute("stackAmount")]
        public int StackAmount; // PaketAnzahl

        [XmlAttribute("materialGroup")]
        public string MaterialGroup;

        [XmlAttribute("measure")]
        public Measure Measure; // Masseinheit

        [XmlAttribute("nurVonVorneAbarbeiten")]
        public bool NurVonVorneAbarbeiten;

        [XmlAttribute("prodOriginalTotal")]
        public int ProdOriginalTotal;

        [XmlAttribute("optimized")]
        public bool Optimized;

		public Plan()
		{
            MaterialGroup = "";
            m_variables = null;
            Information.ScrapsSquare = 0;
            Information.TotalSquare = 0;
            Information.RemainsSquare = 0;
            Information.DetailsSquare = 0;
            Information.ScrapPercent = 0;
            Information.RemainsCount = 0;
            Information.DetailsCount = 0;
            NurVonVorneAbarbeiten = false;
            Optimized = false;
            TotalAmount = 0;
            ProdOriginalTotal = 0;
            StackAmount = 1;
        }

        #region ILC4Serializable Members

        public new void Read(LC4Formatter fmtr, Job job)
        {
            ushort version;
            fmtr.Read(out version);
            ReadLaneData(fmtr, job);
            fmtr.Read(out Length);
            fmtr.Read(out TotalAmount);
            fmtr.Read(out StackAmount);
            fmtr.Read(out MaterialGroup);
            fmtr.Read(out Measure);
            fmtr.Read(out NurVonVorneAbarbeiten);
            fmtr.Read(out m_variables);
            fmtr.Read(out ProdOriginalTotal);
            fmtr.Read(out Optimized);
            fmtr.Read(out Information.ScrapsSquare);
            fmtr.Read(out Information.TotalSquare);
            fmtr.Read(out Information.RemainsCount);
            fmtr.Read(out Information.RemainsSquare);
            fmtr.Read(out Information.DustSquare);
            fmtr.Read(out Information.DetailsCount);
            fmtr.Read(out Information.DetailsSquare);
            fmtr.Read(out Information.ScrapPercent);
        }

        public new void Write(LC4Formatter fmtr, Job job)
        {
            fmtr.Write((ushort)3);
            WriteLaneData(fmtr, job);
            fmtr.Write(Length);
            fmtr.Write(TotalAmount);
            fmtr.Write(StackAmount);
            fmtr.Write(MaterialGroup);
            fmtr.Write(Measure);
            fmtr.Write(NurVonVorneAbarbeiten);
            fmtr.Write(m_variables);
            fmtr.Write(ProdOriginalTotal);
            fmtr.Write(Optimized);
            fmtr.Write(Information.ScrapsSquare);
            fmtr.Write(Information.TotalSquare);
            fmtr.Write(Information.RemainsCount);
            fmtr.Write(Information.RemainsSquare);
            fmtr.Write(Information.DustSquare);
            fmtr.Write(Information.DetailsCount);
            fmtr.Write(Information.DetailsSquare);
            fmtr.Write(Information.ScrapPercent);
        }

        #endregion

        public VariablesList Variables
        {
            get
            {
                if (m_variables == null)
                {
                    m_variables = new VariablesList();
                }
                return m_variables;
            }
        }
    }

    public class PlansList : List<Plan>, ILC4JobSerializable
    {
        #region ILC4Serializable Members

        public void Read(LC4Formatter fmtr, Job job)
        {
            fmtr.GenericCollRead<PlansList, Plan>(this, job);
        }

        public void Write(LC4Formatter fmtr, Job job)
        {
            fmtr.GenericCollWrite<PlansList, Plan>(this, job);
        }

        #endregion
    }
}
