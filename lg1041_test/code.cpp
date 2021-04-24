#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int I(){
	int s=0,f=1;char ch=getchar();
	while (ch<'0' || ch>'9'){if (ch=='-')f=-1;ch=getchar();}
	while (ch>='0' && ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*f;
}
const int N=305;
int n,m,x,y,ans=1e9,maxdep,pre[N];
int fi[N],ne[N<<1],j[N<<1],step;
int p[N][N],len[N],sum[N];
bool vis[N];
void addedge(int fr,int to){
	j[++step]=to;ne[step]=fi[fr];fi[fr]=step;
}
void dfs(int ro,int dep,int fa){
	maxdep=max(maxdep,dep);
	sum[ro]=1;pre[ro]=fa;
	p[dep][++len[dep]]=ro;
	for (int u=fi[ro];u;u=ne[u])
		if (j[u]!=fa){
			dfs(j[u],dep+1,ro);
			sum[ro]+=sum[j[u]];
		}
}
void change(int ro,int col){
	vis[ro]=col;
	for (int u=fi[ro];u;u=ne[u])
		if (j[u]!=pre[ro])change(j[u],col);
}
void solve(int step,int s){
/*	cout <<step<<"  "<<s<<endl;
	for (int i=1;i<=n;++i)cout <<vis[i]<<"  ";cout <<endl;
	system ("pause");*/
	if (step>maxdep)return (void)(ans=min(ans,n-s));
	for (int i=1;i<=len[step];++i){
		if (vis[p[step][i]])continue;
		change(p[step][i],1);
		solve(step+1,s+sum[p[step][i]]);
		change(p[step][i],0);
	}
	ans=min(ans,n-s);
}
int main (){
	freopen ("data.in","r",stdin);
	n=I();m=I();
	for (int i=1;i<=m;++i){
		x=I();y=I();
		addedge(x,y);addedge(y,x);
	}
	dfs(1,1,0);solve(2,0);
	printf ("%d\n",ans);
	return 0;
}
