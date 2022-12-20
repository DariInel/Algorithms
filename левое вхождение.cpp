#include<iostream>
using namespace std;
int n, m;
int b[100000];
int main()
{
    cin >> n ;
    for (int j = 0; j < n; j++){
    	cin >> b[j];
	}
	cin >> m;
    for (int j = 1; j <= m; j++){
    	int a, l, r;
    	cin >> a;
    	l = -1;
    	r = n-1;
    	while ( r - l > 1 )
    	{
    		int m = (l + r) / 2;
    		if ( b[m] < a )
    			l=m;
    		else
    			r = m;
		}
		if(b[r] == a)
			cout << r + 1 << "\n";
		else
			cout << '0' << "\n";		
	}  
}
