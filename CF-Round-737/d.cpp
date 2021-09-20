#include <bits/stdc++.h>
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
using namespace std;

const int N = 3e5 + 5;
struct node {
    int l, r;
    node(){}
    node(int _l, int _r) {
        l = _l; r = _r;
    }
};
vector <node> a[N];
int sor[N * 2], len;
int n, m;

pair <int, int> t[N * 2 * 4];
pair <int, int> c[N * 2 * 4];
int lst[N];
bool flag[N];

void pushdown(int rt) {
    if (c[rt].second == 0) return;
    int ls = rt << 1;
    int rs = rt << 1 | 1;
    int val = c[rt].first;
    int id = c[rt].second;

    if (t[ls].first < val) {
        t[ls].first = val;
        t[ls].second = id;
    }
    c[ls].first = val;
    c[ls].second = id;

    if (t[rs].first < val) {
        t[rs].first = val;
        t[rs].second = id;
    }
    c[rs].first = val;
    c[rs].second = id;

    c[rt].first = 0;
    c[rt].second = 0;
}

pair <int, int> pushup(pair <int, int> ls, pair <int, int> rs) {
    if (ls.first > rs.first) return ls;
    else return rs;
}

void update(int l, int r, int rt, int L, int R, int id, int val) {
    if (L <= l && r <= R) {
        if (t[rt].first < val) {
            t[rt].first = val;
            t[rt].second = id;
        }
        c[rt].first = val;
        c[rt].second = id;
        return;
    }
    pushdown(rt);
    int mid = (l + r) >> 1;
    if (L <= mid) update(lson, L, R, id, val);
    if (mid < R) update(rson, L, R, id, val);
    t[rt] = pushup(t[rt << 1], t[rt << 1 | 1]);
}

pair <int, int> query(int l, int r, int rt, int L, int R) {
    if (L <= l && r <= R) return t[rt];
    pushdown(rt);
    int mid = (l + r) >> 1;
    if (R <= mid) return query(lson, L, R);
    else if (mid < L) return query(rson, L, R);
    else return pushup(query(lson, L, R), query(rson, L, R));
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int x, y, z;
        scanf ("%d%d%d", &x, &y, &z);
        a[x].push_back(node(y, z));
        sor[++len] = y;
        sor[++len] = z;
    }
    sort(sor + 1, sor + len + 1);
    len = unique(sor + 1, sor + len + 1) - sor - 1;
    for (int i = 1; i <= n; ++i) {
        int p = a[i].size();
        for (int j = 0; j < p; ++j) {
            a[i][j].l = lower_bound(sor + 1, sor + len + 1, a[i][j].l) - sor;
            a[i][j].r = lower_bound(sor + 1, sor + len + 1, a[i][j].r) - sor;
        }
    }
    int ans = 0;
    int st = -1;
    for (int i = 1; i <= n; ++i) {
        int p = a[i].size();
        pair <int, int> maxn = make_pair(0, 0);
        for (int j = 0; j < p; ++j) {
            pair <int, int> tmp = query(1, len, 1, a[i][j].l, a[i][j].r);
            if (tmp.first >= maxn.first) maxn = tmp; 
        }
        if (maxn.first + 1 > ans) {
            ans = maxn.first + 1;
            st = i;
        }
        lst[i] = maxn.second;
        for (int j = 0; j < p; ++j) {
            update(1, len, 1, a[i][j].l, a[i][j].r, i, maxn.first + 1);
        }
    }
    while (st != 0) {
        flag[st] = 1;
        st = lst[st];
    }
    printf ("%d\n", n - ans);
    for (int i = 1; i <= n; ++i) {
        if (!flag[i]) printf ("%d ", i);
    }
    return 0;
}