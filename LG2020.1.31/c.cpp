#include <bits/stdc++.h>
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
using namespace std;

const int N = 1e6 + 5;
const int mod = 1e9 + 7;
int a[N], n, ans = 1, t[N << 2];
bool flag;

int I(){
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

void update(int l, int r, int rt, int key) {
    if (l == r) {
        t[rt]++;
        return;
    }
    int mid = (l + r) >> 1;
    if (key <= mid) update(lson, key);
    else update(rson, key);
    t[rt]++;
}

int query(int l, int r, int rt, int key) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (mid - l + 1 - t[rt << 1] >= key) return query(lson, key);
    else return query(rson, key - (mid - l - t[rt << 1] + 1));
}

void solve() {
    int id;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > n - i) return;
        id =  query(1, n, 1, a[i] + 1);
        a[i] = id;
        update(1, n, 1, a[i]);
    }
    flag = 1;
}

int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf ("%d", &a[i]);
        if (a[i] == -1) {
            a[i] = 0;
            ans = 1ll * ans * (n - i + 1) %mod;
        }
    }
    solve();
    if (flag) {
        printf ("%d\n", ans);
        for (int i = 1; i <= n; ++i)
            printf ("%d ", a[i]);
    }
    else puts("0");
    return 0;
}