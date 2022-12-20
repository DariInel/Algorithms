#include <bits/stdc++.h>

using namespace std;

vector <int> a[10001];
int used[101];
int n, m, x, y;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i ++){	    
	        cin >> x >> y;
	        	a[x - 1].push_back(y - 1);
	        	a[y - 1].push_back(x - 1);
	}
    for (int i = 0; i < n ; i++) {
    	cout << a[i].size() << " ";
    	sort(a[i].begin(), a[i].end());
        for(int j = 0; j < a[i].size(); j ++){
        	cout << a[i][j] + 1 << " ";
		}
		cout << endl;
    }
}
