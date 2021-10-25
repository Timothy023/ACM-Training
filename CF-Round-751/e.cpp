#include <bits/stdc++.h>
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
using namespace std;

const int N = 2e6 + 5;
const int inf = 1e9;

int T;
int n, m, ln, st;
long long ans;
int a[N], b[N], sor[N];
vector <int> p[N];

int s[N << 2];
pair <int, int> tr[N << 2];
int col[N << 2];

void pushup(int rt) {
    tr[rt] = min(tr[rt << 1], tr[rt << 1 | 1]);
    s[rt] = s[rt << 1] + s[rt << 1 | 1];
}

void pushdown(int rt) {
    int ls = rt << 1;
    int rs = rt << 1 | 1;
    tr[ls] = make_pair(tr[ls].first + col[rt], tr[ls].second);
    tr[rs] = make_pair(tr[rs].first + col[rt], tr[rs].second);
    col[ls] += col[rt];
    col[rs] += col[rt];
    col[rt] = 0;
}

void build(int l, int r, int rt) {
    col[rt] = 0;
    if (l == r) {
        if (l == 0) {
            tr[rt] = make_pair(0, 0);
        }
        else {
            tr[rt] = make_pair(inf, l);
        }
        s[rt] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}

void update(int l, int r, int rt, int pos, int val) {
    // cout <<"update: " <<l <<"  " <<r <<"  " <<pos <<"  " <<val <<endl;
    if (l == r) {
        tr[rt] = make_pair(val, l);
        s[rt] = 1;
        return;
    }
    pushdown(rt);
    int mid = (l + r) >> 1;
    if (pos <= mid) update(lson, pos, val);
    else update(rson, pos, val);
    pushup(rt);
}

int qs(int l, int r, int rt, int L, int R) {
    if (L > R) return 0;
    if (L <= l && r <= R) return s[rt];
    pushdown(rt);
    int mid = (l + r) >> 1;
    if (R <= mid) return qs(lson, L, R);
    else if (mid < L) return qs(rson, L, R);
    else return qs(lson, L, R) + qs(rson, L, R);
}

void change(int l, int r, int rt, int L, int R, int delta) {
    // cout <<"change: " <<l <<"  " <<r <<"  " <<L <<"  " <<R <<"  " <<delta <<"  " <<tr[rt].first <<"  " <<tr[rt].second <<endl;
    if (L > R) return;
    if (L <= l && r <= R) {
        tr[rt] = make_pair(tr[rt].first + delta, tr[rt].second);
        col[rt] += delta;
        return;
    }
    pushdown(rt);
    int mid = (l + r) >> 1;
    if (L <= mid) change(lson, L, R, delta);
    if (mid < R)  change(rson, L, R, delta);
    pushup(rt);
}

pair <int, int> query(int l, int r, int rt, int L, int R) {
    if (L > R) return make_pair(0, 0);
    if (L <= l && r <= R) return tr[rt];
    pushdown(rt);
    int mid = (l + r) >> 1;
    if (R <= mid) return query(lson, L, R);
    else if (mid < L) return query(rson, L, R);
    else return min(query(lson, L, R), query(rson, L, R));
}

void insert(int v) {
    while (st <= ln && st <= v) {
        int sz = p[st].size();
        for (int j = 0; j < sz; ++j) {
            change(0, n, 1, p[st][j] + 1, n, -1);
            if (st < v) {
                change(0, n, 1, 0, p[st][j] - 1,  1);
                int valaf = qs(0, n, 1, p[st][j] + 1, n);
                int valbe = qs(0, n, 1, 0, p[st][j] - 1);
                int valal = valaf + p[st][j] - 1 - valbe;
                update(0, n, 1, p[st][j], valal);
                ans += valaf;
            }
        }
        st += 1;
    }
}

int I() {
    int s = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s;
}

int main () {
    // scanf ("%d", &T);
    T = I();
    while (T--) {
        ln = 0;
        // scanf ("%d%d", &n, &m);
        n = I(); m = I();
        build(0, n, 1);
        for (int i = 1; i <= n; ++i) {
            // scanf ("%d", &a[i]);
            a[i] = I();
            sor[++ln] = a[i];
        }
        for (int i = 1; i <= m; ++i) {
            // scanf ("%d", &b[i]);
            b[i] = I();
            sor[++ln] = b[i];
        }
        sort(sor + 1, sor + ln + 1);
        ln = unique(sor + 1, sor + ln + 1) - sor - 1;
        for (int i = 1; i <= n; ++i) {
            a[i] = lower_bound(sor + 1, sor + ln + 1, a[i]) - sor;
            p[a[i]].push_back(i);
        }
        for (int i = 1; i <= m; ++i) {
            b[i] = lower_bound(sor + 1, sor + ln + 1, b[i]) - sor;
        }
        sort(b + 1, b + m + 1);
        st = 1;
        ans = 0;
        for (int i = 1; i <= m; ++i) {
            insert(b[i]);
            ans += tr[1].first;
            while (b[i] == b[i + 1] && i < m) {
                ans += tr[1].first;
                i += 1;
            }
            // cout <<tr[1].first <<"  " <<tr[1].second <<endl;
            if (st - 1 == b[i]) {
                int sz = p[b[i]].size();
                for (int j = 0; j < sz; ++j) {
                    change(0, n, 1, 0, p[b[i]][j] - 1,  1);
                    int valaf = qs(0, n, 1, p[b[i]][j] + 1, n);
                    int valbe = qs(0, n, 1, 0, p[b[i]][j] - 1);
                    int valal = valaf + p[b[i]][j] - 1 - valbe;
                    update(0, n, 1, p[b[i]][j], valal);
                    ans += valaf;
                }
            }
        }
        insert(ln + 1);
        for (int i = 1; i <= ln; ++i) p[i].clear();
        printf ("%I64d\n", ans);
    }
    return 0;
}