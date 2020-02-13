#include<bits/stdc++.h>

using namespace std;

const int N=6;
long long m[]={4,9,25,49,121,169};
long long xm[N],M;

long long extend_gcd(long long a,long long b,long long &x,long long &y)
{
	if(b==0)
	{
		x=1;y=0;
		return a;
	}
	long long r=extend_gcd(b,a%b,y,x);
	y-=x*(a/b);
	return r;
}

void init()
{
	long long n=N;
	M=1;
	for(int i=0;i<n;i++) M*=m[i];
	for(int i=0;i<n;i++)
	{
		long long x,y;
		long long tm = M/m[i];
		extend_gcd(tm,m[i],x,y);
		xm[i]=tm*x;
	}
}

long long crt(int a[])
{
	long long n=N,ret=0;
	for(int i=0;i<n;i++)
		ret=(ret+xm[i]*a[i])%M;
	return (ret+M)%M;
}

int mu(int n)
{
	for(int i=2;i*i<=n;i++)
		if(n%i==0)
		{
			n/=i;
			if(n%i==0) return 0;
		}
	return 1;
}

int a[N],w[200];
long long ans;
vector<int> wa[N];

bool check(long long s)
{
	if(s<=0 || s> 1e9) return false;
	for(int i=0;i<200;i++)
		if(mu(s+i)!=w[i])
			return false;
	return true;
}

void f(int dep)
{
	if(dep == N)
	{
		long long r=crt(a);
		while(r<=1e9 && (ans < 0 || r < ans))
		{
			if(check(r))
			{
				ans = r;
				break;
			}
			r += M;
		}
		return ;
	}
	for(int i=0;i<wa[dep].size();i++)
	{
		a[dep] = wa[dep][i];
		f(dep+1);
	}
}

int main()
{
	init();
	for(int i=0;i<10;i++,getchar())
		for(int j=0;j<20;j++)
		{
			w[i*20+j]=getchar()-'0';
		//	putchar(mu(i*20+j+10087)+'0');
		}
	
	int ml=13;
	for(int i=0;i+ml<=200;i++)
	{
		bool flag = true;
		for(int j=0;j<ml;j++)
			if(w[i+j])
			{
				flag=false;
				break;
			}
		if(flag)
		{
			printf("-1");
			return 0;
		}
	}
	
	for(int i=0;i<N;i++)
	{
		for(int j=1;j<=m[i];j++)
		{
			bool flag=true;
			for(int k=m[i]-j+1;k<=200;k+=m[i])
				if(w[k-1])
				{
					flag = false;
					break;
				}
			if(flag)
				wa[i].push_back(j%m[i]);
		}
	}
	ans = -1;
	f(0);
	cout<<ans<<endl;
	return 0;
}
