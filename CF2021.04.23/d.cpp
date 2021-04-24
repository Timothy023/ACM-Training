#include <bits/stdc++.h>
using namespace std;

const int N = 500 * 500;
const int M = 4 * N;

int fi[N], nxt[M], to[M], k[M], step;

void addedge(int fr, int t, int c) {
    to[++step] = t ; nxt[step] = fi[fr]; fi[fr] = step; k[step] = c;
    to[++step] = fr; nxt[step] = fi[t ]; fi[t ] = step; k[step] = c;
}

int dis[N][25];
int n, m, t;
int ans[505][505];

int main () {
    scanf ("%d%d%d", &n, &m, &t);
    memset(fi, -1, sizeof(fi));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m - 1;++j) {
            int x;
            scanf ("%d", &x);
            addedge(i * m + j, i * m + j + 1, x);
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m;++j) {
            int x;
            scanf ("%d", &x);
            addedge(i * m + j, (i + 1) * m + j, x);
        }
    }
    if (t % 2 == 1) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                printf ("-1 ");
            }
            printf ("\n");
        }
        return 0;
    }
    memset(dis, 100, sizeof(dis));
    for (int step = 0; step < t / 2; ++step) {
        for (int i = 0; i < n * m; ++i) {
            if (step == 0) dis[i][0] = 0;
            for (int u = fi[i]; u != -1; u = nxt[u]) {
                dis[to[u]][step + 1] = min(dis[to[u]][step + 1], dis[i][step] + 2 * k[u]);
            }
        }
    }
    for (int i = 0; i < n * m; ++i) {
        ans[i / m][i % m] = dis[i][t / 2];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            printf ("%d ", ans[i][j]);
        printf ("\n");
    }
    return 0;
}