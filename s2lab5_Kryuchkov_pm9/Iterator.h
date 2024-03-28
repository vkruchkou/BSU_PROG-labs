class AbstractIterator
{
public:
	virtual ~AbstractIterator() {};
	virtual bool InRange() const = 0; // индекс в допустимых пределах?
	virtual void Reset() = 0; // сбросить индекс в начало
	virtual int& operator *() const = 0; // разыменование (чтение элемента)
	virtual void operator ++() = 0; // сдвиг на элемент
};
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