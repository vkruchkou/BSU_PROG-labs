#define _CRT_SECURE_NO_WARNINGS
/*������� ������� ������ 9 ������������ ������ 1 ������� 7
������� �������:
 �������. ������� ������ ���������.
��������� �������� ������ �� ������� ��������, ����:  �������, ����� ���������. (char*, int, double)
1.	�������� ������ (������ ������ �� �����)
2.	�������� �������
3.	��������  ��������
4.	�������� ���� ���������
5.	����� ������ �� ������� � � ����
6.	������� �� ���������� �������� �������� � ���� ����.
*/
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "header.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	que  que1;
	int t;
	cout << "1-������� ������ � �����\n2-�������� �������\n3-�������� ��������\n4-�������� ���� ���������\n5-����� ������ �� ������� � � ���� output.txt\n0-�����\n";
	do
	{
		cin >> t;
		try
		{
			if (t == 1)
				que1.init();
			if (t == 2)
				que1.dobavit();
			if (t == 3)
				que1.deliteml();
			if (t == 4)
				que1.delitem();
			if (t == 5)
				que1.eprint();
		}
		catch (const std::exception & ex)
		{
			cout << "������� ����������: ";
			cout << ex.what();
		}
	} while (t);
	system("pause");
	return 0;
}