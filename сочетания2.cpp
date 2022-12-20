#include <bits/stdc++.h>

using namespace std;

int  a, n, k;
int b[1002], c[1002];

void rec(int a) {
    if (a == n) {
        for (int i = 0; i < n; i++) {
            cout << b[i] + 1 << " ";
        }
        cout << endl;
        return;

    }
    if (a == 0) {
        for (int i = 0; i < k - n + 1; i++) {
            b[0] = i;
            c[i] = 1;
            rec(1);
            c[i] = 0;
        }
    }
    else {
        for (int i = b[a - 1] + 1; i < k - n + a + 1; i++) {
            if (c[i])
                continue;
            b[a] = i;
            c[i] = 1;
            rec(a + 1);
            c[i] = 0;

        }
    }
}

int main() {
    cin >> n >> k;
    rec(0);
    return 0;
}
