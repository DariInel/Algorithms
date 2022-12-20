#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n;
	int colors;
	cin >> n >> colors;
	int kyb[n];
	for(int i = 0; i < n; i ++) {
		cin >> kyb[i];
	}
	vector<int> d2 (n);
	int l=0;
	int r=-1;
	for (int i=0; i<n/2; ++i) {
 		int k = (i>r ? 0 : min (d2[l+r-i+1], r-i+1)) + 1;
 		while (i+k-1 < n && i-k >= 0 && kyb[i+k-1] == kyb[i-k]) {
		k++;
		}
 		d2[i] = k--;
		 if (i+k-1 > r) {
			l = i-k, r = i+k-1;
		}
	}
	for(int i = 0; i < n; i ++) {
		cout << d2[i] << " ";
	}
	
	return 0;
}
