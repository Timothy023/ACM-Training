#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int M = 5e5 + 5;
const int mod = 80112002;

int n, m, du[N], f[N], rd[N];
int fi[N], ne[M], to[M], step;
queue <int> q;

void addedge(int x, int y) {
    step += 1;
    ne[step] = fi[x]; fi[x] = step;
    to[step] = y; rd[x]++; du[y]++;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int x, y;
        scanf ("%d%d", &x, &y);
        addedge(x, y);
    }
    for (int i = 1; i <= n; ++i) {
        if (du[i] == 0) {
            q.push(i);
            f[i] = 1;
        }
    }
    while (!q.empty()) {
        int now = q.front(); q.pop();
        for (int u = fi[now]; u; u = ne[u]) {
            du[to[u]]--;
            f[to[u]] = (f[to[u]] + f[now]) % mod;
            if (du[to[u]] == 0) {
                q.push(to[u]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (rd[i] == 0) {
            ans = (ans + f[i]) % mod;
        }
    }
    printf ("%d\n", ans);
    return 0;
}