#include <bits/stdc++.h>

using namespace std;

pair <int, int> dl[100002];
pair <int, int> ans[100002];
int n, x, y;

int main() {
	int cnt_otr = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        dl[2 * i].first = x;
        dl[2 * i].second = 0;
        dl[2 * i + 1].first = y;
        dl[2 * i + 1].second = 1;
    }
    sort(dl, dl + 2 * n);
    int now_;
    now_ = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (dl[i].second == 0) {
            if (now_ == 0) {
                cnt_otr++;
                ans[cnt_otr].first = dl[i].first;
            }
            now_++;
        }
        else {
            now_--;
            if (now_ == 0){
                ans[cnt_otr].second = dl[i].first;
            }
        }
    }
    cout << cnt_otr << endl;
    
    for (int i = 1; i <= cnt_otr; i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}

