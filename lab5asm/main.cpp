#define _CRT_SECURE_NO_WARNINGS
/*������� ������� ������ 9 ������������ ������ 5 ������� 7
������� �������:
����������� ���������, ������� ����������� � ������������ ������.
������� ��������� ?. ����������  � ��� ������� ��������� �� ��������� ����.
������ ����� K (������).������� k-� ������� �� ������.
������ 2-� ������, ����� � � 1-� ������. ���������� ������� �� �������.
*/
#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>
#include <stdio.h>
using namespace std;
//void _fastcall bprintf(char b)
//{
//	cout << b;
//}
//extern	"C" void _cdecl	bleks(int, char[], char[]);
//extern	"C" void _cdecl	leks(int,char[]);
//extern	"C" void _cdecl	dellek(int,char[], char[], int);
extern	"C" int plek(int, char[], char[]);
int main()
{
	setlocale(LC_ALL, "rus");
	cout << "������� ������\n";
	char str1[256], str2[27] = "QWERTYUIOPASDFGHJKLZXCVBNM", buf[256], str3[256];
	fgets(str1, 256, stdin);
	int t, k;
	int len1 = strlen(str1);
	cout << endl;
	//cout << "������� �� ��������� ����" << endl;
	//bleks(len1,str1, str2);
	//cout << "�������" << endl;
	//leks(str1);
	//cout << "������ ������ ������� ��� ��������(� ������ ������� ������� ������)" << endl;
	//cin >> k;
	//dellek(str1,buf, k);
	//cout << "���������� ������" << endl;
	//fputs(str1, stdout);
	//cout << endl;
	cout << "������� ��������� ��� ������" << endl;
	fflush(stdin);
	rewind(stdin);
	fgets(str3, 256, stdin);
	cout << endl;
	cout << str1;
	cout << str2;
	t = plek(len1, str1, str3);
	if(t)
		cout << "��������� �������" << endl;
	else
		cout << "��������� �� �������" << endl;
	system("pause");
	return 0;
}
