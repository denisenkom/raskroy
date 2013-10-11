using System;
using System.Collections.Generic;
using System.Text;
using System.Xml.Serialization;

namespace Denisenko.Cutting.LC4
{
	public enum LaneType {
		None = 0,
        Plate = 1, // Platte
		Cut = 2, // Schnitt
		Lane = 3, // Streifen
		Cutoff = 4, // Aunschnitt
		Scrap = 5, // Abfall
        StressElimination1 = 6, // Spannungsfreischnitt1
        StressElimination2 = 7, // Spannungsfreischnitt2
        StressElimination3 = 8, // Spannungsfreischnitt3
        Pack = 9, // Verpackungsstreifen
		Rest = 10, // 
		Detail = 11, // Teil
        ClearDetail = 12, // FertigTeil
        RawDetail = 13, // RohTeil
    }

	public class Lane : List<Lane>, ILC4JobSerializable
	{
        [XmlAttribute("name")]
        public string Name;

		[XmlAttribute("copyString")]
        public string Remarks;

        [XmlAttribute("laneType")]
        public LaneType LaneType;

        [XmlAttribute("size")]
        public LC4Numeric Size;

		[XmlAttribute("copies")]
		public int Copies;

		[XmlAttribute("sizeType")]
        public SizeType SizeType;

        [XmlAttribute("isCopy")]
        public bool IsCopy;

        [XmlElement("lagen")]
        private LagenList m_lagen;

        [XmlElement("zusatzSchnitte")]
        private CutInfoList m_zusatzSchnitte;

		public Lane()
		{
            Name = string.Empty;
            Remarks = string.Empty;
            m_lagen = new LagenList();
            m_zusatzSchnitte = new CutInfoList();
            IsCopy = false;
            Copies = 1;
		}

        protected void ReadLaneData(LC4Formatter fmtr, Job job)
        {
            ushort version;
            fmtr.Read(out version);
            fmtr.Read(out Name);
            fmtr.Read(out Remarks);
            fmtr.Read(out Size);
            fmtr.Read(out Copies);
            fmtr.Read(out LaneType);
            fmtr.Read(out SizeType);
            m_lagen.Read(fmtr, job);
            fmtr.Read(out m_zusatzSchnitte);
            LanesList lanesList;
            fmtr.Read(out lanesList, job);
            Clear();
            foreach (Lane lane in lanesList)
            {
                Add(lane);
            }
            if (version >= 2)
            {
                fmtr.Read(out IsCopy);
            }
        }

        protected void WriteLaneData(LC4Formatter fmtr, Job job)
        {
            fmtr.Write((ushort)2);
            fmtr.Write(Name);
            fmtr.Write(Remarks);
            fmtr.Write(Size);
            fmtr.Write(Copies);
            fmtr.Write(LaneType);
            fmtr.Write(SizeType);
            m_lagen.Write(fmtr, job);
            fmtr.Write(m_zusatzSchnitte);
            fmtr.Write((LanesList)this, job);
            fmtr.Write(IsCopy);
        }

        #region ILC4Serializable Members

        public void Read(LC4Formatter fmtr, Job job)
        {
            ReadLaneData(fmtr, job);
        }

        public void Write(LC4Formatter fmtr, Job job)
        {
            WriteLaneData(fmtr, job);
        }

        #endregion

        public static explicit operator LanesList(Lane rhs)
        {
            return new LanesList(rhs);
        }

        public LagenList Lagen
        {
            get { return m_lagen; }
        }

        public CutInfoList ZusatzSchnitte
        {
            get { return m_zusatzSchnitte; }
        }
    }

    public class LanesList : List<Lane>, ILC4JobSerializable
    {
        public LanesList()
        {
        }

        public LanesList(ICollection<Lane> lanes)
            : base(lanes)
        {
        }

        #region ILC4Serializable Members

        public void Read(LC4Formatter fmtr, Job job)
        {
            fmtr.GenericCollRead<LanesList, Lane>(this, job);
        }

        public void Write(LC4Formatter fmtr, Job job)
        {
            fmtr.GenericCollWrite<LanesList, Lane>(this, job);
        }

        #endregion
    }
}
