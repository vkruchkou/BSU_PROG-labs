#include <stdio.h>
#include <iostream>
#include <time.h>
#include <cmath>
/*Крючков Василий группа 9 лабораторная работа 5 задание 7
Условие задания:
Используя абстрактные классы, реализовать конкретные классы: ArrayStack( на массиве) и
ArrayStackIterator
*/
using namespace std;

class AbstractIterator
{
public:
	virtual ~AbstractIterator() {};
	virtual bool InRange() const = 0; // индекс в допустимых пределах?
	virtual void Reset() = 0; // сбросить индекс в начало
	virtual int& operator *() const = 0; // разыменование (чтение элемента)
	virtual void operator ++() = 0; // сдвиг на элемент
};
class AbstractContainer
{
public:
	virtual ~AbstractContainer() {};
	virtual bool IsEmpty() const = 0; // контейнер пуст
	virtual bool IsFull() const = 0; // контейнер полный
};
class AbstractStack : public AbstractContainer
{
public:
	virtual void push(const int& n) = 0; // втолкнуть в стек
	virtual int pop(void) = 0; // вытолкнуть из стека	
};


class ArrayStack : public AbstractStack
{
protected:
	int size; // размерность массива
	int* p; // указатель на массив
	int top; // верхушка стека
public:
	ArrayStack(int _size);
	ArrayStack(ArrayStack &s);
	~ArrayStack();
	void push(const int& n); // втолкнуть в стек
	int pop(void); // вытолкнуть из стека
	bool IsEmpty() const;
	bool IsFull() const;
	friend class ArrayStackIterator;
};


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
ArrayStack::ArrayStack(int _size) :size(_size), p(new int[_size]), top(0)  {}
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



class ArrayStackIterator : public AbstractIterator
{
	ArrayStack &a; // ссылка на стек
	int pos; // текущая позиция итератора
	ArrayStackIterator();
public:
	ArrayStackIterator(const ArrayStack& _a);
	bool InRange() const; // индекс в допустимых пределах
	void Reset(); // сбросить индекс в начало
	int& operator *() const; // разыменование (чтение элемента)
	void operator ++(); // сдвиг на элемент
};


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


int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Введите размерность стека\n";
	int n;
	cin >> n;
	srand((unsigned int)time(0));
	ArrayStack stack(n);
	try
	{
		while (!stack.IsFull())
		{
			int t;
				t = (rand() % 100);
				stack.push(t);
		}

		ArrayStack tstack(stack);

		cout << "Сгенерированный стек:\n";

		while (!tstack.IsEmpty())
			cout << tstack.pop() << endl;
		cout << endl;

		ArrayStackIterator istack(stack);
		cout << "Вывод стека с помощью итератора\n";
		while (istack.InRange())
		{
			cout << *istack << endl;
			++istack;
		}
		cout << endl;
	}

	catch (const std::exception & ex)
	{
		cout << endl << "Вызвано исключение: ";
		cout << ex.what() << endl;
	}

	system("pause");
	return 0;
}