#include <bits/stdc++.h>
using namespace std;
int x_sum[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int y_sum[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dist[21][21];
queue <pair<int, int> > q;
int n, x1, x2, yi, y2, x3, y3, x4, y4;
void bfs() {
    q.push(make_pair(x1,yi));
	dist[x1][yi] = 0;
    while(!q.empty()) {
    	x3 = q.front().first;
		y3 = q.front().second;
		q.pop();
		for(int i = 0;i < 8; i ++){
			if((x3 + x_sum[i]) >= 0 && (x3 + x_sum[i]) < n && (y3 + y_sum[i]) >= 0 && (y3 + y_sum[i]) < n){			
				x4 = x3 + x_sum[i];
				y4 = y3 + y_sum[i];
				if(dist[x4][y4] > dist[x3][y3] + 1) {
					dist[x4][y4] = dist[x3][y3] + 1;
					q.push(make_pair(x4, y4));
				}
			}	
		}
    }
}
int main() {
cin >> n >> x1 >> yi >> x2 >> y2;
x1 --;
yi --;
x2 --;
y2 --;
for(int i = 0; i < n; i ++) {
	for(int j = 0; j < n; j ++){
		dist[i][j] = 1000000;
	}
}
bfs();
cout << dist[x2][y2];
return 0;
}
