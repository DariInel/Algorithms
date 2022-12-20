#include <bits/stdc++.h>

using namespace std;

const int N = 11;
int leng, n, m;
int a[N];

void rec (int leng) {
    if (leng == n) {
        for (int i = 0; i < n; i++) {
   	    cout << a[i] << ' ';
  	}
    	cout << '\n';
   	return;
    }
    for (int i = 0; i < m; i++) {
        a[leng] = i;
   	rec (leng + 1);
    }
}

int main() {
    cin >> n >> m;
    rec (0);
}
