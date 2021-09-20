#include<iostream>
#include<queue>
#include<cstring>
#define int long long
#define N 1200000
using namespace std;
int read(){
    int t = 0;char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch <= '9' && ch >= '0'){t = t * 10 + ch - '0'; ch = getchar();}
    return t;
}
typedef pair<long long,int> pii;
int T, n, m, len;
long long dis[N][2];
int beg[N], nex[N*2], to[N*2], va[N*2];
priority_queue<pii> q;
void Add(int a, int b, int v){
    nex[++len] = beg[a], beg[a] = len, to[len] = b, va[len] = v;
    nex[++len] = beg[b], beg[b] = len, to[len] = a, va[len] = v;
}
void dij(int f){
    if(f == 0){
        q.push(pii(0, 1));
        dis[1][f] = 0;
    }
    else{
        q.push(pii(0, n));
        dis[n][f] = 0;
    }
    while(!q.empty()){
        pii st = q.top();
        q.pop();
        int p = st.second;
        if(-st.first > dis[p][f]) continue;
        for(int i = beg[p]; i; i = nex[i]){
            if(dis[to[i]][f] > dis[p][f] + va[i] || dis[to[i]][f] == -1){
                dis[to[i]][f] = dis[p][f] + va[i];
                q.push(pii(-dis[to[i]][f], to[i]));
            }
        }
    }
}
main(){
    cin >> T;
    for(int t = 1; t <= T; t++){
        len = 0;
        memset(beg, 0, sizeof(beg));
        memset(dis, -1, sizeof(dis));
        n = read(); m = read();
        for(int i = 0; i < m; i++){
            int a, b, c;
            a = read(); b = read();
            for(int j = 0; j < b; j++){
                c = read();
                Add(c, n + i + 1, a);
            }
        }
        dij(0);
        dij(1);
        if(dis[n][0] == -1){
            cout << "Case #" << t << ": Evil John\n";
            continue;
        }
        long long zx = 1e18;
        for(int i = 1; i <= n; i++){
            zx = min(zx, max(dis[i][0], dis[i][1]) / 2);
        }
        cout << "Case #" << t << ": " << zx << "\n";
        int f = 0;
        for(int i = 1; i <= n; i++){
            if(max(dis[i][0], dis[i][1]) / 2 == zx){
                if(f) printf(" ");
                printf("%d", i);
                f = 1;
            }
        }
        puts("");
    }
    return 0;
}