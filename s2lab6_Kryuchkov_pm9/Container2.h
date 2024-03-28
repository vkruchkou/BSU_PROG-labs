#define _CRT_SECURE_NO_WARNINGS
#include "Container3.h"
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#pragma warning(disable : 4996)
struct Container2
{
	char Name[50];
	char Space[50];
	Container2() { strcpy(Space, "/0"); strcpy(Name, "/0");};
	Container2(char *mas1, char *mas2) { strcpy(Name, mas1); strcpy(Space, mas2);};
	friend std::ostream & operator<<(std::ostream& os, Container2 const& obj);
	friend std::istream & operator<<(std::istream& is, Container2 const& obj);
	bool operator ==(Container1 const& obj);
	bool operator ==(Container3 const& obj);
	Container2& operator=(Container1 const& obj);
	Container2& operator=(Container2 const& obj);
	Container2& operator=(Container3 const& obj);

};