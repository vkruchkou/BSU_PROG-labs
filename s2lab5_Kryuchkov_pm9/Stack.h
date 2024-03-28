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