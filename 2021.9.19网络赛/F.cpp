#include<bits/stdc++.h>

using namespace std;

double solve()
{
    double a,b,R;
    cin>>a>>b>>R;
    double ans = 0;
    if(b>R)
    {
        ans = 2 * sqrt(a * a + (b-R) * (b-R)) - R;
    }
    else
    {
        ans = 2 * a - R;
    }
    return ans;
}

int main()
{
    int T;
    cin>>T;
    for(int i = 1; i <= T; i++)
        printf("Case #%d: %.2lf\n",i, solve());
}