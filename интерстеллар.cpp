#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+1;
long long n, m, s;
long long a[N];
long long v1, v2;
long long b[N];
vector <int> c;

int main()
{
    cin >> v2;
    for(int i = 1; i <= v2; i++) {
    	a[i] = N;
    	b[i] = N;
	}
	a[1] = 1;
	b[1] = 0;
	for(int i = 1; i <= v2; i++) {
		if((i + 1) <= v2 && a[i + 1] > a[i] + 1) {
			a[i + 1] =  a[i] + 1;
			b[i + 1] = i;
		}
		if((i * 2) <= v2 && a[i * 2] > a[i] + 1) {
			a[i * 2] = a[i] + 1;
			b[i * 2] = i;
		}
		if((i * 3) <= v2 && a[i * 3] > a[i] + 1) {
			a[i * 3] = a[i] + 1;
			b[i * 3] = i;
		}
	}
	cout << a[v2] - 1 << '\n';
	s = v2;
    while (s != 0) {
        c.push_back(s);
        s = b[s];
	}
	for (int i = c.size()-1; i >= 0; i--) {
        cout << c[i] << ' ' ;
	}
}
