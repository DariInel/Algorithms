#include <bits/stdc++.h>

using namespace std;

vector<bool>used;
vector<int>time_in;
vector<int>fup;
vector<vector<int > > A;
int t = 0;
set<int>ans;
void dfs(int v, int p = -1) {
	used[v] = true;
	time_in[v] = fup[v] = t++;
	int k = 0;
	for (int i = 0; i < A[v].size(); i++) {
		int to = A[v][i];
		if (to == p)
			continue;
		if (used[to])
			fup[v] = min(fup[v], time_in[to]);
		if (!used[to])
		{
			dfs(to, v);
			fup[v] = min(fup[v], fup[to]);
			if (fup[to] >= time_in[v] && p != -1)
			{
				ans.insert(v + 1);
			}
			k++;
		}
	}
	if(p == -1 && k > 1)
		ans.insert(v + 1);

}

int main()
{ 
	int n, a, k, b, m;
	cin >> n >> m;
	A.resize(n);
	used.resize(n);
	time_in.resize(n);
	fup.resize(n);
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		A[a - 1].push_back(b - 1);
		A[b - 1].push_back(a - 1);
	}
	dfs(0);
	cout << ans.size() << endl;
	set<int>::iterator it = ans.begin();
	for (it; it != ans.end(); it++) {
		cout << *it << " " << endl;
	}
	
	return 0;
}
