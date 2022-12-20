#include<iostream>

using namespace std;

int main() {
	
	int n; 
    cin >> n;
	int a[1000];
	int dp[1000];

    for(int i = 0; i < n; i++) {
    	cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		dp[i] = 1;
	}
	for(int i = 0; i < n; i++) {
		for(int j = i - 1; j >= 0; j--) {
			if(a[j] < a[i]) {
				if(dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
				}
			}
		}
	}
	int max = dp[0];
	for(int i = 1; i < n; i++)	{
		if(max < dp[i]) {
			max = dp[i];
		}
	}
	cout << max;
}
