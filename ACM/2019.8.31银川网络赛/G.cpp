#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
const long long MAX=9999999999999999ll;
int I(){
	int s=0;char ch=getchar();
	while (ch<'0' || ch>'9')ch=getchar();
	while (ch>='0' && ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s;
}
const int N=1e5+5;
int T,n,k,x,y,w,son[N];
int j[N<<1],co[N<<1],fi[N],ne[N<<1],step;
long long f[N][105];
void addedge(int fr,int to,int c){
	j[++step]=to;co[step]=c;ne[step]=fi[fr];fi[fr]=step;
	j[++step]=fr;co[step]=c;ne[step]=fi[to];fi[to]=step;
}
void dp(int ro,int fa){
	if (ne[fi[ro]]==0){
		f[ro][1]=0;
		son[ro]=1;
		return;
	}
	son[ro]=0;
	for (int u=fi[ro];u;u=ne[u]){
		if (j[u]==fa)continue;
		dp(j[u],ro);
		son[ro]+=son[j[u]];
		for (int i=min(k,son[ro]);i>=1;--i){
			for (int t=1;t<=son[j[u]] && t<=i;++t)
				f[ro][i]=min(f[ro][i],f[ro][i-t]+f[j[u]][t]+1ll*co[u]*t*(k-t));
		}
	}
}
void solve(){
	n=I();k=I();step=0;
	for (int i=1;i<=n;++i)fi[i]=0;
	for (int i=1;i<n;++i){
		x=I();y=I();w=I();
		addedge(x,y,w);
	}
	for (int i=1;i<=n;++i)
		for (int t=1;t<=k;++t)
			if (f[i][t]==MAX)break;
			else f[i][t]=MAX;
	dp(1,0);
	printf ("%lld\n",f[1][k]);
}
int main (){
	T=I();
	for (int i=1;i<=T;++i){
		printf ("Case #%d: ",i);
		solve();
	}
	return 0;
}
