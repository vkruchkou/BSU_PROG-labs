#define _CRT_SECURE_NO_WARNINGS
/*������� ������� ������ 9 ������������ ������ 2 ������� 7
������� �������:
 �������. ������� ������ ���������.
��������� �������� ������ �� ������� ��������, ����:  �������, ����� ���������. (char*, int)
1.	����������� ����������� ��������� ������ �� N ��������� (������ �� �����)
2.	�������������� �����
3.	����� ������ �� �������
4.	����������� ���������� (�������� ������)
5.	������� �� ���������� �������� �������� � ���� ����.
�������������� �����:
������� ���������� ������������� ������� � ������.
������� ������ ���������. ��������� �������� ������ �� ������� ��������, ����:  �������, ����� ���������. (char*, int)
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
	int t;
	que  que1;
	cout << "1-����� ������������ � �������������� ��������� ������������\n2-�������������� �����\n3-����� ������ �� �������\n4-����� ����� �����������\n0-�����\n";
	do
	{
		cin >> t;
		try
		{
			if (t == 1)
				que1 = que();
			if (t == 2)
				que1.udl();
			if (t == 3)
				que1.eprint();
			if (t == 4)
			{
				que1.~que();
				cout << "��� ������ ���������� ������ �������\n";
			}
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