#include <iostream>
#include <iomanip>

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

void mediaPreOrdem (treenodeptr arvore, float &m)
{
    if (arvore != NULL)
    {
        m += arvore->info;
        mediaPreOrdem(arvore->esq, m);
        mediaPreOrdem(arvore->dir, m);
    }
}

float calculaMedia(treenodeptr arvore)
{
    float m = 0;
    mediaPreOrdem(arvore, m);
    return m;
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

    treenodeptr arvore = NULL;

    cin >> x;

    while(x != -1){
        n++;
        tInsere(arvore, x);
        cin >> x;
    }

    cout << fixed << setprecision(2) << "Media: " << (calculaMedia(arvore) / n) << endl;

    cout << endl;
    
    tDestruir(arvore);

    return 0;
}
