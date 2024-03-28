/*������� ������� ������ 9 ������������ ������ 4 ������� 7
������� ����������� �����. ������� ����� ���������, ������� �������� (���). ����������
������������ � ����� �������. ������� ����� ���������(��������� ������������ ������), ����������
����� ���������. ������������� ���� ����� (��������� �� ������), ����. ���������� ������������ �
����������. ���������� public- ����������� ����� ����������� � ���������, ������� �������������
������ ��������. ��������� ������������, ����������� � ������� ������. ������������ �����������
���������� ��� �������� ���������� ��������� �������� ������� ����������� � ��������� ��� ��������
����������������� ������� � ����������� ������, � ������� �����������.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;

class Abstr
{
public:
	Abstr();
	virtual ~Abstr();
	static int qua;
	const int ID = 0;
	virtual void get_method()= 0;
	void get_ID();
	friend void get_qua();
};
int Abstr::qua = 0;
Abstr::Abstr()
{
	int *sid = (int*)&ID;
	*sid = 1000 + qua;
	qua++;
}
Abstr::~Abstr(){}
void Abstr::get_ID()
{
	cout <<"ID: "<< ID << endl << endl;
}
void get_qua()
{
	cout << "���������� ��������� �������� " << Abstr::qua << endl << endl;
}


class Processor
{
public:
	double cpu_speed;
	Processor(double);
	Processor(const Processor&);
	virtual ~Processor();
	void get_method();
};


Processor::Processor(double temp):cpu_speed (temp) {}
Processor::Processor(const Processor& obj) : cpu_speed(obj.cpu_speed) {}
Processor::~Processor(){}
void Processor::get_method()
{
	cout << "������� ���������� " << cpu_speed << endl;
}


class Computer : public Abstr
{
public:
	Processor &pr;
	char* mark;
	int price;
	Computer(char*, int, const Processor&);
	Computer(const Computer& obj);
    virtual ~Computer();
	void get_method();
};


Computer::Computer(char* nmark, int nprice, const Processor& obj) : mark(new char[256]), price(nprice), pr((Processor&)obj), Abstr()
{
	strcpy(mark, nmark);
}
Computer::Computer(const Computer& obj) : mark(new char[256]), price(obj.price), pr(obj.pr)
{
	strcpy(mark,obj.mark);
}
Computer::~Computer() 
{
	delete[] mark;
}
void Computer::get_method()
{
	cout << "����� ����������  " << mark << endl << "���� ���������� " << price << endl;
	pr.get_method();
}


class ComputerWithMonitor : public Computer
{
public:
	double msize;
	ComputerWithMonitor(double, char*, int, const Processor&);
	ComputerWithMonitor(double, const Computer&);
	ComputerWithMonitor(const ComputerWithMonitor&);
	~ComputerWithMonitor();
	void get_method();
};


ComputerWithMonitor::ComputerWithMonitor(double temp, char* nmark, int nprice, const Processor& obj): msize(temp), Computer(nmark, nprice, obj) {}
ComputerWithMonitor::ComputerWithMonitor(double temp, const Computer& obj) : msize(temp), Computer(obj) {}
ComputerWithMonitor::ComputerWithMonitor(const ComputerWithMonitor& obj): msize(obj.msize), Computer(obj) {}
ComputerWithMonitor::~ComputerWithMonitor() {}
void ComputerWithMonitor::get_method()
{
	cout << "������ �������� " << msize << endl;
	Computer::get_method();
}

int main()
{
	setlocale(LC_ALL, "rus");
	char* str1, *str2;
	str1 = new char[256];
	str2 = new char[256];
	strcpy(str1, "Dell\0");
	strcpy(str2, "HP\0");
	get_qua();
	ComputerWithMonitor c1(17.5,str1,1000,3.0);
	c1.get_method();
	c1.get_ID();
	get_qua();
	Processor p1(4.5);
	Computer com1(str2,900,p1);
	com1.get_method();
	com1.get_ID();
	get_qua();
	ComputerWithMonitor c2(17.5, com1);
	c2.get_method();
	c2.get_ID();
	get_qua();
	ComputerWithMonitor c3(c1);
	c3.get_method();
	c3.get_ID();
	get_qua();
	system("pause");
	return 0;
}