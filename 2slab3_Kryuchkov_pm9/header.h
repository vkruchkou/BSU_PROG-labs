#include <iostream>
class nmvect
{
public:
	nmvect(int);
	~nmvect();
	nmvect(nmvect const&);
	double operator[](int);
	nmvect& operator=(nmvect const&);
	nmvect operator+(nmvect const&);
	nmvect operator-(nmvect const&);
	nmvect operator*(double);
	nmvect operator/(double);
	nmvect& operator++();
	nmvect operator++(int);
	nmvect& operator--();
	nmvect operator--(int);
	bool operator==(nmvect const&);
	bool operator!=(nmvect const&);
	bool operator>=(nmvect const&);
	bool operator<=(nmvect const&);
	friend nmvect operator+(nmvect const&, nmvect const&);
	friend nmvect operator-(nmvect const&, nmvect const&);
	friend nmvect operator*(nmvect const&, double);
	friend std::ostream & operator<<(std::ostream&, nmvect const&);
	friend std::istream & operator>>(std::istream&, nmvect const&);
	int operator~();
	int nsize;
	double* vm;
};