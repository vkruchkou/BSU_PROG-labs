#include "Container1.h"
#include "Container2.h"
#include "Container3.h"
#pragma once
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
bool Container3::operator ==(Container1 const& obj)
{
	if (strcmp(Name, obj.Name) == 0)
		return true;
	else
		return false;
}
bool Container3::operator == (Container2 const& obj)
{
	if (strcmp(Name, obj.Name) == 0)
		return true;
	else
		return false;
}
Container3& Container3::operator=(Container1 const& obj)
{
	strcpy(Name, obj.Name);
	SredniyBal = obj.SredniyBal;
	return *this;
}
Container3& Container3::operator=(Container2 const& obj)
{
	strcpy(Name, obj.Name);
	return *this;
}
Container3& Container3::operator=(Container3 const& obj)
{
	strcpy(Name, obj.Name);
	SredniyBal = obj.SredniyBal;
	return *this;
}