/*������� ������� ������ 9 ������������ ������ 4 ������� 7
������� �������:
����������� ���������, ������������� � ������������ ������ ����������� N,
����������� ���������� ��� ��������� �� �����������.
���������� ������������ ����������� ����������.
������ ���������� � qsort. �������� ������� �������.
����, �����, ���������� �������� � ��������� �������.
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
	printf("���������� ���������\n");
	scanf("%d",&n);
	printf("\n");
	a = (char*)malloc(n * sizeof(char));
	printf("t==0 ������\nt==1 ���� � �����\nt==2 ������ \nt==3 ����������\nt==4 �������� ��������\nt==5 ���������� �� �������� qsort\nt==6 ����� bsearch\nt==7 ���������� ���������\n");
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
			printf("������\n");
			scanf(" %c", &s);
			printf("\n");
			printf("�������\n");
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
			printf("������\n");
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
			printf("������\n");
			scanf(" %c", &s);
			printf("\n");
			p = (char *)bsearch(&s, a, n, sizeof(char), ccomp);
			if (p) printf("����\n");
			else printf("����\n");
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