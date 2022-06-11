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

void emOrdem (treenodeptr arvore)
{
    if (arvore != NULL)
    {
        emOrdem(arvore->esq);
        emOrdem(arvore->dir);
        cout << arvore->info << " ";
    }
}


int main()
{
    int x = 0;
    int n = 0;

    treenodeptr arvore = NULL;

    cin >> x;

    while(x != -1){
        tInsere(arvore, x);
        cin >> x;
    }

    emOrdem(arvore);

    return 0;
}
