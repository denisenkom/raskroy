#include "stdafx.h"
#include "perebor.h"

namespace raskroy {
	// Рекурсивный перебор
	// Параметры:
	//	[i] size - размер на котором нужно расположить детали
	//	[o] rashod - количество расположенных деталей
	//	[io] i
	//	[i] end
	//	[i] remains
	scalar perebor::recursive(scalar size, t_amounts &rashod)
	{
		scalar register size1;
		unsigned n;
		if (i != end)
		{
			n = 0;
			scalar best = size;
			bool first = true;
			size1 = size;
			t_amounts rashod1;
			unsigned remain = remains[i->offset];
			while (n <= remain && size1 > saw_thickness)
			{
				scalar remain;
				i++;
				remain = recursive(size1, rashod1);
				i--;
				if (remain < best || first)
				{
					best = remain;
					rashod = rashod1;
					rashod[i->offset] = n;
					if (best <= 0)
						return best;
					first = false;
				}
				n++;
				size1 = size - (i->size + saw_thickness)*n;
				// size1 здесь может быть < 0 что нормально если последний пил больше чем
				// кромка
			}
			// если ничего небыло расположено то возвращаем нули
			//if (best == size)
			//{
			//	rashod.resize(remains.size());
			//	std::fill(rashod.begin(), rashod.end(), 0);
			//}
			return best;
		}
		else
		{
			n = unsigned((size + saw_thickness)/(i->size + saw_thickness));
			unsigned remain = remains[i->offset];
			if (n > remain)
				n = remain;
			rashod.resize(remains.size());
			std::fill(rashod.begin(), rashod.end(), 0);
			rashod[i->offset] = n;
			size1 = size - n*(i->size + saw_thickness);
			// size1 здесь может быть < 0 что нормально если последний пил больше чем
			// кромка
			return size1;
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
	bool perebor::make(const t_size &size, scalar other_size, t_raskroy::t_details &details, t_amounts &rashod)
	{
		if (other_size < size.other_sizes.min->size)
			return false;

		// настройка переменных для рекурсии
		i = size.other_sizes.begin();
		end = size.other_sizes.end(); end--;
		// рекурсивный подбор для размеров [i..end]
		remain = recursive(other_size, rashod);
		if (remain == other_size)	// если ничего небыло расположено
			return false;

		unsigned nums = 0;
		for (i = size.other_sizes.begin(); i != size.other_sizes.end(); i++)
		{
			unsigned rashodi = rashod[i->offset];
			if (rashodi > 0)
			{
				t_raskroy::t_detail detail;
				detail.size = i->size;
				detail.num = rashodi;
				details.push_back(detail);
				nums += rashodi;	// количество пилов
			}
		}
		// Вычисляем количество опилок
		opilki = size.size*saw_thickness*nums;
		// Если последний пил проходит по кромке то уменьшить количество опилок
		if (remain < 0)
		{
			opilki += size.size*remain;
			remain = 0;
		}
		return true;
	}
}