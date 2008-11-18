using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Xml;
using System.Xml.Serialization;

namespace Denisenko.Cutting.LC4
{
	public class Job : ILC4Serializable
	{
		[XmlAttribute("name")]
		public String Name;

		[XmlAttribute("remarks")]
		public String Remarks;

        [XmlElement("details")]
        private DetailsList m_details;

		[XmlElement("sheet")]
		private SheetsList m_sheets;

        [XmlElement("remains")]
        private RemainsList m_remains;

		[XmlElement("cutting")]
        private PlansList m_plans;

        [XmlAttribute("titelTeileListe")]
        public string TitelTeileListe;

        [XmlAttribute("titelPlattenListe")]
        public string TitelPlattenListe;

        [XmlElement("kantes")]
        private KantesList m_kantes;

		public void Serialize(String fileName)
		{
			using (XmlWriter textWriter = XmlWriter.Create(fileName))
			{
				XmlSerializer serializer = new XmlSerializer(typeof(Job));
				serializer.Serialize(textWriter, this);
			}
		}

		public Job()
		{
            m_plans = null;
            m_details = null;
            m_sheets = null;
            m_remains = null;
            m_kantes = null;
		}

        public void SaveLC4(string fileName, bool overWrite)
        {
            using (FileStream stm = new FileStream(fileName, overWrite ? FileMode.Create : FileMode.CreateNew))
            {
                LC4Formatter fmtr = new LC4Formatter(stm, Encoding.Default);
                fmtr.Write(this);
            }
        }

        public static Job LoadLC4(string fileName)
        {
            using (FileStream stm = new FileStream(fileName, FileMode.Open, FileAccess.Read, FileShare.Read))
            {
                LC4Formatter fmtr = new LC4Formatter(stm, Encoding.Default);
                Job doc;
                fmtr.Read(out doc);
                return doc;
            }
        }

        #region ILC4Serializable Members

        public void Read(LC4Formatter fmtr)
        {
            ushort version;
            fmtr.Read(out version);
            fmtr.Read(out Name);
            fmtr.Read(out Remarks);
            fmtr.Read(out m_details);
            fmtr.Read(out m_sheets);
            fmtr.Read(out m_remains);
            fmtr.Read(out m_plans, this);
            if (version >= 2)
            {
                fmtr.Read(out TitelTeileListe);
                fmtr.Read(out TitelPlattenListe);
            }
            if (version >= 3)
            {
                fmtr.Read(out m_kantes);
            }
        }

        public void Write(LC4Formatter fmtr)
        {
            fmtr.Write((ushort)3);
            fmtr.Write(Name);
            fmtr.Write(Remarks);
            fmtr.Write(m_details);
            fmtr.Write(m_sheets);
            fmtr.Write(m_remains);
            fmtr.Write(Plans, this);
            fmtr.Write(TitelTeileListe);
            fmtr.Write(TitelPlattenListe);
            fmtr.Write(m_kantes);
        }

        #endregion

        public PlansList Plans
        {
            get
            {
                if (m_plans == null)
                {
                    m_plans = new PlansList();
                }
                return m_plans;
            }
        }

        public SheetsList Sheets
        {
            get
            {
                if (m_sheets == null)
                {
                    m_sheets = new SheetsList();
                }
                return m_sheets;
            }
        }

        public DetailsList Details
        {
            get
            {
                if (m_details == null)
                {
                    m_details = new DetailsList();
                }
                return m_details;
            }
        }

        public RemainsList Remains
        {
            get
            {
                if (m_remains == null)
                {
                    m_remains = new RemainsList();
                }
                return m_remains;
            }
        }

        public KantesList Kantes
        {
            get
            {
                if (m_kantes == null)
                {
                    m_kantes = new KantesList();
                }
                return m_kantes;
            }
        }
    }
}
