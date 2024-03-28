class AbstractIterator
{
public:
	virtual ~AbstractIterator() {};
	virtual bool InRange() const = 0; // ������ � ���������� ��������?
	virtual void Reset() = 0; // �������� ������ � ������
	virtual int& operator *() const = 0; // ������������� (������ ��������)
	virtual void operator ++() = 0; // ����� �� �������
};
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