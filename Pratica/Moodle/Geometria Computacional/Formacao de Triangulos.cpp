#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct ponto
{
	float x;
	float y;
};
typedef ponto vetor;

vetor cria_vetor(ponto A, ponto B)
{
	vetor AB;
	AB.x = B.x - A.x;
	AB.y = B.y - A.y;
	return AB;
}

float vetorial(vetor A, vetor B)
{
	float v;
	v = A.x * B.y - A.y * B.x;
	return v;
}

float escalar(vetor A, vetor B)
{
	float e;
	e = A.x * B.x + A.y * B.y;
	return e;
}

float area_triangulo(ponto A, ponto B, ponto C)
{
	vetor AB;
	vetor AC;
	float area;
	AB = cria_vetor(A, B);
	AC = cria_vetor(A, C);
	area = fabs(vetorial(AB, AC)) / 2;
	return area;
}

int main()
{
	int n;
	float a;
	ponto p1, p2, p3;
	
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
	    cin >> p1.x >> p1.y;
	    cin >> p2.x >> p2.y;
	    cin >> p3.x >> p3.y;
	    
	    a = area_triangulo(p1, p2, p3);
	    
	    if(a != 0)
	        cout << fixed << setprecision(2) << a << endl;
	    else
	        cout << "Nao formam triangulo" << endl;
	}

	return 0;
}