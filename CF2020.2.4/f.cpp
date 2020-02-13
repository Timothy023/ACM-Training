#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0; char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s;
}

const int N = 5005;
int n, m, x, y, z, val[N], dep[N], fa[N], e[N];
int fi[N], ne[N << 1], j[N << 1], id[N << 1], step;
int p[N], q[N], h[N];
bool flag;

void addedge(int fr, int to, int k) {
    j[++step] = to; id[step] = k; ne[step] = fi[fr]; fi[fr] = step;
    j[++step] = fr; id[step] = k; ne[step] = fi[to]; fi[to] = step;
}
void dfs(int ro, int pre) {
    for (int u = fi[ro]; u; u = ne[u]) {
        if (j[u] == pre) continue;
        fa[j[u]] = ro; e[j[u]] = id[u];
        dep[j[u]] = dep[ro] + 1;
        dfs(j[u], ro);
    }
}
int main () {
    n = I();
    for (int i = 1; i < n; ++i) {
        x = I(); y= I();
        addedge(x, y, i);
        val[i] = 1;
    }
    dfs(1, 0);
    m = I();
    for (int i = 1; i <= m; ++i) {
        x = p[i] = I(); y = q[i] = I(); z = h[i] = I();
        if (dep[x] < dep[y]) swap(x, y);
        while (dep[x] > dep[y]) {
            val[e[x]] = max(val[e[x]], z);
            x = fa[x];
        }
        while (x != y) {
            val[e[x]] = max(val[e[x]], z);
            val[e[y]] = max(val[e[y]], z);
            x = fa[x]; y = fa[y];
        }
    }
    flag = 1;
    for (int i = 1; i <= m; ++i) {
        int tmp = 1e9;
        x = p[i]; y = q[i]; z = h[i];
        if (dep[x] < dep[y]) x ^= y ^= x ^= y;
        while (dep[x] > dep[y]) {
            tmp = min(tmp, val[e[x]]);
            x = fa[x];
        }
        while (x != y) {
            tmp = min(tmp, val[e[x]]);
            tmp = min(tmp, val[e[y]]);
            x = fa[x]; y = fa[y];
        }
        if (tmp != z) {
            flag = 0; break;
        }
    }
    if (flag) for (int i = 1; i < n; ++i) printf ("%d ", val[i]);
    else puts("-1");
    return 0;
}