#pragma once

namespace Denisenko {
namespace Cutting {

public ref class SheetsCollection : IEnumerable<Sheet>
{
public:
	void Add(Sheet sheet)
	{
		m_list->Add(sheet);
	}

	void Clear()
	{
		m_list->Clear();
	}

	virtual IEnumerator<Sheet>^ GetEnumerator()
	{
		return m_list->GetEnumerator();
	}

internal:
	SheetsCollection(void)
	{
		m_list = gcnew List<Sheet>();
	}

private:
	List<Sheet>^ m_list;

	virtual System::Collections::IEnumerator^ GetEnumerator2() sealed = System::Collections::IEnumerable::GetEnumerator
	{
		return GetEnumerator();
	}
};

}
}