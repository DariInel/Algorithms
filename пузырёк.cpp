#include<iostream>
using namespace std;
int main(){
	int i, j, c, a=0, n;
	int f[1000];
	cin >> n;
	for (i = 0; i < n; i++){
		cin >> f[i];	
	}
	for (i = 0; i < n; i++){
		for (j = 0; j < n - i - 1; j ++){
			if (f[j] > f[j + 1]){
				swap(f[j], f[j + 1]);
				a++;
			}
		}
	}
	cout << a;
}

