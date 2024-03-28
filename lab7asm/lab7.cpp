/*Крючков Василий группа 9 лабораторная работа 6 задание 7
Условие задания:
Функция представлена в виде своего ряда Тейлора.
Вычислить приближённое значение суммы этого бесконечного ряда.
Вычисления заканчивать, когда очередное слагаемое окажется по модулю меньше заданного числа eps.
Сравнить полученный результат со значением, вычисленным через стандартные функции,
x и eps запросить у пользователя перед началом вычислений. sinh(x)
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <math.h>
extern	"C" double	func(double, double);
using namespace std;
int main()
{
	double x, e, r;
	setlocale(LC_ALL, "rus");
	cout << "Значение x" << endl;
	cin >> x;
	cout << "Значение e" << endl;
	cin >> e;
	r = func(x, e);
	cout << "sinh(" << x << ")=" << r << endl;
	cout << "Вычисление через функцию sinh из библиотеки <math.h> " << endl;
	cout << "sinh(" << x << ")=" << sinh(x) << endl;
	system("pause");
	return 0;
}