#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

long long hash[2000005];
long long ste[2000005];

int main()  {
	
	string str;
	int n;
	int m;
	int left;
	int right;
	int lenght;
	long long num = 30;	
	ste[0] = 1;
    hash[0] = 0;
    int count = 0;
    cin >> n >> m;
    cin >> str;
    for (int i = 1; i <= n; i++) {
        hash[i] = (hash[i - 1] * num + str[i - 1]) % mod;
        ste[i] = (ste[i - 1] * num) % mod;
    }
    for (int i = 0; i < m; i++) {
        cin >> left >> right >> lenght;
        if(left > right)
            swap(left, right);
        long long hash1, hash2;

        hash1 = (hash[left + lenght - 1] - hash[left - 1] * ste[lenght] % mod + mod) % mod;
        hash2 = (hash[right + lenght - 1] - hash[right - 1] * ste[lenght] % mod + mod) % mod;

            if (hash1 == hash2) {
                count++;
            }
    }
    cout << count;
}

