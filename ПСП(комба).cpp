#include <bits/stdc++.h>

using namespace std;

int cnt = 0, leng, n, sum = 0;
char a[23];

void rec(int leng) {
    if (leng /2 == n) {
        if (cnt != sum)
   	    return;
  	for (int i = 0; i < leng; i++) {
     	    cout << a[i];
   	}
    	cout << '\n';
    	return;
    }
    a[leng] = '(';
    cnt++;
    rec(leng + 1);
    cnt--;
    if (cnt > sum) {
        a[leng] = ')';
        cnt--;
        rec(leng + 1);
        cnt++;
    }
}

int main() {
    cin >> n;
    rec(sum);
    return 0;
}

