#include <iostream>
using namespace std;
int b[1001];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
    	int a;
        cin >> a;
        b[a]++;
    }
    for (int i = 0; i < 1001; i++){
        for (int j = 0; j < b[i]; j++){
            cout << i << "\n";
        }
    }
}
