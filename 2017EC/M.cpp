#include<bits/stdc++.h>

using namespace std;

long long solve()
{
    long long a[5];
    for(int i=0;i<5;i++)
        scanf("%lld",&a[i]);
    int n;
    scanf("%d",&n);
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        if(x<=48) ans+=a[0];
        else if(x<=56) ans+=a[1];
        else if(x<=60) ans+=a[2];
        else if(x<=62) ans+=a[3];
        else ans+=a[4];
    }
    return ans*10000;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
        printf("Case #%d: %lld\n",i,solve());
    return 0;
}