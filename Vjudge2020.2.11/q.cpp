#include <bits/stdc++.h>
using namespace std;

long long I() {
    long long s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

const int N = 2e5 + 5;
const int M = 2e7 + 5;
int n, q, y, z;
long long a[N], maxn, x;
int root[N], t[M], ls[M], rs[M], cnt;

void build(int r1, int &r2, long long l, long long r, long long val, int key) {
    r2 = ++cnt;
    t[r2] = key;
    ls[r2] = ls[r1];
    rs[r2] = rs[r1];
    if (l == r) return;
    long long mid = (l + r) >> 1;
    if (val <= mid) build(ls[r1], ls[r2], l, mid, val, key);
    else build(rs[r1], rs[r2], mid + 1, r, val, key);
}

int query(int rt, long long l, long long r, long long val) {
    if (!rt) return n + 1;
    if (l == r) return t[rt];
    long long mid = (l + r) >> 1;
    if (val <= mid) return query(ls[rt], l, mid, val);
    else {
        int tmp = query(rs[rt], mid + 1, r, val);
        if (ls[rt]) tmp = min(tmp, t[ls[rt]]);
        return tmp;
    }
}

int main () {
    n = I(); q = I();
    for (int i = 1; i <= n; ++i) {
        a[i] = I();
        maxn = max(maxn, a[i]);
    }
    build(0, root[n + 1], 0, maxn, 0, n + 1);
    for (int i = n; i >= 1; --i) {
        build(root[i + 1], root[i], 0, maxn, a[i], i);
    }
    for (int i = 1; i <= q; ++i) {
        x = I(); y = I(); z = I();
        for (int wz; ;) {
            wz = query(root[y], 0, maxn, x);
            if (wz > z) break;
            x %= a[wz];
            y = wz + 1;;
        }
        printf ("%lld\n", x);
    }
    return 0;
}
