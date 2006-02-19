#pragma once

namespace Denisenko {
namespace Cutting {

[Serializable]
public ref class ParametersCollection
{
public:
	property Decimal CutterThickness
	{
		Decimal get() { return m_cutterThickness; }
		void set(Decimal value) { m_cutterThickness = value; }
	}

	Decimal CutOffTop;
	Decimal CutOffBottom;
	Decimal CutOffLeft;
	Decimal CutOffRight;

	ParametersCollection^ Clone()
	{
		return (ParametersCollection^)MemberwiseClone();
	}

internal:
	ParametersCollection()
	{
		m_cutterThickness = Decimal(4.4);
		CutOffTop = 12;
		CutOffBottom = 12;
		CutOffLeft = 12;
		CutOffRight = 12;
	}

private:
	Decimal m_cutterThickness;
};

}
}