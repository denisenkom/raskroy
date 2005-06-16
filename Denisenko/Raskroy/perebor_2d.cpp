#include "stdafx.h"
#include "Perebor2d.h"

namespace Denisenko {
namespace Raskroy {

// Раскрой листа по длине и по ширине, возвращает лучший выриант
// Параметры:
//		[i] rect - размер листа
//		[i/o] stat - статистика
//		[o] raskroy - раскрой листа
//		[o] rashod - расход деталей
//
inline bool Perebor2d::bylen_bywid(const t_rect &rect, t_stat &stat, int s, t_raskroy &raskroy, t_amounts &rashod)
{
	// Пробуем расположить по размеру s
	t_stat stat2(stat);
	if (recursive(sizes[s].begin(), rect, stat, s, raskroy, rashod))
	{
		// Если удачно, то пробуем расположить по размеру !s
		t_amounts rashod2;
		t_raskroy raskroy2;
		if (recursive(sizes[!s].begin(), rect, stat2, !s, raskroy2, rashod2)
			&& /*pcriteria->quality(*/stat2/*)*/ > /*pcriteria->quality(*/stat/*)*/)
		{
			// Если удачно и личше чем по s, то результат будет как по !s
			stat = stat2;
			raskroy = raskroy2;
			rashod = rashod2;
		}
		// Иначе результат как по s
		return true;
	}
	// Иначе нет результата как по s
	return false;
}

// Рекурсивный перебор всех делений листа по длине/ширине (s=0/1) с возможностью кратного расположения
// Параметры:
//		[i] list - размеры листа
//		[i/o] stat - статистика
//		[i] s - выбор направления раскроя по длине/ширине s=0/1
//		[o] raskroy - раскрой листа
//		[o] rashod - расход деталей
//
bool Perebor2d::recursive(t_sizes::iterator begin, const t_rect &rect, t_stat &stat, int s, t_raskroy &raskroy, t_amounts &rashod)
{
	if (begin == sizes[s].end())
		// здесь может произойти зацикливание
		return recursive(sizes[!s].begin(), rect, stat, !s, raskroy, rashod);

	bool first = true;
	t_stat best_stat;	// лучшая статистика внутри цикла, при выходе прибавляется к входной статистике

	// переменные располагаем здесь чтобы избежать лишней инициализации
	t_amounts rashod_perebor, vrashod, rashod1;
	t_raskroy remain_raskroy;	
	t_raskroy recurse_raskroy;
	for (t_sizes::iterator i = begin; i != sizes[s].end(); i++)
	{
		// если размер слишком большой, то закончить цикл,
		// т.к. следующие размеры будут еще больше
		if (i->size > rect.size[s])
			break;

		t_raskroy::t_details details;
		if (!perebor.make(*i, rect.size[!s], details, rashod_perebor))
			continue;

		//stat1.sum_cut_length += rect.size[!s];
		// Добавляем опилки
		scalar opilki1 = perebor.opilki + (rect.size[!s] - perebor.remain)*perebor.saw_thickness;
		scalar opilki2 = perebor.remain*perebor.saw_thickness;
		// Вычисляем остаточный квадрат
		t_rect remain_rect;
		remain_rect.size[s] = i->size;
		remain_rect.size[!s] = perebor.remain;
		// Вычисляем квадрат для рекурсии
		t_rect recurse_rect(rect);
		// Величина, на которую будет уменьшен квадрат рекурсии
		scalar reduce = i->size + perebor.saw_thickness;

		// Рассчет кратности
		int max_kratnostj = int((rect.size[s] + perebor.saw_thickness)/(i->size + perebor.saw_thickness));
		if (max_kratnostj > 1)
		{
			int kol_krat = remains/rashod_perebor;
			if (max_kratnostj > kol_krat)
				max_kratnostj = kol_krat;
		}

		t_stat stat1(0);
		/*stat1.useful_remain = 0;
		stat1.unuseful_remain = 0;
		stat1.useful_num = 0;*/
		rashod1 = rashod_perebor;
		for (int kratnostj = 1; kratnostj <= max_kratnostj; kratnostj++)
		{
			// Корректировка расхода, статистики, квадратов в зависимости от кратности
			if (kratnostj > 1)
			{
				rashod1 = rashod_perebor*kratnostj;
				remain_rect.size[s] += i->size;
			}
			recurse_rect.size[s] -= reduce;
			stat1.opilki = opilki1*kratnostj + opilki2;
			if (recurse_rect.size[s] < 0)
			{
				stat1.opilki += rect.size[!s]*recurse_rect.size[s];
				recurse_rect.size[s] = 0;
			}

			// Кроим остаточный квадрат
			// Корректируем остатки в зависимости от получившегося расхода
			remains -= rashod1;	// потом нужно будет восстановить остатки
			bool have_remain;
			if (have_remain = bylen_bywid(remain_rect, stat1, !s, remain_raskroy, vrashod))
			//if (recursive(sizes[!s].begin(), rect1, stat1, !s, remain_raskroy, rashod))
			{
				// Если есть крой, то дополнительно корректируем остатки и расход
				rashod1 += vrashod;
				remains -= vrashod;
			}

			//if (!first && pcriteria->compare(&best_stat, &stat1))	// already bad
			//	continue;

			// Вызываем рекурсию
			bool have_recurse = recursive(i + 1, recurse_rect, stat1, s, recurse_raskroy, vrashod);
			remains += rashod1;	// восстанавливаем остатки

			// если результат лучше лучшего или первый то
			if (/*pcriteria->quality(*/stat1/*)*/ > /*pcriteria->quality(*/best_stat/*)*/ || first)
			{
				best_stat = stat1;
				raskroy.set(s,
					kratnostj,
					i->size, details,
					have_remain ? &remain_raskroy : 0,
					have_recurse ? &recurse_raskroy : 0);

				// rashod1 - расход в переборе+в остаточной части
				// vrashod - расход в ресурсивной части
				rashod = rashod1;
				if (have_recurse)
					rashod += vrashod;
				first = false;
			}
		}
	}
	// Если был результат
	if (!first)
	{
		// Добавляем нашу лучшую статистику к входной статистике
		stat += best_stat;
		// Раскрой и расход уже хранится в нужном месте
		return true;
	}

	// Если не было результата, то к статистике прибавляются отходы
	scalar rem = rect.square();
	if (rem == 0)
		return false;
	bool useful = (rect.size[0] >= 70 && rect.size[1] >= 200-34)
		|| (rect.size[1] >= 70 && rect.size[0] >= 200-34);
	assert(rem > 0);
	useful ? stat.useful_remain += rem, stat.useful_num++ : stat.unuseful_remain += rem, stat.useful_num++;
	return false;
}

} // namespace Denisenko
} // namespace Raskroy