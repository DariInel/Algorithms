#include <bits/stdc++.h>

using namespace std;

const int N = 970;
long long mas[N][N];

int main() {	
    int n, m;
    cin >> m >> n;
    for (int i = 0; i <= n; i++) {
        mas[i][0] = 1;
    }
    for (int i = 1; i <= m; i++) {
        mas[0][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            mas[i][j] = mas[i - 1][j - 1] + mas[i - 1][j];
        }
    }
    cout << mas[n][m];
}
