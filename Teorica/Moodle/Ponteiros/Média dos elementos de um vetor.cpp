#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int n;
	float m = 0;
	
	int *v = NULL;
	
	cin >> n;
	
	v = new int[n];
	
	for(int i = 0; i < n; i++)
	    cin >> v[i];
	
    for(int i = 0; i < n; i++)
	    m += v[i];
	    
	cout << fixed << setprecision(2) << m / n << endl;
	
	delete [] v; //Libera memória
	
	return 0;
}
