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

void contaPrimos(treenodeptr arvore, int& i)
{
    int div = 0;
    
    if (arvore != NULL)
    {
        contaPrimos(arvore->esq, i);
        
        for(int j = 2; j <= (arvore->info / 2); j++)
            if((arvore->info % j) == 0)
                div++;
                
        if(div == 2)
            i++;
            
        contaPrimos(arvore->dir, i);
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
    int i = 0;

    treenodeptr arvore = NULL;

    cin >> x;

    while(x != -1){
        tInsere(arvore, x);
        cin >> x;
    }
    
    contaPrimos(arvore, i);

    cout << i << " numeros primos" << endl;
    
    tDestruir(arvore);

    return 0;
}
