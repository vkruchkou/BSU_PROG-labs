#define _CRT_SECURE_NO_WARNINGS
#include "Container2.h"
#include "Container3.h"
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#pragma warning(disable : 4996)
struct Container1
{
	char Name[50];
	int SredniyBal;
	Container1() :SredniyBal(0) { strcpy(Name, "/0"); };
	Container1(char *mas, int ball) :SredniyBal(ball) { strcpy(Name, mas); };
	friend std::ostream & operator<<(std::ostream& os, Container1 const& obj);
	friend std::istream & operator<<(std::istream& is, Container1 & obj);
	bool operator == (Container1 const& obj);
	bool operator == (Container2 const& obj);
	bool operator ==(Container3 const& obj);
	Container1& operator=(Container1 const& obj);
	Container1& operator=(Container2 const& obj);
	Container1& operator=(Container3 const& obj);
};