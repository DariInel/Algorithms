#include <bits/stdc++.h>
using namespace std;
long long ct(int n){
	vector<long long> a(n + 1, 0);
	a[0] = 1;
	for(int i = 1; i <= n; i ++){
		for(int j = 0; j < i; j++){
			a[i] += a[j]*a[i - 1 - j];
		}
	}
	return a[n];
}
int main()
{
	int n;
	cin >> n;
	cout << ct(n);
}
