struct internet
{
	char* name;
	int timespeak;
	internet *next;
};
int pust(internet *root);
internet* init(internet* root, int*n);
void fout(internet* root);
internet* dobavit(internet* root, int *n);
internet* delitem(internet* root, int *n);
internet* deletehead(internet* root, int *n);
internet* delitemk(internet* root, int *n);
void listsearch(internet* root, int time);
void listsearch(internet* root, char* nname);
void eprint(internet* head);
internet* internetsort(internet* root);