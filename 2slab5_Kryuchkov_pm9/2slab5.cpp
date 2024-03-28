#include <stdio.h>
#include <iostream>
#include <time.h>
#include <cmath>
/*������� ������� ������ 9 ������������ ������ 5 ������� 7
������� �������:
��������� ����������� ������, ����������� ���������� ������: ArrayStack( �� �������) �
ArrayStackIterator
*/
using namespace std;

class AbstractIterator
{
public:
	virtual ~AbstractIterator() {};
	virtual bool InRange() const = 0; // ������ � ���������� ��������?
	virtual void Reset() = 0; // �������� ������ � ������
	virtual int& operator *() const = 0; // ������������� (������ ��������)
	virtual void operator ++() = 0; // ����� �� �������
};
class AbstractContainer
{
public:
	virtual ~AbstractContainer() {};
	virtual bool IsEmpty() const = 0; // ��������� ����
	virtual bool IsFull() const = 0; // ��������� ������
};
class AbstractStack : public AbstractContainer
{
public:
	virtual void push(const int& n) = 0; // ��������� � ����
	virtual int pop(void) = 0; // ���������� �� �����	
};


class ArrayStack : public AbstractStack
{
protected:
	int size; // ����������� �������
	int* p; // ��������� �� ������
	int top; // �������� �����
public:
	ArrayStack(int _size);
	ArrayStack(ArrayStack &s);
	~ArrayStack();
	void push(const int& n); // ��������� � ����
	int pop(void); // ���������� �� �����
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
		throw exception("���������� �������� ������� c��� �����\n");
	p[top] = n;;
	top++;
}
int  ArrayStack::pop()
{
	if (IsEmpty())
		throw exception("���������� ����� ������� ���� ����\n");
	else
		top--;
	return p[top];
}



class ArrayStackIterator : public AbstractIterator
{
	ArrayStack &a; // ������ �� ����
	int pos; // ������� ������� ���������
	ArrayStackIterator();
public:
	ArrayStackIterator(const ArrayStack& _a);
	bool InRange() const; // ������ � ���������� ��������
	void Reset(); // �������� ������ � ������
	int& operator *() const; // ������������� (������ ��������)
	void operator ++(); // ����� �� �������
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
		throw exception("������ � ������������ ��������\n");
}
void ArrayStackIterator::operator ++()
{
	pos--;
}


int main()
{
	setlocale(LC_ALL, "rus");
	cout << "������� ����������� �����\n";
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

		cout << "��������������� ����:\n";

		while (!tstack.IsEmpty())
			cout << tstack.pop() << endl;
		cout << endl;

		ArrayStackIterator istack(stack);
		cout << "����� ����� � ������� ���������\n";
		while (istack.InRange())
		{
			cout << *istack << endl;
			++istack;
		}
		cout << endl;
	}

	catch (const std::exception & ex)
	{
		cout << endl << "������� ����������: ";
		cout << ex.what() << endl;
	}

	system("pause");
	return 0;
}