#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1

const int N = 1e5 + 5;

struct seg {
    int t[N << 4];
    void clean() {
        memset(t, 0, sizeof(t));
    }
    void update(int l, int r, int rt, int pos, int val) {
        if (l == r) {
            t[rt] = max(t[rt], val);
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) update(lson, pos, val);
        else update(rson, pos, val);
        t[rt] = max(t[rt << 1], t[rt << 1 | 1]);
    }
    int query(int l, int r, int rt, int L, int R) {
        if (L <= l && r <= R) return t[rt];
        int mid = (l + r) >> 1;
        if (R <= mid) return query(lson, L, R);
        else if (mid < L) return query(rson, L, R);
        else return max(query(lson, L, R), query(rson, L, R));
    }
}t;

struct cf {
    int st, en;
    friend bool operator < (cf i, cf j) {
        if (i.st == j.st) return i.en < j.en;
        else return i.st < j.st;
    }
}tmp;
struct node {
    cf va, vb;
}a[N], b[N];
int n, len, sor[N << 2];
bool flag = 1;

bool cmp_st1(node i, node j) {
    return i.va.st > j.va.st;
}
bool cmp_en1(node i, node j) {
    return i.va.en > j.va.en;
}
bool cmp_st2(node i, node j) {
    return i.va.en < j.va.en;
}
bool cmp_en2(node i, node j) {
    return i.va.st < j.va.st;
}
void solve() {
    t.clean();
    sort(a + 1, a + n + 1, cmp_st1);
    sort(b + 1, b + n + 1, cmp_en1);
    for (int i = 1, j = 1, x; j <= n; ++j){
        for (; a[i].va.st > b[j].va.en && i <= n; ++i)
            t.update(1, len, 1, a[i].vb.st, a[i].vb.en);
        x = t.query(1, len, 1, 1, b[j].vb.en);
        if (x >= b[j].vb.st) flag = 0;
    }

    t.clean();
    sort(a + 1, a + n + 1, cmp_st2);
    sort(b + 1, b + n + 1, cmp_en2);
    for (int i = 1, j = 1, x; j <= n; ++j){
        for (; a[i].va.en < b[j].va.st && i <= n; ++i)
            t.update(1, len, 1, a[i].vb.st, a[i].vb.en);
        x = t.query(1, len, 1, 1, b[j].vb.en);
        if (x >= b[j].vb.st) flag = 0;
    }
}
int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf ("%d%d%d%d", &a[i].va.st, &a[i].va.en, &a[i].vb.st, &a[i].vb.en);
        sor[++len] = a[i].va.st;
        sor[++len] = a[i].va.en;
        sor[++len] = a[i].vb.st;
        sor[++len] = a[i].vb.en;
    }
    sort(sor + 1, sor + len + 1);
    len = unique(sor + 1, sor + len + 1) - sor;
    for (int i = 1; i <= n; ++i) {
        a[i].va.st = lower_bound(sor + 1, sor + len + 1, a[i].va.st) - sor;
        a[i].va.en = lower_bound(sor + 1, sor + len + 1, a[i].va.en) - sor;
        a[i].vb.st = lower_bound(sor + 1, sor + len + 1, a[i].vb.st) - sor;
        a[i].vb.en = lower_bound(sor + 1, sor + len + 1, a[i].vb.en) - sor;
        b[i] = a[i];
    }
    solve();
    for (int i = 1; i <= n; ++i) {
        tmp = a[i].va; a[i].va = a[i].vb; a[i].vb = tmp;
        b[i] = a[i];
    }
    solve();
    puts (flag ? "YES" : "NO");
    return 0;
}