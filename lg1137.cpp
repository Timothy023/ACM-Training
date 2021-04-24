#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int N=200005;
int n,m,x,y,du[N];
int fi[N],ne[N<<1],j[N<<1],step,que[N],f[N],tot,tow;
void addedge(int fr,int to){
	j[++step]=to;ne[step]=fi[fr];fi[fr]=step;du[to]++;
}
int main (){
	scanf ("%d%d",&n,&m);
	for (int i=1;i<=m;++i){
		scanf ("%d%d",&x,&y);
		addedge(x,y);
	}
	tot=1;tow=0;
	for (int i=1;i<=n;++i)
		if (du[i]==0){
			que[++tow]=i;
			f[i]=1;
		}
	while (tot<=tow){
		for (int u=fi[que[tot]];u;u=ne[u]){
			du[j[u]]--;
			f[j[u]]=max(f[j[u]],f[que[tot]]+1);
			if (du[j[u]]==0)que[++tow]=j[u];
		}
		++tot;
	}
	for (int i=1;i<=n;++i)
		printf ("%d\n",f[i]);
	return 0;
}
