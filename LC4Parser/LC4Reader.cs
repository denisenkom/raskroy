using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace Denisenko.Cutting.LC4
{
    public class LC4Reader
    {
        private LC4Formatter m_fmt;
        private LC4Document m_document;

        public LC4Document Load(Stream stm)
        {
            m_fmt = new LC4Formatter(stm);
            m_document = new LC4Document();

            Byte[] pad;
            pad = m_fmt.ReadBytes(7);
            m_document.InternalName = m_fmt.ReadString();
            m_document.Description = m_fmt.ReadString();

            pad = m_fmt.ReadBytes(7);
            m_document.SomeInteger1 = m_fmt.ReadInt32();

            pad = m_fmt.ReadBytes(7);
            Int32 sheetsCount = m_fmt.ReadInt32();
            for (Int32 i = 0; i < sheetsCount; i++)
            {
                LoadSheet();
            }

            pad = m_fmt.ReadBytes(7);
            m_document.SomeInteger2 = m_fmt.ReadInt32();

            pad = m_fmt.ReadBytes(7);
            Int32 cutsCount = m_fmt.ReadInt32();
            for (Int32 i = 0; i < cutsCount; i++)
            {
                LoadCutting();
            }

            pad = m_fmt.ReadBytes(13);

            return m_document;
        }

        private void LoadSheet()
        {
            LC4Sheet sheet = new LC4Sheet();
            Byte[] pad;
            pad = m_fmt.ReadBytes(11);
            sheet.SomeString1 = m_fmt.ReadString();
            sheet.SomeString2 = m_fmt.ReadString();
            sheet.SomeString3 = m_fmt.ReadString();
            sheet.Size1 = m_fmt.ReadNumeric();
            sheet.Size2 = m_fmt.ReadNumeric();
            sheet.Thickness = m_fmt.ReadNumeric();
            sheet.SomeInteger1 = m_fmt.ReadInt32();
            sheet.SomeInteger2 = m_fmt.ReadInt32();
            pad = m_fmt.ReadBytes(2);
            sheet.SomeInteger3 = m_fmt.ReadInt32();
            pad = m_fmt.ReadBytes(10);
            sheet.SomeInteger4 = m_fmt.ReadInt32();
            pad = m_fmt.ReadBytes(3);
            m_document.Sheets.Add(sheet);
        }

        private void LoadSection(List<LC4Section> parentCollection)
        {
            LC4Section operation = new LC4Section();

            Byte[] pad;
            pad = m_fmt.ReadBytes(7);

            operation.SectionType = (LC4SectionType)Enum.Parse(typeof(LC4SectionType), m_fmt.ReadString());
            operation.CopyString = m_fmt.ReadString();
            operation.Size = m_fmt.ReadNumeric();
            operation.SomeInteger1 = m_fmt.ReadInt32();
            pad = m_fmt.ReadBytes(2);
            m_fmt.ReadInt32(); // skip type code
            pad = m_fmt.ReadBytes(2);
            operation.SomeInteger2 = m_fmt.ReadInt32();
            pad = m_fmt.ReadBytes(4);
            operation.SomeInteger3 = m_fmt.ReadInt32();
            pad = m_fmt.ReadBytes(7);
            operation.SomeInteger4 = m_fmt.ReadInt32();

            pad = m_fmt.ReadBytes(7);
            Int32 subOperationsCount = m_fmt.ReadInt32();

            for (Int32 i = 0; i < subOperationsCount; i++)
                LoadSection(operation.NestedSections);

            pad = m_fmt.ReadBytes(3);

            parentCollection.Add(operation);
        }

        private LC4Variable LoadVariable()
        {
            LC4Variable result = new LC4Variable();

            Byte[] pad;
            pad = m_fmt.ReadBytes(7);
            result.Name = m_fmt.ReadString();
            result.Value = m_fmt.ReadString();
            pad = m_fmt.ReadBytes(3);

            return result;
        }

        private void LoadCutting()
        {
            LC4Cutting cutting = new LC4Cutting();

            Byte[] pad;
            pad = m_fmt.ReadBytes(11);
            cutting.Name = m_fmt.ReadString();
            cutting.SomeString1 = m_fmt.ReadString();
            cutting.Size1 = m_fmt.ReadNumeric();

            cutting.SomeInteger1 = m_fmt.ReadInt32();
            pad = m_fmt.ReadBytes(0x2);
            cutting.SomeInteger2 = m_fmt.ReadInt32();
            pad = m_fmt.ReadBytes(0x2);
            cutting.SomeInteger3 = m_fmt.ReadInt32();
            pad = m_fmt.ReadBytes(0x4);
            cutting.SomeInteger4 = m_fmt.ReadInt32();
            pad = m_fmt.ReadBytes(0x7);
            cutting.SomeInteger5 = m_fmt.ReadInt32();
            pad = m_fmt.ReadBytes(0x3);
            cutting.SomeString2 = m_fmt.ReadString();
            pad = m_fmt.ReadBytes(0x8);
            cutting.SomeInteger6 = m_fmt.ReadInt32();
            cutting.SheetIndex = m_fmt.ReadInt32();
            pad = m_fmt.ReadBytes(0x7);
            cutting.SomeInteger8 = m_fmt.ReadInt32();

            pad = m_fmt.ReadBytes(0x7);
            Int32 operationsCount = m_fmt.ReadInt32();

            for (Int32 i = 0; i < operationsCount; i++)
            {
                LoadSection(cutting.Sections);
            }
            pad = m_fmt.ReadBytes(0x3);

            cutting.Size2 = m_fmt.ReadNumeric();
            cutting.SomeInteger9 = m_fmt.ReadInt32();
            cutting.SomeInteger10 = m_fmt.ReadInt32();
            cutting.SomeString3 = m_fmt.ReadString();

            pad = m_fmt.ReadBytes(6);
            cutting.SomeInteger11 = m_fmt.ReadInt32();
            pad = m_fmt.ReadBytes(10);

            Int32 variablesCount = m_fmt.ReadInt32();
            for (Int32 i = 0; i < variablesCount; i++)
            {
                cutting.Variables.Add(LoadVariable());
            }

            m_document.Cuttings.Add(cutting);

            cutting.SomeInteger12 = m_fmt.ReadInt32();
            pad = m_fmt.ReadBytes(3);
            cutting.ScrapsSquare = m_fmt.ReadDouble();
            cutting.TotalSquare = m_fmt.ReadDouble();
            cutting.RemainsCount = m_fmt.ReadInt32();
            cutting.RemainsSquare = m_fmt.ReadDouble();
            cutting.DustSquare = m_fmt.ReadDouble();
            cutting.DetailsCount = m_fmt.ReadInt32();
            cutting.DetailsSquare = m_fmt.ReadDouble();
            cutting.ScrapPercent = m_fmt.ReadDouble();
        }
    }
}
