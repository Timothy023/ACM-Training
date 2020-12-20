#include <bits/stdc++.h>
using namespace std;

int getint() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

double pow(double x,long long y)
{
    double res=1;
    while(y>0)
    {
        if(y&1) res=res*x;
        x=x*x;
        y>>=1;
    }
    return res;
}

double f(long long n,long long m,long long p, long long x)
{
    double res=x;
    res=res*n+m;
    res=res/(1-pow(1-p*0.0001,x));
    return res;
}


void solve()
{
    long long n,m,p;
    n=getint();m=getint();p=getint();
    long long l=1,r=1e12;
    while(r-l>=3)
    {
        int ll=(l*2+r)/3,rr=(l+r*2)/3;
        double lf=f(n,m,p,ll),rf=f(n,m,p,rr);
        if(lf>rf) l=ll;
        else r=rr;
    }
    double res=f(n,m,p,l);
    for(int i=l+1;i<=r;i++)
        res=min(res,f(n,m,p,i));
    printf("%.10lf\n",res);
}

int main () {
    int T=getint();
    while(T--)
        solve();
    return 0;
}