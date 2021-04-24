#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

const int N = 2e5 + 5;
int n, m;
int fi[N], ne[N], j[N], id[N], step;
bool flag[N];
void addedge(int fr, int to, int key) {
    id[++step] = key;
    j[step] = to;
    ne[step] = fi[fr];
    fi[fr] = step;
}

bool sta[N], vis[N];

void dfs(int ro, int fr) {
    if (sta[ro]) flag[fr] = 1;
    if (vis[ro]) return;
    sta[ro] = 1;
    vis[ro] = 1;
    for (int u = fi[ro]; u; u = ne[u]) {
        dfs(j[u], id[u]);
    }
    sta[ro] = 0;
}

int main () {
    n = I(); m = I();
    int x, y;
    for (int i = 1; i <= m; ++i) {
        x = I(); y = I();
        addedge(x, y, i);
    }
    for (int i = 1; i <= n; ++i)
        if (!vis[i]) dfs(i, 0);
    int ans = 0;
    for (int i = 1; i <= m; ++i)
        if (flag[i]) ans++;
    printf ("%d\n", ans);
    for (int i = 1; i <= m; ++i)
        if (flag[i]) printf ("%d\n", i);
    return 0;
}