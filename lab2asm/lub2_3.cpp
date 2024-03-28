#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int x,s=0,xx;
	cin >> x;
	xx = x;
	while (x)
	{
		s = s * 100+x%10*10+9;
		x /= 10;
	}
	s /= 10;
	while (s)
	{
		x = x * 10 + s % 10;
		s /= 10;
	}
	cout << " Полученное число " << x;
	_asm
	{
		mov s, 0		// чистим значение переменной
		mov eax, xx
		mov x, eax
		while1:
		mov eax, s
		mov ebx, 100
		mul ebx
		mov s, eax
		mov eax, x
		mov ebx, 10
		mov edx, 0
		div ebx
		mul ebx
		mov ebx, x
		sub ebx, eax
		mov eax, ebx
		mov ebx, 10
		mul ebx
		add eax, 9
		add s, eax
		mov eax, x
		mov edx, 0
		div ebx
		mov x, eax
		cmp x, 0
		jne while1
			mov eax, s
			mov ebx, 10
			mov edx, 0
			div ebx
			mov s, eax
				while2:
			mov eax, x
			mov ebx, 10
			mul ebx
			mov x, eax
			mov eax, s
			mov ebx, 10
			mov edx, 0
			div ebx
			mul ebx
			mov ebx, s
			sub ebx, eax
			add x, ebx
			mov eax, s
			mov ebx, 10
			mov edx, 0
			div ebx
			mov s, eax
			cmp s, 0
				jne while2
	}
	cout << endl << "Результат на assembler " << x;
	system("pause");
	return 0;
}