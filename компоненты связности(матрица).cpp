#include <bits/stdc++.h>

using namespace std;

int n, cnt = 0;
int a[101][101];
int used[101];

void dfs(int v) {
    used[v] = 1;
    for (int i = 0; i < n; i++) {
        if ( used[i] == 0 && a[v][i] == 1)
            dfs(i);
    }
}

int main() { 
    cin >> n;
	for(int i = 0; i < n; i ++) {
		used[i] = 0;
	}
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    dfs(0);
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt + 1;
    return 0;
}
