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

void folhasPreOrdem (treenodeptr arvore, int &n)
{
    if (arvore != NULL)
    {
        folhasPreOrdem(arvore->esq, n);
        folhasPreOrdem(arvore->dir, n);
    }
    else{
        n++;
    }
}

int contaFolhas(treenodeptr arvore)
{
    int n = -1;
    folhasPreOrdem(arvore, n);
    return n;
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

    treenodeptr arvore = NULL;

    cin >> x;

    while(x != -1){
        tInsere(arvore, x);
        cin >> x;
    }

    cout << endl << contaFolhas(arvore) / 2 << endl;

	tDestruir(arvore);
	
    cout << endl;

    return 0;
}
