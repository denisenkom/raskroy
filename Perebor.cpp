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
scalar Perebor::Recursion(scalar i_size, std::list<std::pair<const OtherSize*, unsigned> > & layout)
{
    unsigned amount = 0;
    std::for_each(m_pOtherSize->parts.begin(), m_pOtherSize->parts.end(),
                  [&amount, this](Part * part){amount += (*m_remains)[part->AmountOffset];});
	if (m_pOtherSize != m_pEndOtherSize)
	{
		scalar bestRemain = i_size;
		bool first = true;
		scalar size = i_size;
		unsigned n = 0;

		while (n <= amount && size > m_sawThickness)
		{
			scalar remain;
            std::list<std::pair<const OtherSize *, unsigned> > sublayout;
			m_pOtherSize++;
			remain = Recursion(size, sublayout);
			m_pOtherSize--;
			if (remain < bestRemain || first)
			{
				bestRemain = remain;
                sublayout.push_front(std::make_pair(&*m_pOtherSize, n));
                layout.swap(sublayout);
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
		if (n > amount)
			n = amount;
        layout.clear();
        layout.push_back(std::make_pair(&*m_pOtherSize, n));
		//o_rashods.resize(m_remains->size());
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
bool Perebor::Make(const Size &size, scalar otherSize, t_raskroy::t_details &o_details, Amounts &o_rashods, scalar &o_remain, double &o_opilki)
{
	if (otherSize < size.other_sizes.Min->Value)
		return false;

	// настройка переменных для рекурсии
	m_pOtherSize = size.other_sizes.begin();
	m_pEndOtherSize = size.other_sizes.end();
	m_pEndOtherSize--;
	// рекурсивный подбор для размеров [i..end]
    std::list<std::pair<const OtherSize *, unsigned> > layout;
	scalar remain = Recursion(otherSize, layout);
	if (remain == otherSize)	// если ничего небыло расположено
		return false;

	auto cuts = 0;// количество пилов
	for (auto sz = layout.begin(); sz != layout.end(); sz++)
	{
        auto consumed = sz->second;
        auto os = sz->first;
        if (consumed > 0)
		{
            auto consume_remain = consumed;
			t_raskroy::t_detail detail;
            // fill o_rashods
            // and fill parts attribute
            for (auto part_iter = os->parts.begin();
                 part_iter != os->parts.end(); part_iter++)
            {
                auto ppart = *part_iter;
                auto part_remain = (*m_remains)[ppart->AmountOffset];
                auto to_consume = std::min(part_remain, consume_remain);
                o_rashods[ppart->AmountOffset] += to_consume;
                consume_remain -= to_consume;
                detail.parts.push_back(std::make_pair(ppart, to_consume));
            }
            detail.size = sz->first->Value;
            detail.num = consumed;
			o_details.push_back(detail);
            cuts += consumed;	// количество пилов
		}
	}
	// Вычисляем количество опилок
	double opilki = (double)size.Value * (double)m_sawThickness * (double)cuts;
	// Если последний пил проходит по кромке то уменьшить количество опилок
	if (remain < 0)
	{
		opilki += (double)size.Value * (double)remain;
		remain = 0;
	}
	o_opilki = opilki;
	o_remain = remain;
	return true;
}

} // namespace Denisenko
} // namespace Raskroy
