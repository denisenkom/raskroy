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
			LC4Sheet sheet = m_document.CreateSheet();
			Byte[] pad;
			pad = ReadBytes(11);
			String someString1 = ReadString();
			String someString2 = ReadString();
			String someString3 = ReadString();
			sheet.Size1 = ReadNumeric();
			sheet.Size2 = ReadNumeric();
			sheet.Thickness = ReadNumeric();
			Int32 someInteger1 = ReadInt32();
			Int32 someInteger2 = ReadInt32();
			pad = ReadBytes(2);
			Int32 someInteger3 = ReadInt32();
			pad = ReadBytes(10);
			Int32 someInteger4 = ReadInt32();
			pad = ReadBytes(3);
			m_document.Sheets.Add(sheet);
		}

		private void SaveSheet(LC4Sheet sheet)
		{
			WriteBytes(m_sheetPreambule);
			WriteString("");
			WriteString("");
			WriteString("");
			WriteNumeric(sheet.Size1);
			WriteNumeric(sheet.Size2);
			WriteNumeric(sheet.Thickness);
			WriteInt32(1); // some integer 1
			WriteInt32(0); // some integer 2
			WriteBytes(new Byte[] { 19, 0 });
			WriteInt32(0); // some integer 3
			WriteBytes(new Byte[] { 1, 0, 0 });
			WriteBytes(m_middlePad);
			WriteInt32(0); // some integer 4
			WriteBytes(new Byte[] { 1, 0, 1 }); // teil
		}

		private LC4SectionType TypeFromString(String sectionType)
		{
			switch (sectionType)
			{
				case "Anschnitt":
					return LC4SectionType.Scrap;
				case "Schnitt":
					return LC4SectionType.Cut;
				case "Teil":
					return LC4SectionType.Detail;
				case "Rest":
					return LC4SectionType.Remain;
				case "Streifen":
					return LC4SectionType.NewLine;
				default:
					throw new ArgumentOutOfRangeException("sectionType", sectionType, "Invalid value");
			}
		}

		private String StringFromType(LC4SectionType sectionType)
		{
			switch (sectionType)
			{
				case LC4SectionType.Scrap:
					return "Anschnitt";
				case LC4SectionType.Cut:
					return "Schnitt";
				case LC4SectionType.Detail:
					return "Teil";
				case LC4SectionType.Remain:
					return "Rest";
				case LC4SectionType.NewLine:
					return "Streifen";
				default:
					throw new ArgumentOutOfRangeException("sectionType", sectionType, "Invalid value");
			}
		}

		private void LoadSection(LC4SectionsCollection parentCollection)
		{
			LC4Section operation = m_document.CreateSection();

			Byte[] pad;
			pad = ReadBytes(7);

			operation.SectionType = TypeFromString(ReadString());
			String copyString = ReadString();
			operation.Size = ReadNumeric();
			Int32 someInteger1 = ReadInt32();
			pad = ReadBytes(2);
			Int32 operationTypeCode = ReadInt32();
			pad = ReadBytes(2);
			Int32 someNumber2 = ReadInt32();
			pad = ReadBytes(4);
			Int32 someNumber3 = ReadInt32();
			pad = ReadBytes(7);
			Int32 someNumber4 = ReadInt32();

			pad = ReadBytes(7);
			Int32 subOperationsCount = ReadInt32();

			for (Int32 i = 0; i < subOperationsCount; i++)
				LoadSection(operation);

			pad = ReadBytes(3);

			parentCollection.Add(operation);
		}

		private void SaveSection(LC4Section section)
		{
			WriteBytes(new Byte[] { 1, 0, 1, 5, 0, 2, 0 });
			WriteString(StringFromType(section.SectionType));
			WriteString("");
			WriteNumeric(section.Size);
			WriteInt32(0);
			WriteBytes(new Byte[] { 17, 0 });
			WriteInt32(0); // operation type
			WriteBytes(new Byte[] { 18, 0 });
			WriteInt32(0);
			WriteBytes(new Byte[] { 5, 0, 1, 0 });
			WriteInt32(0);
			WriteBytes(new Byte[] { 1, 0, 1, 5, 0, 1, 0 });
			WriteInt32(0);
			WriteBytes(new Byte[] { 1, 0, 1, 5, 0, 1, 0 });
			WriteInt32(section.Count);
			foreach (LC4Section nestedSection in section)
			{
				SaveSection(nestedSection);
			}
			WriteBytes(new Byte[] { 1, 0, 1 });
		}

		private LC4Variable LoadVariable()
		{
			LC4Variable result = m_document.CreateVariable();

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

		private void LoadCut()
		{
			LC4Cutting cutting = m_document.CreateCutting();

			Byte[] pad;
			pad = ReadBytes(11);
			cutting.Name = ReadString();
			String someString1 = ReadString();
			cutting.Size1 = ReadNumeric();

			Int32 someInt = ReadInt32();
			pad = ReadBytes(0x2);
			Int32 someInt2 = ReadInt32();
			pad = ReadBytes(0x2);
			Int32 someInt3 = ReadInt32();
			pad = ReadBytes(0x4);
			Int32 someInt4 = ReadInt32();
			pad = ReadBytes(0x7);
			Int32 someInt5 = ReadInt32();
			pad = ReadBytes(0x3);
			String someString2 = ReadString();
			pad = ReadBytes(0x8);
			Int32 someInt6 = ReadInt32();
			Int32 someInt7 = ReadInt32();
			pad = ReadBytes(0x7);
			Int32 someInt8 = ReadInt32();

			pad = ReadBytes(0x7);
			Int32 operationsCount = ReadInt32();

			for (Int32 i = 0; i < operationsCount; i++)
				LoadSection(cutting);
			pad = ReadBytes(0x3);

			cutting.Size2 = ReadNumeric();
			Int32 someInt9 = ReadInt32();
			Int32 someInt10 = ReadInt32();
			String someString3 = ReadString();

			pad = ReadBytes(6);
			Int32 someInt11 = ReadInt32();
			pad = ReadBytes(10);

			Int32 variablesCount = ReadInt32();
			if (variablesCount > 0)
			{
				LC4VariablesCollection variables = m_document.CreateVariablesCollection();
				for (Int32 i = 0; i < variablesCount; i++)
					variables.Add(LoadVariable());
				cutting.Variables = variables;
			}

			m_document.Cuttings.Add(cutting);

			Int32 someInt12 = ReadInt32();
			pad = ReadBytes(3);
			Double someDouble1 = ReadDouble();
			Double someDouble2 = ReadDouble();
			Int32 someInt13 = ReadInt32();
			Double someDouble3 = ReadDouble();
			Double someDouble4 = ReadDouble();
			Int32 someInt14 = ReadInt32();
			Double someDouble5 = ReadDouble();
			Double someDouble6 = ReadDouble();
		}

		private void SaveCutting(LC4Cutting cutting)
		{
			WriteBytes(m_cuttingPreambule);
			WriteString(cutting.Name);
			WriteString("");
			WriteNumeric(cutting.Size1);
			WriteInt32(1);
			WriteBytes(new Byte[] { 17, 0 });
			WriteInt32(1);
			WriteBytes(new Byte[] { 18, 0 });
			WriteInt32(1);
			WriteBytes(new Byte[] { 5, 0, 1, 0 });
			WriteInt32(1);
			WriteBytes(new Byte[] { 1, 0, 1, 5, 0, 2, 0 });
			WriteInt32(0);
			WriteBytes(new Byte[] { 1, 0, 0 });
			WriteString("");
			WriteBytes(new Byte[] { 1, 0, 0, 1, 0, 1, 20, 0 });
			WriteInt32(3);
			WriteInt32(0);
			WriteBytes(new Byte[] { 1, 0, 1, 5, 0, 1, 0 });
			WriteInt32(0);
			WriteBytes(new Byte[] { 1, 0, 1, 5, 0, 1, 0 });
			WriteInt32(cutting.Count);
			foreach (LC4Section section in cutting)
			{
				SaveSection(section);
			}
			WriteBytes(new Byte[] { 1, 0, 0 });
			WriteNumeric(cutting.Size2);
			WriteInt32(32);
			WriteInt32(4);
			WriteString("");
			WriteBytes(new Byte[] { 5, 0, 1, 0, 16, 0 });
			WriteInt32(0);
			WriteBytes(new Byte[] { 1, 0, 0, 1, 0, 1, 5, 0, 1, 0 });
			WriteInt32(cutting.Variables.Count);
			foreach (LC4Variable variable in cutting.Variables)
			{
				SaveVariable(variable);
			}
			WriteInt32(0);
			WriteBytes(new Byte[] { 1, 0, 0 });
			WriteDouble(0.0);
			WriteDouble(0.0);
			WriteInt32(0);
			WriteDouble(0.0);
			WriteDouble(0.0);
			WriteInt32(0);
			WriteDouble(0.0);
			WriteDouble(0.0);
		}

		public LC4Document Load(String fileName)
		{
			m_document = new LC4Document();
			m_fileStream = new FileStream(fileName, FileMode.Open);

			Byte[] pad;
			pad = ReadBytes(7);
			m_document.InternalName = ReadString();
			m_document.Generator = ReadString();

			pad = ReadBytes(7);
			Int32 someInteger1 = ReadInt32();

			pad = ReadBytes(7);
			Int32 sheetsCount = ReadInt32();
			for (Int32 i = 0; i < sheetsCount; i++)
				LoadSheet();

			pad = ReadBytes(7);
			Int32 someInteger2 = ReadInt32();

			pad = ReadBytes(7);
			Int32 cutsCount = ReadInt32();
			for (Int32 i = 0; i < cutsCount; i++)
				LoadCut();

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
			WriteString(m_document.Generator);
			WriteBytes(m_middlePad);
			WriteInt32(0); // some integer 1
			WriteBytes(m_middlePad);
			WriteInt32(document.Sheets.Count); // sheets count
			foreach (LC4Sheet sheet in document.Sheets)
			{
				SaveSheet(sheet);
			}
			WriteBytes(m_middlePad);
			WriteInt32(0); // some integer 1
			WriteBytes(m_middlePad);
			WriteInt32(document.Sheets.Count); // cuts count
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
