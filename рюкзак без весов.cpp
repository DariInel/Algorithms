#include <bits/stdc++.h>

using namespace std;

const long long arrsize = 2000001;

int parameters[301];
int backpack[arrsize];
int c[arrsize];

int main() {
	
	vector<int> parameters;
	vector<int> backpack;
	vector<int> c;
    int maxW;
	int n;
	int help1;   
    cin >> maxW;
	cin >> n;

    for (int i = 0; i < n; i++) {
    	cin >> help1;
    	parameters.push_back(help1);
        cin >> parameters[i];
    }
    for (int i = 0; i < maxW; i++) {
        backpack[i] = 0;
    }
    backpack[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = maxW; j >= 0; j--) {
            if (backpack[j] == 1 && backpack[j + parameters[i]] <= maxW) {
                backpack[j + parameters[i]] = 1;
            }
        }
    }
    int max = 0;
    for (int i = maxW; i >= 0; i--) {
        if (backpack[i] == 1) { 
            max = i;
            break;
        }
    }
    cout << max;
    return 0; 
}
