#include<iostream>
#include<string>
#include<stack>
using namespace std;
string s;
stack <long long> a;
int index = 0;
int main()
{
    int sum = 0;
    getline(cin,s);
	for(int i = 0; i < s.size(); i++)
	{
		if( s[i] != ' ')
		{
			if(s[i] == '+')
			{
			    int b, c;
			    b = a.top();
			    a.pop();
			    c = a.top();
			    a.pop();
				sum =  b + c;
				a.push(sum);
			}
			else
			{
				if(s[i] == '-')
				{
				    int b, c;
                    b = a.top();
                    a.pop();
                    c = a.top();
                    a.pop();
					sum = c - b;
					a.push(sum);
				}
				else
				{
					if(s[i] == '*')
					{
					    int b, c;
                        b = a.top();
                        a.pop();
                        c = a.top();
                        a.pop();
						sum = b * c;
						a.push(sum);
					}
					else
					{
					 a.push(s[i]-'0');
					}
			    }
	    	}
		}
	}
	cout << a.top();
}
