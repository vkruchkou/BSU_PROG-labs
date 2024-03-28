#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#pragma warning(disable : 4996)
struct Container3
{
	char Name[50];
	int SredniyBal;
	Container3():SredniyBal(0) { strcpy(Name,"/0"); };
	Container3(char *mas, int ball) :SredniyBal(ball) { strcpy(Name, mas); };
	friend std::ostream & operator<<(std::ostream& os, Container3 const& obj);
	friend std::istream & operator<<(std::istream& is, Container3& obj);
	bool operator ==(Container1 const& obj);
	bool operator ==(Container2 const& obj);
	Container3& operator=(Container1 const& obj);
	Container3& operator=(Container2 const& obj);
	Container3& operator=(Container3 const& obj);
};