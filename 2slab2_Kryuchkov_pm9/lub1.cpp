#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "header.h"
using namespace std;
que::que() :first(new internet[1])
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
		cout << "Не удалось открыть файл для чтения" << endl;
		first = NULL;
		last = NULL;
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
que::~que()
{
	if (first != NULL)
	{
		internet* t;
		while (first != last)
		{
			t = first;
			first = first->next;
			delete[] t;
		}
		delete[] first;
		first = NULL;
		last = NULL;
	}
}
que::que(que const& oth) :first(new internet[1])
{
	int key = 0;
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
		key = 1;
	}
	if (key)
		last = o;
}
que& que::operator=(que const& oth)
{
	if (&oth != this)
	{
		if (first != NULL)
		{
			internet*t;
			while (first != last)
			{
				t = first;
				first = first->next;
				delete[] t;
			}
			delete[] first;
		}
		if (oth.first == NULL)
			return *this;
		first = new internet[1];
		first->name = strcpy(first->name, oth.first->name);
		first->timespeak = oth.first->timespeak;
		internet *o = first;
		internet *n = oth.first;
		int key = 0;
		while (n != oth.last)
		{
			o->next = new internet[1];
			o = o->next;
			n = n->next;
			o->name = strcpy(o->name, n->name);
			o->timespeak = n->timespeak;
			key = 1;
		}
		if (key)
			last = o;
		o->next = NULL;
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
que::internet::~internet() { if (name != NULL) delete[] name; }
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
void que::udl()
{
	if (first == NULL)
		throw exception("Списка не существует. Вызовети конструктор\n");
	if (pust() == 0)
		throw exception("Очередь пуста\n");
	internet* z = first, *l = NULL, *r = NULL, *p = NULL;
	int t = 0;
	while (z)
	{
		if (z->timespeak < t)
		{
			l = p;
			t = z->timespeak;
			r = z->next;
		}
		p = z;
		z = z->next;
	}
	if (!t)
	{
		cout << "Отсуствуют элементы очереди с отрицательными полями\n";
		return;
	}
	if (l == NULL)
	{
		internet* g;
		g = first;
		first = first->next;
		cout << "Hаименьший отрицательный элемент в списке удален\n";
		delete[] g;
		return;
	}
	else
	{
		internet* g;
		g = l->next;
		l->next = r;
		delete[] g;
		cout << "Hаименьший отрицательный элемент в списке удален\n";
		if (r == NULL)
			last = l;
	}
}
void que::eprint()
{
	if (first == NULL)
		throw exception("Списка не существует. Вызовети конструктор\n");
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
}