#include<iostream>
using namespace std;

int abs1(int x) {
	int mask;   
mask = x >> 31;
return (x + mask) ^ mask;

}
int main()
{
	int x;
	cin >> x;
	cout << abs1(x);
	return 0;

}   
