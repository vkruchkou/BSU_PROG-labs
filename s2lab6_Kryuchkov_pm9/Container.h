#define _CRT_SECURE_NO_WARNINGS
#include "Container2.h"
#include "Container3.h"
#include "Container1.h"
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#pragma warning(disable : 4996)
template <class T>
class CONTAINER
{
public:
	T* mas;
	int n;
	CONTAINER<T>();
	CONTAINER<T>(int);
	CONTAINER(const CONTAINER&);
	~CONTAINER();
	friend std::ostream & operator<<(std::ostream&, CONTAINER const&);
	friend std::istream & operator>>(std::istream&, CONTAINER const&);
	friend void bcout(CONTAINER const&);
	CONTAINER& operator = (const CONTAINER&);
	T& operator[](int);
	template <class T1, class T2>
	void peresech(const CONTAINER<T1>&, const CONTAINER< T2> &);
	CONTAINER<Container1> CSort();
};