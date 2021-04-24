#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int maxn=1e4;
int n,m,p,c,inf,ans;
int f[maxn+5];
int main (){
	while (scanf ("%d%d",&n,&m)!=EOF){
		memset(f,60,sizeof(f));
		inf=f[0];f[0]=0;ans=-1;
		for (int i=1;i<=n;++i){
			scanf ("%d%d",&p,&c);
			for (int j=c;j<=maxn;++j)
				f[j]=min(f[j],f[j-c]+p);
		}
		for (int i=maxn;i>=m;--i){
			if (f[i]!=inf){
				if (ans==-1)ans=i;
				else if (f[i]<f[ans])ans=i;
			}
		}
		printf ("%d %d\n",f[ans],ans);
	}
	return 0;
}
