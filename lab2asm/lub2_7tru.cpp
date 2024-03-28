/*Крючков Василий группа 9 УП лабораторная работа 2 задание 7
Условие задания:
7.	Задано число А, содержащее не более четырех цифр и число В(от 0 до 9). , Цифры в числе А= В, продублировать.
Тест:
input			output
123 3		    1233
11 1			1111
-3232 3			-332332
*/
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int a, b, s, aa, m, ab;
	do
	{
		s = 0;
		cout << " Введите число А " << endl;
		cin >> a;
		ab = a;
		if (a < 0)
			a = a * (-1);
		aa = a;
		while (a)
		{
			a /= 10;
			s++;
		}
		if (s > 4)
			cout << " Ошибка ввода. Число А должно содержать не более 4 цифр " << endl;
	} while (s > 4);
	do
	{
		cout << " Введите число В " << endl;
		cin >> b;
		if (b < 0)
			b = b * (-1);
		if (b > 9)
			cout << " Ошибка ввода. Число В должно быть задано от 0 до 9 " << endl;
	} while (b > 9);
	s = 0;
	a = aa;
	while (a)		// мы получаем перевернутое число
	{
		s = s * 10 + a % 10;
		if (a % 10 == b)
			s = s * 10 + b;
		a /= 10;
	}
	while (s)		// переворачиваем число
	{
		a = a * 10 + s % 10;
		s /= 10;
	}
	if (ab < 0)
		a = a * (-1);
	cout << " Результат на с++ " << a;
	_asm
	{
		mov s, 0		// чистим значение переменной
		mov eax, aa		//
		mov a, eax		//  a = aa
		while1 :		// Нахождение перевернутового нужного нам числа
		mov eax, s		//
			mov ebx, 10		//
			mul ebx			// s * 10
			mov s, eax		//
			mov eax, a		//
			mov ebx, 10		//
			mov edx, 0		//
			div ebx			// a / 10
			mul ebx			// a / 10 * 10
			mov ebx, a
			sub ebx, eax	//  a - a / 10 * 10
			add s, ebx		// s = s * 10 + a - a / 10 * 10
			cmp ebx, b		// сравниваем а%10 с b
			jne if2			// если не равно переход на if2	
			mov eax, s
			mov ebx, 10
			mul ebx			// s * 10
			add eax, b
			mov s, eax		// s = s * 10 + b
			if2 :
		mov ebx, 10
			mov eax, a
			mov edx, 0
			div ebx
			mov a, eax		// а/=10
			cmp a, 0		// сравниваем а с 0
			jne while1		// если не равно переход на while1
			while2 :		// Перевертывание полученного числа
		mov eax, a
			mov ebx, 10
			mul ebx			// а * 10
			mov a, eax
			mov eax, s
			mov ebx, 10
			mov edx, 0
			div ebx			// s / 10
			mul ebx			// s / 10 * 10
			mov ebx, s
			sub ebx, eax	//  s - s / 10 * 10
			add a, ebx		//  a = a * 10 + s - s / 10 * 10
			mov eax, s
			mov ebx, 10
			mov edx, 0
			div ebx			// s /= 10
			mov s, eax
			cmp s, 0		// сравниваем s с 0
			jne while2		// если не равно переход на while2
			cmp ab, 0
			jg iff
			cdq
			mov eax, a
			mov ebx, -1
			imul ebx
			mov a, eax
			iff :
	}
	cout << endl << "Результат на assembler " << a << endl;
	system("pause");
	return 0;
}