#include <stdio.h>
#include <iostream>
#include <time.h>
#include "Stack.h"
#include "Iterator.h"
/*������� ������� ������ 9 ������������ ������ 5 ������� 7
������� �������:
��������� ����������� ������, ����������� ���������� ������: ArrayStack( �� �������) �
ArrayStackIterator
*/
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	cout << "������� ����������� �����\n";
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
		cout << "��������������� ����:\n";
		while (!tstack.IsEmpty())
			cout << tstack.pop() << endl;
		cout << endl;
		ArrayStackIterator istack(stack);
		cout << "����� ����� � ������� ���������\n";
		while (istack.InRange())
		{
			cout << *istack << endl;
			++istack;
		}
		cout << endl;
	}
	catch (const std::exception & ex)
	{
		cout << endl << "������� ����������: ";
		cout << ex.what() << endl;
	}
	system("pause");
	return 0;
}