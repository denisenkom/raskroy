#pragma once

using namespace System;
using namespace System::Diagnostics;
using namespace System::Collections::Generic;

namespace Denisenko {
namespace Cutting {

[Serializable]
public ref class Material
{
public:
	Material(Int32 materialID, String^ name, Boolean canRotate)
		: m_materialID(materialID),
		m_name(name),
		m_canRotate(canRotate)
	{
	}

	Material(const Material^ ref)
		: m_materialID(ref->m_materialID),
		m_name(ref->m_name),
		m_canRotate(ref->m_canRotate)
	{
	}

	property Int32 MaterialID { Int32 get() { return m_materialID; } }
	property String^ Name { String^ get() { return m_name; } }
	property Boolean CanRotate { Boolean get() { return m_canRotate; } }

private:
	Int32 m_materialID;
	String^ m_name;
	Boolean m_canRotate;
};

ref class Section;

[Serializable]
public ref class SectionsCollection abstract : IEnumerable<Section^>, ICloneable
{
public:
	virtual IEnumerator<Section^>^ GetEnumerator()
	{
		return m_list->GetEnumerator();
	}

	void Add(Section^ section)
	{
		m_list->AddLast(section);
	}

	void Replace(Section^ section, Section^ withSection)
	{
		LinkedListNode<Section^>^ node = m_list->Find(section);
		node->Value = withSection;
	}

	void Insert(Section^ afterSection, Section^ section)
	{
		m_list->AddAfter(m_list->Find(afterSection), section);
	}

	virtual Object^ Clone() = 0;

internal:
	SectionsCollection() :
		m_list(gcnew LinkedList<Section^>())
	{
	}

	SectionsCollection(SectionsCollection^ ref) :
		m_list(ref->m_list)
	{
	}

private:
	LinkedList<Section^>^ m_list;

	virtual Collections::IEnumerator^ GetEnumerator2() sealed = Collections::IEnumerable::GetEnumerator
	{
		return GetEnumerator();
	}
};


public enum class SectionType
{
	Undefined,
	NewLine,
	Scrap,
	Cut,
	Element,
	Remain
};


public enum class CutType
{
	Undefined, Vertical, Horizontal
};


[Serializable]
public ref class Section : SectionsCollection
{
public:
	virtual Object^ Clone2() = SectionsCollection::Clone
	{
		return Clone();
	}

	Section^ Clone() new
	{
		return gcnew Section(this);
	}

	property Decimal Size
	{
		Decimal get()
		{
			switch(m_cutType)
			{
			case CutType::Horizontal:
				return m_height;
			case CutType::Vertical:
				return m_width;
			case CutType::Undefined:
				throw gcnew Exception("Cannot get size of section with undefined cutting");
			}
			throw gcnew Exception("Never should get here");
		}
	}

	property Cutting::SectionType SectionType
	{
		Cutting::SectionType get() { return m_sectionType; }
	}

	property Section^ Parent
	{
		Section^ get() { return m_parent; }
	}

	property Decimal X
	{
		Decimal get() { return m_x; }
	}
	property Decimal Y
	{
		Decimal get() { return m_y; }
	}
	property Decimal Width
	{ 
		Decimal get() { return m_width; } 
	}
	property Decimal Height 
	{ 
		Decimal get() { return m_height; } 
	}
	Boolean IsLeftEven()
	{
		return m_leftEven;
	}
	Boolean IsRightEven()
	{
		return m_rightEven;
	}
	Boolean IsTopEven()
	{
		return m_topEven;
	}
	Boolean IsBottomEven()
	{
		return m_bottomEven;
	}

internal:
	Decimal m_x;
	Decimal m_y;
	Decimal m_width;
	Decimal m_height;
	CutType m_cutType;
	Cutting::SectionType m_sectionType;
	Section^ m_parent;
	Boolean m_topEven;
	Boolean m_leftEven;
	Boolean m_bottomEven;
	Boolean m_rightEven;

	Section()
	{
	}

	Section(Section^ ref) : 
		SectionsCollection(ref),
		m_sectionType(ref->m_sectionType), m_width(ref->m_width), m_height(ref->m_height),
		m_cutType(ref->m_cutType), m_parent(nullptr)
	{
	}
};


public value class CutResult
{
	Section^ Section1;
	Section^ Section2;
};


[Serializable]
public ref class CuttingScheme
{
public:
	Section^ Cut(Section^ section, Decimal size, CutType cutType, Section^% remain)
	{
		if(section->m_cutType != cutType)
		{
			section = CreateNestedSection(section, cutType);
		}
		return SplitSection(section, size, cutType, remain);
	}

	void MakeSureEdgeEven(Section^% section, CutType cutType)
	{
		if(cutType == CutType::Horizontal && !section->IsTopEven())
			Cut(section, m_parameters->CutOffLeft - m_parameters->CutterThickness, cutType, section);
		else if(cutType == CutType::Vertical && !section->IsLeftEven())
			Cut(section, m_parameters->CutOffLeft - m_parameters->CutterThickness, cutType, section);
	}

	Section^ Cut(Decimal size, Section^% remain)
	{
		throw gcnew NotImplementedException();
	}

	Section^ CutPart(Section^ section, Part part, CutType cutType, Section^% remain)
	{
		throw gcnew NotImplementedException();
	}

	Section^ CutPart(Part part, Section^% remain)
	{
		throw gcnew NotImplementedException();
	}

	void MarkAsPart(Section^ section)
	{
		section->m_sectionType = SectionType::Element;
	}

	void MarkAsRemain(Section^ section)
	{
		throw gcnew NotImplementedException();
	}

	static CutType Rotate(CutType cutType)
	{
		if(cutType == CutType::Vertical)
			return CutType::Horizontal;
		else
			return CutType::Vertical;
	}

	CuttingScheme(Decimal width, Decimal height, ParametersCollection^ parameters)
	{
		m_rootSection = gcnew Section();
		m_rootSection->m_width = width;
		m_rootSection->m_height = height;
		m_parameters = parameters->Clone();
	}

	property Section^ RootSection
	{
		Section^ get() { return m_rootSection; }
	}

	property Decimal Width
	{
		Decimal get() { return m_rootSection->Width; }
	}

	property Decimal Height
	{
		Decimal get() { return m_rootSection->Height; }
	}

	property Material^ Material
	{
		Denisenko::Cutting::Material^ get() { return m_material; }
		void set(Denisenko::Cutting::Material^ value) { m_material = value; }
	}

private:
	Section^ m_rootSection;
	ParametersCollection^ m_parameters;
	Denisenko::Cutting::Material^ m_material;

	Section^ SplitSection(Section^ section, Decimal size, CutType cutType, Section^% remain)
	{
		Debug::Assert(cutType == section->m_cutType);

		Section^ section1 = gcnew Section();
		Section^ cut = gcnew Section();
		remain = gcnew Section();

		section1->m_parent = cut->m_parent = remain->m_parent = section->m_parent;
		section1->m_cutType = cut->m_cutType = remain->m_cutType = cutType;
		section1->m_sectionType = remain->m_sectionType = SectionType::Undefined;
		cut->m_sectionType = SectionType::Cut;
		if(cutType == CutType::Horizontal)
		{
			if(size > section->m_height)
				throw gcnew Exception("Section is too small");
			section1->m_topEven = section->m_topEven;
			section1->m_x = cut->m_x = remain->m_x = section->m_x;
			section1->m_y = section->m_y;
			section1->m_width = cut->m_width = remain->m_width = section->m_width;
			section1->m_height = size;
			section1->m_bottomEven = true;
			cut->m_y = section->m_y + size;
			cut->m_height = Math::Min(m_parameters->CutterThickness, section->m_height - size);
			remain->m_topEven = true;
			remain->m_bottomEven = section->m_bottomEven;
			section1->m_leftEven = remain->m_leftEven = section->m_leftEven;
			section1->m_rightEven = remain->m_rightEven = section->m_rightEven;
			remain->m_y = section->m_y + size + m_parameters->CutterThickness;
			remain->m_height = section->m_height - size - m_parameters->CutterThickness;
			if(remain->m_height < Decimal::Zero)
				remain = nullptr;
		}
		else // Vertical
		{
			if(size > section->m_width)
				throw gcnew Exception("Section is too small");
			section1->m_x = section->m_x;
			section1->m_y = cut->m_y = remain->m_y = section->m_y;
			section1->m_height = cut->m_height = remain->m_height = section->m_height;
			section1->m_width = size;
			section1->m_rightEven = true;
			section1->m_leftEven = section->m_leftEven;
			cut->m_x = section->m_x + size;
			cut->m_width = Math::Min(m_parameters->CutterThickness, section->m_width - size);
			remain->m_leftEven = true;
			remain->m_rightEven = section->m_rightEven;
			section1->m_topEven = remain->m_topEven = section->m_topEven;
			section1->m_bottomEven = remain->m_bottomEven = section->m_bottomEven;
			remain->m_x = section->m_x + size + m_parameters->CutterThickness;
			remain->m_width = section->m_width - size - m_parameters->CutterThickness;
			if(remain->m_width < Decimal::Zero)
				remain = nullptr;
		}

		section->m_parent->Replace(section, section1);
		section->m_parent->Insert(section1, cut);
		if(remain != nullptr)
			section->m_parent->Insert(cut, remain);
		return section1;
	}

	Section^ CreateNestedSection(Section^ section, CutType cutType)
	{
		Section^ result = gcnew Section();
		result->m_x = section->m_x;
		result->m_y = section->m_y;
		result->m_width = section->m_width;
		result->m_height = section->m_height;
		result->m_cutType = cutType;
		result->m_parent = section;
		result->m_topEven = section->m_topEven;
		result->m_leftEven = section->m_leftEven;
		result->m_bottomEven = section->m_bottomEven;
		result->m_rightEven = section->m_rightEven;
		section->m_sectionType = SectionType::NewLine;
		section->Add(result);
		return result;
	}
};


}
}