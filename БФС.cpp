#include <bits/stdc++.h>

using namespace std;

vector <int> a[1000001];
int s[10001];
bool used[10001];
queue <int> q;
int x, m, y, sta, en;

void bfs(int v) {
    q.push(v);
    used[v] = 1;
    s[v] = 0;
    while(!q.empty()) {
        int ps = q.front();
        q.pop();
        for(int i = 0; i < a[ps].size(); i++) {
            int test = a[ps][i];
            if(!used[test]) {
                used[test] = 1;
                q.push(test);
                s[test] = s[ps] + 1;
            }
        }
    }
}

int main() {
	int n;
    cin >> n;
	cin >> m >> sta >> en;
    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        x --;
        y --;
        a[y].push_back(x);
        a[x].push_back(y);
    }
    if(sta == en) {
    	cout << 0;
    }
    else {
        bfs(sta - 1);
        if (s[en - 1] == 0)
            cout << -1;
        else
            cout << s[en - 1];
    }
}
