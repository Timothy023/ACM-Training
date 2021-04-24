#include<bits/stdc++.h>

using namespace std;

const long double pi=31415926535.8979323846;

int main()
{
    double n,m;
    cout << fixed << setprecision(20) << pi << "\n";
    cin>>n>>m;
    long double ans=m*n*(n+1);
    int t=2*m/pi;
    long double x=t*(t+1)*pi+2*m*(2*(m-t-1)+1);
    for(int r=1;r<=n;r++)
        ans+=x*r+2*x*r*(n-r)+2*m*m*(n-r)*(n-r+1);
    printf("%.10lf\n",ans);
}
