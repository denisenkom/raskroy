#include "stdafx.h"
#include "Perebor2d.h"

namespace Denisenko {
namespace Raskroy {

// Раскрой листа по длине и по ширине, возвращает лучший выриант
// Параметры:
//		[i] rect - размер листа
//		[o] stat - статистика
//		[o] raskroy - раскрой листа
//		[o] rashod - расход деталей
//
inline bool Perebor2d::Optimize(const Rect &rect, Stat &stat, int s, t_raskroy &raskroy, Amounts &rashod)
{
	// Пробуем расположить по размеру s
	Stat stat1;
	if (Recursion(m_sizes[s].begin(), rect, stat1, s, raskroy, rashod))
	{
		// Если удачно, то пробуем расположить по размеру !s
#ifdef _DEBUG
		Stat checkStat;
		raskroy.CheckAndCalcStat(m_perebor.get_SawThickness(), rect, &checkStat);
		if(!checkStat.IsEqual(stat1))
		{
			raskroy.CheckAndCalcStat(m_perebor.get_SawThickness(), rect, &checkStat);
			assert(checkStat.IsEqual(stat1));
		}
#endif
		Amounts rashod2(rashod.size());
		t_raskroy raskroy2;
		Stat stat2;
		if (Recursion(m_sizes[!s].begin(), rect, stat2, !s, raskroy2, rashod2)
			&& /*pcriteria->quality(*/stat1/*)*/ < /*pcriteria->quality(*/stat2/*)*/)
		{
			// Если удачно и личше чем по s, то результат будет как по !s
#ifdef _DEBUG
			Stat checkStat;
			raskroy2.CheckAndCalcStat(m_perebor.get_SawThickness(), rect, &checkStat);
			if(!checkStat.IsEqual(stat2))
				assert(checkStat.IsEqual(stat2));
#endif
			stat = stat2;
			raskroy = raskroy2;
			rashod = rashod2;
		}
		else
		{
			stat = stat1;
		}
		// Иначе результат как по s
		return true;
	}
	// Иначе нет результата как по s
	return false;
}


void _parts_layout_fill(LayoutBuilder & layout, int axis, const Rect & rect, const t_raskroy::t_details & details, scalar saw_size) {
    scalar remain = rect.Size[axis];
    for (auto parti = details.begin();
            parti != details.end(); parti++)
    {
        LayoutElementBuilder part_el;
        part_el.type = ELEM_RECT;
        part_el.size = parti->size;
        // TODO: implement the case when there are many parts
        // on the other_size
        part_el.part = parti->other_size;
        for (auto i = 0; i < parti->num; i++) {
            assert(remain >= parti->size);
            layout.elements.push_back(part_el);
            remain -= parti->size;

            // adding cut element
            if (remain > 0) {
                scalar cut_size = std::min(saw_size, remain);
                layout.append_cut(cut_size);
                remain -= cut_size;
            }
        }
    }
}


bool Perebor2d::new_optimize(const Rect &rect, LayoutBuilder &layout)
{
    // choose best (biggest) size to start with
    const Size * best_by[2] = {0};
    for (int i = 0; i <= 1; i++) {
        // get biggest size that fits by i axis
        for (auto sizei = m_sizes[i].begin();
             sizei != m_sizes[i].end(); sizei++)
        {
            if (sizei->Value <= rect.Size[i]) {
                best_by[i] = &*sizei;
                break;
            }
        }
    }
    int best_parts_axis;
    const Size * best_size;
    if (!best_by[0] || !best_by[1]) {
        return false;
    } else if (best_by[0] && best_by[1]) {
        // if both axises match, choose best of them
        // best is the one with biggest usage ratio to sheet
        if (double(best_by[0]->Value) / double(rect.Size[0]) >= double(best_by[1]->Value) / double(rect.Size[1])) {
            best_parts_axis = 1;
            best_size = best_by[0];
        } else {
            best_parts_axis = 0;
            best_size = best_by[1];
        }
    } else if (best_by[0]) {
        best_parts_axis = 1;
        best_size = best_by[0];
    } else {
        best_parts_axis = 0;
        best_size = best_by[1];
    }

    // do 1D bin packing optimization
	double cut;
	Amounts rashodPerebor(m_remains->size());
	scalar remain;
    t_raskroy::t_details details;
	if (!m_perebor.Make(*best_size, rect.Size[best_parts_axis], details, rashodPerebor, remain, cut))
		return false;

    *m_remains -= rashodPerebor;

    scalar saw_size = m_perebor.get_SawThickness();
    Rect parts_block;
    parts_block.Size[!best_parts_axis] = best_size->Value;
    parts_block.Size[best_parts_axis] = rect.Size[best_parts_axis] - remain - saw_size;
    scalar remain_bottom_height = rect.Size[1] - parts_block.Size[1] - saw_size;
    scalar remain_right_width = rect.Size[0] - parts_block.Size[0] - saw_size;

    // choose "best" main cut direction, along 0 or 1 axis
    // best is the one that produce remaining rect with biggest square
    // consider cut along x (0) axis
    double remain_x_bottom = double(rect.Size[0]) * double(remain_bottom_height);
    double remain_x_right =  double(remain_right_width) * double(parts_block.Size[1]);
    double max_remain_x = std::max(remain_x_bottom, remain_x_right);
    // consider cut along y (1) axis
    double remain_y_bottom = double(parts_block.Size[0]) * double(remain_bottom_height);
    double remain_y_right = double(remain_right_width) * double(rect.Size[1]);
    double max_remain_y = std::max(remain_y_bottom, remain_y_right);
    int x_axis;
    if (max_remain_x >= max_remain_y) {
        // do layout along Y axis, main cut along X axis
        x_axis = 0;
    } else {
        // do layout along X axis, main cut along Y axis
        // transpose coordinates
        x_axis = 1;
    }

    // comments below assumes axis = 1, if axis = 0 comments are true
    // if you transpose coordinates

    // best main cut is along x axis
    int y_axis = !x_axis;
    layout.axis = y_axis;
    scalar remain_x = rect.Size[x_axis];
    scalar remain_y = rect.Size[y_axis];

    // horizontal sub-layout for top part containing details
    std::unique_ptr<LayoutBuilder> top_layout(new LayoutBuilder);
    top_layout->axis = x_axis;

    // parts sub-sub-layout
    std::unique_ptr<LayoutBuilder> pparts_layout(new LayoutBuilder);
    pparts_layout->axis = best_parts_axis;
    _parts_layout_fill(*pparts_layout, best_parts_axis, parts_block, details, saw_size);
    top_layout->append_sublayout(pparts_layout, parts_block.Size[x_axis]);
    assert(parts_block.Size[x_axis] <= remain_x);
    remain_x -= parts_block.Size[x_axis];

    if (remain_x > 0) {
        // vertical cut separating parts block and right remain
        auto cut_size = std::min(saw_size, remain_x);
        top_layout->append_cut(cut_size);
        remain_x -= cut_size;

        if (remain_x > 0) {
            // sublayout for right remain
            Rect remain_right(remain_x, parts_block.Size[y_axis]);
            std::unique_ptr<LayoutBuilder> pright_layout(new LayoutBuilder);
            if (new_optimize(remain_right, *pright_layout)) {
                top_layout->append_sublayout(pright_layout, remain_x);
            } else {
                top_layout->append_remain(remain_x);
            }
        }
    }

    // adding top sub-layout to resulting layout
    layout.append_sublayout(top_layout, parts_block.Size[y_axis]);
    remain_y -= parts_block.Size[y_axis];
    assert(remain_y >= 0);

    if (remain_y > 0) {
        // horizontal cut separating top and bottom remain
        auto cut_size = std::min(saw_size, remain_y);
        layout.append_cut(cut_size);
        remain_y -= cut_size;

        if (remain_y > 0) {
            // create layout for bottom part
            std::unique_ptr<LayoutBuilder> pbottom_layout(new LayoutBuilder);
            Rect remain_bottom(rect.Size[x_axis], remain_y);
            if (new_optimize(remain_bottom, *pbottom_layout)) {
                layout.append_sublayout(pbottom_layout, remain_y);
            } else {
                layout.append_remain(remain_y);
            }
        }
    }
    return true;
}


class NestingCounterGuard
{
public:
	NestingCounterGuard(int* counterPtr) : m_counterPtr(counterPtr) { (*m_counterPtr)++; }
	~NestingCounterGuard() { (*m_counterPtr)--; }

private:
	int* m_counterPtr;
};

class CompletedCounterGuard
{
public:
	CompletedCounterGuard(int* nestingPtr, int* counterPtr)
		: m_nestingPtr(nestingPtr), m_counterPtr(counterPtr)
	{
	}

	~CompletedCounterGuard()
	{
		if((*m_nestingPtr) == 1)
		{
			(*m_counterPtr)++;
		}
	}
private:
	int* m_counterPtr;
	int* m_nestingPtr;
};

// Рекурсивный перебор всех делений листа по длине/ширине (s=0/1) с возможностью кратного расположения
// Параметры:
//		[i] list - размеры листа
//		[o] stat - статистика
//		[i] s - выбор направления раскроя по длине/ширине s=0/1
//		[o] raskroy - раскрой листа
//		[o] rashod - расход деталей
//
bool Perebor2d::Recursion(Sizes::iterator begin, const Rect &rect, Stat &stat, int s, t_raskroy &raskroy, Amounts &rashod)
{
	NestingCounterGuard nestingCounterGuard(&m_nesting);

	if (begin == m_sizes[s].end())
	{
		// здесь может произойти зацикливание
		return Recursion(m_sizes[!s].begin(), rect, stat, !s, raskroy, rashod);
	}

	bool first = true;
	Stat bestStat;	// лучшая статистика внутри цикла, при выходе прибавляется к входной статистике

	// переменные располагаем здесь чтобы избежать лишней инициализации
	Amounts rashodPerebor(rashod.size());
	Amounts vrashod(rashod.size());
	Amounts rashod1(rashod.size());
	t_raskroy remainRaskroy;	
	t_raskroy recurseRaskroy;
	t_raskroy::t_details details;
	for (Sizes::iterator i = begin; i != m_sizes[s].end(); i++)
	{
		CompletedCounterGuard completedCounterGuard(&m_nesting, &m_completedCounter);

		// если размер слишком большой, то закончить цикл,
		// т.к. следующие размеры будут еще больше
		if (i->Value > rect.Size[s])
			break;

		double opilki;
		scalar remain;
		details.clear();
		if (!m_perebor.Make(*i, rect.Size[!s], details, rashodPerebor, remain, opilki))
			continue;

		//stat1.sum_cut_length += rect.size[!s];
		// Добавляем опилки
		double opilki1 = opilki + (double)(rect.Size[!s] - remain) * (double)m_perebor.get_SawThickness();
		double opilki2 = (double)remain * (double)m_perebor.get_SawThickness();
		// Вычисляем остаточный квадрат
		Rect remainRect;
		remainRect.Size[s] = i->Value;
		remainRect.Size[!s] = remain;
		// Вычисляем квадрат для рекурсии
		Rect recurseRect(rect);
		// Величина, на которую будет уменьшен квадрат рекурсии
		scalar reduce = i->Value + m_perebor.get_SawThickness();

		// Рассчет кратности
		int maxKratnostj = int((rect.Size[s] + m_perebor.get_SawThickness()) / (i->Value + m_perebor.get_SawThickness()));
		if (maxKratnostj > 1)
		{
			int kolKrat = *m_remains / rashodPerebor;
			if (maxKratnostj > kolKrat)
				maxKratnostj = kolKrat;
		}

		Stat stat1;
		/*stat1.useful_remain = 0;
		stat1.unuseful_remain = 0;
		stat1.useful_num = 0;*/
		for (int kratnostj = 1; kratnostj <= maxKratnostj; kratnostj++)
		{
			stat1.MakeZero();
			// Корректировка расхода, статистики, квадратов в зависимости от кратности
			if (kratnostj > 1)
			{
				rashod1 = rashodPerebor * kratnostj;
				remainRect.Size[s] += m_perebor.get_SawThickness() + i->Value;
			}
			else if(kratnostj == 1)
			{
				rashod1 = rashodPerebor;
			}
			recurseRect.Size[s] -= reduce;
			stat1.Opilki = opilki1 * (double)kratnostj + opilki2;
			if (recurseRect.Size[s] < 0)
			{
				stat1.Opilki += (double)rect.Size[!s] * (double)recurseRect.Size[s];
				recurseRect.Size[s] = 0;
			}

			// Кроим остаточный квадрат
			// Корректируем остатки в зависимости от получившегося расхода
			*m_remains -= rashod1;	// потом нужно будет восстановить остатки
			Stat remainStat;
			bool haveRemain = Optimize(remainRect, remainStat, !s, remainRaskroy, vrashod);
			if (haveRemain)
			//if (Recursion(sizes[!s].begin(), rect1, stat1, !s, remain_raskroy, rashod))
			{
				// Если есть крой, то дополнительно корректируем остатки и расход
				stat1 += remainStat;
				rashod1 += vrashod;
				*m_remains -= vrashod;
			}
			else
			{
				stat1.AddScrap(remainRect);
			}

			//if (!first && pcriteria->compare(&best_stat, &stat1))	// already bad
			//	continue;

			// Вызываем рекурсию
			Stat recurseStat;
			bool haveRecurse = Recursion(i + 1, recurseRect, recurseStat, s, recurseRaskroy, vrashod);
			if(haveRecurse)
			{
#ifdef _DEBUG
				Stat checkStat;
				recurseRaskroy.CheckAndCalcStat(m_perebor.get_SawThickness(), recurseRect, &checkStat);
				if(!checkStat.IsEqual(recurseStat))
				{
					//recurseRaskroy.CheckAndCalcStat(m_perebor.get_SawThickness(), recurseRect, &checkStat);
					assert(checkStat.IsEqual(recurseStat));
				}
#endif
				stat1 += recurseStat;
			}
			else
			{
				stat1.AddScrap(recurseRect);
			}
			*m_remains += rashod1;	// восстанавливаем остатки

			// если результат лучше лучшего или первый то
			if (bestStat < stat1 || first)
			{
				bestStat = stat1;
				raskroy.set(s,
					kratnostj,
					i->Value, details,
					haveRemain ? &remainRaskroy : 0,
					haveRecurse ? &recurseRaskroy : 0);

				// rashod1 - расход в переборе+в остаточной части
				// vrashod - расход в ресурсивной части
				rashod = rashod1;
				if (haveRecurse)
					rashod += vrashod;
				first = false;
			}
		}
		if (!first)
			break;
	}
	// Если был результат
	if (!first)
	{
		// Добавляем нашу лучшую статистику к входной статистике
		stat = bestStat;
		// Раскрой и расход уже хранится в нужном месте
		return true;
	}
	return false;
}

} // namespace Denisenko
} // namespace Raskroy
