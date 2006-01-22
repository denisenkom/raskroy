#pragma once

namespace Denisenko {
namespace Cutting {

ref class CuttingSection;

public ref class CuttingSectionsCollection abstract : IEnumerable<CuttingSection^>, ICloneable
{
public:
	virtual IEnumerator<CuttingSection^>^ GetEnumerator()
	{
		return m_list->GetEnumerator();
	}

	void Add(CuttingSection^ section)
	{
		m_list->Add(section);
	}

	virtual Object^ Clone() = 0;

internal:
	CuttingSectionsCollection() :
		m_list(gcnew List<CuttingSection^>())
	{
	}

	CuttingSectionsCollection(CuttingSectionsCollection^ ref) :
		m_list(ref->m_list)
	{
	}

private:
	List<CuttingSection^>^ m_list;

	virtual Collections::IEnumerator^ GetEnumerator2() sealed = Collections::IEnumerable::GetEnumerator
	{
		return GetEnumerator();
	}
};


public enum class CuttingSectionType
{
	NewLine,
	Scrap,
	Cut,
	Element,
	Remain
};


public ref class CuttingSection : CuttingSectionsCollection
{
public:
	virtual Object^ Clone2() = CuttingSectionsCollection::Clone
	{
		return Clone();
	}

	CuttingSection(CuttingSectionType sectionType) :
		m_sectionType(sectionType)
	{
	}

	CuttingSection(CuttingSectionType sectionType, Size size) :
		m_sectionType(sectionType), m_size(size)
	{
	}

	CuttingSection(CuttingSection^ ref) : 
		CuttingSectionsCollection(ref),
		m_sectionType(ref->m_sectionType), m_size(ref->m_size)
	{
	}

	CuttingSection^ Clone() new
	{
		return gcnew CuttingSection(this);
	}

	property Denisenko::Size Size {
		Denisenko::Size get() { return m_size; }
		void set(Denisenko::Size value) { m_size = value; }
	}
	property CuttingSectionType SectionType { CuttingSectionType get() { return m_sectionType; } }

internal:
	Denisenko::Size m_size;
	CuttingSectionType m_sectionType;
};


public ref class CuttingScheme : CuttingSectionsCollection
{
public:
	property Size Width
	{ 
		Size get() { return m_width; } 
		void set(Size value) { m_width = value; }
	}
	property Size Height 
	{ 
		Size get() { return m_height; } 
		void set(Size value) { m_height = value; }
	}

	CuttingScheme^ Clone() new
	{
		return gcnew CuttingScheme(this);
	}

	virtual Object^ Clone2() = CuttingSectionsCollection::Clone
	{
		return Clone();
	}

internal:
	Size m_width;
	Size m_height;


	CuttingScheme()
	{
	}

	CuttingScheme(CuttingScheme^ ref) :
		CuttingSectionsCollection(ref),
		m_width(ref->m_width), m_height(ref->m_height)
	{
	}
};


}
}