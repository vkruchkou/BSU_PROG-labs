struct que
{
public:
	que();
	~que();
	que(que const&);
	que& operator=(que const&);
	int pust();
	void init();
	void dobavit();
	void deliteml();
	void delitem();
	void eprint();
private:
	struct internet
	{
		char* name;
		int timespeak;
		internet *next;
		internet();
		~internet();
		internet(internet const&);
		internet& operator=(internet const&);
	};
private:
	internet* first;
	internet* last;
};