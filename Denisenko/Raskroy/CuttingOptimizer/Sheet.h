#pragma once

namespace Denisenko {
namespace CuttingOptimizer {

public ref struct Sheet
{
public:
	Sheet(Double length, Double width) :
	  m_length(length), m_width(width)
	{
	}

	property Double Length { Double get() { return m_length; } }
	property Double Width { Double get() { return m_width; } }

private:
	Double m_length;
	Double m_width;
};

}
}