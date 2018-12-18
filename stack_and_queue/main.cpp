#include "Multystack.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>

void main()
{
	setlocale(LC_ALL, "RUS");
	Multystack<int> mst(4, 100);
	int ms, val = 0;
	std::cout << "Тестирование системы N стеков:" << std::endl;
	for (ms = 0; ms < 40; ms++)
	{
		mst.Put(0, ms);
		val++;
	}
	for (ms = 40; ms < 70; ms++)
	{
		mst.Put(1, ms);
		val++;
	}
	for (ms = 70; ms < 90; ms++)
	{
		mst.Put(2, ms);
		val++;
	}
	for (ms = 90; ms < 100; ms++)
	{
		mst.Put(3, ms);
		val++;
	}
	std::cout << "Число циклов - " << val << ", перепаковок - " << mst.GetResizeCount() << std::endl;
}