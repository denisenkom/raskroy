#pragma once

using namespace System;

namespace Denisenko {
namespace Cutting {

public value class Part
{
public:
	Part(Decimal length, Decimal width, Int32 quantity, Boolean canRotate) :
		m_length(length), m_width(width), m_quantity(quantity), m_canRotate(canRotate)
	{
	}

	property Decimal Length { Decimal get() { return m_length; } }
	property Decimal Width { Decimal get() { return m_width; } }
	property Int32 Quantity { Int32 get() { return m_quantity; } }
	property Boolean CanRotate { Boolean get() { return m_canRotate; } }

private:
	Decimal m_length;
	Decimal m_width;
	Int32 m_quantity;
	Boolean m_canRotate;
};

}
}