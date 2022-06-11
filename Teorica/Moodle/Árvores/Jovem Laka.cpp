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

void preOrdem (treenodeptr arvore, list<int>& i)
{
    if (arvore != NULL)
    {
        i.push_back(arvore->info);
        preOrdem(arvore->esq, i);
        preOrdem(arvore->dir, i);
    }
}

void emOrdem (treenodeptr arvore, list<int>& i)
{
    if (arvore != NULL)
    {
        emOrdem(arvore->esq, i);
        i.push_back(arvore->info);
        emOrdem(arvore->dir, i);
    }
}

void posOrdem (treenodeptr arvore, list<int>& i)
{
    if (arvore != NULL)
    {
        posOrdem(arvore->esq, i);
        posOrdem(arvore->dir, i);
        i.push_back(arvore->info);
    }
}

int checkPosition(list<int> l, int n)
{
    int i = 0;

    while(!l.empty()) {
        if (n == l.front())
            return i;

        l.pop_front();
        i++;
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

    int prePos;
    int emPos;
    int posPos;

    list<int> pre;
    list<int> em;
    list<int> pos;

    treenodeptr arvore = NULL;

    cin >> x;

    while(x != -1){
        tInsere(arvore, x);
        cin >> x;
    }

    cin >> n;

    preOrdem(arvore, pre);
    prePos = checkPosition(pre, n);

    emOrdem(arvore, em);
    emPos = checkPosition(em, n);

    posOrdem(arvore, pos);
    posPos = checkPosition(pos, n);

    if(prePos < emPos){
        if(prePos < posPos)
            cout << "Pre" << endl;
        else
            cout << "Pos" << endl;
    }
    else if(emPos < posPos)
        cout << "Em" << endl;
    else
        cout << "Pos" << endl;
    
    tDestruir(arvore);

    return 0;
}
