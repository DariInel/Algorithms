#include <bits/stdc++.h>
using namespace std;
int a[1000001];
void sort(int l, int r){
	if (r - l == 1)
		return;
    int m = (l + r)/2;
	sort(l, m);
	sort(m, r);
	vector <int> c;
	int p1 = l, p2 = m;
	while (p1 < m && p2 < r){
 	   if (a[p1] <= a[p2])
 	       c.push_back(a[p1++]);
 	   else{
 	       c.push_back(a[p2++]);
 	   }
	}
	for (int i = p1; i < m; i++)
 	   c.push_back(a[i]);
	for (int i = p2; i < r; i++)
  	  c.push_back(a[i]);
	for (int i = l; i < r; i++)
 	   a[i] = c[i - l];
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(0, n);
    for (int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }
}

