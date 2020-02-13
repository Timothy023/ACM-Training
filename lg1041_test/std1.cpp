#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
const int maxn=500;
int vis[maxn],deep[maxn][maxn],count[maxn];
int n,m,i,j,x,y,ans=1006,maxx=0;
struct Node
{
    int father,child[maxn],number;
};
Node node[maxn];
void Input(void)
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        node[i].number=0;
        count[i]=1;
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        if(x>y) swap(x,y);
        node[y].father=x;
        node[x].number++;
        node[x].child[node[x].number]=y;
    }
}
void Deep(int tree,int now)
{
    maxx=max(maxx,now);
    for(int i=1;i<=node[tree].number;i++)
    {
        deep[now][0]++;
        deep[now][deep[now][0]]=node[tree].child[i];
        Deep(node[tree].child[i],now+1);
    }
    return ;
}
int Count(int tree)
{
    for(int i=1;i<=node[tree].number;i++)
    {
        count[tree]+=Count(node[tree].child[i]);
    }
    return count[tree];
}
void work(int tree,int tag)
{
    for(int i=1;i<=node[tree].number;i++)
    {
        vis[node[tree].child[i]]=tag;
        work(node[tree].child[i],tag);
    }
    return ;
}
void dfs(int now,int cnt) 
{
    if(now==maxx)
    {
        ans=min(ans,cnt);
        return ;
    }
    int f=0;
    for(int i=1;i<=deep[now][0];i++)
    {
        if(vis[deep[now][i]]>0)
        {
            f++;
            continue;
        }
        vis[deep[now][i]]=1;
        work(deep[now][i],1);
        dfs(now+1,cnt-count[deep[now][i]]);
        vis[deep[now][i]]=0;
        work(deep[now][i],0);
    }
    if(f==deep[now][0]) ans=min(ans,cnt);
}
int main()
{
	freopen ("data.in","r",stdin);
    Input();
    Deep(1,2);
    Count(1);
    dfs(2,n);
    printf("%d",ans);
    return 0;
}
