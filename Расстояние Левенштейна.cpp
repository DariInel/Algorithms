#include <bits/stdc++.h>

using namespace std;

int main() {
    string str1;
    string str2;
    cin >> str1 >> str2;
    int edit[str1.size()][str2.size()];
    for(int i = 0; i < str1.size(); i ++) {
    	edit[i][0] = i + 1;
	}
	for(int j = 0; j < str2.size(); j ++) {
    	edit[0][j] = j + 1;
	}
	for(int i = 1; i < str1.size(); i ++) {
		for(int j = 1; j < str2.size(); j++) {
			int cost = 0;
			if(str1[i] != str2[j]) {
				cost = 1;
			}
			edit[i][j] = min(edit[i][j - 1] + 1, edit[i-1][j] + 1, edit[i-1][j-1] +cost);
		}	
	}
	cout << edit[str1.size() - 1][str2.size() - 1];
    return 0; 
}
