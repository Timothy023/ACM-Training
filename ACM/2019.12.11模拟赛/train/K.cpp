#include<bits/stdc++.h>

using namespace std;

long long A,B,N;
long long L[100010];
	
void solve(int ord)
{
	scanf("%lld%lld%lld",&A,&B,&N);
	L[0]=0;
	for(int i=1;i<=A;i++)
	{
		scanf("%lld",&L[i]);
		L[i]+=L[i-1];
	}
	for(int x=0;x<N;x++)
	{
		long long lA=A,lB=B;
		int l=0,r=A;
		while(r-l>1)
		{
			int mid=(l+r)/2;
			if(L[mid]>=A) r=mid;
			else l=mid;
		}
		A=r;B=lA-L[l];
		if(A==lA&&B==lB) break;
	}
	printf("Case #%d: %lld-%lld\n",ord,A,B);
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
		solve(i);
}
