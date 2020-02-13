#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int mod=504;
int n,k;
int f[205][205],sum[205];
int main (){
	scanf ("%d%d",&n,&k);
	if (k>n*2-1){
		puts("0");
		return 0;
	}
	for (int i=1;i<=n;++i)
		sum[2*i-1]=sum[2*i]=2*i-1;
	n=n*2-1;
	f[0][0]=1;
	for (int i=1;i<=n;++i){
		f[i][0]=1;
		for (int j=1;j<=sum[i];++j)
			f[i][j]=(f[i-1][j]+f[i-1][j-1]*(sum[i]-(j-1)))%mod;
	}
	printf ("%d\n",f[n][k]);
	return 0;
}
