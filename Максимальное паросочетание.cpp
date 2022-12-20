#include <bits/stdc++.h>

using namespace std;

vector<bool>used;
vector<vector<int > > A;
vector<int>ans;
bool kuhn(int v)
{
	if (used[v])
		return false;
	used[v] = true;
	for (int i = 0; i < A[v].size(); i++)
	{
		int to = A[v][i];
		if (ans[to] == -1 || kuhn(ans[to]))
		{
			ans[to] = v;
			return true;
		}
	}
	return false;

}

int main() {
	int n, a, k, b, m;
	cin >> n >> m;
	A.resize(n);
	ans.resize(m, -1);
	used.resize(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a;
			if (a == 1)
			{
				A[i].push_back(j);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		used.assign(n, false);
		kuhn(i);
	}
	for (int i = 0; i < m; i++)
	{
		if (ans[i] != -1)
			cout << ans[i] + 1<< " ";
		else
			cout << 0 << " ";
	}
	return 0;
}
