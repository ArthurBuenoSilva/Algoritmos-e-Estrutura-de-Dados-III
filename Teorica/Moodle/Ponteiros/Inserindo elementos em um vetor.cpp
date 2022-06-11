#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int n;
	
	int *v = NULL;
	
	cin >> n;
	
	v = new int[n];
	
	for(int i = 0; i < n; i++)
	    cin >> v[i];
	
    for(int i = 0; i < n; i++)
	    cout << v[i] << " ";
	
	delete [] v; //Libera memória
	
	return 0;
}
