// CuttingOptimizer.h

#pragma once

#include "../raskroy.h"

using namespace std;
using namespace System;
using namespace Denisenko::Raskroy;

namespace Denisenko {
namespace CuttingOptimizer {

	public ref class Optimizer
	{
	public:

		Optimizer()
		{
			m_started = false;
			m_cutterThickness = 4.4;
			m_parts = gcnew PartsCollection();
			m_sheets = gcnew SheetsCollection();
			m_raskroy = new Denisenko::Raskroy::Raskroy();
		}

		~Optimizer()
		{
			delete m_raskroy;
		}

		property Double CutterThickness
		{
			Double get() { return m_cutterThickness; }
			void set(Double value) { m_cutterThickness = value; }
		}

		property PartsCollection^ Parts { PartsCollection^ get() { return m_parts; } }
		property SheetsCollection^ Sheets { SheetsCollection^ get() { return m_sheets; } }

		void Reset()
		{
			m_started = false;
		}

		Boolean NextResult([out] CuttingResult^ cuttingResult)
		{
			if(!m_started)
			{
				Denisenko::Raskroy::Parts convParts = ConvertParts();
				Denisenko::Raskroy::Parts convSheets = ConvertSheets();
				m_raskroy->Begin(convParts, convSheets);
				m_started = true;
			}
			Denisenko::Raskroy::t_result result;
			bool retVal = m_raskroy->NextResult(result);
			cuttingResult = ConvertResult(result);
			return retVal;
		}

	private:
		Denisenko::Raskroy::Raskroy* m_raskroy;
		Double m_cutterThickness;
		PartsCollection^ m_parts;
		SheetsCollection^ m_sheets;
		Boolean m_started;

		Denisenko::Raskroy::Parts ConvertParts()
		{
			Denisenko::Raskroy::Parts result;
			return result;
		}

		Denisenko::Raskroy::Parts ConvertSheets()
		{
			Denisenko::Raskroy::Parts result;
			return result;
		}

		CuttingResult^ ConvertResult(const Denisenko::Raskroy::t_result& result)
		{
			return nullptr;
		}
	};
}
}