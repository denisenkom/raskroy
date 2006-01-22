#pragma once

using namespace System;

namespace Denisenko {

public value class Size
{
public:
	const static Int64 Factor = 1000;

	explicit Size(Double value)
	{
		m_scaled = (Int64)(value * Factor);
	}

	virtual String^ ToString() override
	{
		return ToDouble().ToString();
	}

	Double ToDouble()
	{
		return (Double)m_scaled / (Double)Factor;
	}

	static Size Parse(String^ string)
	{
		return Size(Double::Parse(string));
	}

	static Size Parse(String^ string, Globalization::NumberStyles style)
	{
		return Size(Double::Parse(string, style));
	}

	static Size Parse(String^ string, IFormatProvider^ provider)
	{
		return Size(Double::Parse(string, provider));
	}

	static Size FromScaled(Int64 scaled)
	{
		return Size(scaled);
	}

	static Size FromNonScaled(Int32 nonScaled)
	{
		return Size(nonScaled * Factor);
	}

	property Int64 Scaled 
	{
		Int64 get() { return m_scaled; }
		void set(Int64 value) { m_scaled = value; }
	}

	inline bool operator == (Size rightOperand) { return m_scaled == rightOperand.m_scaled; }
	inline bool operator != (Size rightOperand) { return m_scaled != rightOperand.m_scaled; }
	inline bool operator >= (Size rightOperand) { return m_scaled >= rightOperand.m_scaled; }
	inline bool operator <= (Size rightOperand) { return m_scaled <= rightOperand.m_scaled; }
	inline bool operator > (Size rightOperand) { return m_scaled > rightOperand.m_scaled; }
	inline bool operator < (Size rightOperand) { return m_scaled < rightOperand.m_scaled; }
	inline Size operator -= (Size rightOperand) { m_scaled -= rightOperand.m_scaled; return *this; }
	inline Size operator += (Size rightOperand) { m_scaled += rightOperand.m_scaled; return *this; }
	inline Size operator - (Size rightOperand) { return Size(m_scaled - rightOperand.m_scaled); }
	inline Size operator + (Size rightOperand) { return Size(m_scaled + rightOperand.m_scaled); }
	inline Size operator * (Int32 rightOperand) { return Size(m_scaled * rightOperand); }

	static Size Min(Size size1, Size size2)
	{
		return Size(Math::Min(size1.m_scaled, size2.m_scaled));
	}

	static Size Max(Size size1, Size size2)
	{
		return Size(Math::Max(size1.m_scaled, size2.m_scaled));
	}

	const static Size Zero;

private:
	Int64 m_scaled;

	Size(Int64 scaled) : m_scaled(scaled) { }
};

}