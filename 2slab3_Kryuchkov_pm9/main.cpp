#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include "header.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	cout << "������� ����������� �������\n";
	try
	{
		do
		{
			cin >> n;
			if (n < 1)
				cout << "����������� �� ����� ���� ������ ������\n";
		} while (n < 1);
		cout << "������� ������ vec1 ����������� " << n << endl;
		nmvect vec1(n);
		cin >> vec1;
		cout << "������� ������ vec2 ����������� " << n << endl;
		nmvect vec2(n);
		cin >> vec2;
		cout << endl;
		cout << "vec1 = " << vec1;
		cout << "vec2 = " << vec2;
		cout << "vec1 + vec2 = " << vec1 + vec2 << "\n";
		cout << "vec1 = " << vec1;
		cout << "vec2 = " << vec2;
		cout << "vec1 - vec2 = " << vec1 - vec2 << "\n";
		double a;
		cout << "������� �����\n";
		cin >> a;
		cout << "vec2 = " << vec2;
		cout << "vec2 * a = " << vec2 * a << "\n";
		cout << "vec2 = " << vec2;
		cout << "vec2 / a = " << vec2 / a << "\n";
		cout << "vec1 = " << vec1;
		cout << "vec2 = " << vec2;
		cout << "vec1 + (++vec2) = " << vec1 + (++vec2) << " vec2 = " << vec2 << "\n";
		cout << "vec1 = " << vec1;
		cout << "vec2 = " << vec2;
		cout << "vec1 + vec2++ = " << vec1 + vec2++ << " vec2 = " << vec2 << "\n";
		cout << "vec1 = " << vec1;
		cout << "vec2 = " << vec2;
		cout << "vec1 + (--vec2) = " << vec1 + (--vec2) << " vec2 = " << vec2 << "\n";
		cout << "vec1 = " << vec1;
		cout << "vec2 = " << vec2;
		cout << "vec1 + vec2-- = " << vec1 + vec2-- << " vec2 = " << vec2 << "\n";
		cout << "vec2 = " << vec2;
		~vec2;
		cout << "~vec2 = " << vec2 << "\n";
		cout << "vec1 = " << vec1;
		cout << "vec2 = " << vec2;
		cout << "vec1 == vec2 = " << (vec1 == vec2) << "\n";
		cout << "vec1 != vec2 = " << (vec1 != vec2) << "\n";
		cout << "vec1 <= vec2 = " << (vec1 <= vec2) << "\n";
		cout << "vec1 >= vec2 = " << (vec1 >= vec2) << "\n";
	}
	catch (const std::exception & ex)
	{
		cout << "������� ����������: ";
		cout << ex.what();
	}
	system("pause");
	return 0;
}