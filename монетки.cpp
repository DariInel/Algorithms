#include<iostream>
using namespace std;
long long n, m;
int a[1010][1010], b[1010][1010];
long long sum = 0;
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    	for(int j = 0; j < n; j++)
    		b[i][j] = 1000;
    for(int i = 0; i < n; i++)
    	for(int j = 0; j < m; j++)
    		cin >> a[i][j];
    		b[0][0] = a[0][0];
    for (int i = 1; i < n; i++)
   		b[i][0] = a[i][0] + b[i - 1][0];
   	for (int i = 1; i < m; i++)
    	b[0][i] = a[0][i] + b[0][i - 1];
	for (int i = 1; i <= n; i++){
   		for (int j = 1; j <= m; j++){
       		b[i][j] = a[i][j] + min(b[i - 1][j], b[i][j - 1]);
   		}
	}
	cout << b[n - 1][m - 1];
}

