using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace Denisenko.Cutting.LC4
{
	public class LC4Parser
	{
		private LC4Document m_document;
		private System.IO.FileStream m_fileStream;
		private static readonly Byte[] m_header =         { 1, 0, 1, 5, 0, 3, 0 };
		private static readonly Byte[] m_middlePad =      { 1, 0, 1, 5, 0, 1, 0 };
		private static readonly Byte[] m_sheetPreambule = { 1, 0, 1, 5, 0, 1, 0, 5, 0, 2, 0 };
		private static readonly Byte[] m_cuttingPreambule = { 1, 0, 1, 5, 0, 3, 0, 5, 0, 2, 0 };
		private static readonly Byte[] m_teil =      { 13, 0, 1, 0, 0, 13, 0, 1, 0, 0, 1, 0, 0 };
		private static readonly Byte[] m_stringPreambule = { 13, 0, 1, 0, 1, 14, 0 };
		private static readonly Byte[] m_int32Preambule = { 6, 0 };
		private static readonly Byte[] m_doublePreambule = { 11, 0 };
		private static readonly Byte[] m_numericPreambule = { 15, 0, 5, 0, 1, 0, 8, 0 };
		private static readonly Byte[] m_numericTeil = { 1, 0, 0 };

		private void LoadSheet()
		{
			LC4Sheet sheet = new LC4Sheet();
			Byte[] pad;
			pad = ReadBytes(11);
			sheet.SomeString1 = ReadString();
			sheet.SomeString2 = ReadString();
			sheet.SomeString3 = ReadString();
			sheet.Size1 = ReadNumeric();
			sheet.Size2 = ReadNumeric();
			sheet.Thickness = ReadNumeric();
			sheet.SomeInteger1 = ReadInt32();
			sheet.SomeInteger2 = ReadInt32();
			pad = ReadBytes(2);
			sheet.SomeInteger3 = ReadInt32();
			pad = ReadBytes(10);
			sheet.SomeInteger4 = ReadInt32();
			pad = ReadBytes(3);
			m_document.Sheets.Add(sheet);
		}

		private void SaveSheet(LC4Sheet sheet)
		{
			WriteBytes(m_sheetPreambule);
			WriteString(sheet.SomeString1);
			WriteString(sheet.SomeString2);
			WriteString(sheet.SomeString3);
			WriteNumeric(sheet.Size1);
			WriteNumeric(sheet.Size2);
			WriteNumeric(sheet.Thickness);
			WriteInt32(sheet.SomeInteger1);
			WriteInt32(sheet.SomeInteger2);
			WriteBytes(new Byte[] { 19, 0 });
			WriteInt32(sheet.SomeInteger3);
			WriteBytes(new Byte[] { 1, 0, 0 });
			WriteBytes(m_middlePad);
			WriteInt32(sheet.SomeInteger4);
			WriteBytes(new Byte[] { 1, 0, 1 }); // teil
		}

		private void LoadSection(List<LC4Section> parentCollection)
		{
			LC4Section operation = new LC4Section();

			Byte[] pad;
			pad = ReadBytes(7);

			operation.SectionType = (LC4SectionType)Enum.Parse(typeof(LC4SectionType), ReadString());
			operation.CopyString = ReadString();
			operation.Size = ReadNumeric();
			operation.SomeInteger1 = ReadInt32();
			pad = ReadBytes(2);
			ReadInt32(); // skip type code
			pad = ReadBytes(2);
			operation.SomeInteger2 = ReadInt32();
			pad = ReadBytes(4);
			operation.SomeInteger3 = ReadInt32();
			pad = ReadBytes(7);
			operation.SomeInteger4 = ReadInt32();

			pad = ReadBytes(7);
			Int32 subOperationsCount = ReadInt32();

			for (Int32 i = 0; i < subOperationsCount; i++)
				LoadSection(operation.NestedSections);

			pad = ReadBytes(3);

			parentCollection.Add(operation);
		}

		private void SaveSection(LC4Section section)
		{
			WriteBytes(new Byte[] { 1, 0, 1, 5, 0, 2, 0 });
			WriteString(section.SectionType.ToString());
			WriteString(section.CopyString);
			WriteNumeric(section.Size);
			WriteInt32(section.SomeInteger1);
			WriteBytes(new Byte[] { 17, 0 });
			WriteInt32((Int32)section.SectionType); // operation type
			WriteBytes(new Byte[] { 18, 0 });
			WriteInt32(section.SomeInteger2);
			WriteBytes(new Byte[] { 5, 0, 1, 0 });
			WriteInt32(section.SomeInteger3);
			WriteBytes(new Byte[] { 1, 0, 1, 5, 0, 1, 0 });
			WriteInt32(section.SomeInteger4);
			WriteBytes(new Byte[] { 1, 0, 1, 5, 0, 1, 0 });
			WriteInt32(section.NestedSections.Count);
			foreach (LC4Section nestedSection in section.NestedSections)
			{
				SaveSection(nestedSection);
			}
			WriteBytes(new Byte[] { 1, 0, 0 });
		}

		private LC4Variable LoadVariable()
		{
			LC4Variable result = new LC4Variable();

			Byte[] pad;
			pad = ReadBytes(7);
			result.Name = ReadString();
			result.Value = ReadString();
			pad = ReadBytes(3);

			return result;
		}

		private void SaveVariable(LC4Variable variable)
		{
			WriteBytes(new Byte[] { 1, 0, 1, 5, 0, 2, 0 });
			WriteString(variable.Name);
			WriteString(variable.Value);
			WriteBytes(new Byte[] { 1, 0, 0 });
		}

		private void LoadCutting()
		{
			LC4Cutting cutting = new LC4Cutting();

			Byte[] pad;
			pad = ReadBytes(11);
			cutting.Name = ReadString();
			cutting.SomeString1 = ReadString();
			cutting.Size1 = ReadNumeric();

			cutting.SomeInteger1 = ReadInt32();
			pad = ReadBytes(0x2);
			cutting.SomeInteger2 = ReadInt32();
			pad = ReadBytes(0x2);
			cutting.SomeInteger3 = ReadInt32();
			pad = ReadBytes(0x4);
			cutting.SomeInteger4 = ReadInt32();
			pad = ReadBytes(0x7);
			cutting.SomeInteger5 = ReadInt32();
			pad = ReadBytes(0x3);
			cutting.SomeString2 = ReadString();
			pad = ReadBytes(0x8);
			cutting.SomeInteger6 = ReadInt32();
			cutting.SheetIndex = ReadInt32();
			pad = ReadBytes(0x7);
			cutting.SomeInteger8 = ReadInt32();

			pad = ReadBytes(0x7);
			Int32 operationsCount = ReadInt32();

			for (Int32 i = 0; i < operationsCount; i++)
			{
				LoadSection(cutting.Sections);
			}
			pad = ReadBytes(0x3);

			cutting.Size2 = ReadNumeric();
			cutting.SomeInteger9 = ReadInt32();
			cutting.SomeInteger10 = ReadInt32();
			cutting.SomeString3 = ReadString();

			pad = ReadBytes(6);
			cutting.SomeInteger11 = ReadInt32();
			pad = ReadBytes(10);

			Int32 variablesCount = ReadInt32();
			for (Int32 i = 0; i < variablesCount; i++)
			{
				cutting.Variables.Add(LoadVariable());
			}

			m_document.Cuttings.Add(cutting);

			cutting.SomeInteger12 = ReadInt32();
			pad = ReadBytes(3);
			cutting.ScrapsSquare = ReadDouble();
			cutting.TotalSquare = ReadDouble();
			cutting.RemainsCount = ReadInt32();
			cutting.RemainsSquare = ReadDouble();
			cutting.DustSquare = ReadDouble();
			cutting.DetailsCount = ReadInt32();
			cutting.DetailsSquare = ReadDouble();
			cutting.ScrapPercent = ReadDouble();
		}

		private void SaveCutting(LC4Cutting cutting)
		{
			WriteBytes(m_cuttingPreambule);
			WriteString(cutting.Name);
			WriteString(cutting.SomeString1);
			WriteNumeric(cutting.Size1);
			WriteInt32(cutting.SomeInteger1);
			WriteBytes(new Byte[] { 17, 0 });
			WriteInt32(cutting.SomeInteger2);
			WriteBytes(new Byte[] { 18, 0 });
			WriteInt32(cutting.SomeInteger3);
			WriteBytes(new Byte[] { 5, 0, 1, 0 });
			WriteInt32(cutting.SomeInteger4);
			WriteBytes(new Byte[] { 1, 0, 1, 5, 0, 2, 0 });
			WriteInt32(cutting.SomeInteger5);
			WriteBytes(new Byte[] { 1, 0, 0 });
			WriteString(cutting.SomeString2);
			WriteBytes(new Byte[] { 1, 0, 0, 1, 0, 1, 20, 0 });
			WriteInt32(cutting.SomeInteger6);
			WriteInt32(cutting.SheetIndex);
			WriteBytes(new Byte[] { 1, 0, 1, 5, 0, 1, 0 });
			WriteInt32(cutting.SomeInteger8);
			WriteBytes(new Byte[] { 1, 0, 1, 5, 0, 1, 0 });
			WriteInt32(cutting.Sections.Count);
			foreach (LC4Section section in cutting.Sections)
			{
				SaveSection(section);
			}
			WriteBytes(new Byte[] { 1, 0, 0 });
			WriteNumeric(cutting.Size2);
			WriteInt32(cutting.SomeInteger9);
			WriteInt32(cutting.SomeInteger10);
			WriteString(cutting.SomeString3);
			WriteBytes(new Byte[] { 5, 0, 1, 0, 16, 0 });
			WriteInt32(cutting.SomeInteger11);
			WriteBytes(new Byte[] { 1, 0, 0, 1, 0, 1, 5, 0, 1, 0 });
			WriteInt32(cutting.Variables.Count);
			foreach (LC4Variable variable in cutting.Variables)
			{
				SaveVariable(variable);
			}
			WriteInt32(cutting.SomeInteger12);
			WriteBytes(new Byte[] { 1, 0, 0 });
			WriteDouble(cutting.ScrapsSquare);
			WriteDouble(cutting.TotalSquare);
			WriteInt32(cutting.RemainsCount);
			WriteDouble(cutting.RemainsSquare);
			WriteDouble(cutting.DustSquare);
			WriteInt32(cutting.DetailsCount);
			WriteDouble(cutting.DetailsSquare);
			WriteDouble(cutting.ScrapPercent);
		}

		public LC4Document Load(String fileName)
		{
			m_document = new LC4Document();
			m_fileStream = new FileStream(fileName, FileMode.Open);

			Byte[] pad;
			pad = ReadBytes(7);
			m_document.InternalName = ReadString();
			m_document.Description = ReadString();

			pad = ReadBytes(7);
			m_document.SomeInteger1 = ReadInt32();

			pad = ReadBytes(7);
			Int32 sheetsCount = ReadInt32();
			for (Int32 i = 0; i < sheetsCount; i++)
			{
				LoadSheet();
			}

			pad = ReadBytes(7);
			m_document.SomeInteger2 = ReadInt32();

			pad = ReadBytes(7);
			Int32 cutsCount = ReadInt32();
			for (Int32 i = 0; i < cutsCount; i++)
			{
				LoadCutting();
			}

			pad = ReadBytes(13);
			m_fileStream.Close();

			return m_document;
		}

		public void Save(String fileName, FileMode fileMode, LC4Document document)
		{
			m_document = document;
			m_fileStream = new FileStream(fileName, fileMode);
			WriteBytes(m_header);
			WriteString(m_document.InternalName);
			WriteString(m_document.Description);
			WriteBytes(m_middlePad);
			WriteInt32(m_document.SomeInteger1);
			WriteBytes(m_middlePad);
			WriteInt32(document.Sheets.Count); // sheets count
			foreach (LC4Sheet sheet in document.Sheets)
			{
				SaveSheet(sheet);
			}
			WriteBytes(m_middlePad);
			WriteInt32(m_document.SomeInteger2);
			WriteBytes(m_middlePad);
			WriteInt32(document.Cuttings.Count); // cuts count
			foreach (LC4Cutting cutting in document.Cuttings)
			{
				SaveCutting(cutting);
			}
			WriteBytes(m_teil);
			m_fileStream.Close();
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

		private Int32 ReadInt32()
		{
			Byte[] preambule = ReadBytes(2);
			if (!ArraysEqual(preambule, new Byte[] { 0x06, 0x00 }))
				throw new Exception("Error");
			Byte[] value = ReadBytes(4);
			return BitConverter.ToInt32(value, 0);
		}

		private void WriteInt32(Int32 value)
		{
			WriteBytes(m_int32Preambule);
			WriteBytes(BitConverter.GetBytes(value));
		}

		private String ReadString()
		{
			Byte[] preambule = ReadBytes(7);
			Int32 stringLength = ReadInt32();
			Byte[] value = ReadBytes(stringLength);
			return Encoding.ASCII.GetString(value);
		}

		private void WriteString(String value)
		{
			WriteBytes(m_stringPreambule);
			WriteInt32(value.Length);
			WriteBytes(Encoding.ASCII.GetBytes(value));
		}

		private LC4Numeric ReadNumeric()
		{
			Byte[] preambule = ReadBytes(8);
			Byte[] value = ReadBytes(8);
			Byte[] teil = ReadBytes(3);
			return LC4Numeric.FromScaled(BitConverter.ToInt64(value, 0));
		}

		private void WriteNumeric(LC4Numeric numeric)
		{
			WriteBytes(m_numericPreambule);
			WriteBytes(BitConverter.GetBytes(numeric.Scaled));
			WriteBytes(m_numericTeil);
		}

		private Double ReadDouble()
		{
			Byte[] preambule = ReadBytes(2);
			Byte[] data = ReadBytes(8);
			return BitConverter.ToDouble(data, 0);
		}

		private void WriteDouble(Double value)
		{
			WriteBytes(m_doublePreambule);
			WriteBytes(BitConverter.GetBytes(value));
		}

		private Byte[] ReadBytes(Int32 count)
		{
			Byte[] result = new Byte[count];
			m_fileStream.Read(result, 0, count);
			return result;
		}

		private void WriteBytes(Byte[] array)
		{
			m_fileStream.Write(array, 0, array.Length);
		}
	}
}
