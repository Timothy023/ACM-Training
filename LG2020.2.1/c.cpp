#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0; char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s;
}

const int N = 5e5 + 5;
const int M = 1e7 + 5;
struct node {
    int id, u, k;
}qu[N];
int n, q, fa[N][25], col[N], d[N], ans[N];
int fi[N], ne[N], j[N], step, l[N], r[N], dep[N];
int root[N], ls[M], rs[M], cnt, t[M];
vector <int> c[N];

bool cmp1(node i, node j) {
    return col[i.u] < col[j.u];
}
void addedge(int fr, int to) {
    j[++step] = to; ne[step] = fi[fr]; fi[fr] = step;
}
void dfs(int ro, int d) {
    dep[ro] = d;
    c[col[ro]].push_back(ro);
    l[ro] = c[col[ro]].size();
    for (int u = fi[ro]; u; u = ne[u])
        dfs(j[u], d + 1);
    r[ro] = c[col[ro]].size();
}
int get_fa(int u, int k) {
    for (int j = 0; k; ++j) {
        if (k & 1)
            u = fa[u][j];
        k >>= 1;
    }
    return u;
}
void update(int l, int r, int r1, int &r2, int wz, int val) {
    r2 = ++cnt;
    t[r2] = t[r1] + val;
    ls[r2] = ls[r1]; rs[r2] = rs[r1];
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (wz <= mid) update(l, mid, ls[r1], ls[r2], wz, val);
    else update(mid + 1, r, rs[r1], rs[r2], wz, val);
}
int query(int l, int r, int r1, int r2, int wz) {
    if (l == r) return t[r2] - t[r1];
    int mid = (l + r) >> 1;
    if (wz <= mid) return query(l, mid, ls[r1], ls[r2], wz);
    else return query(mid + 1, r, rs[r1], rs[r2], wz);
}
void build(int color) {
    for (int i = 1; i <= cnt; ++i)
        t[i] = ls[i] = rs[i] = 0;
    cnt = 0;
    for (int i = 0; i < c[color].size(); ++i) {
        update(1, n, root[i], root[i + 1], dep[c[color][i]], d[c[color][i]]);
    }
}
int main () {
    n = I(); q = I();
    for (int i = 1; i <= n; ++i) col[i] = I();
    for (int i = 1; i <= n; ++i) d[i] = I();
    for (int i = 2; i <= n; ++i) {
        fa[i][0] = I();
        addedge(fa[i][0], i);
    }
    for (int j = 1; j <= 20; ++j)
        for (int i = 1; i <= n; ++i)
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
    dfs(1, 1);
    for (int i = 1; i <= q; ++i) {
        int u = I(), k = I();
        qu[i].u = get_fa(u, k);
        qu[i].k = dep[qu[i].u] + k;
        qu[i].id = i;
    }
    sort(qu + 1, qu + q + 1, cmp1);
    int now = -1;
    for (int i = 1; i <= q; ++i) {
        if (qu[i].u == 0) continue;
        if (col[qu[i].u] != now) {
            build(col[qu[i].u]);
            now = col[qu[i].u];
        }
        ans[qu[i].id] = query(1, n, root[l[qu[i].u] - 1], root[r[qu[i].u]], qu[i].k);
    }
    for (int i = 1; i <= q; ++i)
        printf ("%d\n", ans[i]);
    return 0;
}