#include <stdio.h>
#include <iostream>
#include <time.h>
#include "Stack.h"
#include "Iterator.h"
using namespace std;
bool ArrayStack::IsEmpty() const
{
	if (top == 0)
		return true;
	else
		return false;
}
bool ArrayStack::IsFull() const
{
	if (top == size)
		return true;
	else
		return false;
}
ArrayStack::ArrayStack(int _size) :size(_size), p(new int[_size]), top(0), AbstractStack() {}
ArrayStack::ArrayStack(ArrayStack &s) : size(s.size), p(new int[s.size]),top(s.top)
{
	for (int i = 0; i < size; i++)
		p[i] = s.p[i];
}
ArrayStack::~ArrayStack()
{
	delete[] p;
}
void ArrayStack::push(const int& n)
{
	if (IsFull())
		throw exception("Невозможно добавить элемент cтек полон\n");
	p[top] = n;;
	top++;
}
int  ArrayStack::pop()
{
	if (IsEmpty())
		throw exception("Невозможно взять элемент стек пуст\n");
	else
		top--;
	return p[top];
}
ArrayStackIterator::ArrayStackIterator(const ArrayStack& _a) : a((ArrayStack&)_a), pos(a.top), AbstractIterator() {}
bool ArrayStackIterator::InRange() const
{
	if (pos < 1)
		return false;
	else
		return true;
}
void ArrayStackIterator::Reset()
{
	pos = a.top;
}
int& ArrayStackIterator::operator *() const
{
	if (InRange())
		return a.p[pos-1];
	else
		throw exception("Индекс в недопустимых пределах\n");
}
void ArrayStackIterator::operator ++()
{
	pos--;
}