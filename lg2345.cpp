#include <bits/stdc++.h>
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
using namespace std;

const int N = 1e5 + 5;

struct SegTree {
    long long t[N << 2];
    SegTree() {
        memset(t, 0, sizeof(t));
    }
    void update(int l, int r, int rt, int key, int val) {
        if (l == r) {
            t[rt] += val;
            return;
        }
        int mid = (l + r) >> 1;
        if (key <= mid) update(lson, key, val);
        else update(rson, key, val);
        t[rt] = t[rt << 1] + t[rt << 1 | 1];
    }
    long long query(int l, int r, int rt, int L, int R) {
        if (L <= l && r <= R) return t[rt];
        int mid = (l + r) >> 1;
        long long sum = 0;
        if (L <= mid) sum = query(lson, L, R);
        if (mid < R) sum += query(rson, L, R);
        return sum;
    }
}val, num;

struct node {
    int x, v;
    friend bool operator < (node i, node j) {
        return i.v < j.v;
    }
}a[N];

int n, maxn;
long long ans;

int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf ("%d%d", &a[i].v, &a[i].x);
        maxn = max(maxn, a[i].x);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        long long t1, t2, t3, t4;
        t1 = val.query(1, maxn, 1, 1, a[i].x); t2 = val.t[1] - t1;
        t3 = num.query(1, maxn, 1, 1, a[i].x); t4 = num.t[1] - t3;
        ans += (a[i].x * t3 - t1) * a[i].v + (t2 - a[i].x * t4) * a[i].v;
        val.update(1, maxn, 1, a[i].x, a[i].x);
        num.update(1, maxn, 1, a[i].x, 1);
    }
    printf ("%lld\n", ans);
    return 0;
}