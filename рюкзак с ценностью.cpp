#include <bits/stdc++.h>

using namespace std;

const long long arrsize = 2000001;

int parameters[500][2];
int backpack[arrsize];
int c[arrsize];

int main() {
    int maxW;
	int n;
    cin >> n;
    cin >> maxW;

    for (int i = 0; i < n; i++) {
        cin >> parameters[i][0] >> parameters[i][1];
    }
    for (int i = 0; i < maxW; i++) {
        backpack[i] = -1;
    }
    backpack[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = maxW; j >= 0; j--) {
            if (backpack[j] >= 0 && backpack[j + parameters[i][1]] < backpack[j] + parameters[i][0])
                backpack[j + parameters[i][1]] = backpack[j] + parameters[i][0];
        }
    }
    int max = 0;
    for (int i = maxW; i >= 0; i--){
        if (max < backpack[i]){
            max = backpack[i];
        }
    }
    cout << max;
    return 0; 
}
