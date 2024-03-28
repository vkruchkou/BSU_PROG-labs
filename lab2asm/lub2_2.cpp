#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int s = 0, x, xx, t, k, i;
	cin >> x;
	for (i = 0; i <= 9; i++)
	{
		xx = x;
		k = 0;
		while (xx != 0)
		{
			t = xx % 10;
			xx /= 10;
			if (t == i)
				k++;
		}
		if (k != 0)
			s++;
	}
	cout << "Количество различных цифр у числа " << x << " равно " << s;
	_asm
	{
		mov s, 0		// чистим значение переменной
		mov i, 0		// чистим значение переменной
		for_1:
		mov eax, x			//
			mov xx, eax		// xx = x
			mov k, 0		// k = 0
			while_1 :
			mov eax, xx
			mov edx, 0
			mov ebx, 10
			div ebx			// x/10
			mul ebx			// x/10*10
			mov ebx, xx
			mov t, ebx		// t=xx
			sub t, eax		// t= t-x/10*10
			mov eax, xx
			mov edx, 0
			mov ebx, 10
			div ebx			// xx/10
			mov xx, eax		// xx=xx/10
			mov eax, i
			cmp t, eax
			jne  if_1		// if(t!=i) переход на if_1
			add k, 1			// k++
			if_1:
			cmp xx, 0
			jne while_1		// if(xx!=0) переход на while_1
			cmp k, 0
			je  if_2
			add s, 1		// s++
			if_2 :
			add i, 1		// i++			
			cmp i, 10
			jne for_1		// if(i!=10) переход на for_1
	}
	cout << endl << "Результат на assembler " << s;
	system("pause");
	return 0;
}