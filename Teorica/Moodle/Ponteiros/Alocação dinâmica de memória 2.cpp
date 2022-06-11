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
	
	int n;
	
	float m = 0;
	
	cin >> n;
	
	nota = new notas[n];
	
	for(int i = 0; i < n; i++)
		cin >> nota[i].n1 >> nota[i].n2 >> nota[i].n3 >> nota[i].n4;
	
	for(int i = 0; i < n; i++)
	    nota[i].m = (nota[i].n1 + nota[i].n2 + nota[i].n3 + nota[i].n4) / 4.0;
	
	for(int i = 0; i < n; i++)
	    m += nota[i].m;
	   
	cout << fixed << setprecision(2) << m / n << endl;

	delete [] nota; //Libera memória
	
	return 0;
}
