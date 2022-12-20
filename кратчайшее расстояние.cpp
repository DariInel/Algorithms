#include <bits/stdc++.h>

using namespace std;

const long long maxi = 1e9;

int n;
typedef pair<int, int> help1;
vector<help1> g[100002];
priority_queue <help1> q;
int dp[100002];
bool used[100002];
pair<int, int> v;

void dijkstra(int top) {
   for(int i = 0; i <= n; i++) {
       dp[i] = maxi;
   }
   dp[top] = 0;
   q.push(make_pair(top, maxi));
   while(!q.empty()) {
       v = q.top();
       q.pop();
       for(int i = 0; i < g[v.first].size(); i++){
           if (dp[g[v.first][i].first] > dp[v.first] + g[v.first][i].second){
               dp[g[v.first][i].first] = dp[v.first] + g[v.first][i].second;
               q.push(make_pair(g[v.first][i].first, dp[g[v.first][i].first]));
           }
       }
   }
}

int main() {
	
	int m;
	cin >> n >> m; 
	int y;
	int x;
	int w;  
    for(int i = 0; i < m; i++) {
        cin >> x >> y >> w;
        g[x].push_back(make_pair(y, w));
        g[y].push_back(make_pair(x, w));
    }
	int start;
	int finish;
    cin >> start >> finish;
    dijkstra(start);
    if (dp[finish] == maxi) {
        cout << -1;
    }
    else
        cout << dp[finish];
}
