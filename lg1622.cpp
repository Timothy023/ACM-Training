#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int N=105;
int a[N],n,m,f[N][N];
int main (){
	scanf ("%d%d",&m,&n);
	for (int i=1;i<=n;++i)
		scanf ("%d",&a[i]);
	sort(a+1,a+n+1);
	a[0]=0;a[n+1]=m+1;
	for (int l=1,j;l<=n;++l)
		for (int i=1;i+l-1<=n;++i){
			j=i+l-1;
			f[i][j]=2147483600;
			for (int k=i;k<=j;++k)
				f[i][j]=min(f[i][j],f[i][k-1]+f[k+1][j]+a[j+1]-a[i-1]-2);
		}
	printf ("%d\n",f[1][n]);
	return 0;
}
