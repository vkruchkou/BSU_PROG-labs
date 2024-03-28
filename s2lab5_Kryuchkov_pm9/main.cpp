#include <stdio.h>
#include <iostream>
#include <time.h>
#include "Stack.h"
#include "Iterator.h"
/*Крючков Василий группа 9 лабораторная работа 5 задание 7
Условие задания:
Используя абстрактные классы, реализовать конкретные классы: ArrayStack( на массиве) и
ArrayStackIterator
*/
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Введите размерность стека\n";
	int n;
	cin >> n;
	cout << endl;
	srand((unsigned int)time(0));
	ArrayStack stack(n);
	try
	{
		while (!stack.IsFull())
			stack.push(rand() % 65);
		ArrayStack tstack(stack);
		cout << "Сгенерированный стек:\n";
		while (!tstack.IsEmpty())
			cout << tstack.pop() << endl;
		cout << endl;
		ArrayStackIterator istack(stack);
		cout << "Вывод стека с помощью итератора\n";
		while (istack.InRange())
		{
			cout << *istack << endl;
			++istack;
		}
		cout << endl;
	}
	catch (const std::exception & ex)
	{
		cout << endl << "Вызвано исключение: ";
		cout << ex.what() << endl;
	}
	system("pause");
	return 0;
}