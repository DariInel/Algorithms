#include <bits/stdc++.h>
using namespace std;
vector<int> x; bool Flag;
void Next(int N, int M)
{
	int i = N-1;
	while(i>=0 && x[i] !=M)
	{
		if(x[i] == 0)
		x[i] = 1;
		else
		x[i] = 0;
		i --;
	}
	if(i >= 0)
	{
		x[i] --;
		Flag = true;
	}
	else Flag=false;
}
int main()
{
int N, M;
cin >> N;
x.resize(N, 1);
do
{
	for(int i = 0; i < N; i++)
	cout << x[i];
	cout << endl;
	Next(N, 1);
	}	
	while(Flag);
  return 0;
}
