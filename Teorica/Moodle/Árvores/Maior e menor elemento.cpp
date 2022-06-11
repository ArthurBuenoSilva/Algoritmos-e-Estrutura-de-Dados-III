#include <iostream>
#include <list>

using namespace std;

struct treenode{
    int info;
    treenode *esq;
    treenode *dir;
};
typedef treenode* treenodeptr;

void tInsere(treenodeptr &p, int x)
{
    if (p == NULL)
    {
        p = new treenode;
        p->info = x;
        p->esq = NULL;
        p->dir = NULL;
    }
    else if (x < p->info)
        tInsere(p->esq, x);
    else
        tInsere(p->dir, x);
}

treenodeptr tPesq(treenodeptr p, int x)
{
    if (p == NULL)
        return NULL;
    else
    if (x == p->info)
        return p;
    else
    if (x < p->info)
        return tPesq(p->esq, x);
    else
        return tPesq(p->dir,x);
}

void emOrdem (treenodeptr arvore, list<int>& l)
{
    if (arvore != NULL)
    {
        emOrdem(arvore->esq, l);
        l.push_back(arvore->info);
        emOrdem(arvore->dir, l);
    }
}

void tDestruir (treenodeptr &arvore)
{
	if (arvore != NULL)
	{
		tDestruir(arvore->esq);
		tDestruir(arvore->dir);
		delete arvore;
	}
	arvore = NULL;
}

int main()
{
    int x = 0;
    int n = 0;
    list<int> l;

    treenodeptr arvore = NULL;

    cin >> x;

    while(x != -1){
        tInsere(arvore, x);
        cin >> x;
    }
    
    emOrdem(arvore, l);

    cout << l.front() << " e " << l.back() << endl;
    
    tDestruir(arvore);

    return 0;
}
