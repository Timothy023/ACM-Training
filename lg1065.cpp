#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int n,m,N,s,ans;
int tim[50],ti[50],tis[50][50];
int a[500],sx[50][50],sum[50];
bool flag[50][5000];
int main (){
	scanf ("%d%d",&m,&n);N=n*m;
	for (int i=1;i<=N;++i)
		scanf ("%d",&a[i]);
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			scanf ("%d",&sx[i][j]);
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			scanf ("%d",&tis[i][j]);
	for (int i=1;i<=N;++i){
		sum[a[i]]++;s=0;
		for (int j=ti[a[i]]+1;;++j){
			if (!flag[sx[a[i]][sum[a[i]]]][j])++s;
			else s=0;
			if (s==tis[a[i]][sum[a[i]]]){
				for (int k=j-s+1;k<=j;++k)
					flag[sx[a[i]][sum[a[i]]]][k]=1;
				ti[a[i]]=j;
				break;
			}
		}
	}
	for (int i=1;i<=n;++i)
		ans=max(ans,ti[i]);
	printf ("%d\n",ans);
	return 0;
}
