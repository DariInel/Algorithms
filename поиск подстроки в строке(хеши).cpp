#include <bits/stdc++.h>

using namespace std;

const long long md = 1e9 + 7;

long long hash[2000010];
long long step[2000010];
long long hash1[2000010];
long long sum = 0;
long long getrez(int l, int p){
   return ((hash[p] - (hash[l] * step[p - l]) % md + md) % md);
}

int main() {
	
    string string1;
	string string2;
    cin >> string1;
    cin >> string2;
    long long x = 28;
    step[0] = 1;
    hash[0] = 0;
    int k = 0;
    for (int i = 1; i <= string1.size(); i++){
        hash[i] = (hash[i - 1] * x + string1[i - 1]) % md;
        step[i] = (step[i - 1] * x) % md;
    }
    for (int i = 1; i <= string2.size() + 1; i++){
        hash1[i] = (hash1[i - 1] * x + string2[i - 1]) % md;
    }
    for (int i = 0; i < string1.size() - string2.size() + 1; i++){
        if (hash1[string2.size()] == getrez(i, i + string2.size())){
            sum++;
            k = 1;
        }
    }
    if(sum == 0)
    cout << "-1";
	else {	
	    for (int i = 0; i < string1.size() - string2.size() + 1; i++){
	        if (hash1[string2.size()] == getrez(i, i + string2.size())){
	            cout << i + 1 << ' ';
	            k = 1;
	        }
	    }
	}
}
