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
void svvod(char *a, int n)
{
	scanf("%s",a);
}
void svvid(char *a, int n)
{
	for (int j = 0; j < n; j++)
		printf("%c ", a[j]);
	printf("\n");
}
void randmas(char *a, int n)
{
	srand(time(0));
	int t;
	char l[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ?/.,";
	for (int i = 0; i < n;)
	{
		t = rand() % 100;
		if (t<66)
		{
			a[i] = l[t];
			i++;
		}
	}
}
int comp(const void*x, const void *y)
{
	return (*(char *)x - *(char *)y)*(-1);
}
int ccomp(const void*x, const void *y)
{
	return *(char *)x - *(char *)y;
}
void pdchet(char *a, int n)
{
	int max = 0, min = 256;
	for (int i = 0; i < n; i++) {
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int *c = new int[max + 1 - min];
	for (int i = 0; i < max + 1 - min; i++) {
		c[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		c[a[i] - min] = c[a[i] - min] + 1;
	}
	int i = 0;
	for (int j = min; j < max + 1; j++) {
		while (c[j - min] != 0) {
			a[i] = j;
			c[j - min]--;
			i++;
		}
	}
}
int main()
{
	setlocale(LC_ALL, "rus");
	char *a;
	char s;
	int n, t,g;
	void(*functoin[4])(char*, int) = { svvod,svvid,randmas,pdchet };
	printf("Количество элементов\n");
	scanf("%d",&n);
	printf("\n");
	a = (char*)malloc(n * sizeof(char));
	printf("t==0 ввыход\nt==1 ввод с клавы\nt==2 рандом \nt==3 добавление\nt==4 удаление элемента\nt==5 сортировка по убыванию qsort\nt==6 поиск bsearch\nt==7 сортировка подсчетом\n");
	do
	{
		scanf("%d", &t);
		printf("\n");
		if (t == 2)
		{
			functoin[2](a, n);
			functoin[1](a, n);
		}
		if (t == 1)
			functoin[0](a, n);
		if (t == 3)
		{
			printf("Символ\n");
			scanf(" %c", &s);
			printf("\n");
			printf("Позиция\n");
			scanf("%d", &g);
			printf("\n");
			n++;
			a = (char *)realloc(a, n * sizeof(char));
			for (int i = n - 1; i > g; i--)
				a[i] = a[i - 1];
			a[g] = s;
			functoin[1](a, n);
		}
		if (t == 4)
		{
			printf("Символ\n");
			scanf(" %c", &s);
			printf("\n");
			for (int i = 0; i < n; i++)
			{
				if (a[i] == s)
				{
					for (int j = i; j < n; j++)
						a[j] = a[j + 1];
					a[n - 1] = 0;
					n--;
				}
			}
			a = (char *)realloc(a, n * sizeof(char));
			functoin[1](a, n);
		}
		if (t == 5)
		{
			qsort(a, n, sizeof(char), comp);
			functoin[1](a, n);
		}
		if (t == 6)
		{
			char *p;
			printf("Символ\n");
			scanf(" %c", &s);
			printf("\n");
			p = (char *)bsearch(&s, a, n, sizeof(char), ccomp);
			if (p) printf("Есть\n");
			else printf("Нету\n");
		}
		if (t == 7)
		{
			functoin[3](a, n);
			functoin[1](a, n);
		}
	} while (t);
	free(a);
	system("pause");
	return 0;
}