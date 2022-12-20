#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, count;
    cin >> n;
    for (int i = 0; i < n; i++) {
        count = 0;
        for (int j = 0; j < n; j++) {
        	int a;
            cin >> a;
            if (a == 1)
                count++;
        }
        cout << count << "\n";
    }
}
