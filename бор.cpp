#include <bits/stdc++.h>

using namespace std;

const int inf = 1e7;

bool answer[inf];

struct vertix
{
	vertix * next[27];
	int cnt;
	int id;
	vertix()
	{
		for (int i = 0; i < 27; i++)
		{
			next[i] = NULL;
		}
		cnt = 0;
	}
};

vertix * root = new vertix();

void add(string &s, int id) {
	vertix * v = root;
	for (int i = 0; i < s.size(); i++) {
		char c = s[i] - 'a';
		if (v -> next[c] == NULL) {
			v -> next[c] = new vertix();
		}
		v = v -> next[c];
	}
	v -> cnt++;
	v -> id = id;
}

bool find(string &s) {
	vertix * v = root;
	for (int i = 0; i < s.size(); i++) {
		char c = s[i] - 'a';
		v = v -> next[c];
		if (v == NULL) {
			return false;
		}
	}
	return true;
}

int main() {
	
	int m;
	string str;
	cin >> str;
	cin >> m;
	for (int i = 1; i <= m; ++i) {
        string word;
        cin >> word;
        add(word, i);
    }
    for (int j = 0; j < str.length(); j++) {
        vertix *y = root;
        for (int i = j; i < str.length(); i++) {
            if (y -> next[str[i] - 'a'] == NULL) {
                break;
			}
            y = y -> next[str[i] - 'a'];
            if (y -> cnt) {
                answer[y -> id] = 1;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        if (!answer[i]) {
            cout << "No" << endl;
        }
        else {
            cout << "Yes" << endl;
        }
    }
	return 0;
}

