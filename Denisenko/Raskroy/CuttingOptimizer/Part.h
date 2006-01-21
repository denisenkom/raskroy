#pragma once

using namespace System;

namespace Denisenko {
namespace Cutting {

public value class Part
{
public:
	Part(Int32 length, Int32 width, Int32 quantity, Boolean canRotate) :
		m_length(length), m_width(width), m_quantity(quantity), m_canRotate(canRotate)
	{
	}

	property Int32 Length { Int32 get() { return m_length; } }
	property Int32 Width { Int32 get() { return m_width; } }
	property Int32 Quantity { Int32 get() { return m_quantity; } }
	property Boolean CanRotate { Boolean get() { return m_canRotate; } }

private:
	Int32 m_length;
	Int32 m_width;
	Int32 m_quantity;
	Boolean m_canRotate;
};

}
}