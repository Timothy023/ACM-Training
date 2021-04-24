#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
char ch[155][155];
int n,f[155][155],ans,ls;
int main (){
	scanf ("%d",&n);
	for (int i=1;i<=n;++i)
		scanf ("%s",ch[i]+1);
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			if (ch[i][j]=='B')continue;
			f[i][j]=f[i][j-1]+1;
			ls=f[i][j];
			for (int k=i;k>=1;--k){
				ls=min(ls,f[k][j]);
				ans+=ls;
			}
		}
	}
	printf ("%d\n",ans);
	return 0;
}
