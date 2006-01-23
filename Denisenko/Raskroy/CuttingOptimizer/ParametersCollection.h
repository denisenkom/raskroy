#pragma once

namespace Denisenko {
namespace Cutting {

public ref class ParametersCollection
{
public:
	property Size CutterThickness
	{
		Size get() { return m_cutterThickness; }
		void set(Size value) { m_cutterThickness = value; }
	}

	Size CutOffTop;
	Size CutOffBottom;
	Size CutOffLeft;
	Size CutOffRight;

	ParametersCollection^ Clone()
	{
		return (ParametersCollection^)MemberwiseClone();
	}

internal:
	ParametersCollection()
	{
		m_cutterThickness = Size(4.4);
		CutOffTop = Size(12);
		CutOffBottom = Size(12);
		CutOffLeft = Size(12);
		CutOffRight = Size(12);
	}

private:
	Size m_cutterThickness;
};

}
}