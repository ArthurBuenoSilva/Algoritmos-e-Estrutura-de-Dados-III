#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int n;
	int m;
	
	int *v = NULL;
	
	cin >> n;
	
	v = new int[n];
	
	for(int i = 0; i < n; i++)
	    cin >> v[i];
	
    for(int i = 0; i < n; i++){
        if(i == 0)
	        m = v[i];
        if(v[i] > m)
            m = v[i];
    }
    
    cout << m << endl;
	
	delete [] v; //Libera memória
	
	return 0;
}
