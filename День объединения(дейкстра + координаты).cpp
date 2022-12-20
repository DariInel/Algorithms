#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

struct point {
	int x;
	int y;
	point() {
	}
	void read() {
		cin >> x >> y;
	}
};

double lenght(point &a, point &b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
	
	int n;
	cin >> n;
	vector<point>Points(n);

	for (int i = 0; i < n; i++)
	{
		Points[i].read();
	}
	vector<double>dist(n, inf);
	vector<bool>used(n, 0);
	vector<int>p(n, -1);
	dist[0] = 0;
	double answer = 0;
	for (int i = 0; i < n; i++) {
		int v = -1;
		for (int j = 0; j < n; j++) {
			if ((v == -1 || dist[j] < dist[v]) && !used[j]) {
				v = j;
			}
		}		
		used[v] = 1;
		answer += dist[v];
		for (int to = 0; to < n; to++) {
			if (v != to) {
				double s = lenght(Points[v], Points[to]);
				if (s < dist[to]) {
					dist[to] = s;
					p[to] = v;
				}
			}
		}
	}	
	cout << fixed << setprecision(6)<< answer << endl;
	return 0;
}
