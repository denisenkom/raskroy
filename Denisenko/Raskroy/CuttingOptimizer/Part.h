#pragma once

using namespace System;

namespace Denisenko {
namespace CuttingOptimizer {

public ref struct Part
{
public:
	Part(Double length, Double width, Int32 quantity) :
		m_length(length), m_width(width), m_quantity(quantity)
	{
	}

	property Double Length { Double get() { return m_length; } }
	property Double Width { Double get() { return m_width; } }
	property Double Quantity { Double get() { return m_quantity; } }

private:
	Double m_length;
	Double m_width;
	Int32 m_quantity;
};

}
}