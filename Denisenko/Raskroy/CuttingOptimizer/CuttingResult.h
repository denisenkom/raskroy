#pragma once

namespace Denisenko {
namespace Cutting {

ref class CuttingSection;

public ref class CuttingSectionsCollection : IEnumerable<CuttingSection^>
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

internal:
	CuttingSectionsCollection()
	{
		m_list = gcnew List<CuttingSection^>();
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
	CuttingSection(CuttingSectionType sectionType, Int32 size) :
	  m_sectionType(sectionType), m_size(size)
	{
	}

	property Int32 Size { Int32 get() { return m_size; } }
	property CuttingSectionType SectionType { CuttingSectionType get() { return m_sectionType; } }

internal:
	Int32 m_size;
	CuttingSectionType m_sectionType;
};


public ref class CuttingResult : CuttingSectionsCollection
{
public:
	property Int32 Size1
	{ 
		Int32 get() { return m_size1; } 
		void set(Int32 value) { m_size1 = value; }
	}
	property Int32 Size2 
	{ 
		Int32 get() { return m_size2; } 
		void set(Int32 value) { m_size2 = value; }
	}

internal:
	CuttingResult()
	{
	}

	Int32 m_size1;
	Int32 m_size2;
};


}
}