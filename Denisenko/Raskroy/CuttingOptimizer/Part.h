#pragma once

using namespace System;

namespace Denisenko {
namespace Cutting {

public value class Part
{
public:
	Part(Size length, Size width, Int32 quantity, Boolean canRotate) :
		m_length(length), m_width(width), m_quantity(quantity), m_canRotate(canRotate)
	{
	}

	property Size Length { Size get() { return m_length; } }
	property Size Width { Size get() { return m_width; } }
	property Int32 Quantity { Int32 get() { return m_quantity; } }
	property Boolean CanRotate { Boolean get() { return m_canRotate; } }

private:
	Size m_length;
	Size m_width;
	Int32 m_quantity;
	Boolean m_canRotate;
};

}
}