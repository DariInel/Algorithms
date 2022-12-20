#include <bits/stdc++.h>

using namespace std;

int n;
int dist[101];
int a[101][101];
int strt, fnish;
int used[101];
int main()
{
    cin >> n >> strt >> fnish;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        dist[i] = 2000000000;
        used[i] = 0;
    }
    dist[strt - 1] = 0;
    int k = 0;
    while (k < n){
        int sit = 2000000000;
        int index = 0;
        for (int i = 0; i < n; i++){
            if (dist[i] < sit && used[i] == 0){
                index = i;
                sit = dist[i];
            }
        }
        for (int i = 0; i < n; i++){
            if (a[index][i] >= 0 && used[i] == 0)
                dist[i] = min(dist[i], dist[index] + a[index][i]);
        }
        k++;
        used[index] = 1;
    }
    if (dist[fnish - 1] == 2000000000)
        cout << -1;
    else
        cout << dist[fnish -1];
}

