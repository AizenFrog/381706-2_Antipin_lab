#pragma once
#include <iostream>

class Monom
{
protected:
	int n;//размер
	double c;//коэффициент
	unsigned int* power;//степени
	Monom* NextMonom;//следующий моном
public:
	Monom()
	{}
	Monom(int _n, unsigned int* _power, double _c);
	Monom(const Monom& monom);
	~Monom();
	int GetN();//вернуть размер
	double GetC();//вернуть коэффициент
	unsigned int* GetPower();//вернуть указатель на степени
	Monom* GetNextMonom();//вернуть указатель на следующий моном
	void SetN(int _n);//изменить размер
	void SetC(double _c);//изменить коэффициент
	void SetPower(unsigned int* _power);//изменить степени
	void SetNextMonom(Monom* monom);//изменить указатель на следующий моном
	Monom& operator=(const Monom& monom);
	Monom operator+(const Monom& monom);
	Monom operator-(const Monom& monom);
	Monom operator*(const Monom& monom);
	bool operator==(const Monom& monom);
	bool operator>(const Monom& monom);
	bool operator<(const Monom& monom);
	friend std::ostream& operator<<(std::ostream& os, Monom& monom);
};

