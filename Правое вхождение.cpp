#include<iostream>
using namespace std;
int n, m;
int b[100000];
int main()
{
    cin >> n >> m;
    for (int j = 0; j < n; j++){
    	cin >> b[j];
	}
    for (int j = 1; j <= m; j++){
    	int a, l, r;
    	cin >> a;
    	l = 0;
    	r = n;
    	while ( r - l > 1 )
    	{
    		int m = (l + r) / 2;
    		if ( b[m] > a )
    			r=m;
    		else
    			l = m;
		}
		if(b[l] == a)
			cout << l + 1 << "\n";
		else
			cout << '0' << "\n";		
	}  
}
