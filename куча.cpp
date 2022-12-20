#include <bits/stdc++.h>

using namespace std;

int n, a[100001], ind = 1, id = 0, x, y;

void Ext() {
    int max_1;
    max_1 = a[1];
    a[1] = a[ind - 1];
    a[ind - 1] = 0;
    ind--;
    id = 1;
    while (a[id] < max (a[2 * id], a[2 * id + 1])) { 
        if (a[2 * id] > a[2 * id + 1]) {
            swap(a[2 * id], a[id]);
            id  = 2 * id;
        }
        else{
            swap(a[2 * id + 1], a[id]);
            id = id * 2 + 1;
        }
    }
    cout << max_1 << endl;
    return;
}

void Ins(int x) {
	int pr = 0;
    a[ind] = x;
    ind++;
    pr = (ind - 1) / 2;
    id = ind - 1;
    while (a[pr] < x) {
        swap(a[pr], a[id]);
        id  = pr;
        pr = pr / 2;
    }
    return;
}

int main() {
    cin >> n;
    a[0] = 2000000000;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 1)
            Ext();
        else{
            cin >> y;
            Ins(y);
        }
    }
}

