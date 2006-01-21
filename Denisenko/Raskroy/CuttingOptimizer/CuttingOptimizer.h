// CuttingOptimizer.h

#pragma once

#include "raskroy.h"

using namespace std;
using namespace System;
using namespace Denisenko::Raskroy;

namespace Denisenko {
namespace Cutting {
namespace Optimizing {

	public ref class Optimizer
	{
	public:

		ref class ParametersCollection
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

		Optimizer()
		{
			m_started = false;
			m_parts = gcnew PartsCollection();
			m_sheets = gcnew SheetsCollection();
			m_parameters = gcnew ParametersCollection();
			m_raskroy = new Denisenko::Raskroy::Raskroy();
		}

		~Optimizer()
		{
			delete m_raskroy;
		}

		property PartsCollection^ Parts { PartsCollection^ get() { return m_parts; } }
		property SheetsCollection^ Sheets { SheetsCollection^ get() { return m_sheets; } }
		property ParametersCollection^ Parameters { ParametersCollection^ get() { return m_parameters; } }
		property CuttingResult^ CurrentResult { CuttingResult^ get() { return m_result; } }

		void Reset()
		{
			m_started = false;
		}

		Boolean NextResult() 
		{
			if(!m_started)
			{
				Denisenko::Raskroy::Parts convParts = ConvertParts();
				Denisenko::Raskroy::Parts convSheets = ConvertSheets();
				m_raskroy->put_SawThickness(Parameters->CutterThickness.Scaled);
				m_raskroy->Begin(convParts, convSheets);
				m_started = true;
			}
			Denisenko::Raskroy::t_result result;
			if(m_raskroy->NextResult(result))
			{
				m_result = ConvertResult(result);
				return true;
			}
			else
			{
				m_result = nullptr;
				return false;
			}
		}

	private:
		Denisenko::Raskroy::Raskroy* m_raskroy;
		PartsCollection^ m_parts;
		SheetsCollection^ m_sheets;
		Boolean m_started;
		ParametersCollection^ m_parameters;
		CuttingResult^ m_result;

		Denisenko::Raskroy::Parts ConvertParts()
		{
			Denisenko::Raskroy::Parts result;
			for each(Part^ part in Parts)
			{
				result.push_back(Denisenko::Raskroy::Part(
					part->Length.Scaled,
					part->Width.Scaled,
					part->CanRotate,
					part->Quantity));
			}
			return result;
		}

		Denisenko::Raskroy::Parts ConvertSheets()
		{
			Denisenko::Raskroy::Parts result;
			for each(Sheet^ sheet in Sheets)
			{
				result.push_back(Denisenko::Raskroy::Part(
					sheet->Length.Scaled,
					sheet->Width.Scaled));
			}
			return result;
		}

		CuttingResult^ ConvertResult(const Denisenko::Raskroy::t_result& result)
		{
			CuttingResultBuilder^ builder = gcnew CuttingResultBuilder();
			return builder->Convert(result, Parameters->CutterThickness,
				Size::FromScaled(result.sheet->Rect.Length),
				Size::FromScaled(result.sheet->Rect.Width));
		}
	};
}
}
}