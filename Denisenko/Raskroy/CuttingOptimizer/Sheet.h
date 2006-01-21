#pragma once

namespace Denisenko {
namespace Cutting {

public value class Sheet
{
public:
	Sheet(Size length, Size width) :
	  m_length(length), m_width(width)
	{
	}

	property Size Length { Size get() { return m_length; } }
	property Size Width { Size get() { return m_width; } }

private:
	Size m_length;
	Size m_width;
};

}
}