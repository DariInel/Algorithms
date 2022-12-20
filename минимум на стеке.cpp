#include<iostream>
using namespace std;
const long long min_1 = 1e9+1;
pair<long long, long long>a[1000005];
int index;
void push(long long x)
{
    if (index == 0)
        {
            a[index].first = x;
            a[index].second = x;
        }
    else
    {
        a[index].first = x;
        a[index].second = min(x, a[index - 1].second);
    }
    index++;
}
void pop()
{
    index--;
}
int min_()
{
    long long c = min_1;
    if (index != 0)
        c = min(c, a[index-1].second);
    return c;
}
int main()
{
    int n;
    index = 0;
    cin>>n;
    int a;
    for(int i = 0; i < n; i++)
    {
        cin>>a;
        if (a == 1)
        {
        	int a2;
            cin>>a2;
            push(a2);
        }
        if (a == 2)
        {
            pop();
        }
        if (a == 3)
        {
            cout<<min_()<<endl;
        }
    }
    return 0;
}
