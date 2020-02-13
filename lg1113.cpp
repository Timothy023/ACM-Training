#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int N=5e4+5;
int n,ti[N],id;
int fi[N],ne[N],step,j[N],ans;
void addedge(int fr,int to){
	j[++step]=to;ne[step]=fi[fr];fi[fr]=step;
}
void dfs(int ro,int cost){
	if (cost>ans)ans=cost;
	for (int u=fi[ro];u;u=ne[u])
		dfs(j[u],cost+ti[j[u]]);
}
int main (){
	scanf ("%d",&n);
	for (int i=1;i<=n;++i){
		scanf ("%d%d",&id,&ti[i]);
		int ls=0;
		while (id!=0){
			scanf ("%d",&id);
			if (!id)break;
			ls=max(ls,ti[id]);
		}
		ti[i]+=ls;
		ans=max(ans,ti[i]);
	}
	printf ("%d\n",ans);
	return 0;
}
