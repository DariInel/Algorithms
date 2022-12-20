#include<iostream>

using namespace std;

int main() {
	int i, j, c, mi, n, m;
	int f[1000];
	cin >> n;
	for (i = 0; i < n; i++){
		cin >> f[i];
	}
	for (i = 0; i < n; i++){
		m = f[i];
		mi = i;
		for (j = i; j < n; j ++){
			if (f[j]  m){
				m = f[j];
				mi = j;
			}
		}
		swap(f[mi], f[i]);	
	}
	for (j = 0; j < n; j ++){
		cout << f[j] << " ";
	}
}


