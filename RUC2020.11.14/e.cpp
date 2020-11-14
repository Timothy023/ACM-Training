#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m, zd = -1;
int fi[N], ne[N << 1], j[N << 1], step;
int mx[N], sx[N], mxid[N], sxid[N], ms = -1, mt = -1, mdis = -1, dis[N];
bool flag[N], jc, jjc = true;

void addedge(int fr, int to) {
    j[++step] = to; ne[step] = fi[fr]; fi[fr] = step;
    j[++step] = fr; ne[step] = fi[to]; fi[to] = step;
}

void dfs(int ro, int fa) {
    mx[ro] = -1; sx[ro] = -1;
    for (int u = fi[ro]; u; u = ne[u]) {
        if (j[u] == fa) continue;
        dfs(j[u], ro);

        if (mx[j[u]] != -1) {
            if (mx[ro] == -1) {
                mx[ro] = mx[j[u]] + 1;
                mxid[ro] = mxid[j[u]];
            }
            else if (mx[ro] < mx[j[u]] + 1) {
                sx[ro] = mx[ro]; sxid[ro] = mxid[ro];
                mx[ro] = mx[j[u]] + 1; mxid[ro] = mxid[j[u]];
            }
            else if (sx[ro] == -1 || sx[ro] < mx[j[u]] + 1) {
                sx[ro] = mx[j[u]] + 1;
                sxid[ro] = mxid[j[u]];
            }
        }
    }

    if (flag[ro]) {
        if (mx[ro] == -1) {
            mx[ro] = 0;
            mxid[ro] = ro;
        }
        else if (sx[ro] == -1) {
            sx[ro] = 0;
            sxid[ro] = ro;
        }
    }

    if (sx[ro] != -1) {
        if (sx[ro] + mx[ro] > mdis) {
            mdis = sx[ro] + mx[ro];
            ms = sxid[ro]; mt = mxid[ro];
        }
    }
}

void dfs1(int ro, int fa, int dep) {
    if (dep == mdis / 2 && !jc) {
        if (zd == -1) zd = ro;
    }
    if (ro == mt) jc = 1;
    for (int u = fi[ro]; u; u = ne[u]) {
        if (j[u] != fa)
            dfs1(j[u], ro, dep + 1);
    }
    if (dep == mdis / 2 && !jc) zd = -1;
}

void check(int ro, int fa, int dep) {
    if (flag[ro] && dep != mdis / 2) {
        jjc = 0;
        return;
    }
    for (int u = fi[ro]; u; u = ne[u])
        if (j[u] != fa)
            check(j[u], ro, dep + 1);
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf ("%d%d", &x, &y);
        addedge(x, y);
    }
    for (int i = 1; i <= m; ++i) {
        int x;
        scanf ("%d", &x);
        flag[x] = 1;
    }
    if (m == 1) {
        puts("YES");
        printf ("%d\n", 1);
        return 0;
    }
    dfs(1, 0);
    if (mdis % 2 == 1) {
        puts("NO");
        return 0;
    }
    dfs1(ms, 0, 0);
    check(zd, 0, 0);
    if (jjc) {
        puts("YES");
        printf ("%d\n", zd);
    }
    else puts("NO");
    return 0;
}