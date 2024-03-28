#include "Container1.h"
#include "Container3.h"
#include "Container2.h"
#pragma once
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
bool Container2::operator ==(Container1 const& obj)
{
	if (strcmp(Name, obj.Name) == 0)
		return true;
	else
		return false;
}
bool Container2::operator ==(Container3 const& obj)
{
	if (strcmp(Name, obj.Name) == 0)
		return true;
	else
		return false;
}
Container2& Container2::operator=(Container1 const& obj)
{
	strcpy(Name, obj.Name);
	return *this;
}
Container2& Container2::operator=(Container2 const& obj)
{
	strcpy(Name, obj.Name);
	strcpy(Space, obj.Space);
	return *this;
}
Container2& Container2::operator=(Container3 const& obj)
{
	strcpy(Name, obj.Name);
	return *this;
}