/*Крючков Василий группа 9 лабораторная работа 2 задание 2.7
Условие задания:
Сумму вычислить с точностью e, действительное число x и точность e вводятся с консоли. 
Для сравнения со значением ряда для х, вычислить функцию у(х).:ln=(1+x)/(1-x)=2(x+x^3/3+x^5/5+x^7/7...), x∈(-1,+1)
Тест:
input					output
0.00001 -0.5			-1.09861
0.014 0.9				2.86856
0.0002 1.4				Ошибка ввода, x должен принадлежать промежутку (-1,+1)
*/
#include <iostream>
#include <math.h>
using namespace std;
long double lnfunk (long double e, long double x)
{
	long double s, ss;
	s = x;
	ss = x;
		for (int k = 3; fabs(ss) > e; k += 2)
		{
			ss *= x * x * (k - 2) / k;
			s += ss;
		}
	s *= 2;
	return s;
}
int main()
{
	setlocale(LC_ALL, "rus");
	long double e, x;
	cout << "Введите точность e\n";
	cin >> e;
	cout << "Введите значение x\n";
	cin >> x;
	if (x < -1 || x > 1)
	{
		cout << "Ошибка ввода, x должен принадлежать промежутку (-1,+1) \n";
		system("pause");
		return 0;
	}
	else
		cout << "C точностью "<<e <<" "<< "ln=(1+x)/(1-x)= " << lnfunk(e,x) <<endl;
	system("pause");
	return 0;
}