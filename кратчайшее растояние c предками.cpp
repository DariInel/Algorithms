#include <bits/stdc++.h>

using namespace std;
int pr[10001];
vector <int> a[1000001];
vector <int> ans;
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
                pr[test] = ps;
            }
        }
    }
}

int main() {
	int n;
    cin >> n;
	for(int i = 0; i < n; i ++)
    for(int j = 0; j < n; j++) {
        cin >> x;
        if(x){
        a[i].push_back(j);
        a[j].push_back(i);
    }
    }	
	cin >> sta >> en;
    if(sta == en) {
    	cout << 0 << endl;
    	cout << sta;
    }
    else {
        bfs(sta - 1);
        if (s[en - 1] == 0)
            cout << -1;
        else {
            cout << s[en - 1] << endl;
            int x = pr[en - 1];
            ans.push_back(en - 1);
            while(x != (sta - 1)){
            	ans.push_back(x);
            	x = pr[x];
			};
			ans.push_back(sta - 1);
			for(int i = ans.size() - 1; i >= 0; i --)
			cout << ans[i] + 1 << " ";
		}
    }
}
