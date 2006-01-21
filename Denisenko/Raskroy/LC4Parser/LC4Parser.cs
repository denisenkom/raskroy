using System;
using System.Collections.Generic;
using System.Text;

namespace Denisenko.LC4Parser
{
	public class LC4Parser
	{
		StreamParser m_streamParser;
		LC4Document m_document;

		private void ParseSheet()
		{
			LC4Sheet sheet = m_document.CreateSheet();
			Byte[] pad;
			pad = m_streamParser.ReadBytes(11);
			String someString1 = m_streamParser.ParseString();
			String someString2 = m_streamParser.ParseString();
			String someString3 = m_streamParser.ParseString();
			sheet.Size1 = m_streamParser.ParseNumeric();
			sheet.Size2 = m_streamParser.ParseNumeric();
			sheet.Thickness = m_streamParser.ParseNumeric();
			Int32 someInteger1 = m_streamParser.ParseInt32();
			Int32 someInteger2 = m_streamParser.ParseInt32();
			pad = m_streamParser.ReadBytes(2);
			Int32 someInteger3 = m_streamParser.ParseInt32();
			pad = m_streamParser.ReadBytes(10);
			Int32 someInteger4 = m_streamParser.ParseInt32();
			pad = m_streamParser.ReadBytes(3);
			m_document.Sheets.Add(sheet);
		}

		private void ParseOperation(LC4SectionsCollection parentCollection)
		{
			LC4Section operation = m_document.CreateSection();

			Byte[] pad;
			pad = m_streamParser.ReadBytes(7);

			String operationType = m_streamParser.ParseString();
			switch(operationType) {
				case "Anschnitt":
					operation.SectionType = LC4SectionType.Scrap;
					break;
				case "Schnitt":
					operation.SectionType = LC4SectionType.Cut;
					break;
				case "Teil":
					operation.SectionType = LC4SectionType.Detail;
					break;
				case "Rest":
					operation.SectionType = LC4SectionType.Remain;
					break;
				case "Streifen":
					operation.SectionType = LC4SectionType.NewLine;
					break;
			}

			String copyString = m_streamParser.ParseString();
			operation.Size = m_streamParser.ParseNumeric();
			Int32 someInteger1 = m_streamParser.ParseInt32();
			pad = m_streamParser.ReadBytes(2);
			Int32 operationTypeCode = m_streamParser.ParseInt32();
			pad = m_streamParser.ReadBytes(2);
			Int32 someNumber2 = m_streamParser.ParseInt32();
			pad = m_streamParser.ReadBytes(4);
			Int32 someNumber3 = m_streamParser.ParseInt32();
			pad = m_streamParser.ReadBytes(7);
			Int32 someNumber4 = m_streamParser.ParseInt32();

			pad = m_streamParser.ReadBytes(7);
			Int32 subOperationsCount = m_streamParser.ParseInt32();

			for (Int32 i = 0; i < subOperationsCount; i++)
				ParseOperation(operation);

			pad = m_streamParser.ReadBytes(3);

			parentCollection.Add(operation);
		}

		private LC4Variable ParseVariable()
		{
			LC4Variable result = m_document.CreateVariable();

			Byte[] pad;
			pad = m_streamParser.ReadBytes(7);
			result.Name = m_streamParser.ParseString();
			result.Value = m_streamParser.ParseString();
			pad = m_streamParser.ReadBytes(3);

			return result;
		}

		private void ParseCut()
		{
			LC4Cutting cutting = m_document.CreateCutting();

			Byte[] pad;
			pad = m_streamParser.ReadBytes(11);
			cutting.Name = m_streamParser.ParseString();
			String someString1 = m_streamParser.ParseString();
			cutting.Size1 = m_streamParser.ParseNumeric();

			Int32 someInt = m_streamParser.ParseInt32();
			pad = m_streamParser.ReadBytes(0x2);
			Int32 someInt2 = m_streamParser.ParseInt32();
			pad = m_streamParser.ReadBytes(0x2);
			Int32 someInt3 = m_streamParser.ParseInt32();
			pad = m_streamParser.ReadBytes(0x4);
			Int32 someInt4 = m_streamParser.ParseInt32();
			pad = m_streamParser.ReadBytes(0x7);
			Int32 someInt5 = m_streamParser.ParseInt32();
			pad = m_streamParser.ReadBytes(0x3);
			String someString2 = m_streamParser.ParseString();
			pad = m_streamParser.ReadBytes(0x8);
			Int32 someInt6 = m_streamParser.ParseInt32();
			Int32 someInt7 = m_streamParser.ParseInt32();
			pad = m_streamParser.ReadBytes(0x7);
			Int32 someInt8 = m_streamParser.ParseInt32();

			pad = m_streamParser.ReadBytes(0x7);
			Int32 operationsCount = m_streamParser.ParseInt32();

			for (Int32 i = 0; i < operationsCount; i++)
				ParseOperation(cutting);
			pad = m_streamParser.ReadBytes(0x3);

			cutting.Size2 = m_streamParser.ParseNumeric();
			Int32 someInt9 = m_streamParser.ParseInt32();
			Int32 someInt10 = m_streamParser.ParseInt32();
			String someString3 = m_streamParser.ParseString();

			pad = m_streamParser.ReadBytes(6);
			Int32 someInt11 = m_streamParser.ParseInt32();
			pad = m_streamParser.ReadBytes(10);

			Int32 variablesCount = m_streamParser.ParseInt32();
			if (variablesCount > 0)
			{
				LC4VariablesCollection variables = m_document.CreateVariablesCollection();
				for (Int32 i = 0; i < variablesCount; i++)
					variables.Add(ParseVariable());
				cutting.Variables = variables;
			}

			m_document.Cuttings.Add(cutting);

			Int32 someInt12 = m_streamParser.ParseInt32();
			pad = m_streamParser.ReadBytes(3);
			Double someDouble1 = m_streamParser.ParseDouble();
			Double someDouble2 = m_streamParser.ParseDouble();
			Int32 someInt13 = m_streamParser.ParseInt32();
			Double someDouble3 = m_streamParser.ParseDouble();
			Double someDouble4 = m_streamParser.ParseDouble();
			Int32 someInt14 = m_streamParser.ParseInt32();
			Double someDouble5 = m_streamParser.ParseDouble();
			Double someDouble6 = m_streamParser.ParseDouble();
		}

		public LC4Document Parse(String fileName)
		{
			m_document = new LC4Document();
			m_streamParser = new StreamParser(fileName);

			Byte[] pad;
			pad = m_streamParser.ReadBytes(7);
			m_document.InternalName = m_streamParser.ParseString();
			m_document.Generator = m_streamParser.ParseString();

			pad = m_streamParser.ReadBytes(7);
			Int32 someInteger1 = m_streamParser.ParseInt32();

			pad = m_streamParser.ReadBytes(7);
			Int32 sheetsCount = m_streamParser.ParseInt32();
			for (Int32 i = 0; i < sheetsCount; i++)
				ParseSheet();

			pad = m_streamParser.ReadBytes(7);
			Int32 someInteger2 = m_streamParser.ParseInt32();

			pad = m_streamParser.ReadBytes(7);
			Int32 cutsCount = m_streamParser.ParseInt32();
			for (Int32 i = 0; i < cutsCount; i++)
				ParseCut();

			pad = m_streamParser.ReadBytes(13);

			return m_document;
		}

	}
}
