#include <bits/stdc++.h>

using namespace std;

int a[101][101], b[101];

int main()
{
    int n, count, co = -1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int j = 0; j < n; j++) {
        count = 0;
        for (int i = 0; i < n; i++) {
            if (a[i][j] == 0) {
                count++;
            }
        }
        if (count == n) {
            co++;
            b[co] = j + 1;
        }
    }
    co++;
    cout << co << " ";
    for (int i = 0; i < co; i++) {
        cout << b[i] << ' ';
    }
    cout << "\n";
    co = -1;
    for (int i = 0; i < n; i++) {
        count = 0;
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 0)
                count++;
        }
        if (count == n) {
            co++;
            b[co] = i + 1;
        }
    }
    co++;
    cout << co << " ";
    for (int i = 0; i < co; i++) {
        cout << b[i] << " ";
    }
}
