#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 305
int n,p,hed[N],cnt;
struct EG
{
    int to,nxt;
}E[2*N];
void ae(int f,int t)
{
    E[++cnt].to = t;
    E[cnt].nxt = hed[f];
    hed[f] = cnt;
}
int dep[N],siz[N];
vector<int>v[N];
void dfs(int u,int f)
{
    siz[u]=1;
    for(int j=hed[u];j;j=E[j].nxt)
    {
        int to = E[j].to;
        if(to==f)continue;
        dep[to]=dep[u]+1;
        v[dep[to]].push_back(to);
        dfs(to,u);
        siz[u]+=siz[to];
    }
}
bool brk[N];
void bk(int u)
{
    brk[u]=1;
    for(int j=hed[u];j;j=E[j].nxt)
    {
        int to = E[j].to;
        if(dep[to]<dep[u])continue;
        bk(to);
    }
}
void rbk(int u)
{
    brk[u]=0;
    for(int j=hed[u];j;j=E[j].nxt)
    {
        int to = E[j].to;
        if(dep[to]<dep[u])continue;
        rbk(to);
    }
}
int Dfs(int dep)
{
    int ret = 0;
    for(int i=0;i<v[dep].size();i++)
    {
        int to = v[dep][i];
        if(brk[to])continue;
        bk(to);
        ret=max(ret,Dfs(dep+1)+siz[to]);
        rbk(to);
    }
    return ret;
}
int main()
{
	freopen ("data.in","r",stdin);
    scanf("%d%d",&n,&p);
    for(int f,t,i=1;i<=p;i++)
    {
        scanf("%d%d",&f,&t);
        ae(f,t),ae(t,f);
    }
    dfs(1,0);
    int ans = n-Dfs(1);
    printf("%d\n",ans);
    return 0;
}
