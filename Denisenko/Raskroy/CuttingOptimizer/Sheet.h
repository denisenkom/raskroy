#pragma once

namespace Denisenko {
namespace Cutting {

public value class Sheet
{
public:
	Sheet(Int32 length, Int32 width) :
	  m_length(length), m_width(width)
	{
	}

	property Int32 Length { Int32 get() { return m_length; } }
	property Int32 Width { Int32 get() { return m_width; } }

private:
	Int32 m_length;
	Int32 m_width;
};

}
}