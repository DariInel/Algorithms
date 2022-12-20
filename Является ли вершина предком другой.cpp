#include <bits/stdc++.h>

using namespace std;

const long long arr_size= 100001;

vector<int> arr[arr_size];
int n, m, b;
int timet = 0;
int used[arr_size];
int in[arr_size], out[arr_size];
int start;

void dfs(int v) {
    used[v] = 1;
    in[v] = timet;
    timet++;
    for(int i = 0; i < arr[v].size(); i++) {
        if (used[arr[v][i]] == 0)
            dfs(arr[v][i]);

    }
    out[v] = timet;
    timet++;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
    	int b;
        cin >> b;
        if (b == 0) {
            start = i;
        }
        else { 
        	b--;
            arr[b].push_back(i);
            arr[i].push_back(b);
        }
    }
    dfs(start);
    cin >> m;
    for(int i = 0; i < m; i++) {
    	int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        if (in[vertex2 - 1] > in [vertex1 - 1] && out[vertex1 - 1] > out[vertex2 - 1]) {
            cout << 1 << "\n";
        }
        else {
            cout << 0 << "\n";
        }
    }
}

