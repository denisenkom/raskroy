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


public ref class CuttingResult : CuttingSectionsCollection
{
public:
	property Size Size1
	{ 
		Size get() { return m_size1; } 
		void set(Size value) { m_size1 = value; }
	}
	property Size Size2 
	{ 
		Size get() { return m_size2; } 
		void set(Size value) { m_size2 = value; }
	}

	CuttingResult^ Clone() new
	{
		return gcnew CuttingResult(this);
	}

	virtual Object^ Clone2() = CuttingSectionsCollection::Clone
	{
		return Clone();
	}

internal:
	Size m_size1;
	Size m_size2;


	CuttingResult()
	{
	}

	CuttingResult(CuttingResult^ ref) :
		CuttingSectionsCollection(ref),
		m_size1(ref->m_size1), m_size2(ref->m_size2)
	{
	}
};


}
}