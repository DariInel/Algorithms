#include <bits/stdc++.h>
using namespace std;
void co(int n, int m) {
	int a[m];
	int i = m - 1;
	while(n > 0){
		if(n % 2 == 1)
		a[i] = 0;
		else
		a[i] = 1;
		n /= 2;
		i --;
	}
	for(int j = 0; j <= i; j ++)
	a[j] = 1;
	for(int j = 0; j < m; j ++)
	cout << a[j];
}
int main()
{
	int n;
	cin >> n;
	int m = (1 << n) - 1;
//	for(int m = 0; m < (1 << n); ++ m){
		for(int s = m; s; s = (s - 1)&m){
			co(s, n);
			cout << endl;
	}
	for(int i = 1; i <= n; i++)
	cout << 1;
//	}
}
