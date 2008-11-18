using System;
using System.Collections.Generic;
using System.Text;
using System.Xml.Serialization;

namespace Denisenko.Cutting.LC4
{
	public class LC4Variable : ILC4Serializable
	{
		[XmlAttribute("name")]
        public string Name;

		[XmlAttribute("value")]
        public string Value;

        [XmlAttribute("isValueChanged")]
        public bool IsValueChanged;

        public LC4Variable()
        {
        }

        public LC4Variable(string name, string value)
        {
            Name = name;
            Value = value;
            IsValueChanged = false;
        }

        #region ILC4Serializable Members

        public void Read(LC4Formatter fmtr)
        {
            ushort version;
            fmtr.Read(out version);
            fmtr.Read(out Name);
            fmtr.Read(out Value);
            fmtr.Read(out IsValueChanged);
        }

        public void Write(LC4Formatter fmtr)
        {
            fmtr.Write((ushort)2);
            fmtr.Write(Name);
            fmtr.Write(Value);
            fmtr.Write(IsValueChanged);
        }

        #endregion
    }

    public class VariablesList : List<LC4Variable>, ILC4Serializable
    {
        #region ILC4Serializable Members

        public void Read(LC4Formatter fmtr)
        {
            fmtr.GenericCollRead<VariablesList, LC4Variable>(this);
        }

        public void Write(LC4Formatter fmtr)
        {
            fmtr.GenericCollWrite<VariablesList, LC4Variable>(this);
        }

        #endregion
    }
}
