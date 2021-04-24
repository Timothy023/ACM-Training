#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int T,n,m;
int flag[55][55],ls[55];
char s1[55],s2[55];
bool pd,jc[55],orz;
void dfs(int step){
	if (step>m){
		pd=1;
		for (int i=1;i<m;++i)
			printf ("%d ",ls[i]);
		printf ("%d\n",ls[m]);
		return;
	}
	for (int i=1;i<=m && !pd;++i)
		if (flag[step][i]==n && !jc[i]){
			ls[step]=i;
			jc[i]=1;dfs(step+1);jc[i]=0;
			if (pd)return;
		}
	pd=1;orz=1;
}
int main (){
	scanf ("%d",&T);
	while (T--){
		scanf ("%d%d",&n,&m);pd=orz=0;
		memset(flag,0,sizeof(flag));
		for (int i=1;i<=n;++i){
			scanf ("%s",s1+1);scanf ("%s",s2+1);
			for (int j=1;j<=m;++j)
				for (int k=1;k<=m;++k)
					if (s1[j]==s2[k])flag[j][k]++;
		}
		dfs(1);
		if (orz)puts("-1");
	}
	return 0;
}
