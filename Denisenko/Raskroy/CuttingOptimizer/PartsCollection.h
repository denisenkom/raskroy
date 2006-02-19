#pragma once

#include "Part.h"

using namespace System;
using namespace System::Collections::Generic;

namespace Denisenko {
namespace Cutting {

	public ref class PartsCollection : IEnumerable<Part>
{
public:
	void Add(Part part)
	{
		m_list->Add(part);
	}

	void Clear()
	{
		m_list->Clear();
	}

	virtual IEnumerator<Part>^ GetEnumerator()
	{
		return m_list->GetEnumerator();
	}

internal:
	PartsCollection(void)
	{
		m_list = gcnew List<Part>();
	}

private:
	List<Part>^ m_list;

	virtual System::Collections::IEnumerator^ GetEnumerator2() sealed = System::Collections::IEnumerable::GetEnumerator
	{
		return GetEnumerator();
	}
};


}
}