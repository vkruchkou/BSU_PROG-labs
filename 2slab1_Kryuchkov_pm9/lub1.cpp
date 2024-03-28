#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "header.h"
using namespace std;
que::que() :first(new internet[1]), last(new internet[1]) {}
que::~que()
{
	if (first == last)
		delete[] first;
	else
	{
		delete[] first;
		delete[] last;
	}
}
que::que(que const& oth) :first(new internet[1]), last(new internet[1])
{
	first->name = strcpy(first->name, oth.first->name);
	first->timespeak = oth.first->timespeak;
	internet *o = first;
	internet *n = oth.first;
	while (n != oth.last)
	{
		o->next = new internet[1];
		o = o->next;
		n = n->next;
		o->name = strcpy(o->name, n->name);
		o->timespeak = n->timespeak;
	}
	last->name = strcpy(last->name, oth.last->name);
	last->timespeak = oth.last->timespeak;
}
que& que::operator=(que const& oth)
{
	if (&oth != this)
	{
		internet*t;
		while (first != last)
		{
			t = first;
			first = first->next;
			delete[] t;
		}
		delete[] first;
		delete[] last;
		first = new internet[1];
		last = new internet[1];
		first = oth.first;
		last = oth.last;
	}
	return *this;
}
que::internet::internet()
{
	name = new char[256];
	name[0] = '\0';
	timespeak = 0;
}
que::internet::internet(internet const& oth) :name(new char[256])
{
	name = strcpy(name, oth.name);
	timespeak = oth.timespeak;
	next = oth.next;
}
que::internet::~internet() {  delete[] name; }
que::internet& que::internet::operator=(internet const& oth)
{
	if (&oth != this)
	{
		if (name != NULL)
			delete[] name;
		name = new char[256];
		name = strcpy(name, oth.name);
		timespeak = oth.timespeak;
		next = oth.next;
	}
	return *this;
}
int que::pust()
{
	if (strcmp(first->name, "\0") == 0)
		return 0;
	else

		return 1;
}
void que::init()
{
	if (pust() == 1)
		throw exception("Невозможно записать данные из файла в непустой список.Удалите существующий список\n");
	internet* t = NULL;
	internet* h = NULL;
	int key = 0;
	char newname[255];
	int newtime;
	FILE *fp;
	char str1[256];
	char* p;
	if ((fp = fopen("input.txt", "r")) == NULL)
	{
		cout << "Не удалось открыть файл для чтения\n(функция открытия файла на 97 строке)" << endl;
		return;
	}
	while (!feof(fp))
	{
		fgets(str1, 256, fp);
		if (str1[strlen(str1) - 1] == '\n')
			str1[strlen(str1) - 1] = '\0';
		if (key == 0)
		{
			p = NULL;
			p = strtok(str1, " ");
			strcpy(newname, p);
			first->name = strcpy(new char[strlen(newname) + 1], newname);
			p = strtok(NULL, " ");
			newtime = atoi(p);
			first->timespeak = newtime;
			first->next = NULL;
			t = first;
			last = t;
			key = 1;
		}
		else
		{
			p = NULL;
			h = t;
			t = t->next;
			t = new internet[1];
			p = strtok(str1, " ");
			strcpy(newname, p);
			t->name = strcpy(new char[strlen(newname) + 1], newname);
			p = strtok(NULL, " ");
			newtime = atoi(p);
			t->timespeak = newtime;
			h->next = t;
			t->next = NULL;
			last = t;
		}
		if (key == 0)
		{
			cout << "Файл пуст";
		}
	}
	fclose(fp);
	cout << "Список считан" << endl;
	return;
}
void que::dobavit()
{
	internet* h;
	int newtime;
	char newname[255];
	cout << "Введите фамилию\n";
	cin >> newname;
	cout << "Введите время разговора\n";
	cin >> newtime;
	h = new internet[1];
	h->name = strcpy(new char[strlen(newname) + 1], newname);
	h->timespeak = newtime;
	h->next = NULL;
	if (pust() == 0)
	{
		first = h;
		last = h;
		cout << "Элемент добавлен\n";
		return;
	}
	last->next = h;
	last = h;
	cout << "Элемент добавлен\n";
	return;
}
void que::deliteml()
{
	if (pust() == 0)
		throw exception("Очередь пуста\n");
	if (first == last)
	{
		first->name[0] = '\0';
		first->timespeak = 0;
		cout << "Элемент удален\n";
		return;
	}
	internet* t;
	t = first;
	first = first->next;
	cout << "Элемент удален\n";
	delete[] t;
	return;
}
void que::delitem()
{
	if (pust() == 0)
		throw exception("Очередь пуста\n");
	if (first == last)
	{
		first->name[0] = '\0';
		first->timespeak = 0;
		cout << "Элементы удален\n";
		return;
	}
	internet* t;
	while (first != last)
	{
		t = first;
		first = first->next;
		delete[] t;
	}
	first->name[0] = '\0';
	first->timespeak = 0;
	cout << "Элементы удалены\n";
	return;
}
void que::eprint()
{
	if (pust() == 0)
		throw exception("Очередь пуста\n");
	internet* l = first;
	cout << "Начало очереди\n";
	while (l)
	{
		cout << l->name << " ";
		cout << l->timespeak << endl;
		l = l->next;
	}
	cout << "Конец очереди\n";
	FILE *fp;
	if ((fp = fopen("output.txt", "w")) == NULL)
	{
		cout << "Не удалось открыть файл для записи";
		return;
	}
	internet *t;
	t = first;
	fputs("Начало очереди\n", fp);
	while (t != NULL)
	{
		fputs(t->name, fp);
		fputs(" ", fp);
		fprintf(fp, "%d", t->timespeak);
		fputs("\n", fp);
		t = t->next;
	}
	fputs("Конец очереди\n", fp);
	cout << "Список заагружен в файл output.txt" << endl;
	fclose(fp);
}