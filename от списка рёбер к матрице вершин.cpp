#include <bits/stdc++.h>

using namespace std;

int a[501][501];
int used[101];
int n, x, y, cnt = 0;

int main() {
    cin >> n ;
    for (int i = 0; i < n; i ++){	    
	    cin >> x;
		for (int j = n- 1; j > -1; j--) {
			y = x%10;
			x /= 10;
			a[i][j] = y;
			if(y) cnt ++;
	    }
	}
	cout << cnt/2 << endl;
    for (int i = 0; i < n ; i++) {
        for(int j = n - (n - i); j < n; j ++){
        	if(a[i][j]){
        		cout << i + 1 << " " << j + 1 << endl;
			}
		}
    }
}
