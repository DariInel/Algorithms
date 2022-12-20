#include <bits/stdc++.h>

using namespace std;

int n, max_1;
int dp[101][101];
int a[101][101];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == -1)
                dp[i][j] = 1000000000;
            else
                dp[i][j] = a[i][j];
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][k] != 1000000000 && dp[k][j] != 1000000000)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    max_1 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && dp[i][j] > max_1 && dp[i][j] != 1000000000)
                max_1 = dp[i][j];
        }
    }
    cout << max_1;
}
