#include<iostream>
using namespace std;
int n, k;
int a[10000];
int main()
{
    cin >> n >> k;   
	int l, r;
    int sum = 0;
	for(int j = 0; j < n; j ++)
   	{
   		float s;
   		cin >> s;
   		a[j] = s * 100;
 	}
    if (k == 1)
    {
    	int max = a[0];
      	for(int j = 1; j < n; j ++)
   		{
   			if(max < a[j])
			   max = a[j];		
	    }	
	    l = max;
	}
	else
	{
   		

   		l = 0;
   		r = 10000001;
   		while(r - l > 1)
   		{
   		 	sum = 0;
    		int m = (l + r) / 2;
    		for(int i = 0; i < n; i++)
    		{
    		  	sum = sum + a[i]/m;	
			}
   			if ( sum < k )
   				r=m;
   			else
   				l = m;
		}
	
  	}	
	double q = l * 0.01;
	printf("%.2f", q);
}
