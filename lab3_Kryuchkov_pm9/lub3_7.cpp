/*Крючков Василий группа 9 лабораторная работа 3 задание 7
Условие задания:
Поместить в последовательности A=(ai), i=1..n , n<=100, четные элементы, по очереди (через один) с нечётными.

*/
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void randmas(int *a, int n)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
		a[i] = rand() % 100;
}
void vvivod(int *a, int n)
{
	for (int i = 0; i < n; i++)
		cout << setw(5) << a[i];
	cout << endl;
}
void cheredovanie(int *a, int n)
{
	int k = 2, t = 0, i = 0;
		for (int i = 0; i < n - 1; i++)
		{
			if (a[i] % 2 == 0)
				if (a[i + 1] % 2 == 0)				 //выполняется если два последующих элемента четные
				{ 
				while(a[i + 1] % 2 == 0 && i + k < n)//ищим первый нечетный элемент идущий после этих двух последующих элементов
				{									 //и меняем его местами со вторым из этих двух последующих элементов
					t = a[i + 1];
					a[i + 1] = a[i + k];
					a[i + k] = t;
					k++;
				}
				k = 2;
				}
			if (a[i] % 2 == 1)
				if (a[i + 1] % 2 == 1)				  //выполняется если два последующих элемента нечетные
				{
				while (a[i + 1] % 2 == 1 && i + k < n)//ищим первый четный элемент идущий после этих двух последующих элементов
					{								  //и меняем его местами со вторым из этих двух последующих элементов
						t = a[i + 1];
						a[i + 1] = a[i + k];
						a[i + k] = t;
						k++;
					}
					k = 2;
				}
		}
}
int otchistka(int *a, int n)
{
	if(a[n-1] % 2 == 0)
		for (int i = n-1; i >0 ; i--)
			if (a[i] % 2 == 0 && a[i - 1] % 2 == 0)
				n--;
	if (a[n - 1] % 2 == 1)
		for (int i = n - 1; i >0; i--)
			if (a[i] % 2 == 1 && a[i - 1] % 2 == 1)
				n--;
	return n;
}
int main()
{
	setlocale(LC_ALL, "rus");
	int a[100], n;
	do
	{
	cout <<  "Введите количество элементов массива" << endl;
	cin >> n;
	if (n > 100)
		cout << "Ошибка ввода количество элементов должно быть <= 100" << endl;
	} while (n > 100);
	randmas(a, n);
	cout << "Исходный массив" << endl;
	vvivod(a, n);
	cheredovanie(a, n);
	//n = otchistka(a, n);
	cout << "Полученный массив" << endl;
	vvivod(a, n);
	system("pause");
	return 0;
}