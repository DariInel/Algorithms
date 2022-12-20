#include <bits/stdc++.h>
using namespace std;

int main() {
	
	string s;
	long long answer = 0;
	getline(cin, s);
	int n = s.size();
	vector<int>prefix(n);
	for (int i = 1; i < n; i++) {
		int j = prefix[i - 1];
		while (j > 0 && s[j] != s[i]) {
			j = prefix[j - 1];
		}
		if (s[i] == s[j]) {
			j++;
		}
		prefix[i] = j;
	}
	for (int i = 0; i < n; i++) {
		answer = answer +  prefix[i];
	}
	cout << answer;
	return 0;
}
