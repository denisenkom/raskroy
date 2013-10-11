using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace Denisenko.Cutting.LC4
{
    public class LC4FormatException : ApplicationException
    {
        public LC4FormatException(string message)
            : base(message)
        {
        }
    }

    internal class Utils
    {
        public static bool ArraysEqual(Byte[] array1, Byte[] array2)
        {
            if (array1.Length != array2.Length)
                return false;
            for (Int32 i = 0; i < array1.Length; i++)
                if (array1[i] != array2[i])
                    return false;
            return true;
        }
    }

    internal enum DataType
    {
        None = 0,
        Boolean = 1,
        Byte = 2,
        SByte = 3,
        Short = 4,
        UShort = 5,
        Int = 6,
        UInt = 7,
        Long = 8,
        ULong = 9,
        Float = 10,
        Double = 11,
        Char = 12,
        String = 13,
        Char_Array = 14,
        LC4Numeric = 15,
        e_HOUnit = 16,
        SectionType = 17,
        SizeType = 18,
        TextureDirection = 19,
        e_LagenRefList = 20,
        e_DistancedReference = 21,
        e_CalculationType = 22,
        e_SinglePartWorkMode = 23,
        e_SinglePartCalcMode = 24,
        e_EdgeReference = 25,
        e_CutReference = 26,
        e_DepthReference = 27,
        e_VertexReference = 28,
        c_CutInfoDescription = 29,
        c_GrooveDescription = 30,
        c_SingleGroove = 31,
        c_DistancedGroove = 32,
        c_FilledGroove = 33,
        c_CutOutDescription = 34,
        c_SinglePartArrayDescription = 35,
        c_AngularCutDescription = 36,
    }

    public class Rectangle
    {
        public LC4Numeric X;
        public LC4Numeric Y;
        public LC4Numeric Height;
        public LC4Numeric Width;
    }

    public class LC4Formatter
    {
        private Stream m_stm;
        private Encoding m_encoding;

        public LC4Formatter(Stream stm, Encoding encoding)
        {
            m_stm = stm;
            m_encoding = encoding;
        }

        private Byte[] ReadBytes(Int32 count)
        {
            Byte[] result = new Byte[count];
            if (m_stm.Read(result, 0, count) != count)
            {
                throw new LC4FormatException("Неожиданный конец файла");
            }
            return result;
        }

        private void WriteBytes(Byte[] array)
        {
            m_stm.Write(array, 0, array.Length);
        }

        private void Write(DataType type)
        {
            ushort shType = (ushort)type;
            m_stm.WriteByte((byte)shType);
            m_stm.WriteByte((byte)(shType >> 8));
        }

        private void Read(out DataType type)
        {
            byte[] buffer = ReadBytes(2);
            type = (DataType)BitConverter.ToUInt16(buffer, 0);
        }

        private void ReadTypeCheck(DataType expected)
        {
            DataType type;
            Read(out type);
            if (expected != type)
            {
                throw new LC4FormatException("Неожиданный тип данных");
            }
        }

        public void Read(out bool value)
        {
            ReadTypeCheck(DataType.Boolean);
            value = BitConverter.ToBoolean(ReadBytes(1), 0);
        }

        public void Write(bool val)
        {
            Write(DataType.Boolean);
            WriteBytes(BitConverter.GetBytes(val));
        }

        public void Read(out byte value)
        {
            ReadTypeCheck(DataType.Byte);
            value = ReadBytes(1)[0];
        }

        public void Write(byte val)
        {
            Write(DataType.Byte);
            m_stm.WriteByte(val);
        }

        public void Read(out ushort value)
        {
            ReadTypeCheck(DataType.UShort);
            value = BitConverter.ToUInt16(ReadBytes(2), 0);
        }

        public void Write(ushort val)
        {
            Write(DataType.UShort);
            WriteBytes(BitConverter.GetBytes(val));
        }

        public void Read(out int value)
        {
            ReadTypeCheck(DataType.Int);
            value = BitConverter.ToInt32(ReadBytes(4), 0);
        }

        public void Write(int value)
        {
            Write(DataType.Int);
            WriteBytes(BitConverter.GetBytes(value));
        }

        public void Read(out long value)
        {
            ReadTypeCheck(DataType.Long);
            value = BitConverter.ToInt64(ReadBytes(8), 0);
        }

        public void Write(long value)
        {
            Write(DataType.Long);
            WriteBytes(BitConverter.GetBytes(value));
        }

        public void Read(out double value)
        {
            ReadTypeCheck(DataType.Double);
            Byte[] data = ReadBytes(8);
            value = BitConverter.ToDouble(data, 0);
        }

        public void Write(double value)
        {
            Write(DataType.Double);
            WriteBytes(BitConverter.GetBytes(value));
        }

        public void Read(out string value)
        {
            ReadTypeCheck(DataType.String);
            bool isNotNull;
            Read(out isNotNull);
            if (isNotNull)
            {
                ReadTypeCheck(DataType.Char_Array);
                Int32 stringLength;
                Read(out stringLength);
                Byte[] bytes = ReadBytes(stringLength);
                value = m_encoding.GetString(bytes);
            }
            else
            {
                value = null;
            }
        }

        public void Write(string value)
        {
            Write(DataType.String);
            if (value != null)
            {
                Write(true);
                Write(DataType.Char_Array);
                Write(value.Length);
                WriteBytes(m_encoding.GetBytes(value));
            }
            else
            {
                Write(false);
            }
        }

        public void Read(out e_HOUnit unit)
        {
            ReadTypeCheck(DataType.e_HOUnit);
            int value;
            Read(out value);
            unit = (e_HOUnit)value;
        }

        public void Write(e_HOUnit unit)
        {
            Write(DataType.e_HOUnit);
            Write((int)unit);
        }

        public void Read(out GrooveDescription.EdgeReference edge)
        {
            ReadTypeCheck(DataType.e_EdgeReference);
            int value;
            Read(out value);
            edge = (GrooveDescription.EdgeReference)value;
        }

        public void Write(GrooveDescription.EdgeReference value)
        {
            Write(DataType.e_EdgeReference);
            Write((int)value);
        }

        public void Read(out GrooveDescription.CutReference cut)
        {
            ReadTypeCheck(DataType.e_CutReference);
            int value;
            Read(out value);
            cut = (GrooveDescription.CutReference)value;
        }

        public void Write(GrooveDescription.CutReference value)
        {
            Write(DataType.e_CutReference);
            Write((int)value);
        }

        public void Read(out GrooveDescription.DepthReference depth)
        {
            ReadTypeCheck(DataType.e_DepthReference);
            int value;
            Read(out value);
            depth = (GrooveDescription.DepthReference)value;
        }

        public void Write(GrooveDescription.DepthReference value)
        {
            Write(DataType.e_DepthReference);
            Write((int)value);
        }

        public void Read(out GrooveDescription.DistanceReference distance)
        {
            ReadTypeCheck(DataType.e_DistancedReference);
            int value;
            Read(out value);
            distance = (GrooveDescription.DistanceReference)value;
        }

        public void Write(GrooveDescription.DistanceReference value)
        {
            Write(DataType.e_DistancedReference);
            Write((int)value);
        }

        public void Read(out GrooveDescription.CalculationType type)
        {
            ReadTypeCheck(DataType.e_CalculationType);
            int value;
            Read(out value);
            type = (GrooveDescription.CalculationType)value;
        }

        public void Write(GrooveDescription.CalculationType value)
        {
            Write(DataType.e_CalculationType);
            Write((int)value);
        }

        public void Read(out GrooveDescription.VertexReference vert)
        {
            ReadTypeCheck(DataType.e_VertexReference);
            int value;
            Read(out value);
            vert = (GrooveDescription.VertexReference)value;
        }

        public void Write(GrooveDescription.VertexReference value)
        {
            Write(DataType.e_VertexReference);
            Write((int)value);
        }

        public void Read(out GrooveDescription.SinglePartWorkMode type)
        {
            ReadTypeCheck(DataType.e_SinglePartWorkMode);
            int value;
            Read(out value);
            type = (GrooveDescription.SinglePartWorkMode)value;
        }

        public void Write(GrooveDescription.SinglePartWorkMode value)
        {
            Write(DataType.e_SinglePartWorkMode);
            Write((int)value);
        }

        public void Read(out Measure measure)
        {
            measure = new Measure();
            measure.Read(this);
        }

        public void Write(Measure measure)
        {
            measure.Write(this);
        }

        public void Write(ILC4Serializable obj)
        {
            if (obj != null)
            {
                Write(true);
                obj.Write(this);
            }
            else
            {
                Write(false);
            }
        }

        public void Write(ILC4JobSerializable obj, Job job)
        {
            if (obj != null)
            {
                Write(true);
                obj.Write(this, job);
            }
            else
            {
                Write(false);
            }
        }

        public void Read(out LC4Numeric value)
        {
            ReadTypeCheck(DataType.LC4Numeric);
            value = new LC4Numeric();
            value.Read(this);
        }

        public void Write(LC4Numeric numeric)
        {
            Write(DataType.LC4Numeric);
            numeric.Write(this);
        }

        public void Read(out LaneType sectionType)
        {
            ReadTypeCheck(DataType.SectionType);
            int sectionTypeInt;
            Read(out sectionTypeInt);
            sectionType = (LaneType)sectionTypeInt;
        }

        public void Write(LaneType type)
        {
            Write(DataType.SectionType);
            Write((int)type);
        }

        public void Read(out e_LagenRefList lagenRefList)
        {
            ReadTypeCheck(DataType.e_LagenRefList);
            int sectionTypeInt;
            Read(out sectionTypeInt);
            lagenRefList = (e_LagenRefList)sectionTypeInt;
        }

        public void Write(e_LagenRefList lagenRefList)
        {
            Write(DataType.e_LagenRefList);
            Write((int)lagenRefList);
        }

        public void Read(out SizeType sizeType)
        {
            ReadTypeCheck(DataType.SizeType);
            int sizeTypeInt;
            Read(out sizeTypeInt);
            sizeType = (SizeType)sizeTypeInt;
        }

        public void Write(SizeType type)
        {
            Write(DataType.SizeType);
            Write((int)type);
        }

        public void Write(TextureDirection dir)
        {
            Write(DataType.TextureDirection);
            Write((int)dir);
        }

        public void Read(out TextureDirection dir)
        {
            ReadTypeCheck(DataType.TextureDirection);
            int val;
            Read(out val);
            dir = (TextureDirection)val;
        }

        public void Read<T>(out T value)
            where T : ILC4Serializable, new()
        {
            bool exists;
            Read(out exists);
            if (exists)
            {
                value = new T();
                value.Read(this);
                return;
            }
            value = default(T);
        }

        public void Read<T>(out T value, Job job)
            where T : ILC4JobSerializable, new()
        {
            bool exists;
            Read(out exists);
            if (exists)
            {
                value = new T();
                value.Read(this, job);
                return;
            }
            value = default(T);
        }

        public void GenericCollRead<CollType, ItemType>(CollType coll)
            where CollType : ICollection<ItemType>
            where ItemType : ILC4Serializable, new()
        {
            coll.Clear();
            ushort version;
            Read(out version);
            int count;
            Read(out count);
            for (int i = 0; i < count; i++)
            {
                ItemType item;
                Read(out item);
                coll.Add(item);
            }
        }

        public void GenericCollWrite<CollType, ItemType>(CollType coll)
            where CollType : ICollection<ItemType>
            where ItemType : ILC4Serializable, new()
        {
            Write((ushort)1);
            Write(coll.Count);
            foreach (ItemType item in coll)
            {
                Write(item);
            }
        }

        public void GenericCollRead<CollType, ItemType>(CollType coll, Job job)
            where CollType : ICollection<ItemType>
            where ItemType : ILC4JobSerializable, new()
        {
            coll.Clear();
            ushort version;
            Read(out version);
            int count;
            Read(out count);
            for (int i = 0; i < count; i++)
            {
                ItemType item;
                Read(out item, job);
                coll.Add(item);
            }
        }

        public void GenericCollWrite<CollType, ItemType>(CollType coll, Job job)
            where CollType : ICollection<ItemType>
            where ItemType : ILC4JobSerializable, new()
        {
            Write((ushort)1);
            Write(coll.Count);
            foreach (ItemType item in coll)
            {
                Write(item, job);
            }
        }

        public void Read(out CutInfoDescription cid)
        {
            bool exists;
            Read(out exists);
            if (!exists)
            {
                cid = null;
                return;
            }
            DataType dataType;
            Read(out dataType);
            switch (dataType)
            {
                case DataType.c_CutInfoDescription:
                    cid = new CutInfoDescription();
                    break;

                case DataType.c_GrooveDescription:
                    cid = new GrooveDescription();
                    break;

                case DataType.c_SingleGroove:
                    cid = new SingleGroove();
                    break;

                case DataType.c_DistancedGroove:
                    cid = new DistancedGroove();
                    break;

                case DataType.c_FilledGroove:
                    cid = new FilledGroove();
                    break;

                case DataType.c_CutOutDescription:
                    cid = new CutOutDescription();
                    break;

                case DataType.c_SinglePartArrayDescription:
                    cid = new SinglePartArrayDescription();
                    break;

                case DataType.c_AngularCutDescription:
                    cid = new AngularCutDescription();
                    break;

                default:
                    throw new ApplicationException("Unknown CutInfoDescription");
            }
            cid.Read(this);
        }

        public void Write(CutInfoDescription cid)
        {
            if (cid == null)
            {
                Write(false);
                return;
            }
            Write(true);
            if (cid is GrooveDescription)
            {
                Write(DataType.c_GrooveDescription);
            }
            else if (cid is SingleGroove)
            {
                Write(DataType.c_SingleGroove);
            }
            else if (cid is DistancedGroove)
            {
                Write(DataType.c_DistancedGroove);
            }
            else if (cid is FilledGroove)
            {
                Write(DataType.c_FilledGroove);
            }
            else if (cid is CutOutDescription)
            {
                Write(DataType.c_CutOutDescription);
            }
            else if (cid is SinglePartArrayDescription)
            {
                Write(DataType.c_SinglePartArrayDescription);
            }
            else if (cid is AngularCutDescription)
            {
                Write(DataType.c_AngularCutDescription);
            }
            else if (cid is CutInfoDescription)
            {
                Write(DataType.c_CutInfoDescription);
            }
            cid.Write(this);
        }
    }
}
