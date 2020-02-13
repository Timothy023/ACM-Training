#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int n,f[105][105],x,y,m,ans=1e9;
int main (){
	scanf ("%d", &n);
	memset(f,60,sizeof(f));
	f[0][1]=0;
	for (int i=1; i<=n; ++i){
		scanf ("%d",&m);
		for (int j=1;j<=m;++j){
			do{
				scanf ("%d", &x);
				if (!x)break;
				scanf ("%d", &y);
				f[i][j] = min(f[i][j], f[i-1][x]+y);
			}while (1);
			if (i==n)ans=min(ans,f[i][j]);
		}
	}
	printf ("%d\n",ans);
	return 0;
}
