#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int n;
	int x = 0;
	
	int *v = NULL;
	
	cin >> n;
	
	v = new int[n];
	
	for(int i = 0; i < n; i++)
	    cin >> v[i];
	
    for(int i = 0; i < n; i++)
	    if(v[i] >= 0 && v[i] % 2 == 0)
	        x++;
	
	cout << x << endl;
	
	delete [] v; //Libera memória
	
	return 0;
}
