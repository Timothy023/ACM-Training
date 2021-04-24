#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9'){ if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9'){ s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

const int kq = 321;
const int N = 1e5 + 5;
int n, m, a[N], sor[N], len, ans[N];
int sum[N];

struct node {
    int l, r, t, id;
    friend bool operator < (node i, node j) {
        if (i.l / kq == j.l / kq) return i.r < j.r;
        else return i.l / kq < j.l / kq;
    }
}q[N];

void test(int l, int r, int t, int id) {
    int le = r - l + 1, ta = -1;
    for (int i = 1; i <= 300; ++i) {
        int x = l + rand() % le;
        if (sum[a[x]] * t > le) ta = max(ta, sor[a[x]]);
    }
    ans[id] = ta;
}

int main () {
    n = I(); m = I();
    // scanf ("%d%d", &n ,&m);
    for (int i = 1; i <= n; ++i) {
        a[i] = I();
        // scanf ("%d", &a[i]);
        sor[i] = a[i];
    }
    len = n;
    sort(sor + 1, sor + n + 1);
    len = unique (sor + 1, sor + n + 1) - sor - 1;
    for (int i = 1; i <= n; ++i) {
        a[i] = lower_bound(sor + 1, sor + len + 1, a[i]) - sor;
    }

    for (int i = 1; i <= m; ++i) {
        q[i].l = I(); q[i].r = I(); q[i].t = I();
        // scanf ("%d%d%d", &q[i].l, &q[i].r, &q[i].t);
        q[i].id = i;
    }
    sort(q + 1, q + m + 1);

    int l = 1, r = 0;
    for (int i = 1; i <= m; ++i) {
        while (l < q[i].l) {
            sum[a[l]] -= 1;
            l += 1;
        }
        while (l > q[i].l) {
            l -= 1;
            sum[a[l]] += 1;
        }
        while (r < q[i].r) {
            r += 1;
            sum[a[r]] += 1;
        }
        while (r > q[i].r) {
            sum[a[r]] -= 1;
            r -= 1;
        }
        test(q[i].l, q[i].r, q[i].t, q[i].id);
    }
    for (int i = 1; i <= m; ++i)
        printf ("%d\n", ans[i]);
    return 0;
}