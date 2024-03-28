#include "Container1.h"
#include "Container2.h"
#include "Container3.h"
#include "Container.h"
#pragma once
template <class T>
CONTAINER<T>::CONTAINER() : n(0), mas(NULL)
{}
template <class T>
CONTAINER<T>::CONTAINER(int nn) : n(nn), mas(new T[n])
{}
template <class T>
CONTAINER<T>::CONTAINER(const CONTAINER<T>& obj) : n(obj.n)
{
	if (mas != NULL)
		delete[] mas;
	mas = new T[n];
	for (int i = 0; i < n; i++)
		mas[i] = obj.mas[i];
}
template <class T>
CONTAINER<T>::~CONTAINER()
{
	delete[] mas;
}
template <class T>
std::ostream & operator<<(std::ostream& os, CONTAINER<T> const& obj)
{
	for (int i = 0; i < obj.n; i++)
		os << obj.mas[i] << "\n";
	return os;
}
template <class T>
std::istream & operator>>(std::istream& is, CONTAINER<T> const& obj)
{
	for (int i = 0; i < obj.n; i++)
		is >> obj.mas[i];
	return is;
}
template <class T>
void bcout(CONTAINER<T> const& obj)
{
	//ifstream f("data.dat", ios::binary);
	////f.open("data.dat",ios::binary);
	//f << obj;
	//f.close();
}
template <class T>
CONTAINER<T>& CONTAINER<T>::operator = (const CONTAINER<T>& obj)
{
	if (this != &obj)
	{
		if (mas != NULL)
			delete[] mas;
		n = obj.n;
		mas = new T[n];
		for (int i = 0; i < n; i++)
			mas[i] = obj.mas[i];
	}
	return *this;
}
template <class T>
T& CONTAINER<T>::operator[] (int i)
{
	return mas[i];
}
template <class T>
template <class T1, class T2>
void CONTAINER<T>::peresech(const CONTAINER<T1>& obj1, const CONTAINER<T2>& obj2)
{
	int k = 0;
	for (int i = 0; i < obj1.n; i++)
		for (int j = 0; i < obj2.n; j++)
			if (obj1.mas[i] == obj2.mas[j])
				k++;
	if (mas != NULL)
		delete[] mas;
	mas = new T[k];
	k = 0;
	for (int i = 0; i < obj1.n; i++)
		for (int j = 0; i < obj2.n; j++)
			if (obj1.mas[i] == obj2.mas[j])
			{
				mas[k] = obj1.mas[i];
				k++;
			}
}
//template <class T>
//void Csearch (const CONTAINER<T>& obj1, const Container2& obj2)
//{}
CONTAINER<Container1> CONTAINER<Container1>::CSort()
{
	int i = 0, j = 0, f = 0;
	while (i < n && f)
	{
		f = 0;
		for (j = n - 1; j > i; j--)
			if (mas[j - 1].SredniyBal > mas[j].SredniyBal)
			{
				std::swap(mas[j - 1], mas[j]);
				f = 1;
			}
		i++;
		return *this;
	}
}