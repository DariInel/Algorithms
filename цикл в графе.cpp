#include <bits/stdc++.h>

using namespace std;

int n, m, x, y, cnt = 0;
vector <int> a[1001];
int b[1001], used[1001];
void rr(int v) {
    used[v] = 1;
    for (int i = 0; i < a[v].size(); i++) {
        if (cnt == 1)
            return;
        if (used[a[v][i]] == 0)
            rr(a[v][i]);
        if (used[a[v][i]] == 1) { 
            cnt = 1;
            return;
        }
    }
    used[v] = 2;
}

int main() {
    cin >> n ;
    for (int i = 0; i < n; i++) {
    	for(int j = 0; j < n; j++){
        cin >> x ;
        if(x == 1)
        a[i].push_back(j);
    }
    }
    rr(0);
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            rr(i);
        }
    }
    if (cnt == 1)
        cout << "1";
    else
        cout << "0";
    return 0;
}
