#include <bits/stdc++.h>
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
using namespace std;

inline int I() {
    int s = 0; char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9'){s = s * 10 + ch - '0'; ch = getchar();}
    return s;
}

const int N = 1e6 + 5;
int n, k, root, x, y;
int t[N << 2], fa[N], val[N];
int fi[N], ne[N], j[N], step;
long long ans;

void addedge(int fr, int to) {
    j[++step] = to; ne[step] = fi[fr]; fi[fr] = step;
}
void get_root() {
    for (root = 1; fa[root]; root = fa[root]);
}
void update(int l, int r, int rt, int wz, int key) {
    if (l == r) {
        t[rt] = key;
        return;
    }
    int mid = (l + r) >> 1;
    if (wz <= mid) update(lson, wz, key);
    else update(rson, wz, key);
    t[rt] = t[rt << 1] | t[rt << 1 | 1];
}
int query (int l, int r, int rt, int val) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if ((t[rt << 1 | 1] | val) >= k) return query(rson, val);
    else return query(lson, val | t[rt << 1 | 1]);
}
void solve(int ro, int dep) {
    update(1, n, 1, dep, val[ro]);
    if (t[1] >= k) ans += query(1, n, 1, 0);
    for (int u = fi[ro]; u; u = ne[u])
        solve(j[u], dep + 1);
    update(1, n, 1, dep, 0);
}
int main () {
    n = I(); k = I();
    for (int i = 1; i <= n; ++i) val[i] = I();
    for (int i = 1; i < n; ++i) {
        x = I(); y = I();
        fa[y] = x;
        addedge(x, y);
    }
    get_root();
    solve(root, 1);
    printf ("%lld\n", ans);
    return 0;
}