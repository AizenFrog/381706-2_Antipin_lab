#include <iostream>
#include "Vector.h"
#include "Matrix.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	Matrix<int> a(5), b(5), c(5);
	cout << "Тестирование программ поддержки треугольных матриц" << endl;
	for (int i = 0; i < 5; i++)
		for (int g = 0; g < 5; g++)
		{
			a[i][g] = i * 10 + g;
			b[i][g] = (i * 10 + g) * 100;
		}
	c = a + b;
	cout << "Matrix a = " << endl << a << endl;
	cout << "Matrix b = " << endl << b << endl;
	cout << "Matrix c = a + b " << endl << c << endl;
	return 0;
}