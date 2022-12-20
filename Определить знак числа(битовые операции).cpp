#include <iostream>
using namespace std;

int getSign(int x) {
	int mask;  
if (x != 0)
		mask = 1;
	else
		mask = 0;    
return mask | (x >> 31);
}

int main()
{
	int x;
	cin >> x;
	cout << getSign(x);
	return 0;
}
