#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e12
const int maxn=1e5+10;
struct node{    int x;    ll w;    node(int _x,ll _w)    {        x=_x;        w=_w;    }};
vector<node>a[maxn];
int n,t,m,siz[maxn];
ll dp[maxn][102];
void dfs(int u,int fa){    if(a[u].size()==1)    {        dp[u][1]=0;        siz[u]=1; }    dp[u][0]=0;    for(int i=0;i<a[u].size();i++)    {        int v=a[u][i].x;        ll w=a[u][i].w;        if(v==fa) continue;        dfs(v,u);        siz[u]+=siz[v];        dp[u][m]=min(dp[v][m],dp[u][m]);      for(int j=min(m,siz[u]);j>=1;j--)        {            for(int k=1;k<=min(j,siz[v]);k++)                dp[u][j]=min(dp[u][j],dp[u][j-k]+dp[v][k]+1ll*w*1ll*k*1ll*(m-k));      }    }}
int main(){      
freopen ("G.in","r",stdin);
freopen ("G.out","w",stdout);
scanf("%d",&t);    int cas=0;    while(t--)    {        scanf("%d%d",&n,&m);        for(int i=1;i<=n;i++)            a[i].clear();        for(int i=1;i<n;i++)        {            int x,y;            ll w;            scanf("%d%d%lld",&x,&y,&w);            a[x].push_back(node(y,w));            a[y].push_back(node(x,w));        }         memset(siz,0,sizeof siz);        int rt=1;        for(int i=1;i<=n;i++)        if(a[i].size()>1)        {            rt=i;            break;        }        for(int i=1;i<=n;i++)        for(int j=1;j<=m;j++)            dp[i][j]=inf;        for(int i=1;i<=n;i++)            dp[i][0]=0;        dfs(rt,-1);        printf("Case #%d: %lld\n",++cas,dp[rt][m]);    }    return 0;}

