#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int N=55;
const int M=1500;
int n,sum,ans,m;
int f[N][N][M],a[N][N];
int main (){
	scanf ("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n-i+1;++j)
			scanf ("%d",&a[i][j]);
	for (int i=n;i>=1;--i){
		for (int j=0;j<=n-i+1;++j)
			sum+=a[j][i];
		for (int j=n-i+1;j>=0;sum-=a[j--][i]){
			for (int k=max(2*j-1,0);k<=m;++k){
				int t=max(0,j-1);
				f[i][j][k]=f[i+1][t][k-j]+sum;
				ans=max(ans,f[i][j][k]);
				f[i][j][k]=max(f[i][j][k],f[i][j+1][k]);
			}
		}
	}
	printf ("%d\n",ans);
	return 0;
}
