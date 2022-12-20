#include<iostream>
using namespace std;
double eps = 1e-6;
double a, b, c, d;
double f(double g){
return a * g * g * g + b * g * g + c * g + d;	
}
int main()
{
	double r, l, m;
    cin >> a >> b >> c >> d ;
    r = 1;
    while (f(r) * f(-r) >= 0)
    	 r =r * 2;
    l = r * (-1);
    while(r - l > eps)
    {
    	m = (l + r)/2;
    	if(f(m) * f(r) > 0)
    		r = m;
    	else 
    		l = m;
	}
    printf("%.6f", l);
}

