#include<iostream>
using namespace std;
int n, m;
int a[1001];
int b[1001];
int dp[1001][1001];
int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
    	cin >> a[i];
	}
	cin >> m;
	for(int i = 0; i < m; i ++)
    {
    	cin >> b[i];
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			dp[i][j] = 0;
		}
	}
	for(int i = 0; i< n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if (a[i] != b[j])
			{
				dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);	
       		}
       		else
       		{
       			dp[i+1][j+1] = dp[i][j] + 1;
			}
	    }
	}
	int max_1 = -10000 ;
	for(int j = 0; j <= m; j ++)
	{
		if(max_1 < dp[n][j])
		{
			max_1 = dp[n][j];
		}
	}
	cout << max_1;
}
