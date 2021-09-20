#include <bits/stdc++.h>
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
using namespace std;

const int N = 1e5 + 5;
int k, n, x, y;
int tr[N << 2];
int ans[N];

int queryR(int l, int r, int rt, int pos, int val) {
    if (l == r) {
        if (val >= tr[rt]) return l;
        else return -1;
    }
    int mid = (l + r) >> 1;
    if (pos > mid) return queryR(rson, pos, val);
    else {
        int tmp = -1;
        if (tr[rt << 1] <= val)
            tmp = queryR(lson, pos, val);
        if (tmp != -1) return tmp;
        else {
            if (tr[rt << 1 | 1] <= val)
                return queryR(rson, pos, val);
            else return -1;
        }
    }
}

int queryL(int l, int r, int rt, int pos, int val) {
    if (l == r) {
        if (val >= tr[rt]) return l;
        else return -1;
    }
    int mid = (l + r) >> 1;

    int tmp = -1;
    if (tr[rt << 1] <= val)
        tmp = queryL(lson, pos, val);
    if (tmp != -1) return tmp;
    else {
        if (pos <= mid) return -1;
        if (tr[rt << 1 | 1] <= val)
            return queryL(rson, pos, val);
        else return -1;
    }
}

void update(int l, int r, int rt, int pos, int val) {
    if (l == r) {
        tr[rt] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) update(lson, pos, val);
    else update(rson, pos, val);
    tr[rt] = min(tr[rt << 1], tr[rt << 1 | 1]);
}

int main () {
    scanf ("%d%d", &k, &n);
    for (int i = 0; i < n; ++i) {
        scanf ("%d%d", &x, &y);
        if (tr[1] > x) continue;
        int pos = queryR(0, k - 1, 1, i % k, x);
        if (pos == -1 && i % n - 1 >= 0) pos = queryL(0, k - 1, 1, i % k - 1, x);
        ans[pos] ++;
        update(0, k - 1, 1, pos, x + y);
    }
    int maxn = ans[0];
    // for (int i = 0; i < k; ++i) {
        // cout <<ans[i] <<"  ";
    // }
    for (int i = 1; i < k; ++i)
        maxn = max(ans[i], maxn);
    bool flag = false;
    for (int i = 0; i < k; ++i) {
        if (ans[i] == maxn) {
            if (flag == true) {
                printf (" ");
            }
            flag = true;
            printf ("%d", i);
        }
    }
    puts("");
    return 0;
}