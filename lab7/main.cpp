#define _CRT_SECURE_NO_WARNINGS
/*Крючков Василий группа 9 лабораторная работа 7 задание 7
Условие задания:
7.7. Элемент списка структура. Структура содержит данные об услугах Интернет, поля:  фамилия, время разговора. (char*, int)
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
	cout << "1-Считать список с файла\n2-Добавить в список i-й (на i-ю позицию) элемент\n3-Удаление  i-го элемента из списка -\n4-Удаление списка (всех элементов)\n5-Поиск элемента в списке\n6-Вывод  списка в текстовый файл\n7-Сортировка списка по первому элементу структуры\n8-Проверка на пустой список\n9-Вывод списка в консоль\n0-выход\n";
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
			cout << "Введите фамилию или время разговор\n";
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
				cout << "Список пуст" << endl;
			else
				cout << "Список не пуст" << endl;
		if (t == 9)
			if (pust(root) == 1)
				eprint(root);
			else
				cout << "Список пуст" << endl;
	} while (t);
	system("pause");
	return 0;
}