// Planer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "time.h"

class order
{
	time_t date_of_release;
	//t_details details;
};

typedef std::list<order> t_orders;

order template_orders[] = {
	order()//,
};

void insert_order(order & x)
{
	// ¬ыбрать заказы с таким же цветом и сроком выдачи в пределах недели от этого заказа
	// ??? „то если они пересекаютс€

	// ”брать карты раскро€ заказов из производственного плана

	// ѕолучить карты раскро€ дл€ выбранных заказов

	// распределить полученные карты раскро€ по заказам

	// ќптимально вставить карты раскро€ в производственный план
}

int _tmain(int argc, _TCHAR* argv[])
{
	//tm x;

	return 0;
}