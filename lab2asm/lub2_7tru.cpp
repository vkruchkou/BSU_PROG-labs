/*������� ������� ������ 9 �� ������������ ������ 2 ������� 7
������� �������:
7.	������ ����� �, ���������� �� ����� ������� ���� � ����� �(�� 0 �� 9). , ����� � ����� �= �, ��������������.
����:
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
		cout << " ������� ����� � " << endl;
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
			cout << " ������ �����. ����� � ������ ��������� �� ����� 4 ���� " << endl;
	} while (s > 4);
	do
	{
		cout << " ������� ����� � " << endl;
		cin >> b;
		if (b < 0)
			b = b * (-1);
		if (b > 9)
			cout << " ������ �����. ����� � ������ ���� ������ �� 0 �� 9 " << endl;
	} while (b > 9);
	s = 0;
	a = aa;
	while (a)		// �� �������� ������������ �����
	{
		s = s * 10 + a % 10;
		if (a % 10 == b)
			s = s * 10 + b;
		a /= 10;
	}
	while (s)		// �������������� �����
	{
		a = a * 10 + s % 10;
		s /= 10;
	}
	if (ab < 0)
		a = a * (-1);
	cout << " ��������� �� �++ " << a;
	_asm
	{
		mov s, 0		// ������ �������� ����������
		mov eax, aa		//
		mov a, eax		//  a = aa
		while1 :		// ���������� ��������������� ������� ��� �����
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
			cmp ebx, b		// ���������� �%10 � b
			jne if2			// ���� �� ����� ������� �� if2	
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
			mov a, eax		// �/=10
			cmp a, 0		// ���������� � � 0
			jne while1		// ���� �� ����� ������� �� while1
			while2 :		// �������������� ����������� �����
		mov eax, a
			mov ebx, 10
			mul ebx			// � * 10
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
			cmp s, 0		// ���������� s � 0
			jne while2		// ���� �� ����� ������� �� while2
			cmp ab, 0
			jg iff
			cdq
			mov eax, a
			mov ebx, -1
			imul ebx
			mov a, eax
			iff :
	}
	cout << endl << "��������� �� assembler " << a << endl;
	system("pause");
	return 0;
}