// CuttingOptimizer.h

#pragma once

#include "errors.h"
#include "results_generator.h"

using namespace std;
using namespace System;

namespace Denisenko {
namespace Cutting {
namespace Optimizing {

	public ref class CannotCutDetailsException : public Exception
	{
	public:
		CannotCutDetailsException(String^ message)
			: Exception(message)
		{
		}
	};

	public ref class Optimizer
	{
	public:

		Optimizer()
		{
			m_started = false;
			m_parts = gcnew List<Part^>();
			m_sheets = gcnew List<Sheet^>();
			m_parameters = gcnew ParametersCollection();
			m_raskroy = new Denisenko::Raskroy::ResultsGenerator();
		}

		~Optimizer()
		{
			delete m_raskroy;
		}

		property List<Part^>^ Parts { List<Part^>^ get() { return m_parts; } }
		property List<Sheet^>^ Sheets { List<Sheet^>^ get() { return m_sheets; } }
		property ParametersCollection^ Parameters { ParametersCollection^ get() { return m_parameters; } }
		property CuttingScheme^ CurrentResult { CuttingScheme^ get() { return m_result; } }
		property Single PercentCompleted { Single get() { return m_raskroy->GetPercentCompleted(); } } // thread safe

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
				m_raskroy->put_SawThickness(ToScaled(Parameters->CutterThickness));
				m_raskroy->Begin(convParts, convSheets);
				m_started = true;
			}
			Denisenko::Raskroy::Result result;
			try
			{
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
			catch(Denisenko::Raskroy::CannotSetPartsException& err)
			{
				if(err.sheets->size() == 0)
					throw gcnew CannotCutDetailsException("Нельзя расположить детали, список листов не заполнен.");
				if(err.sizes[0].size() == 0)
					throw gcnew CannotCutDetailsException("Нельзя расположить детали, список деталей не заполнен.");
				throw gcnew CannotCutDetailsException("Нельзя расположить детали, возможно размер детали не соответствует размеру листа.");
			}
		}

	private:
		Denisenko::Raskroy::ResultsGenerator* m_raskroy;
		List<Part^>^ m_parts;
		List<Sheet^>^ m_sheets;
		Boolean m_started;
		ParametersCollection^ m_parameters;
		CuttingScheme^ m_result;

		Denisenko::Raskroy::Parts ConvertParts()
		{
			Denisenko::Raskroy::Parts result;
			
			for(Int32 i = 0; i < Parts->Count; i++)
			{
				Denisenko::Raskroy::Part part;
				part.rect.Size[0] = ToScaled(Parts[i]->Length);
				part.rect.Size[1] = ToScaled(Parts[i]->Width);
				part.Rotate = Parts[i]->CanRotate;
				part.Amount = Parts[i]->Quantity;
				part.Tag = i;
				result.push_back(part);
			}
			return result;
		}

		Denisenko::Raskroy::Parts ConvertSheets()
		{
			Denisenko::Raskroy::Parts result;
			for(Int32 i = 0; i < Sheets->Count; i++)
			{
				Denisenko::Raskroy::Part sheet;
				sheet.rect.Size[0] = ToScaled(Sheets[i]->Width - Parameters->CutOffLeft - Parameters->CutOffRight);
				sheet.rect.Size[1] = ToScaled(Sheets[i]->Height - Parameters->CutOffTop - Parameters->CutOffBottom);
				sheet.Tag = i;
				result.push_back(sheet);
			}
			return result;
		}

		CuttingScheme^ ConvertResult(const Denisenko::Raskroy::Result& input)
		{
			CuttingScheme^ result = gcnew CuttingScheme();
			result->Sheet = Sheets[input.sheet->Tag];
			result->Parameters = m_parameters;
			CuttingResultBuilder^ builder = gcnew CuttingResultBuilder();
			builder->LoadSections(input.raskroy, m_parameters, result);
			return result;
		}
	};
}
}
}
