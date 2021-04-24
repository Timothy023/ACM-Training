#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int N=2e5+5;
int a[N],n,f[N],g[N],ans1,ans2,sum;
int solve(){
	int tmp=-2147483647;
	f[0]=g[n+1]=-2147483647;
	for (int i=1;i<=n;++i)f[i]=max(f[i-1],0)+a[i];
	for (int i=1;i<=n;++i)f[i]=max(f[i],f[i-1]);
	for (int i=n;i>=1;--i)g[i]=max(g[i+1],0)+a[i];
	for (int i=n;i>=1;--i)g[i]=max(g[i],g[i+1]);
	for (int i=1;i< n;++i)tmp=max(tmp,f[i]+g[i+1]);
	return tmp;
}
int main (){
	scanf ("%d",&n);
	for (int i=1;i<=n;++i){
		scanf ("%d",&a[i]);
		if (a[i]<0)sum++;
	}
	ans1=solve();
	if (sum+2<=n){
		for (int i=1;i<=n;++i){
			ans2+=a[i];
			a[i]=-a[i];
		}
		ans2+=solve();
	}
	else {
		sort(a+1,a+n+1);
		ans2=a[n-1]+a[n];
	}
	printf ("%d\n",max(ans1,ans2));
	return 0;
}
