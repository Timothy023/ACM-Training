#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int N=1e5+5;
int n,m,s;
int i[N<<1],j[N<<1],first[N<<1],ne[N<<1];
int maxson[N],sum[N],fa[N],deep[N];
void dfs1(int ro)
{
	sum[ro]=1;
	for (int u=first[ro];u;u=ne[u])
		if (!sum[j[u]])
		{
			deep[j[u]]=deep[ro]+1;
			fa[j[u]]=ro;
			dfs1(j[u]);
			sum[ro]+=sum[j[u]];
			maxson[ro]=sum[maxson[ro]]>sum[j[u]]?maxson[ro]:j[u];
		}
}
int top[N],dfn[N],len,lso[N],rso[N],dfsx[N];
void dfs2(int ro,int t)
{
	top[ro]=t;
	dfn[ro]=++len;
	dfsx[len]=ro;lso[ro]=len;
	if (maxson[ro])dfs2(maxson[ro],t);
	for (int u=first[ro];u;u=ne[u])
		if (!dfn[j[u]])
			dfs2(j[u],j[u]);
	rso[ro]=len;
}
int ask_lca(int l,int r){
	while (top[l]!=top[r])
	{
		if (deep[top[l]]<deep[top[r]])r=fa[top[r]];
		else l=fa[top[l]];
	}
	if (deep[l]<deep[r])return l;
	else return r;
}
int T;
struct seg_tree{
	#define lson l,mid,rt<<1
	#define rson mid+1,r,rt<<1|1
	#define N 200005
	int t[N<<2],col[N<<2];
	void pushdown(int rt){
		if (t[rt]!=-1)
			t[rt<<1]=t[rt<<1|1]=col[rt<<1]=col[rt<<1|1]=t[rt];
	}
	void build(int l,int r,int rt){
		t[rt]=col[rt]=-1;
		if (l==r){
			t[rt]=dfsx[l];
			return;
		}
		int mid=(l+r)>>1;
		build(lson);build(rson);
	}
	void update(int l,int r,int rt,int ll,int rr,int key){
		if (ll<=l && r<=rr){
			t[rt]=col[rt]=key;
			return;
		}
		pushdown(rt);
		int mid=(l+r)>>1;
		if (ll<=mid)update(lson,ll,rr,key);
		if (mid<rr)update(rson,ll,rr,key);
	}
	int query(int l,int r,int rt,int wz){
		if (l==r)return t[rt];
		pushdown(rt);
		int mid=(l+r)>>1;
		if (wz<=mid)return query(lson,wz);
		else return query(rson,wz);
	}
	bool pd(int l,int r,int rt,int wz){
		if (l==r)return (col[rt]!=-1);
		pushdown(rt);
		int mid=(l+r)>>1;
		if (wz<=mid)return pd(lson,wz);
		else return pd(rson,wz);
	}
};
struct zs_tree{
	#define N 200005
	int ro[N],ls[N*20],rs[N*20],sum[N*20],len;
	void update(int l,int r,int oro,int &ro,int val){
		ro=++len;
		sum[ro]=sum[oro]+1;
		if (l==r)return;
		ls[ro]=ls[oro];rs[ro]=rs[oro];
		int mid=(l+r)>>1;
		if (val<=mid)update(l,mid,ls[oro],ls[ro],val);
		else update(mid+1,r,rs[oro],rs[ro],val);
		
	}
	void build(){
		len=0;
		for (int i=1;i<=n;++i)
			update(1,n,ro[i-1],ro[i],dfsx[i]);
	}
	int query(int l,int r,int lro,int rro,int val){
		if (l==r)return sum[rro]-sum[lro];
		int mid=(l+r)>>1;
		if (val<=mid)return query(l,mid,ls[lro],ls[rro],val)+sum[rs[rro]]-sum[rs[lro]];
		else return query(mid+1,r,rs[lro],rs[rro],val);
	}
};
seg_tree tr;
zs_tree zx;
int q,kin,u,v,t1,t2,s1,s2,ls;
bool f1,f2;
int ABS(int val){
	return (val<0)?(-val):(val);
}
int main ()
{
	scanf ("%d",&T);
	while (T--){
		scanf ("%d",&n);s=1;len=0;
		for (int b=1;b<=n;++b)
			first[b]=sum[b]=dfn[b]=0;
		memset(maxson,0,sizeof(maxson));
		for (int b=1;b<n;++b)
		{
			scanf ("%d%d",&i[b],&j[b]);
			ne[b]=first[i[b]];first[i[b]]=b;
			j[b+n]=i[b];i[b+n]=j[b];
			ne[b+n]=first[i[b+n]];first[i[b+n]]=b+n;
		}
		dfs1(s);dfs2(s,s);
		tr.build(1,n,1);
		zx.build();
		scanf ("%d",&q);
		while (q--){
			scanf ("%d",&kin);
			if (kin==1){
				scanf ("%d",&u);
				t1=tr.pd(1,n,1,dfn[u]);
				if (!t1){
					tr.update(1,n,1,lso[u],rso[u],u);
				}
			}
			else {
				scanf ("%d%d",&u,&v);
				t1=tr.query(1,n,1,dfn[u]);t2=tr.query(1,n,1,dfn[v]);
				f1=tr.pd(1,n,1,dfn[u]);f2=tr.pd(1,n,1,dfn[v]);
				if (t1!=t2)ls=ask_lca(t1,t2);
				ls=deep[t1]+deep[t2]-deep[ls]*2;
				if (f1)s1=zx.query(1,n,zx.ro[lso[t1]-1],zx.ro[rso[t1]],u);
				else s1=1;
				if (f2)s2=zx.query(1,n,zx.ro[lso[t2]-1],zx.ro[rso[t2]],v);
				else s2=1;
				if (t1==t2)printf ("%d\n",ABS(s1-s2));
				else printf ("%d\n",ls+s1+s2-2);
			}
		}
	}
	return 0;
}
