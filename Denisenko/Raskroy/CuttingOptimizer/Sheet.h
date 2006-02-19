#pragma once

namespace Denisenko {
namespace Cutting {

public value class Sheet
{
public:
	Sheet(Decimal length, Decimal width) :
	  m_length(length), m_width(width)
	{
	}

	property Decimal Length { Decimal get() { return m_length; } }
	property Decimal Width { Decimal get() { return m_width; } }

private:
	Decimal m_length;
	Decimal m_width;
};

}
}