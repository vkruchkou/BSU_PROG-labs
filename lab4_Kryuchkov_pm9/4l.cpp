/*Крючков Василий группа 9 лабораторная работа 4 задание 7
Условие задания:
Разработать программу, запрашивающую у пользователя массив размерности N,
выполняющую сортировку его элементов по возрастанию. 
Сортировку осуществлять сортировкой «подсчётом». 
Вторая сортировка – qsort. Элементы массива символы. 
Ввод, вывод, сортировку выделить в отдельные функции.
*/
#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdio.h>
using namespace std;
void randmas(char *a, int n)
{
	srand(time(0));
	int t;
	char l[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ?/.,";
	for (int i = 0; i < n;)
	{
		t = rand() % 240+14;
		//if (t<66)
		//{
			a[i] = t;
			i++;
	//	}
	}
}
void vvod(char *a, int n)
{
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
void vvid(char *a, int n)
{
	for (int i = 0; i < n; i++)
		cout << setw(5) << a[i];
	cout <<endl;
}
void qsort(char *a, int f, int l)//Хоара
{
	int mid = (f + l) / 2;
	int *b = new int;
	int ff = f, ll = l;
	for (; ff <= mid; ff++)
	{
		if (a[ff] >= a[mid])
		{
			for (; ll >= mid; ll--)
			{
				if (a[ll] <= a[mid])
				{
					*b = a[ff];
					a[ff] = a[ll];
					a[ll] = *b;
					break;
				}
			}
		}
	}
	delete b;
	if (ff < l)
	{
		qsort(a, mid, l);
	}
	if (f < ll)
	{
		qsort(a, f, mid);
	}
}
int main()
{
	char *a;
	int n,t;
	setlocale(LC_ALL, "rus");
	cout << "Количество элементов\n";
	cin >> n;
	a = new char[n];
	cout <<("t==0 ввыход\nt==1 ввод с клавы\nt==2 рандом \nt==3 сортировка qsort\n");
	do
	{
		cin >> t;
		if (t == 2)
		{
			randmas(a, n);
			vvid(a, n);
		}
		if (t == 1)
			vvod(a, n);
		if (t == 3)
		{
			qsort(a, 0, n);
			vvid(a, n);
		}
	}
	while (t);
	delete[] a;
	system("pause");
	return 0;
}