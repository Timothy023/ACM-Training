#include<bits/stdc++.h>

using namespace std;

long long mod=1e9+7;

long long pw(long long x,int y)
{
    long long res=1;
    while(y>0)
    {
        if(y&1) res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return res;
}

void solve()
{
    long long n,m,k;
    scanf("%lld%lld%lld",&n,&m,&k);
    long long ans=pw(k,n*m);
    for(int i=2;i<=k;i++)
        ans=(ans+n*m*pw(i-1,n+m-2)%mod*pw(k,(n-1)*(m-1))%mod)%mod;
    printf("%lld\n",ans);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        printf("Case #%d: ",i);
        solve();
    }
}