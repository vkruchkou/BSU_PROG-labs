#define _CRT_SECURE_NO_WARNINGS
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
	//bool operator == (Container1 const& obj);
	//bool operator == (Container2 const& obj);
	//bool operator ==(Container3 const& obj);
	template< class T>
	bool operator ==(T const& obj);
	//Container1& operator=(Container1 const& obj);
	//Container1& operator=(Container2 const& obj);
	//Container1& operator=(Container3 const& obj);
	template< class T>
	Container1& operator=(T const& obj);
};
struct Container2
{
	char Name[50];
	char Space[50];
	Container2() { strcpy(Space, "/0"); strcpy(Name, "/0");};
	Container2(char *mas1, char *mas2) { strcpy(Name, mas1); strcpy(Space, mas2);};
	friend std::ostream & operator<<(std::ostream& os, Container2 const& obj);
	friend std::istream & operator<<(std::istream& is, Container2 const& obj);
	/*bool operator ==(Container1 const& obj);
	bool operator ==(Container2 const& obj);
	bool operator ==(Container3 const& obj);
	Container2& operator=(Container1 const& obj);
	Container2& operator=(Container2 const& obj);
	Container2& operator=(Container3 const& obj);*/
	template< class T>
	bool operator ==(T const& obj);
	template< class T>
	Container2& operator=(T const& obj);
};
struct Container3
{
	char Name[50];
	int SredniyBal;
	Container3():SredniyBal(0) { strcpy(Name,"/0"); };
	Container3(char *mas, int ball) :SredniyBal(ball) { strcpy(Name, mas); };
	friend std::ostream & operator<<(std::ostream& os, Container3 const& obj);
	friend std::istream & operator<<(std::istream& is, Container3& obj);
	/*bool operator ==(Container1 const& obj);
	bool operator ==(Container2 const& obj);
	Container3& operator=(Container1 const& obj);
	Container3& operator=(Container2 const& obj);
	Container3& operator=(Container3 const& obj);*/
	template< class T>
	bool operator ==(T const& obj);
	template< class T>
	Container3& operator=(T const& obj);
};
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