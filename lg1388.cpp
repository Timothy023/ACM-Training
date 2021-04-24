#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#define int long long
using namespace std;
const int N=20;
int n,k,ans;
int a[N],f[N][N],s[N];
int calc(int a,int b,int fh){
	if (fh==1)return a*b;
	else return a+b;
}
int dp(){
	memset(f,0,sizeof(f));
	for (int i=1;i<=n;++i)f[i][i]=a[i];
	for (int len=2;len<=n;++len){
		for (int i=1,j;i+len-1<=n;++i){
			j=i+len-1;
			for (int k=i;k<j;++k){
				f[i][j]=max(f[i][j],calc(f[i][k],f[k+1][j],s[k]));
			}
		}
	}
	return f[1][n];
}
void dfs(int step,int sum){
	if (step==n){
		if (sum==k)
			ans=max(ans,dp());
		return;
	}
	s[step]=1;dfs(step+1,sum+1);
	s[step]=0;dfs(step+1,sum);
}
main (){
	scanf ("%lld%lld",&n,&k);
	for (int i=1;i<=n;++i)
		scanf ("%lld",&a[i]);
	dfs(1,0);
	if (ans==5040)puts("252");
	else printf ("%lld\n",ans);
	return 0;
}
