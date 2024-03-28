#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#pragma once
#pragma warning(disable : 4996)
/*������� ������� ������ 9 ������������ ������ 7 ������� 7
 ����������� �������������� static_cast, dynamic_cast ��� ���������� �����������.
*/
using namespace std;
class basis1 {
public:
	void f() { cout << "b1" << endl; };
};
class basis2 {
public:
	virtual void f() { cout << "b2" << endl; };

};
class inherit : public basis1, public basis2 { };


int main()
{
	setlocale(LC_ALL, "rus");
	inherit inh;
	inherit *p_inh = &inh;
	basis1 bp1, *p_bp1 = &bp1;
	basis2 bp2, *p_bp2 = &bp2;
	p_inh = static_cast<inherit *>(p_bp1);
	if (p_inh != NULL)
		cout << "1)p_inh = static_cast<inherit *>(p_bp1) �������� �����������, �� f �� �������� �����������" << endl;
	else
		cout << "1)p_inh = static_cast<inherit *>(p_bp1) ���������� �����������" << endl;
	cout << endl;
	p_inh = &inh;
	p_bp1 = &bp1;
	p_bp2 = &bp2;
	p_inh = static_cast<inherit *>(p_bp2);
	if (p_inh != NULL)
		cout << "2)p_inh = static_cast<inherit *>(p_bp2) �������� �����������, �� f �� �������� �����������" << endl;
	else 
		cout << "2)p_inh = static_cast<inherit *>(p_bp2) ���������� �����������" << endl;
	cout << endl;
	p_inh = &inh;
	p_bp1 = &bp1;
	p_bp2 = &bp2;
	p_inh = dynamic_cast<inherit *>(p_bp2);
	if (p_inh != NULL)
		cout << "2)p_inh = dynamic_cast<inherit *>(p_bp2) �������� �����������, �� f �� �������� �����������" << endl;
	else
		cout << "2)p_inh = dynamic_cast<inherit *>(p_bp2) ���������� �����������" << endl;
	cout << endl;
	p_inh = &inh;
	p_bp1 = &bp1;
	p_bp2 = &bp2;
	p_bp1 = static_cast<basis1 *>(&inh); 
	if (p_bp1 != NULL)
	{ 
		cout << "3)p_bp1 = static_cast<basis1 *>(&inh) �������� �����������" << endl;
		p_bp1->f();
	}
	else
		cout << "3)p_bp1 = static_cast<basis1 *>(&inh) ���������� �����������" << endl;
	cout << endl;
	p_inh = &inh;
	p_bp1 = &bp1;
	p_bp2 = &bp2;
	p_bp1 = dynamic_cast<basis1 *>(&inh); 
	if (p_bp1 != NULL)
	{ 
		cout << "3)p_bp1 = dynamic_cast<basis1 *>(&inh) �������� �����������" << endl;
		p_bp1->f();
	}
	else 
		cout << "3)p_bp1 = dynamic_cast<basis1 *>(&inh) ���������� �����������" << endl;
	cout << endl;
	p_inh = &inh;
	p_bp1 = &bp1;
	p_bp2 = &bp2;
	p_bp2 = static_cast<basis2 *>(&inh);
	if (p_bp2 != NULL)
	{ 
		cout << "4)p_bp2 = static_cast<basis2 *>(&inh) �������� �����������" << endl;
		p_bp2->f();
	}
	else
		cout << "4)p_bp2 = static_cast<basis2 *>(&inh) ���������� �����������" << endl;
	cout << endl;
	p_inh = &inh;
	p_bp1 = &bp1;
	p_bp2 = &bp2;
	p_bp2 = dynamic_cast<basis2 *>(&inh);
	if (p_bp2 != NULL)
	{
		cout << "4)p_bp2 = dynamic_cast<basis2 *>(&inh) �������� �����������" << endl;
		p_bp2->f();
	}
	else
		cout << "4)p_bp2 = dynamic_cast<basis2 *>(&inh) ���������� �����������" << endl;
	cout << endl;
	p_inh = &inh;
	p_bp1 = &bp1;
	p_bp2 = &bp2;
	p_bp1 = dynamic_cast<basis1 *>(&bp2); 
	if (p_bp1 != NULL)
	{
		cout << "5)p_bp1 = dynamic_cast<basis1 *>(&bp2) �������� �����������" << endl;
		p_bp1->f();
	}
	else
		cout << "5)p_bp1 = dynamic_cast<basis2 *>(&inh) ���������� �����������" << endl;
	p_bp1->f();
	cout << endl;
	p_inh = &inh;
	p_bp1 = &bp1;
	p_bp2 = &bp2;
	p_bp1 = dynamic_cast<basis1 *>(p_bp2);
	if (p_bp1 != NULL)
	{
		cout << "8)p_bp1 = dynamic_cast<basis1 *>(p_bp2) �������� �����������" << endl;
		p_bp1->f();
	}
	else
		cout << "8)p_bp1 = dynamic_cast<basis1 *>(p_bp2) ���������� �����������" << endl;
	system("pause");
	return 0;
}