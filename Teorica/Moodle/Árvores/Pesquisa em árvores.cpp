#include <iostream>

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
    int t = 0;
    treenodeptr arvore = NULL;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x != -1)
            tInsere(arvore, x);
    }

    cin >> t;

    treenodeptr p = tPesq(arvore, t);

    if(p != nullptr)
        cout << "Encontrado" << endl;
    else
        cout << "Nao Encontrado" << endl;
    
    tDestruir(arvore);

    return 0;
}
