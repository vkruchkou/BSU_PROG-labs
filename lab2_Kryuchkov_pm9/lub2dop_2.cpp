/*������� ������� ������ 9 ������������ ������  �������������� �������
������� �������:
�������� ���������� ��� double, ��������� ������� � ������� �� ������� ������ �� ������,
��������� ���������� � ������� ��� ������� ������� (� ������ ����� ).
������������ ����������� ������� ���������� � ���������� �������� � �������.
��������� �������������� ��������� � ���� int.
*/
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	double a, b, r, rr;
	char s;
	cout << "Calculator 1.01\n" << "��� ������ �� ��������� ������� ������ ������ ����� ��������E�\n" << "��� ��������� ������ ������ �������� ������� ������ ������ ����� ��������S�\n";
	for (;;)
	{
		cout << "������� ���� ��������\n";
		cin >> s;
		if (s == 'E')
		{
			cout << "�� ����� �� ���������\n";
			break;
		}
		if (s == 'S')
			cout << "'O'-���������� � ������� �������\n" << "'o'-���������� � ������� �������\n" << "'h'-��������� ������� � ������� �� �������\n" << "'p'-�������������� ��������� � ���� int\n";
		if (s == 'h')
		{
			cout << "������� �������� ������ ��������\n";
			cin >> a;
			cout << "������� �������� ������ ��������\n";
			cin >> b;
			cout << "10 �/� " << dec << int(a / b) << " " << (a - a*int(a / b)) << "   8 �/� " << oct << int(a / b) << " " << (a - a*int(a / b)) << "    16 �/� " << hex << int(a / b) << " " << (a - a*int(a / b)) << endl;
		}
		if (s == 'O'|| s == 'o' || s == 'p')
		{
			cout << "������� �������� ��������\n";
			cin >> a;
		}
		if (s == 'O')
			cout << "10 �/� " << dec << ceil(a) << "    8 �/� " << oct << ceil(a) << "    16 �/� " << hex << ceil(a) << endl;
		if (s == 'o')
			cout << "10 �/� " << dec << floor(a) << "    8 �/� " << oct << floor(a) << "    16 �/� " << hex << floor(a) << endl;
		if (s == 'p')
			cout << "10 �/� " << dec << int(a) << "    8 �/� " << oct << int(a) << "    16 �/� " << hex << int(a) << endl;
		switch (s)
		{
		case 'p': break;
		case 'o': break;
		case 'O': break;
		case 'S': break;
		case 'h': break;
		default: cout << "�� ����� �������������� ���� ��������\n";
		}
	}
	system("pause");
	return 0;
}