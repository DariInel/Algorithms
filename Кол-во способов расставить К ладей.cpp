#include <bits/stdc++.h>
using namespace std;
int main() {	
    int n, m;
    cin >> n >> m;
    if(n < m){
    	cout << 0;
    	return 0;
	}
	if(n == m){
		int sum = 1;
		for(int i = 2; i <= m; i++)
		sum *= i;
		cout << sum;
		return 0;
	}
	int sum = 1;
	for(int i = 0; i < m; i++)
	sum *= (n - i)*(n - i);
	int k = 1;
	for(int i = 2; i <= m; i++)
	k *= i;
	cout << sum/k;
}
