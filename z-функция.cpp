#include <bits/stdc++.h>
using namespace std;

int main() {
	
	string s;
	getline(cin, s);	
	int str_size = s.size();
	int z[str_size];
	for(int i = 0; i < str_size; i ++) {
		z[i] = 0;
	}
	int left = 0;
	int right = 0;
	for (int i = 1; i < str_size; i++) {
		z[i] = max(min(right - i + 1, z[i - left]), 0);
		while (i + z[i] < str_size && s[z[i]] == s[z[i] + i]) {
			z[i]++;
		}
		if (i + z[i] - 1 > right) {
			left = i;
			right = i + z[i] - 1;
		}
	}
	for (int i = 0; i < str_size; i++) {
		cout << z[i] << " ";
	}
	return 0;
}
