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
	CuttingSection(CuttingSectionType sectionType, Size size) :
	  m_sectionType(sectionType), m_size(size)
	{
	}

	property Denisenko::Size Size { Denisenko::Size get() { return m_size; } }
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

internal:
	CuttingResult()
	{
	}

	Size m_size1;
	Size m_size2;
};


}
}