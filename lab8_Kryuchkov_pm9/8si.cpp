/*������� ������� ������ 9 ������������ ������ 8 ������� 7
������� �������:
���������  ����� ������������ �� ��������� ������( ������������ ��������� ������� main.)
�����  ���������� ��������  � � �������
���������
*/
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#pragma warning(disable : 4996)
using namespace std;
void revpoi(int *mas, int n, int x, int &res)
{
	if (n == 1)
	{
		if (mas[n - 1] == x)
			res++;
		return;
	}
	else
	{
		n--;
		if (mas[n] == x)
			res++;
		return(revpoi(mas, n, x, res));
	}
}
int main(int argc, char*argv[]) 
{
	setlocale(LC_ALL, "rus");
	if (argc == 1)
	{
		cout << "�� �� ����� ����������\n";
		return 1;
	}
	char str[256];
	char *e;
	fflush(stdin);
	fstream fp;
	int*mas, n = 1, i = 0;
	mas = (int*)malloc(n * sizeof(int));
	if (argc == 2)
	{
		fp.open("C:\\input.txt", ios::in);
		if (!fp.is_open())
		{
			fp.close();
			cout << "�� ������� ������� ���� ��� ������\n";
			return 1;
		}
		else
		{
			fp.seekg(0, ios::end);
			if (!fp.tellg())
			{
				fp.close();
				cout << "���� ����\n";
				return 1;
			}
			else
			{
				fp.seekg(0, ios::beg);
				fp.getline(str, 256);
				fp.close();
				char *p = strtok(str, " ");
				while (p != NULL)
				{
					e = NULL;
					mas[i] = strtol(p, &e, 10);
					i++;
					n++;
					mas = (int*)realloc(mas, n * sizeof(int));
					p = strtok(NULL, " ");
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < argc - 2; i++)
		{
			e = NULL;
			mas[i] = strtol(argv[i+2], &e, 10);
			n++;
			mas = (int*)realloc(mas, n * sizeof(int));
		}	
	}
	n--;
	cout << "��������� ������\n";
	for (i = 0; i < n; i++)
		cout << mas[i] << " ";
	cout << endl;
	int res = 0;
	e = NULL;
	int x = strtol(argv[1], &e, 10);
	revpoi(mas, n, x, res);
	cout << "���������� ���������� " << x << " � �������\n";
	for (i = 0; i < n; i++)
		cout << mas[i] << " ";
	cout << endl;
	cout << "����� " << res << endl;
	fstream clear("C:\\output.txt", ios::out);
	clear.close();
	fp.open("C:\\output.txt", ios::out);
	if (!fp.is_open())
	{
		cout << "�� ������� ������� ���� ��� ������\n";
		return 1;
	}
	else
	{
		fp << "���������� ���������� " << x << " � �������\n";
		for (i = 0; i < n; i++)
			fp << mas[i] << " ";
		fp << endl;
		fp << "����� " << res << endl;
		fp.close();
		cout << "���������� �������� � ����\n";
		free(mas);
		system("pause");
	}
	return 0;
}