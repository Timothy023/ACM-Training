#include <bits/stdc++.h>
#define st (n1 * 2 + n2 + n3 + 1)
#define en (n1 * 2 + n2 + n3 + 2)
using namespace std;

const int N = 1e4 + 5;
const int inf = 2147483647;
int n1, n2, n3, m, x, y, sum;
int fi[N * 10], nxt[N * 20], to[N * 20], k[N * 20], step = 1;
int cur[N * 10], hs[N * 10], h[N * 10], ans;

void addedge(int f, int t, int c) {
    step += 1; to[step] = t; k[step] = c;
    nxt[step] = fi[f]; fi[f] = step;

    step += 1; to[step] = f; k[step] = 0;
    nxt[step] = fi[t]; fi[t] = step;
}

int isap(int ro, int flow) {
    if (ro == en) return flow;
    int s = 0;
    for (int u = cur[ro]; u; u = nxt[u]) {
        if (h[ro] > h[to[u]] && k[u] > 0) {
            int flag = isap(to[u], min(flow - s, k[u]));
            s += flag;
            k[u] -= flag;
            k[u ^ 1] += flag;
            cur[ro] = u;
            if (s == flow) return s;
        }
    }
    if (!(--hs[h[ro]])) h[st] = sum + 1;
    hs[(++h[ro])]++;
    return s;
}

int main () {
    scanf ("%d%d%d", &n1, &n2, &n3);
    sum = en + 1;
    for (int i = 1; i <= n1; ++i) addedge(n2 + n3 + i, n1 + n2 + n3 + i, 1);
    for (int i = 1; i <= n2; ++i) addedge(st, i, 1);
    for (int i = 1; i <= n3; ++i) addedge(n2 + i, en, 1);
    scanf ("%d", &m);
    for (int i = 1; i <= m; ++i) {
        scanf ("%d%d", &x, &y);
        addedge(y, n2 + n3 + x, 1);
    }
    scanf ("%d", &m);
    for (int i = 1; i <= m; ++i) {
        scanf ("%d%d", &x, &y);
        addedge(n2 + n3 + x, y, 1);
    }
    hs[0] = sum;
    while (h[st] < sum) {
        for (int i = 1; i <= en; ++i) cur[i] = fi[i];
        ans += isap(st, inf);
    }
    printf ("%d\n", ans);
    return 0;
}