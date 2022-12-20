#include <bits/stdc++.h>

using namespace std;

int a[101][101];

int main() {
    int n, count;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        count = 0;
	if (a[i][i] == 1) {
            cout << "NO";
            return 0;
        }
        for (int j = 0; j < n; j++) {
            if (a[i][j] == a[j][i] && i != j)
                count = count + 1;
        }       
        if (count < n - 1) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
