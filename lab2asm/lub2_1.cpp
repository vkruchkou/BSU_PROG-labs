#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	unsigned int m = 0, x, xs, res = 1;
	cout << "������� �����\n";
	cin >> x;
	xs = x;
	while (x)
	{
		x /= 10;
		m++;
	}
	cout << "���������� ��� ���� �����, ����������� �� �++ � ����� " << xs << " " << int(m / 2) << endl;
	m = 0;
	x = xs;
	_asm
	{
		mov ebx, 10			//���������� 10 � ebx
		mov eax, x			//���������� �������� � � eax
		for1 :				//
		add m, 1			//m++
			mov edx, 0		//������ ������� edx ��� ����������� �������
			div ebx			//����� ���� ����� �� 10
			cmp eax, 0		//����������
			JNZ for1		//���� �� ����� ���� ��������� �� JNZ
			mov eax, m		//���������� ��������  m � eax
			mov ebx, 2		//���������� 2 � ebx
			mov edx, 0		//������ ������� edx ��� ����������� �������
			div ebx			//����� ���� ����� �� 2
			mov res, eax	//����������� ���������� res �������
	}
	cout << "��������� �� assembler " << res << endl;	// ��������� �� assembler
	system("pause");
	return 0;
}