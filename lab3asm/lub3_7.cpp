/*������� ������� ������ 9 ������������ ������ 3 ������� 7
������� �������:
7.	(�������� �����) ���� ����������� ������������������ X=(xi),i=1..n, n<=10,  ����� ����� � ����� �.
��������, ���������� �� � � ���� ������������������. (���������� �������� ������� log n.)
*/
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void randmas(int *a, int n)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
		a[i] = rand() % 100;
}
void vvivod(int *a, int n)
{
	for (int i = 0; i < n; i++)
		cout << setw(5) << a[i];
	cout << endl;
}
void SortBubbble(int *a, int n)
{
	int i, j, t;
	for (int i = 0; i < n; i++)
		for (int j = n-1; j > i; j--)
			if (a[j - 1] > a[j])
			{
				t = a[j - 1];
				a[j - 1] = a[j];
				a[j] = t;
			}
}
int BinarySearch(int*a, int n, int x)
{
	int m, i=0;
	while (i <= n)
	{
		m = (i + n) / 2;
		if (x == a[m])
			return 1;
		else
			if (x > a[m])
				i = m + 1;
			else
				n = m - 1;
	}
	return -1;
}
int main()
{
	setlocale(LC_ALL, "rus");
	int a[10], n, x, i, m, t=0;
	do
	{
		cout << "������� ���������� ��������� �������" << endl;
		cin >> n;
		if (n > 10)
			cout << "������ ����� ���������� ��������� ������ ���� <= 10" << endl;
	} while (n > 10);
	randmas(a, n);
	SortBubbble(a, n);
	cout << "�������� ������" << endl;
	vvivod(a, n);
	cout << "������� ����� A ��� ������" << endl;
	cin >> x;
	if (BinarySearch(a, n, x) == 1)
		cout << "� ���������� � ���� ������������������" << endl;
	else
		cout << "� �� ���������� � ���� ������������������" << endl;
	_asm
	{
		mov i, 0
			while0:
		mov eax, i
		add eax, n
		mov ebx, 2
		mov edx, 0
		div ebx
		mov esi, 0
		mov m, eax
		mov ecx, m
			for1:
		add esi, 4
			loop for1
		mov eax, a[esi]
		cmp x , eax
		jne if0
		mov t, 1
		jmp ends0
			if0:
		cmp x, eax
		jl if1
		add m, 1
		mov eax, m
		mov i, eax
		jmp if2
			if1:
		sub m, 1
		mov eax, m
		mov n, eax
			if2:
		mov eax, n
		cmp i, eax
		jle while0
		ends0:
	}
	cout << "��������� �� ����������" << endl;
	if (t == 1)
		cout << "� ���������� � ���� ������������������" << endl;
	else
		cout << "� �� ���������� � ���� ������������������" << endl;
	system("pause");
	return 0;
}