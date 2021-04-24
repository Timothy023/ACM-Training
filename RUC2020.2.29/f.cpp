#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

const int N = 2e5 + 5;

struct node{
    int t, h;
    friend bool operator < (node i, node j) {
        if (i.t == j.t) return i.h > j.h;
        else return i.t < j.t;
    }
}q[N];
int n, maxn;


int root = 1;

struct seg_tree {
    int ls[N * 30], rs[N * 30], t[N * 30], t1[N * 30], id[N * 30], cnt, inf;
    seg_tree() { 
        cnt += 1;
        memset(t1, 127,sizeof(t1));
        inf = t1[0];
    }
    int query(int l, int r, int ro, int L, int R) {
        if (!ro) return 0;
        if (L <= l && r <= R) return t[ro];
        int mid = (l + r) >> 1, sum = 0;
        if (L <= mid) sum += query(l, mid, ls[ro], L, R);
        if (R > mid) sum += query(mid + 1, r, rs[ro], L, R);
        return sum;
    }
    void clear(int l, int r, int rt, int L, int R) {
        if (!t[rt] || !rt) return;
        if (l == r) {
            t[rt] = 0; t1[rt] = inf;
            return;
        }
        int mid = (l + r) >> 1;
        if (L <= mid) clear(l, mid, ls[rt], L, R);
        if (mid < R) clear(mid + 1, r, rs[rt], L, R);
        t[rt] = t[ls[rt]] + t[rs[rt]];

        if (t1[ls[rt]] == inf) t1[rt] = t1[rs[rt]];
        else if (t1[rs[rt]] == inf) t1[rt] = t1[ls[rt]];
        else {
            if (id[t1[ls[rt]]] < id[t1[rs[rt]]]) t1[rt] = t1[ls[rt]];
            else t1[rt] = t1[rs[rt]];
        }
    }
    void update(int l, int r, int &ro, int wz, int val) {
        if (!ro) ro = ++cnt;
        if (l == r) {
            t[ro] = val;
            t1[ro] = ro;
            id[ro] = l;
            return;
        }
        int mid = (l + r) >> 1;
        if (wz <= mid) update(l, mid, ls[ro], wz, val);
        else update(mid + 1, r, rs[ro], wz, val);
        t[ro] = t[ls[ro]] + t[rs[ro]];

        if (t1[ls[ro]] == inf) t1[ro] = t1[rs[ro]];
        else if (t1[rs[ro]] == inf) t1[ro] = t1[ls[ro]];
        else {
            if (id[t1[ls[ro]]] < id[t1[rs[ro]]]) t1[ro] = t1[ls[ro]];
            else t1[ro] = t1[rs[ro]];
        }
    }
    int find(int l, int r, int rt, int L, int R) {
        if (L > R) return inf;
        if (L <= l && r <= R) return t1[rt];
        int mid = (l + r) >> 1;
        if (R <= mid) return find(l, mid, ls[rt], L, R);
        else if (mid < L) return find(mid + 1, r, rs[rt], L, R);
        else {
            int p1 = find(mid + 1, r, rs[rt], L, R);
            int p2 = find(l, mid, ls[rt], L, R);
            if (p1 == inf) return p2;
            else if (p2 == inf) return p1;
            else {
                if (id[p1] < id[p2]) return p1;
                else return p2;
            }
        }
    }
}t;

int ans;

int main () {
#ifdef debug
    freopen ("test.in", "r", stdin);
    freopen ("test.out", "w", stdout);
#endif
    n = I();
    for (int i = 1; i <= n; ++i) {
        q[i].t = I(); q[i].h = I();
        maxn = max(maxn, q[i].h);
    }
    sort(q + 1, q + n + 1);
    for (int i = 1; i <= n; ++i) {
        int tmp = t.query(1, maxn, root, 1, q[i].h);
        int t1 = t.find(1, maxn, root, q[i].h + 1, maxn);

        // cout <<q[i].t <<"  " <<q[i].h <<"  " <<tmp <<"  " <<t1 <<endl;
        // if (t1 != t.inf) cout <<t.id[t1] <<"  " <<t.t[t1] <<endl;

        if (t1 != t.inf) q[i].h = min(q[i].h, t.id[t1] - t.t[t1]);
        if (tmp + q[i].t <= q[i].h) {
            ans++;
            while (1) {
                tmp = t.query(1, maxn, root, q[i].h - q[i].t + 1, q[i].h);
                if (!tmp) break;
                t.clear(1, maxn, root, q[i].h - q[i].t + 1, q[i].h);
                q[i].t += tmp;
            }
            // cout <<"update: " <<q[i].h <<"  " <<q[i].t <<endl;
            t.update(1, maxn, root, q[i].h, q[i].t);
        }
    }
    printf ("%d\n", ans);
    return 0;
}