/*������� ������� ������ 9 ������������ ������ 6 ������� 7
������� �������:
������� ������������ � ���� ������ ���� �������.
��������� ����������� �������� ����� ����� ������������ ����.
���������� �����������, ����� ��������� ��������� �������� �� ������ ������ ��������� ����� eps.
�������� ���������� ��������� �� ���������, ����������� ����� ����������� �������,
x � eps ��������� � ������������ ����� ������� ����������. sinh(x)
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
	cout << "�������� x" << endl;
	cin >> x;
	cout << "�������� e" << endl;
	cin >> e;
	r = func(x, e);
	cout << "sinh(" << x << ")=" << r << endl;
	cout << "���������� ����� ������� sinh �� ���������� <math.h> " << endl;
	cout << "sinh(" << x << ")=" << sinh(x) << endl;
	system("pause");
	return 0;
}