#define _CRT_SECURE_NO_WARNINGS
/*������� ������� ������ 9 ������������ ������ 7 ������� 7
������� �������:
7.7. ������� ������ ���������. ��������� �������� ������ �� ������� ��������, ����:  �������, ����� ���������. (char*, int)
*/
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "function.h"
using namespace std;
int main()
{
	char str[256], *e = NULL;
	setlocale(LC_ALL, "rus");
	internet *root = NULL, *h = NULL;
	int n;
	int t;
	cout << "1-������� ������ � �����\n2-�������� � ������ i-� (�� i-� �������) �������\n3-��������  i-�� �������� �� ������ -\n4-�������� ������ (���� ���������)\n5-����� �������� � ������\n6-�����  ������ � ��������� ����\n7-���������� ������ �� ������� �������� ���������\n8-�������� �� ������ ������\n9-����� ������ � �������\n0-�����\n";
	do
	{
		cin >> t;
		if (t == 1)
			root = init(root, &n);
		if (t == 2)
			root = dobavit(root, &n);
		if (t == 3)
			root = delitemk(root, &n);
		if (t == 4)
			root = delitem(root, &n);
		if (t == 5)
		{
			cout << "������� ������� ��� ����� ��������\n";
			cin >> str;
			e = NULL;
			if (strtol(str, &e, 10) == 0)
				listsearch(root, str);
			else
				listsearch(root, atoi(str));
		}
		if (t == 6)
			fout(root);
		if (t == 7)
			internetsort(root);
		if (t == 8)
			if (pust(root) == 0)
				cout << "������ ����" << endl;
			else
				cout << "������ �� ����" << endl;
		if (t == 9)
			if (pust(root) == 1)
				eprint(root);
			else
				cout << "������ ����" << endl;
	} while (t);
	system("pause");
	return 0;
}