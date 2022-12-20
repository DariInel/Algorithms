#include <bits/stdc++.h>

using namespace std;

long long a[1000001];
int n = 0;

void qsort(int l, int r) {
	long long k = a[rand() % (r - l) + l];
    int l1 = l, r1 = r;   
    while (l1 <= r1) {
        while (a[l1] < k)
            l1++;
        while (a[r1] > k)
            r1--;
        if (l1 <= r1) {
            swap(a[l1], a[r1]);
            l1++;
            r1--;
        }
    }
    if (l < r1)
        qsort(l, r1);
    if (l1 < r)
        qsort(l1, r);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    qsort(0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}

