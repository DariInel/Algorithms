#include <bits/stdc++.h>

using namespace std;

int a[101][101];

int main()
{   
    int n, x, m, y; 
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j ++) {
	    a[i][j] = 0;
	}
    }
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        a[x - 1][y - 1] = 1;
        a[y - 1][x - 1] = 1;
    }
    bool f = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(a[i][j] == 0 && i != j)  
                f = false;
        }
    }
    if(f) {
        cout << "YES";
    }
    else {
	cout << "NO";
    }
}

