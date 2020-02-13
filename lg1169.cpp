#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int I(){
	int s=0,f=1;char ch=getchar();
	while (ch<'0' || ch>'9'){if (ch=='-')f=-1;ch=getchar();}
	while (ch>='0' && ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*f;
}
const int N=2005;
int n,m,ls,b,ans1,ans2;
int a[N][N],le[N][N],ri[N][N],up[N][N];
int main (){
	n=I();m=I();
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j){
			a[i][j]=I();
			le[i][j]=ri[i][j]=j;
			up[i][j]=1;
		}
	for (int i=1;i<=n;++i){
		for (int j=2;j<=m;++j)
			if (a[i][j]!=a[i][j-1])
				le[i][j]=le[i][j-1];
		for (int j=m-1;j>=1;--j)
			if (a[i][j]!=a[i][j+1])
				ri[i][j]=ri[i][j+1];
	}
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j){
			if (i>1 && a[i][j]!=a[i-1][j]){
				le[i][j]=max(le[i][j],le[i-1][j]);
				ri[i][j]=min(ri[i][j],ri[i-1][j]);
				up[i][j]=up[i-1][j]+1;
			}
			ls=ri[i][j]-le[i][j]+1;
			b=min(ls,up[i][j]);
			ans1=max(ans1,b*b);
			ans2=max(ans2,ls*up[i][j]);
		}
	printf ("%d\n%d\n",ans1,ans2);
	return 0;
}
