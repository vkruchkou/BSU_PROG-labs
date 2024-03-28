#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	unsigned int m = 0, x, xs, res = 1;
	cout << "Введите число\n";
	cin >> x;
	xs = x;
	while (x)
	{
		x /= 10;
		m++;
	}
	cout << "Количество пар цифр чисел, вычисленное на с++ у числа " << xs << " " << int(m / 2) << endl;
	m = 0;
	x = xs;
	_asm
	{
		mov ebx, 10			//перемещаем 10 в ebx
		mov eax, x			//перемещаем значение х в eax
		for1 :				//
		add m, 1			//m++
			mov edx, 0		//чистим регистр edx для дальнейшего деления
			div ebx			//делим наше число на 10
			cmp eax, 0		//сравниваем
			JNZ for1		//если не равно нулю переходим на JNZ
			mov eax, m		//перемещаем значение  m в eax
			mov ebx, 2		//перемещаем 2 в ebx
			mov edx, 0		//чистим регистр edx для дальнейшего деления
			div ebx			//делим наше число на 2
			mov res, eax	//присваеваем переменной res частное
	}
	cout << "Результат на assembler " << res << endl;	// результат на assembler
	system("pause");
	return 0;
}