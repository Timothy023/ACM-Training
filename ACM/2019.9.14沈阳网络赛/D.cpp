#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int mod=1e9+7;
const int N=1e5+5;
int n,x,y,z;
long long m[5][N],a[5],jl[5][N],lsj[5],ls[5];
int fi[N],j[N<<1],ne[N<<1],k[N<<1],step;
void addedge(int fr,int to,int cost){
	j[++step]=to;k[step]=cost;ne[step]=fi[fr];fi[fr]=step;
}
void solve(int ro,int fa){
	if (ne[fi[ro]]==0 && fa!=0){
		m[0][ro]=1;return;
	}
	for (int u=fi[ro];u;u=ne[u]){
		if (j[u]==fa)continue;
		solve(j[u],ro);
		for (int t=0;t<=2;++t){
			ls[(k[u]+t)%3]=m[t][j[u]];
			lsj[(k[u]+t)%3]=(jl[t][j[u]]+m[t][j[u]]*k[u]%mod)%mod;
		}
		
		for (int p=0;p<=2;++p)
			for (int q=0;q<=2;++q)
				a[(p+q)%3]=(a[(p+q)%3]+m[p][ro]*lsj[q]%mod+jl[p][ro]*ls[q]%mod)%mod;
		
		for (int t=0;t<=2;++t){
			m[t][ro]+=ls[t];
			jl[t][ro]=(jl[t][ro]+lsj[t])%mod;
		}
	}
	m[0][ro]++;
	for (int t=0;t<=2;++t)
		a[t]=(a[t]+jl[t][ro])%mod;
	/*
	cout <<ro-1<<":\n"<<"DianShu:"<<m[0][ro]<<"  "<<m[1][ro]<<"  "<<m[2][ro]<<"\n";
	cout <<"JuLi: "<<jl[0][ro]<<"  "<<jl[1][ro]<<"  "<<jl[2][ro]<<endl;
	cout <<"Answer: "<<a[0]<<"  "<<a[1]<<"  "<<a[2]<<endl;
	*/
}
int main (){
	while (scanf ("%d",&n)!=EOF){
		a[0]=a[1]=a[2]=step=0;
		for (int i=1;i<=n;++i){
			fi[i]=m[0][i]=m[1][i]=m[2][i]=jl[0][i]=jl[1][i]=jl[2][i]=0;
		}
		for (int i=1;i<n;++i){
			scanf ("%d%d%d",&x,&y,&z);
			x++;y++;
			addedge(x,y,z);
			addedge(y,x,z);
		}
		solve(1,0);
		printf ("%lld %lld %lld\n",a[0]*2%mod,a[1]*2%mod,a[2]*2%mod);
	}
	return 0;
}
