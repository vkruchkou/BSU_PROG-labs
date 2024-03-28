#define _CRT_SECURE_NO_WARNINGS
/*Крючков Василий группа 9 лабораторная работа 5 задание 7
Условие задания:
Разработать программу, которая запрашивает у пользователя строку.
Лексемы разделены ?. Определяет  в ней лексемы состоящие из заглавных букв.
Ввести число K (индекс).Удалить k-ю лексему из строки.
Ввести 2-ю строку, найти её в 1-й строке. Результаты вывести на консоль.
*/
#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>
#include <stdio.h>
using namespace std;
//void _fastcall bprintf(char b)
//{
//	cout << b;
//}
//extern	"C" void _cdecl	bleks(int, char[], char[]);
//extern	"C" void _cdecl	leks(int,char[]);
//extern	"C" void _cdecl	dellek(int,char[], char[], int);
extern	"C" int plek(int, char[], char[]);
int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Введите строку\n";
	char str1[256], str2[27] = "QWERTYUIOPASDFGHJKLZXCVBNM", buf[256], str3[256];
	fgets(str1, 256, stdin);
	int t, k;
	int len1 = strlen(str1);
	cout << endl;
	//cout << "Лексемы из заглавных букв" << endl;
	//bleks(len1,str1, str2);
	//cout << "Лексемы" << endl;
	//leks(str1);
	//cout << "Ведите индекс лексемы для удаления(у первой лексемы нулевой индекс)" << endl;
	//cin >> k;
	//dellek(str1,buf, k);
	//cout << "Изменненая строка" << endl;
	//fputs(str1, stdout);
	//cout << endl;
	cout << "Введите подстроку для поиска" << endl;
	fflush(stdin);
	rewind(stdin);
	fgets(str3, 256, stdin);
	cout << endl;
	cout << str1;
	cout << str2;
	t = plek(len1, str1, str3);
	if(t)
		cout << "Подстрока найдена" << endl;
	else
		cout << "Подстрока не найдена" << endl;
	system("pause");
	return 0;
}
