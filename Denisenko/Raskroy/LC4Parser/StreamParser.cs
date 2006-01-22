using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Denisenko.Cutting.LC4
{
	public class StreamParser
	{
		private System.IO.FileStream m_fileStream;

		public StreamParser(String fileName)
		{
			m_fileStream = new FileStream(fileName, FileMode.Open);
		}

		private bool ArraysEqual(Byte[] array1, Byte[] array2)
		{
			if(array1.Length != array2.Length)
				return false;
			for (Int32 i = 0; i < array1.Length; i++)
				if (array1[i] != array2[i])
					return false;
			return true;
		}

		public Int32 ParseInt32()
		{
			Byte[] preambule = ReadBytes(2);
			if (!ArraysEqual(preambule, new Byte[] { 0x06, 0x00 }))
				throw new Exception("Error");
			Byte[] value = ReadBytes(4);
			return BitConverter.ToInt32(value, 0);
		}

		public String ParseString()
		{
			Byte[] preambule = ReadBytes(7);
			Int32 stringLength = ParseInt32();
			Byte[] value = ReadBytes(stringLength);
			return Encoding.ASCII.GetString(value);
		}

		public LC4Numeric ParseNumeric()
		{
			Byte[] preambule = ReadBytes(8);
			Byte[] value = ReadBytes(8);
			Byte[] teil = ReadBytes(3);
			return LC4Numeric.FromScaled(BitConverter.ToInt64(value, 0));
		}

		public double ParseDouble()
		{
			Byte[] preambule = ReadBytes(2);
			Byte[] data = ReadBytes(8);
			return BitConverter.ToDouble(data, 0);
		}

		public Byte[] ReadBytes(Int32 count)
		{
			Byte[] result = new Byte[count];
			m_fileStream.Read(result, 0, count);
			return result;
		}
	}
}
