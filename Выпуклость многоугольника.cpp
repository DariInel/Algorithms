#include<bits/stdc++.h>

using namespace std;
typedef pair <int,int> point;
vector <point> a;

int sq (int x1, int y1, int x2, int y2, int x3, int y3) {
	return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}
int main(){
	int MX = 0;
	int n, x0, y0;
	cin >> n >> x0 >> y0;
	int x, y;
	for(int i = 0; i < n; i ++) {
		cin >> x >> y;
		MX = max(MX, x);
		a.push_back({x, y});
	}
	a.push_back({a[0].first, a[0].second});
	MX += 1;
	for(int i = 0; i < n; i ++) {
		if((a[i].second < y0 && a[i + 1].second > y0)
	}
	if(result)
    cout << "YES";
    else
	cout << "NO";
  return 0;
}
