#define _CRT_SECURE_NO_WARNINGS
/*Крючков Василий группа 9 лабораторная работа 1 задание 7
Условие задания:
 Очередь. Элемент списка структура.
Структура содержит данные об услугах Интернет, поля:  фамилия, время разговора. (char*, int, double)
1.	Создание списка (чтение данных из файла)
2.	Добавить элемент
3.	Удаление  элемента
4.	Удаление всех элементов
5.	Вывод списка на консоль и в файл
6.	Запросы на выполнение операций оформить в виде меню.
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
	cout << "1-Считать список с файла\n2-Добавить элемент\n3-Удаление элемента\n4-Удаление всех элементов\n5-Вывод списка на консоль и в файл output.txt\n0-выход\n";
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
			cout << "Вызвано исключение: ";
			cout << ex.what();
		}
	} while (t);
	system("pause");
	return 0;
}