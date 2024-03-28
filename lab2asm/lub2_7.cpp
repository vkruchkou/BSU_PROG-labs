/*������� ������� ������ 9 �� ������������ ������ 2 ������� 7
������� �������:
7.	��������� �������� ��������� �� �++ � ���������� ��������� ����� �������� (int) ����������.
������������ �������� �� ����������: +, -, ���������, �������.
���������� ������, ������ ��������� �� �++, 
������������������ ������� � ��������������� ��������� �� �++, 
������� ��� ���� �� 10,100 � �.�. (��� � �������������� ��������).
*/
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int x,y,z,res,a,b,c,d;
	cout << "������� ����a x y z" << endl;
	cin >> x>>y>>z;
	a = int(cosh(x*x*x));
	b = int(sqrt(x));
	c = int(sin(x) * 1000.0);
	d = int(abs(y));
	cout << " ��������� �� �++ " << int(a / b) + int(z * c / 3) - int(d / x);
	_asm
	{
		mov eax,a
		mov ebx,b
		mov edx,0
		idiv ebx
		mov res,eax
		mov eax,c
		mov ebx,z
		imul ebx
		mov edx,0
		mov ebx,3
		idiv ebx
		add res,eax
		mov eax,d
		mov ebx,x
		mov edx,0
		idiv ebx
		sub res,eax
	}
	cout << endl << "��������� �� assembler " << res << endl;
	system("pause");
	return 0;
}