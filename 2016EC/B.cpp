#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int N,K;
int A[100100];

bool ovf(int l,int r,int lr)
{
    if(l<r) swap(l,r);
    if(l>=62) return 1;
    return ((1ull<<l)+(1ull<<r)-(1ull<<lr))<=K;
}

void solve()
{
    scanf("%lld%lld",&N,&K);
    long long l=(N+1)/2,r=N/2;
    int L=(l+1)/2+r,R=(r+1)/2+l,LR=(l+1)/2+(r+1)/2;
    if(!ovf(l,r,lr))
    {
        puts("NOT FOUND!");
        return ;
    }
    int tl=(N+1)/2,tr=N/2;
    for(int i=N-1;i>=0;i--)
    {
        A[i]=0;
        int l,r,lr,ttl=tl,ttr=tr;
        if(N-1-i >= i && A[N-1-i]!=A[i])
            if(i&1)
                ttr=-1;
            else
                ttl=-1;
        
    }
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
    return 0;
}