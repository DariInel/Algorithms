#include <bits/stdc++.h>
using namespace std;

const long long inf = 1e8;
const int arr_size = 20;

int main() {

	int n;
	cin >> n;
	int dist[arr_size][arr_size];
	int parent[inf][arr_size];
	int dp[inf][arr_size];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> dist[i][j];
		}
	}
	for (int mask = 1; mask < (1 << n); mask++){
        for (int j = 0; j < n; j++) {
            dp[mask][j] = inf;
        }
	}
	for (int i = 0; i < n; i++) {
        dp[(1 << i)][i] = 0;
	}
	for (int mask = 1; mask < (1 << n); mask++){
        for (int j = 0; j < n; j++) {
            parent[mask][j] = -1;
        }
	}
	for (int mask = 1; mask < (1 << n); mask++) {
		for (int from = 0; from < n; from++) {
			for (int to = 0; to < n; to++) {
				if (!(mask & (1 << to)) && (mask & (1 << from))) {
					if(dp[mask | (1 << to)][to] > dp[mask][from] + dist[from][to]) {
						dp[mask | (1 << to)][to] = dp[mask][from] + dist[from][to];
						parent[mask | (1 << to)][to] = from;
					}
				}
			}
		}
	}
	int mini = inf;
	for(int i = 0; i < n; i ++) {
		mini = min(dp[(1 << n) -1][i], mini);
	}
	cout << mini << endl;
	long long answer = 0;
	for(long long i = 0; i < n; i ++) {
        if(dp[(1 << n) - 1][i] < dp[(1 << n) - 1][answer]) {
            answer = i;
        }
	}
	vector <long long> recover;
	long long mask = (1 << n) - 1;
	while (parent[mask][answer] != -1) {
        recover.push_back(answer + 1);
        long long tempa = parent[mask][answer];
        mask -= 1 << answer;
        answer = tempa;
	}
	recover.push_back(answer + 1);
	reverse(recover.begin(), recover.end());
	for(long long i = 0; i < recover.size(); i ++) {
        cout << recover[i] << " ";
	}
	return 0;
}

