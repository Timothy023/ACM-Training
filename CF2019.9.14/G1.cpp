#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int N=2e5+5;
int a[N],ri[N],sum[N],n,ans,maxn,q;
int main (){
	scanf ("%d%d",&n,&q);
	for (int i=1;i<=n;++i)
		scanf ("%d",&a[i]);
	for (int i=n;i>=1;--i)
		if (ri[a[i]]==0)ri[a[i]]=i;
	for (int i=1,j;i<=n;){
		j=ri[a[i]];
		for (int k=i;k<=j;++k)
			j=max(j,ri[a[k]]);
		maxn=0;
		for (int k=i;k<=j;++k){
			sum[a[k]]++;
			maxn=max(maxn,sum[a[k]]);
		}
		ans+=(j-i+1-maxn);
		for (int k=i;k<=j;++k){
			sum[a[k]]--;
		}
		i=j+1;
	}
	printf ("%d\n",ans);
	return 0;
}
