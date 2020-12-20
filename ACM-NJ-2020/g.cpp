#include <bits/stdc++.h>
using namespace std;

long long mod=1e9+7,lx=1e6+7;
const int dx[]={1,0,0,-1};
const int dy[]={0,-1,1,0};

int getint() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

vector<vector<int> > G;
int n,lbt;
char c[1010][1010];

vector<int> cut,low,dfn,vis;
vector<int> totsiz,siz,color;
int cnt,totcolor;
void cut_bridge(int cur,int fa,int dep,int c)
{
    cnt++;
    vis[cur]=1;dfn[cur]=low[cur]=dep;
    siz[cur]=0;
    color[cur]=c;
    int children=0;
    for(int i=0;i<G[cur].size();i++)
    {
        int to=G[cur][i];
        if(to!=fa&&vis[to]==1)
        {
            if(dfn[to]<low[cur])
                low[cur]=dfn[to];
        }
        if(vis[to]==0)
        {
            int tmp=cnt;
            cut_bridge(to,cur,dep+1,c);
            children++;
            if(low[to]<low[cur]) low[cur]=low[to];
            if((fa==-1&&children>1)||(fa!=-1&&low[to]>=dfn[cur])){
                cut[cur]=true;
                siz[cur] += cnt-tmp;
            }
        }
    }
    vis[cur]=2;
}

void solve()
{
    n=getint();
    lbt=n*n;
    G.clear();
    G.resize(n*n+1);
    for(int i=0;i<n;i++)
        scanf("%s",c[i]);
    for(int x=0;x<n;x++)
        for(int y=0;y<n;y++)
            if(c[x][y]=='o')
            {
                for(int i=0;i<4;i++)
                {
                    int tx=x+dx[i],ty=y+dy[i];
                    if(tx>=0&&tx<n&&ty>=0&&ty<n)
                    {
                        if(c[x][y]=='o')
                        {
                            if(c[tx][ty]=='.')
                            {
                                G[lbt].push_back(x*n+y);
                                G[x*n+y].push_back(lbt);
                            }
                            else if(c[tx][ty]=='o')
                            {
                                G[tx*n+ty].push_back(x*n+y);
                                G[x*n+y].push_back(tx*n+ty);
                            }
                        }
                    }
                }
            }
    cut.clear();cut.resize(G.size());
    low.clear();low.resize(G.size());
    dfn.clear();dfn.resize(G.size());
    vis.clear();vis.resize(G.size());
    siz.clear();siz.resize(G.size());
    color.clear();color.resize(G.size());
    cnt=0;
    cut_bridge(lbt,-1,0,1);
    totcolor=1;
    totsiz.clear();totsiz.push_back(0);
    totsiz.push_back(cnt);
    long long totdead=0;
    for(int x=0;x<n;x++)
        for(int y=0;y<n;y++)
            if(c[x][y]=='o'&&color[x*n+y]==0)
            {
                cnt=0;
                cut_bridge(x*n+y,-1,0,totcolor+1);
                totcolor++;
                totsiz.push_back(cnt);
                totdead+=cnt;
            }
//    for(int i=0;i<n*n;i++) cout<<cut[i]<<' '<<siz[i]<<'|';
    long long ans=0;
    for(int x=0;x<n;x++)
        for(int y=0;y<n;y++)
            if(c[x][y]=='o'||c[x][y]=='x')
            {
                long long resans=totdead;
                if(c[x][y]=='o')
                {
                    if(color[x*n+y]==1&&cut[x*n+y])
                        resans+=siz[x*n+y];
                    if(color[x*n+y]!=1)
                        resans--;
                }
                if(c[x][y]=='x')
                {
                    bool alive=false;
                    vector<int> bc;
                    for(int i=0;i<4;i++)
                    {
                        int tx=x+dx[i],ty=y+dy[i];
                        if(tx>=0&&tx<n&&ty>=0&&ty<n&&c[tx][ty]!='x')
                        {
                            if(color[tx*n+ty]==1||c[tx][ty]=='.')
                                alive=true;
                            else if(color[tx*n+ty]>1)
                                bc.push_back(color[tx*n+ty]);
                        }
                    }
                    if(alive)
                    {
                        for(int i=0;i<bc.size();i++)
                        {
                            bool flag=true;
                            for(int j=0;j<i;j++)
                                if(bc[i]==bc[j])
                                    flag=false;
                            if(flag)
                                resans-=totsiz[bc[i]];
                        }
                    }
                    else
                        resans++;
                }
                ans=(ans*lx+resans)%mod;
//                cout<<resans<<endl;
            }
    printf("%lld\n",ans);
}

int main () 
{
    int T=getint();
    while(T--)
        solve();
    return 0;
}