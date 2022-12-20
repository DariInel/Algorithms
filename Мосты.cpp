#include <bits/stdc++.h>
using namespace std;

vector<bool>used;
vector<int>time_in;
vector<int>fup;
vector<vector<pair<int, int> > > graph;
int t = 0;
vector<int>ans;
void dfs(int v, int predok = -1) {
	used[v] = true;
	time_in[v] = fup[v] = t++;
	for (int i = 0; i < graph[v].size(); i++) {
		int to = graph[v][i].first;
		if (to == predok)
			continue;
		if (used[to])
			fup[v] = min(fup[v], time_in[to]);
		if (!used[to]) {
			dfs(to, v);
			fup[v] = min(fup[v], fup[to]);
			if (fup[to] > time_in[v]) {
				ans.push_back(graph[v][i].second);
			}
		}
	}
}

int main() {
	int n, a, k, b, m;
	cin >> n >> m;
	graph.resize(n);
	used.resize(n);
	time_in.resize(n);
	fup.resize(n);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a - 1].push_back({ b - 1, i});
		graph[b - 1].push_back({ a - 1, i });
	}
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			dfs(i);
		}
	}
	cout << ans.size() << endl;
	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] + 1 << endl;
	}
	
	return 0;
}
