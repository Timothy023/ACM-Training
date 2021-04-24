#include <bits/stdc++.h>
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
using namespace std;

long long I() {
    long long s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

const int N = 2e5 + 5;
struct node {
    long long l, r;
    friend bool operator < (node i, node j) {
        return i.r < j.r;
    }
}q[N];
long long n;
int k;
long long t[N << 2];

void update(int l, int r, int rt, int wz, long long val) {
    if (l == r) {
        t[rt] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (wz <= mid) update(lson, wz, val);
    else update(rson, wz, val);
    t[rt] = max(t[rt << 1], t[rt << 1 | 1]);
}

long long query(int l, int r, int rt, int wz) {
    if (r <= wz) return t[rt];
    int mid = (l + r) >> 1;
    if (mid < wz) return max(t[rt << 1], query(rson, wz));
    else return query(lson, wz);
}
int f(int l, int r, long long val) {
    int ans = 0, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (q[mid].r < val) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return ans;
}
int main () {
    n = I(); k = I();
    for (int i = 1; i <= k; ++i) {
        q[i].l = I(); q[i].r = I();
    }
    sort(q + 1, q + k + 1);
    q[0].l = 0; q[0].r = 0;
    for (int i = 1; i <= k; ++i) {
        int wz = f(0, i - 1, q[i].l);
        long long x = query(0, k, 1, wz);
        x += q[i].r - q[i].l + 1;
        update(0, k, 1, i, x);
    }
    cout <<n - t[1] <<endl;
    return 0;
}