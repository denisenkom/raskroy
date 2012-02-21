#include "perebor.h"

namespace raskroy {
	Perebor::Perebor(t_amounts &remains, scalar saw_thickness)
		: remains(remains), saw_thickness(saw_thickness)
	{
	}

	// Рекурсивный перебор
	// Параметры:
	//		[i] size - размер на котором нужно расположить детали
	//		[o] rashod - количество расположенных деталей
	scalar Perebor::recursive(scalar size, t_amounts &rashod)
	{
		//if (i == perebor_other_sizes->end())
		//	return size;
		scalar register size1;
		//t_amounts best_amounts(amounts.size());
		unsigned n;
		if (i != end)
		{
			n = 0;
			scalar best = size;
			size1 = size;
			t_amounts rashod1;
			rashod1.resize(rashod.size());
			std::fill(rashod1.begin(), rashod1.end(), 0);
			unsigned remain = i->num(remains);
			while (size1 > saw_thickness && n < remain)
			{
				scalar remain;
				//if (size1 < perebor_minimum_size - factory.saw_thickness)
				//	remain = size1;
				//else
				//{
					i++;
					remain = recursive(size1, rashod1);
					i--;
				//}
				if (remain < best)
				{
					best = remain;
					//perebor_i->n = n;
					std::copy(rashod1.begin(), rashod1.end(), rashod.begin());
					i->make_rashod(rashod, n, remains);
				}
				n++;
				size1 = size - (i->size + saw_thickness)*n;
			}
			//amounts = best_amounts;
			return best;
		}
		else
		{
			n = unsigned((size + saw_thickness)/(i->size + saw_thickness));
			unsigned remain = i->num(remains);
			if (n > remain)
				n = remain;
			i->make_rashod(rashod, n, remains);
			size1 = size - n*(i->size + saw_thickness);
			return size1;
		}
	}

	// Перебор деталей одного базисного размера на другом размере с контролем остатков
	// Параметры:
	//		[i] size - базисный размер
	//		[i] other_size - перпендикулярный размер
	//		[o] stat - статистика
	//		[o] raskroy - расположение деталей
	//		[o] rashod - расход деталей
	// Возвращает true если хотя бы одна деталь установлена
	bool Perebor::make(const t_size &size, scalar other_size, t_stat &stat, t_raskroy &raskroy, t_amounts &rashod)
	{
		if (other_size < size.other_sizes.watchMin()->size)
			return false;

		unsigned nums = 0;
		i = size.other_sizes.begin();
		end = size.other_sizes.end();
		end--;
		scalar remain = recursive(other_size, rashod);
		if (remain < other_size)
		{
			for (i = size.other_sizes.begin(); i != size.other_sizes.end(); i++)
			{
				unsigned rashodi = i->num(rashod);
				if (rashodi > 0)
				{
					t_raskroy::t_detail detail;
					detail.size = i->size;
					detail.num = rashodi;
					raskroy.details.push_back(detail);
					nums += rashodi;
				}
			}
			stat.sum_cut_length = size.size*(nums);
			stat.sum_remain = size.size*saw_thickness;
			this->remain = remain;
			return true;
		}
		else
			return false;
	}
}