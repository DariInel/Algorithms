#include <bits/stdc++.h>
using namespace std;

int main() {
	
	string text;
	string str;
	cin >> text;
	cin >> str;
	string finish_str = str + "#" + text;
	int n = finish_str.size();
	vector<int>prefix(n);
	for (int i = 1; i < n; i++) {
		int j = prefix[i - 1];
		while (j > 0 && finish_str[j] != finish_str[i]) {
			j = prefix[j - 1];
		}
		if (finish_str[i] == finish_str[j]) {
			j++;
		}
		prefix[i] = j;
	}
	bool flag = 0;
	for (int i = str.size() + 1; i < n; i++) {
		if(prefix[i] == str.size()) {
			cout << (i - 2 * str.size()) + 1 << " ";
			flag = 1;
		}
	}
	if(flag == 0) {
		cout << "-1";
	}
	return 0;
}
