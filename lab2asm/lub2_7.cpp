/*Крючков Василий группа 9 УП лабораторная работа 2 задание 7
Условие задания:
7.	Вычислить значение выражения на С++ и Ассемблере используя целые значения (int) переменных.
Обязательные операции на ассемблере: +, -, умножение, деление.
Квадратный корень, модуль вычислять на С++, 
тригонометрических функций и гиперболических вычислять на С++, 
умножая при этом на 10,100 и т.д. (как в индивидуальном варианте).
*/
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int x,y,z,res,a,b,c,d;
	cout << "Введите числa x y z" << endl;
	cin >> x>>y>>z;
	a = int(cosh(x*x*x));
	b = int(sqrt(x));
	c = int(sin(x) * 1000.0);
	d = int(abs(y));
	cout << " Результат на с++ " << int(a / b) + int(z * c / 3) - int(d / x);
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
	cout << endl << "Результат на assembler " << res << endl;
	system("pause");
	return 0;
}