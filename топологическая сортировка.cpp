#include <bits/stdc++.h>

using namespace std;

vector <int> a[100001], ans;
int n, m, i, x, y, used[100001];
bool cnt = false;

void dfs(int v) {
    used[v] = 1;
    for (int i = 0; i < a[v].size(); i++) {
        if (cnt)
            return;
        if (used[a[v][i]] == 0)
            dfs(a[v][i]);
        if (used[a[v][i]] == 1) {
            cnt = true;
            return;
        }
    }
    used[v] = 2;
    ans.push_back(v);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--;
        y--;
        a[x].push_back(y);
    }
    for (int i = 0; i < n ; i++) {
        if (used[i] == 0)
            dfs(i);
    }
    if (cnt)
        cout << -1;
    else{
        for (int i = n - 1; i >= 0; i--) {
            cout << ans[i] + 1 << ' ';
        }
    }
}
