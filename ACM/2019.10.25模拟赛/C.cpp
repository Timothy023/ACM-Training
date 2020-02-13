#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int N=1e5+5;
int n,siz[N],root=-1,id,ans=2147483647,sum,tmp;
int fi[N],ne[N<<1],j[N<<1],step,maxn[N],son[N];
bool vis[N];
void addedge(int fr,int to){
	j[++step]=to;ne[step]=fi[fr];fi[fr]=step;
	j[++step]=fr;ne[step]=fi[to];fi[to]=step;
}
void dfs(int ro,int fa,int sum){
	siz[ro]=1;
	for (int u=fi[ro];u;u=ne[u]){
		if (j[u]==fa || vis[j[u]])continue;
		dfs(j[u],ro,sum);
		siz[ro]+=siz[j[u]];
		maxn[ro]=max(maxn[ro],siz[j[u]]);
	}
	maxn[ro]=max(maxn[ro],sum-siz[ro]);
	if (root==-1)root=ro;
	else if (maxn[ro]<maxn[root])root=ro;
}
int main (){
	int x,y;
	scanf ("%d",&n);
	for (int i=1;i<n;++i){
		scanf ("%d%d",&x,&y);
		addedge(x,y);
	}
	dfs(1,0,n);
	id=root;
	dfs(id,0,n);
	vis[id]=1;
//	cout <<id<<endl;
	for (int i=1;i<=n;++i)son[i]=siz[i];
	for (int u=fi[id];u;u=ne[u]){
		tmp=n-son[j[u]];
		root=-1;
		dfs(j[u],id,siz[j[u]]);
		int mm=0;
		for (int uu=fi[root];uu;uu=ne[uu]){
			if (j[uu]==id)continue;
			mm=max(mm,siz[j[uu]]);
		}
		tmp+=mm;
		ans=min(ans,tmp);
//		cout <<j[u]<<"  "<<mm<<"  "<<tmp<<"  "<<son[j[u]]<<endl;
	}
	printf ("%d\n",ans);
	return 0;
}
