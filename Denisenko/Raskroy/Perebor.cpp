#include "stdafx.h"
#include "Perebor.h"

namespace Denisenko {
namespace Raskroy {

// Рекурсивный перебор
// Параметры:
//	[i] size - размер на котором нужно расположить детали
//	[o] rashod - количество расположенных деталей
// this:
//	[io] m_pOtherSize
//	[i]  m_pEndOtherSize
//	[i]  m_remains
scalar Perebor::Recursion(scalar i_size, Amounts &o_rashods)
{
	if (m_pOtherSize != m_pEndOtherSize)
	{
		scalar bestRemain = i_size;
		bool first = true;
		scalar size = i_size;
		unsigned n = 0;
		unsigned amount = m_remains[m_pOtherSize->Offset];

		while (n <= amount && size > m_sawThickness)
		{
			scalar remain;
			Amounts rashods;
			m_pOtherSize++;
			remain = Recursion(size, rashods);
			m_pOtherSize--;
			if (remain < bestRemain || first)
			{
				bestRemain = remain;
				o_rashods = rashods;
				rashods[m_pOtherSize->Offset] = n;
				if (bestRemain <= 0) // лучше быть не может
					return bestRemain;
				first = false;
			}
			size -= m_pOtherSize->Value + m_sawThickness;
			n++;
			// size здесь может быть < 0 что нормально если последний пил больше чем
			// кромка
		}
		// если ничего небыло расположено то возвращаем нули
		//if (best == size)
		//{
		//	rashod.resize(remains.size());
		//	std::fill(rashod.begin(), rashod.end(), 0);
		//}
		return bestRemain;
	}
	else
	{
		scalar fullSize = m_pOtherSize->Value + m_sawThickness;
		unsigned n = unsigned((i_size + m_sawThickness) / fullSize);
		unsigned amount = m_remains[m_pOtherSize->Offset];
		if (n > amount)
			n = amount;
		o_rashods.resize(m_remains.size());
		std::fill(o_rashods.begin(), o_rashods.end(), 0);
		o_rashods[m_pOtherSize->Offset] = n;
		// результат здесь может быть < 0 что нормально если последний пил больше чем
		// кромка
		return i_size - n * fullSize;
	}
}

// Перебор деталей одного базисного размера на другом размере с контролем остатков
// Параметры:
//		[i] size - базисный размер
//		[i] other_size - перпендикулярный размер
//		[o] stat - статистика
//		[o] details - расположение деталей, на вход подается пустой контейнер
//		[o] rashod - расход деталей
// Возвращает true если хотя бы одна деталь установлена
bool Perebor::Make(const Size &size, scalar otherSize, t_raskroy::t_details &details, Amounts &rashods, scalar &o_remain, scalar &o_opilki)
{
	if (otherSize < size.OtherSizes.Min->Value)
		return false;

	// настройка переменных для рекурсии
	m_pOtherSize = size.OtherSizes.begin();
	m_pEndOtherSize = size.OtherSizes.end();
	m_pEndOtherSize--;
	// рекурсивный подбор для размеров [i..end]
	scalar remain = Recursion(otherSize, rashods);
	if (remain == otherSize)	// если ничего небыло расположено
		return false;

	unsigned cuts = 0;// количество пилов
	for (OtherSizes::const_iterator pOtherSize = size.OtherSizes.begin(); pOtherSize != size.OtherSizes.end(); pOtherSize++)
	{
		unsigned rashod = rashods[pOtherSize->Offset];
		if (rashod > 0)
		{
			t_raskroy::t_detail detail;
			detail.size = pOtherSize->Value;
			detail.num = rashod;
			details.push_back(detail);
			cuts += rashod;	// количество пилов
		}
	}
	// Вычисляем количество опилок
	scalar opilki = size.Value * m_sawThickness * cuts;
	// Если последний пил проходит по кромке то уменьшить количество опилок
	if (remain < 0)
	{
		opilki += size.Value * remain;
		remain = 0;
	}
	o_opilki = opilki;
	o_remain = remain;
	return true;
}

} // namespace Denisenko
} // namespace Raskroy