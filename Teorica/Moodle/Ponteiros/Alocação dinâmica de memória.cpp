#include <iostream>
#include <iomanip>

using namespace std;

struct notas
{
	int n1;
	int n2;
	int n3;
	int n4;
	float m;
};

int main()
{
	notas *nota = NULL;
	
	nota = new notas;
	
	cin >> nota->n1 >> nota->n2 >> nota->n3 >> nota->n4;
	
	nota->m = (nota->n1 + nota->n2 + nota->n3 + nota->n4) / 4.0;
	
	cout << fixed << setprecision(2) << nota->m;

	delete nota; //Libera memória
	
	return 0;
}
