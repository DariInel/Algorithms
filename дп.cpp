#include<iostream>
using namespace std;
int n, k, i, j;
int a[100];
int main()
{
    cin >> n >> k;
    a[0] = 1;
    for(i = 0; i <= n; i++)
    {
    		if ( a[i] > 0)
    		{
    			for(int j = 1; j <= k ; j++)
    			{
    				a[i + j] = a[i] + a[i + j];
				}
			}
	}
	cout << a[n-1];
}
