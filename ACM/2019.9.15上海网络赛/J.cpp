#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int I(){
	int s=0,f=1;char ch=getchar();
	while (ch<'0' || ch>'9')ch=getchar();
	while (ch>='0' && ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s;
}
const int mod=1e9+7;
int T,n,a[305],sum[305],ans;
int f[305][150005];
int main (){
	T=I();
	while (T--){
		n=I();ans=0;
		for (int i=1;i<=n;++i)a[i]=I();
		sort(a+1,a+n+1);
		sum[n+1]=0;f[n+1][0]=1;
		for (int i=n;i>=1;--i)sum[i]=sum[i+1]+a[i];
		for (int i=n;i>=1;--i){
			for (int j=0;j<=sum[i+1];++j)
				f[i][j]=f[i+1][j];
			for (int j=sum[i+1]+1;j<=sum[i];++j)f[i][j]=0;
			for (int j=a[i];j<=sum[i];++j){
				f[i][j]=(f[i][j]+f[i+1][j-a[i]]);
				if (f[i][j]>=mod)f[i][j]-=mod;
			}
		}
		for (int i=n;i>=1;--i){
			for (int j=max((sum[1]+1)/2-a[i],0);j<=(sum[1]-a[i])/2 && j<=sum[i+1];++j){
				ans=(ans+f[i+1][j]);
				if (ans>=mod)ans-=mod;
			}
		}
		printf ("%d\n",ans);
	}
	return 0;
}
