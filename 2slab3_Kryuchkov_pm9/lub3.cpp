#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include "header.h"
using namespace std;
nmvect::nmvect(int n)
{
	vm = new double[n];
	nsize = n;
	for (int i = 0; i < n; i++)
	{
		vm[i] = 0.0;
	}
}
nmvect::~nmvect()
{
	delete[] vm;
}
nmvect::nmvect(nmvect const& oth) :nsize(oth.nsize), vm(new double[nsize])
{
	for (int i = 0; i < nsize; i++)
	{
		vm[i] = oth.vm[i];
	}
}
nmvect& nmvect::operator=(nmvect const& oth)
{
	if (&oth != this)
	{
		if (vm != NULL)
		{
			delete[] vm;
		}
		nsize = oth.nsize;
		vm = new double[nsize];
		for (int i = 0; i < nsize; i++)
		{
			vm[i] = oth.vm[i];
		}
	}
	return *this;
}
nmvect nmvect::operator+(nmvect const&oth)
{
	if (nsize != oth.nsize)
		throw exception( "ƒанна€ операци€ с векторами разной размерности невозможна/n");
	nmvect vv(*this);
	for (int i = 0; i < nsize; i++)
		vv.vm[i] += oth.vm[i];
	return vv;
}
nmvect nmvect::operator-(nmvect const&oth)
{
	if (nsize != oth.nsize)
		throw exception("ƒанна€ операци€ с векторами разной размерности невозможна/n");
	nmvect vv(*this);
	for (int i = 0; i < nsize; i++)
		vv.vm[i] = vv.vm[i] - oth.vm[i];
	return vv;
}
nmvect nmvect::operator*(double a)
{
	nmvect vv(*this);
	for (int i = 0; i < nsize; i++)
		vv.vm[i] = vv.vm[i] * a;
	return vv;
}
nmvect nmvect::operator/(double a)
{
	if (a == 0.0)
		throw exception("ƒеление на ноль невозможно\n");
	nmvect vv(*this);
	for (int i = 0; i < nsize; i++)
		vv.vm[i] = vv.vm[i] / a;
	return vv;
}
nmvect& nmvect::operator++()
{
	for (int i = 0; i < nsize; i++)
		vm[i] = vm[i] + 1.0;
	return *this;
}
nmvect nmvect::operator++(int)
{
	nmvect vv(*this);
	for (int i = 0; i < nsize; i++)
		vm[i] = vm[i] + 1.0;
	return vv;

}
nmvect& nmvect::operator--()
{
	for (int i = 0; i < nsize; i++)
		vm[i] = vm[i] - 1.0;
	return *this;
}
nmvect nmvect::operator--(int)
{
	nmvect vv(*this);
	for (int i = 0; i < nsize; i++)
		vm[i] = vm[i] - 1.0;
	return vv;

}
bool nmvect::operator==(nmvect const& oth)
{
	if (nsize != oth.nsize)
		throw exception("ƒанна€ операци€ с векторами разной размерности невозможна/n");
	for (int i = 0; i < nsize; i++)
		if (vm[i] != oth.vm[i])
			return false;
	return true;
}
bool nmvect::operator!=(nmvect const& oth)
{
	if (nsize != oth.nsize)
		throw exception("ƒанна€ операци€ с векторами разной размерности невозможна/n");
	for (int i = 0; i < nsize; i++)
		if (vm[i] != oth.vm[i])
			return true;
	return false;
}
bool nmvect::operator<=(nmvect const& oth)
{
	if (nsize != oth.nsize)
		throw exception("ƒанна€ операци€ с векторами разной размерности невозможна/n");
	double l = 0.0;
	double ll = 0.0;
	for (int i = 0; i < nsize; i++)
		l += (vm[i] * vm[i]);
	for (int i = 0; i < nsize; i++)
		ll += (oth.vm[i] * oth.vm[i]);
	if (l <= ll)
		return true;
	else
		return false;
}
bool nmvect::operator>=(nmvect const& oth)
{
	if (nsize != oth.nsize)
		throw exception("ƒанна€ операци€ с векторами разной размерности невозможна/n");
	double l = 0.0;
	double ll = 0.0;
	for (int i = 0; i < nsize; i++)
		l += (vm[i] * vm[i]);
	for (int i = 0; i < nsize; i++)
		ll += (oth.vm[i] * oth.vm[i]);
	if (l >= ll)
		return true;
	else
		return false;
}
double nmvect::operator[](int i)
{
	if (i > nsize - 1)
	{
		throw exception("ќшибка доступа/n");
	}
	return vm[i];
}
int nmvect::operator~()
{
	for (int i = 0; i < nsize; i++)
		vm[i] = vm[i] * (-1.0);
	return 0;
}
std::ostream & operator<<(std::ostream& os, nmvect const& vec)
{
	os << "(";
	int i = 0;
	for (; i < vec.nsize - 1; i++)
	{
		os << vec.vm[i] << ",";
	}
	os << vec.vm[i] << ")" << endl;
	return os;
}
std::istream & operator>>(std::istream& is, nmvect const& vec)
{
	for (int i = 0; i < vec.nsize; i++)
		is >> vec.vm[i];
	return is;
}
nmvect operator+(nmvect const& o1, nmvect const& o2)
{
	if (o2.nsize != o1.nsize)
		throw exception("ƒанна€ операци€ с векторами разной размерности невозможна/n");
	nmvect vv(o1.nsize);
	for (int i = 0; i < o1.nsize; i++)
		vv.vm[i] = o1.vm[i] + o2.vm[i];
	return vv;
}
nmvect operator-(nmvect const& o1, nmvect const& o2)
{
	if (o2.nsize != o1.nsize)
		throw exception("ƒанна€ операци€ с векторами разной размерности невозможна/n");
	nmvect vv(o1.nsize);
	for (int i = 0; i < o1.nsize; i++)
		vv.vm[i] = o1.vm[i] - o2.vm[i];
	return vv;
}
nmvect operator*(nmvect const& o1, double a)
{
	nmvect vv(o1.nsize);
	for (int i = 0; i < o1.nsize; i++)
		vv.vm[i] = o1.vm[i] * a;
	return vv;
}