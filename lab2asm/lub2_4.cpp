#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int x, s = 0, xx,m=0;
	cin >> x;
	xx = x;
	while (x)
	{
		if (x % 10 > m)
			m = x % 10;
		x /= 10;
	}
	x = xx;
	while (x)
	{
		s = s * 10 + x % 10;
		if (x % 10 == m)
		s = s * 10 + m;
		x/= 10;
	}
	while (s)
	{
		x = x * 10 + s % 10;
		s /= 10;
	}
	cout << " Полученное число " << x;
	_asm
	{
		mov s, 0		// чистим значение переменной
		mov m, 0
		mov eax, xx
		mov x, eax
		while0 :
		mov eax, x
		mov ebx, 10
		mov edx, 0
		div ebx
		mul ebx
		mov ebx, x
		sub ebx, eax
		cmp ebx, m
		jbe if1
			mov m, ebx
			if1:
		mov eax, x
		mov ebx, 10
		mov edx, 0
		div ebx
		mov x, eax
		cmp x, 0
		jne while0
		mov eax, xx
		mov x, eax
		while1 :
			mov eax, s
			mov ebx, 10
			mul ebx
			mov s, eax
			mov eax, x
			mov ebx, 10
			mov edx, 0
			div ebx
			mul ebx
			mov ebx, x
			sub ebx, eax
			add s, ebx
			cmp ebx, m
			jne if2
			mov eax,s
			mov ebx,10
			mul ebx
			add eax, m
			mov s, eax
				if2:
			mov ebx,10
			mov eax, x
			mov edx, 0
			div ebx
			mov x, eax
			cmp x, 0
			jne while1
			while2 :
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