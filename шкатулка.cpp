#include <bits/stdc++.h>

using namespace std;

queue <int> q;
int n, k, l, m;
int s[2001], used[2001];

int main() {
    cin >> n >> k >> l >> m;
    used[0] = 1;
    q.push(0);
    s[0] = 0;
    while(!q.empty()) {
    	int a;
        a = q.front();
        q.pop();
	if (!used[a - l] && a - l >= 0) {
            used[a - l] = 1;
            q.push(a - l);
            s[a - l] = s[a] + 1;
        }
        if (!used[a + k] && a + k <= n) {
            used[a + k] = 1;
            q.push(a + k);
            s[a + k] = s[a] + 1;
        }    
    }
    if (used[m] == 1)
        cout << s[m];
    else
        cout << "No solution";
}
