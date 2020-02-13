#include<iostream>
#include<cstdlib>
#include<cstdio>
#define ll long long
using namespace std;
inline void orzcy(int &s)
{
	s=0;int f=1;char ch=getchar();
	while (ch<'0' || ch>'9'){if (ch=='-')f=-1;ch=getchar();}
	while (ch>='0' && ch<='9'){s=s*10+ch-'0';ch=getchar();}
	s*=f;
}
int n,m,s,len;
ll dis[1005];
int fan[1005];
int i[4005],j[4005],first[4005],ne[4005];
ll k[4005];
struct node
{
	ll val,xh;
	friend bool operator <= (node i,node j){return i.val<=j.val;}
}dui[1005];
inline void pop()
{
	dui[1]=dui[len--];
	fan[dui[1].xh]=1;
	int now=1;
	while (now*2<=len)
	{
		int ne=now<<1;
		if (ne<len && dui[ne+1]<=dui[ne])ne++;
		if (dui[now]<=dui[ne])break;
		fan[dui[now].xh]^=fan[dui[ne].xh]^=fan[dui[now].xh]^=fan[dui[ne].xh];
		node tt=dui[now];
		dui[now]=dui[ne];
		dui[ne]=tt;
		now=ne;
	}
}
inline void pop1(int now)
{
	while (now>1)
	{
		int ne=now>>1;
		if (dui[now]<=dui[ne])
		{
			fan[dui[now].xh]^=fan[dui[ne].xh]^=fan[dui[now].xh]^=fan[dui[ne].xh];
			node tt=dui[now];
			dui[now]=dui[ne];
			dui[ne]=tt;
		}
		else break;
		now=ne;
	}
}
int an[1005];
inline void dij(){
	dui[1].val=0;dui[1].xh=s;len=1;fan[s]=1;
	for (int b=1;b<=n;++b)
		if (b!=s)
		{
			dui[++len].val=21474836470000000ll;
			dui[len].xh=b;
			fan[b]=len;
		}
	for (int b=1;b<=n;++b)
	{
		dis[dui[1].xh]=dui[1].val;
		node y=dui[1];
		pop();
		fan[y.xh]=1001;
		for (int u=first[y.xh];u;u=ne[u])
			if (dis[i[u]]+k[u]<dui[fan[j[u]]].val)
			{
				dui[fan[j[u]]].val=dis[i[u]]+k[u];
				pop1(fan[j[u]]);
				if (i[u]!=s)an[j[u]]=max(i[u],an[i[u]]);
				else an[j[u]]=0;
			}
			else if (dis[i[u]]+k[u]==dui[fan[j[u]]].val)
				if (i[u]!=s)an[j[u]]=min(an[j[u]],max(i[u],an[i[u]]));
				else an[j[u]]=0;
	}
//	for (int b=1;b<=n;++b)printf ("%d ",an[b]);puts("");
}
int step,ans;
void addedge(int fr,int to,int cost){
	i[++step]=fr;j[step]=to;k[step]=cost;
	ne[step]=first[i[step]];first[i[step]]=step;
}
const int mod=998244353;
inline void sol(){
	orzcy(n);orzcy(m);step=ans=0;
	for (int b=1;b<=n;++b)first[b]=0;
	int x,y,z;
	for (int b=1;b<=m;++b){
		orzcy(x);orzcy(y);orzcy(z);
		addedge(x,y,z);addedge(y,x,z);
	}
	for (int b=1;b<=n;++b){
		for (int c=1;c<=n;++c){
			an[c]=5000;dis[c]=21474836470000000ll;
		}
		s=b;an[s]=0;dij();
		for (int c=1;c<=n;++c)
			ans=(ans+an[c])%mod;
	}
	printf ("%d\n",ans);
}
int T;
int main (){
	scanf ("%d",&T);
	while (T--)sol();
	return 0;
}
