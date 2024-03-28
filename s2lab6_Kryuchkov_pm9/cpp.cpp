#include "h.h"
#pragma once
std::ostream & operator<<(std::ostream& os, Container1 const& obj)
{
	os << obj.Name << " " << obj.SredniyBal << "\n";
	return os;
}
std::istream & operator<<(std::istream& is, Container1 & obj)
{
	char * str = new char[256];
	is >> str;
	int t;
	is >> t;
	obj.SredniyBal = t;
	strcpy(str, obj.Name);
	delete[]str;
	return is;
}

template<>
bool Container1::operator == (Container1 const& obj)
{
	if (strcmp(Name, obj.Name) == 0)
		return true;
	else
		return false;
}
template<>
bool Container1::operator == (Container2 const& obj)
{
	if (strcmp(Name, obj.Name) == 0)
		return true;
	else
		return false;
}
template<>
bool Container1::operator ==(Container3 const& obj)
{
	if (strcmp(Name, obj.Name) == 0)
		return true;
	else
		return false;
}
template<class T>
bool Container1::operator == (T const& obj)
{
	return false;
}
template<>
Container1& Container1::operator=(Container1 const& obj)
{
	strcpy(Name, obj.Name);
	SredniyBal = obj.SredniyBal;
	return *this;
}
template<>
Container1& Container1:: operator=(Container2 const& obj)
{
	strcpy(Name, obj.Name);
	return *this;
}
template<>
Container1& Container1::operator=(Container3 const& obj)
{
	strcpy(Name, obj.Name);
	SredniyBal = obj.SredniyBal;
	return *this;
}
template<class T>
Container1&  Container1::operator=(T const& obj)
{
	throw std::exception("Error\n");
}



std::ostream & operator<<(std::ostream& os, Container2 const& obj)
{
	os << obj.Name << " " << obj.Space << "\n";
	return os;
}
std::istream & operator<<(std::istream& is, Container2 const& obj)
{
	char * str = new char[256];
	is >> str;
	strcpy(str, obj.Name);
	is >> str;
	strcpy(str, obj.Space);
	delete[]str;
	return is;
}
template<>
bool Container2::operator ==(Container1 const& obj)
{
	if (strcmp(Name, obj.Name) == 0)
		return true;
	else
		return false;
}
template<>
bool Container2::operator ==(Container2 const& obj)
{
	if (strcmp(Name, obj.Name) == 0)
		if (strcmp(Space, obj.Space) == 0)
			return true;
	else
		return false;
}
template<>
bool Container2::operator ==(Container3 const& obj)
{
	if (strcmp(Name, obj.Name) == 0)
		return true;
	else
		return false;
}
template<>
Container2& Container2::operator=(Container1 const& obj)
{
	strcpy(Name, obj.Name);
	return *this;
}
template<>
Container2& Container2::operator=(Container2 const& obj)
{
	strcpy(Name, obj.Name);
	strcpy(Space, obj.Space);
	return *this;
}
template<>
Container2& Container2::operator=(Container3 const& obj)
{
	strcpy(Name, obj.Name);
	return *this;
}
template<class T>
bool Container2::operator == (T const& obj)
{
	return false;
}
template<class T>
Container2& Container2::operator=(T const& obj)
{
	throw std::exception("Error\n");
}



std::ostream & operator<<(std::ostream& os, Container3 const& obj)
{
	os << obj.Name << " " << obj.SredniyBal << "\n";
	return os;
}
std::istream & operator<<(std::istream& is, Container3& obj)
{
	char * str = new char[256];
	is >> str;
	int t;
	is >> t;
	obj.SredniyBal = t;
	strcpy(str, obj.Name);
	delete[]str;
	return is;
}
template<>
bool Container3::operator ==(Container1 const& obj)
{
	if (strcmp(Name, obj.Name) == 0)
		return true;
	else
		return false;
}
template<>
bool Container3::operator == (Container2 const& obj)
{
	if (strcmp(Name, obj.Name) == 0)
		return true;
	else
		return false;
}
template<>
bool Container3::operator == (Container3 const& obj)
{
	if (strcmp(Name, obj.Name) == 0)
		return true;
	else
		return false;
}
template<>
Container3& Container3::operator=(Container1 const& obj)
{
	strcpy(Name, obj.Name);
	SredniyBal = obj.SredniyBal;
	return *this;
}
template<>
Container3& Container3::operator=(Container2 const& obj)
{
	strcpy(Name, obj.Name);
	return *this;
}
template<>
Container3& Container3::operator=(Container3 const& obj)
{
	strcpy(Name, obj.Name);
	SredniyBal = obj.SredniyBal;
	return *this;
}
template<class T>
bool Container3::operator == (T const& obj)
{
	return false;
}
template<class T>
Container3& Container3::operator=(T const& obj)
{
	throw std::exception("Error\n");
}


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
	//ofstream f;
	//f.open("data.dat",ios::binary);
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
	}
	return *this;
}