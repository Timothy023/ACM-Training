#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, x, y, p, q;
int fi[N], ne[N << 1], j[N << 1], k[N<<1], c[N<<1], step;
int stk[N], r[N], len, sta, be[N], s[N];
bool vis[N], flag;
long long ans;

inline int I(){
    int s = 0; char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s;
}

void addedge(int fr, int to, int c1, int c2) {
    ++step; k[step] = c1; c[step] = c2; j[step] = to;
    ne[step] = fi[fr]; fi[fr] = step;
}
void dfs(int ro, int fa) {
    stk[++sta] = ro;
    if (vis[ro]) {
        flag = 1;
        do{
            r[++len] = stk[sta];
            sta--;
        }while (stk[sta] != ro);
        return;
    }
    vis[ro] = 1;
    for (int u = fi[ro]; u; u = ne[u]) {
        if (j[u] != fa) dfs(j[u], ro);
        if (flag) return;
    }
    --sta;
}
void dfs1(int ro, int f) {
    if (be[ro] && f != ro) return;
    be[ro] = f;
    for (int u = fi[ro]; u; u = ne[u])
        dfs1(j[u], f);
}
int main () {
    n = I();
    for (int i = 1; i <= n; ++i) {
        x = I(); y = I(); p = I(); q = I();
        addedge(x, y, p, q);
        addedge(y, x, p, q);
        ans += p;
    }
    dfs(1, 0);
    for (int i = 1; i <= len; ++i)
        be[r[i]] = r[i];
    for (int i = 1; i <= len; ++i) {
        x = y = -1;
        for (int u = fi[r[i]]; u; u = ne[u]) {
            if (be[j[u]]) {
                if (x == -1) {
                    x = k[u]; y = c[u];
                }
                else {
                    if (c[u] < y) x = k[u];
                }
            }
        }
        s[r[i]] = x;
        dfs1(r[i], r[i]);
    }
    for (int i = 1; i <= n; ++i)
        printf ("%lld\n", ans - s[be[i]]);
    return 0;
}