#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "function.h"
using namespace std;
int pust(internet *root)
{
	if (root == NULL)
		return 0;
	else
		return 1;
}
internet* init(internet* root, int*n)
{
	if (pust(root) == 1)
	{
		cout << "Невозможно записать данные из файла в непустой список.Удалите существующий список" << endl;
		return root;
	}
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
		return NULL;
	}
	while (!feof(fp))
	{
		fgets(str1, 256, fp);
		if (str1[strlen(str1) - 1] == '\n')
			str1[strlen(str1) - 1] = '\0';
		if (key == 0)
		{
			p = NULL;
			root = new internet[1];
			p = strtok(str1, " ");
			strcpy(newname, p);
			root->name = strcpy(new char[strlen(newname) + 1], newname);
			p = strtok(NULL, " ");
			newtime = atoi(p);
			root->timespeak = newtime;
			root->next = NULL;
			t = root;
			key = 1;
			*n++;

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
			*n++;
		}
	}
	fclose(fp);
	cout << "Список считан" << endl;
	return root;
}
void fout(internet* root)
{
	FILE *fp;
	int i = 0;
	if ((fp = fopen("output.txt", "w")) == NULL)
	{
		cout << "Не удалось открыть файл для записи";
		return;
	}
	internet *t;
	t = root;
	while (t != NULL)
	{
		fprintf(fp, "%d", i);
		fputs("-элемент \n", fp);
		fputs(t->name, fp);
		fputs(" ", fp);
		fprintf(fp, "%d", t->timespeak);
		fputs("\n", fp);
		i++;
		t = t->next;
	}
	cout << "Список заагружен в файл output.txt" << endl;
	fclose(fp);
}
internet* dobavit(internet* root, int *n)
{
	internet* h, *t;
	t = root;
	int k;
	cout << "Введите позицию\n";
	cin >> k;
	int i = 0;
	int newtime;
	char newname[255];
	cout << "Введите фамилию\n";
	cin >> newname;
	cout << "Введите время разговора\n";
	cin >> newtime;
	h = new internet[1];
	h->name = strcpy(new char[strlen(newname) + 1], newname);
	h->timespeak = newtime;
	if (k == 0)
	{
		h->next = root;
		root = h;
	}
	else
	{
		k--;
		while (i != k && t->next != NULL)
		{
			t = t->next;
			i++;
		}
		if (i == k && t->next != NULL)
		{
			h->next = t->next;
			t->next = h;
			cout << "Элемент успешно добавлен\n";
		}
		else
		{
			if (i == k)
			{
				t->next = h;
				h->next = NULL;
			}
			else
				cout << "Невозможно добавить на эту позицию\n";
		}
	}
	*n++;
	return root;
}
internet* delitem(internet* root, int *n)
{
	internet* t;
	internet* h;
	t = root;
	h = t;
	while (t->next != NULL)
	{
		t = t->next;
		delete h;
		h = t;
	}
	*n = 0;
	return NULL;
}
internet* deletehead(internet* root, int *n)
{
	internet* t;
	t = root->next;
	*n--;
	delete root;
	return(t);
}
internet* delitemk(internet* root, int *n)
{
	internet* t;
	int k;
	cout << "Введите позицию\n";
	cin >> k;
	if (k == 0)
		root = deletehead(root, n);
	else
	{
		internet* p;
		p = root;
		int i = 0;
		k--;
		while (i != k && p->next != NULL)
		{
			p = p->next;
			i++;
		}
		if (i == k && p->next != 0)
		{
			t = p->next;
			p->next = t->next;
			delete t;
			cout << "Элемент успешно удален\n";
			*n--;
		}
		else
			if (i == k)
			{
				t = p->next;
				delete t;
				p->next = NULL;
			}
			else
				cout << "Нет элемета с такой позицией\n";
	}
	return root;
}
void listsearch(internet* root, int time)
{
	internet* p;
	p = root;
	int key = 0;
	int i = 0;
	do {
		if (p->timespeak == time)
		{
			cout << "Найденный" << i << "-элемент \n" << p->name << " " << p->timespeak << endl;
			key = 1;
		}
		p = p->next;
		i++;
	} while (p != 0);
	if (key == 0)
		cout << "Не найдено ниодного элемента\n";
}
void listsearch(internet* root, char* nname)
{
	internet* p;
	p = root;
	int i = 0;
	int key = 0;
	do {
		if (strcmp(p->name, nname) == 0)
		{
			cout << "Найденный" << i << "-элемент \n" << p->name << " " << p->timespeak << endl;
			key = 1;
		}
		p = p->next;
		i++;
	} while (p != 0);
	if (key == 0)
		cout << "Не найдено ниодного элемента\n";
}
void eprint(internet* head)
{
	internet* l = head;
	int i = 0;
	while (l)
	{
		cout << " " << i << "-элемент \n";
		cout << l->name << " ";
		cout << l->timespeak << endl;
		l = l->next;
		i++;
	}
}
internet* internetsort(internet* root)
{
	internet *a, *b, *p, *h = NULL;

	for (internet* i = root; i != NULL; )
	{
		a = i;
		i = i->next;
		b = h;
		for (p = NULL; (b != NULL) && (strcmp(a->name, b->name) > 0); )
		{
			p = b;
			b = b->next;
		}

		if (p == NULL) {
			a->next = h;
			h = a;
		}
		else {
			a->next = b;
			p->next = a;
		}
	}
	if (h != NULL)
		root = h;
	return root;
}