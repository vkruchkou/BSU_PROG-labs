/*������� ������� ������ 9 ������������ ������ 1 ������� 8
������� �������:
�������� �� ����� �������.
����:
input			output
17				�������
234				���������
31				�������
88				���������
*/
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int x, xs, t;
	cin >> x;
	xs = x;
	t = 1;
	for (int i = 2; i<x; i++)
		if (x%i == 0)		//���� ���� ��� ��������� ����� ��������� �� ����� �� 2 �� �����,
			t = 0;			//������� ������ ���������� �� ����, �� ����������� ���������� t �������� 0; ���� t=1, �� ����� �������
	if (t == 1)
		cout << " ����� " <<xs << " �������\n";
	else
		cout << " ����� " <<xs << " ���������\n";
	system("pause");
	return 0;
}
