#include<bits/stdc++.h>

using namespace std;

void solve(int ord)
{
	long long a,b,c,d,e;
	scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e);
	int n;
	scanf("%d",&n);
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		int mp;
		scanf("%d",&mp);
		if(mp<=48) ans+=a*10000;
		else if(mp<=56) ans+=b*10000;
		else if(mp<=60) ans+=c*10000;
		else if(mp<=62) ans+=d*10000;
		else ans+=e*10000;
	}
	printf("Case #%d: %lld\n",ord,ans);
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
		solve(i);
}
/*
2
11 12 13 14 15
2
1 49
11 12 13 14 15
2
1 49

*/
