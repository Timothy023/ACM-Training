#include<iostream>
#include<cstdlib>
#include<cstdio>
#define ll long long
using namespace std;
int T;
const int mod=1e9+7;
ll jz(ll i,ll j,ll k){
	ll ls;
	ls=i;
	ls=(ls*ls*ls*k+(ls-1)*ls*ls*j);
	return ls;
}
ll jz1(ll i,ll j,ll k){
	ll ls=7*jz(i/2,j,k);
	return (ls+(i/2)%mod*(i/2)%mod*18%mod*j%mod);
}
ll solve(ll n,ll jia,ll cheng){
	ll now=cheng,l1,l2,i;
	if (n==1)return now;
	for (i=2;i<=64;i<<=1){
		l1=jz(i,jia,cheng);l2=now*7+18*(i/2)*(i/2)*jia;
		if (l1>l2)break;
		else now=l1;
		if (i==n)return now%mod;
	}
	for (;i<=n;i<<=1){
		now=(now%mod*7%mod+18*(i/2)%mod*(i/2)%mod*jia%mod)%mod;
	}
	return now;
}
int main (){
	ll n,a,b;
	scanf ("%d",&T);
	while (T--){
		scanf ("%I64d%I64d%I64d",&n,&a,&b);
		cout <<solve(n,a,b)<<endl;
	}
	return 0;
}
