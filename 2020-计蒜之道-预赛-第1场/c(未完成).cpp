#include <bits/stdc++.h>
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
using namespace std;

const int N = 3e5 + 5;
int n, m, b[N], w[N], a[N];
long long ans, s[3][N], sa[N], f[N];
long long t[N << 2];

struct node{
    long long t, l, r, c;
    friend bool operator < (node i, node j) {
        if (i.r == j.r) return i.l > j.l;
        else return i.r < j.r;
    }
}q[N];



long long query(int l, int r, int rt, int L, int R) {
    if (L > R) return 0;
    if (L <= l && r <= R) return t[rt];
    int mid = (l + r) >> 1;
    if (R <= mid) return query(lson, L, R);
    else if (L > mid) return query(rson, L, R);
    else return max(query(lson, L, R), query(rson, L, R));
}

void update(int l, int r, int rt, int key, long long val) {
    if (l == r) {
        t[rt] = max(t[rt], val);
        return;
    }
    int mid = (l + r) >> 1;
    if (key <= mid) update(lson, key, val);
    else update(rson, key, val);
    t[rt] = min(t[rt << 1], t[rt << 1 | 1]);
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf ("%d", &b[i]);
        s[1][i] = s[1][i - 1] + b[i];
    }
    for (int i = 1; i <= n; ++i) {
        scanf ("%d", &w[i]);
        s[2][i] = s[2][i - 1] + w[i];
    }
    for (int i = 1; i <= n; ++i) {
        a[i] = max(b[i], w[i]);
        sa[i] = sa[i - 1] + a[i];
    }
    for (int i = 1; i <= m; ++i) {
        scanf ("%d%d%d%d", &q[i].t, &q[i].l ,&q[i].r, &q[i].c);
    }
    ans = sa[n];
    sort(q + 1, q + m + 1);
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j < i; ++j) {
            if (q[i].t != q[j].t) continue;
            if (q[i].l <= q[j].l && q[j].r <= q[i].r) q[i].c += q[j].c;
        }
    }
    for (int i = 1; i <= m; ++i) {
        long long tmp = (s[q[i].t][q[i].r] - s[q[i].t][q[i].l - 1]) - (sa[q[i].r] - sa[q[i].l - 1]) + q[i].c;
        for (int j = 1; j < i ; ++j) {
            if (q[i].l <= q[j].l && q[j].r <= q[i].r) continue;
            if (q[i].t == q[j].t) {
                if (q[i].l > q[j].r) {
                    tmp = max(tmp, f[j] + (s[q[i].t][q[i].r] - s[q[i].t][q[i].l - 1]) - (sa[q[i].r] - sa[q[i].l - 1]) + q[i].c);
                }
                else {
                    tmp = max(tmp, f[j] + (s[q[i].t][q[i].r] - s[q[i].t][q[j].r]) - (sa[q[i].r] - sa[q[j].r]) + q[i].c);
                }
            }
            else {
                if (q[i].l > q[j].r) {
                    tmp = max(tmp, f[j] + (s[q[i].t][q[i].r] - s[q[i].t][q[i].l - 1]) - (sa[q[i].r] - sa[q[i].l - 1]) + q[i].c);
                }
                else continue;
            }
        }
        f[i] = tmp;
        ans = max(ans, sa[n] + tmp);
    }
    cout <<ans <<endl;
    return 0;
}