#include <bits/stdc++.h>
using namespace std;

const int mod = 1e8 - 3;
const int N = 1e5 + 5;
int n, ans, a[N], b[N], sa[N], sb[N], c[N], tmp[N];

void solve(int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    solve(l, mid); solve(mid + 1, r);
    int i = l, j = mid + 1, len = l;
    for (; i <= mid && j <= r;) {
        if (a[i] < a[j]) tmp[len++] = a[i++];
        else {
            ans = (ans + mid - i + 1) % mod;
            tmp[len++] = a[j++];
        }
    }
    while (i <= mid) tmp[len++] = a[i++];
    while (j <= r) tmp[len++] = a[j++];
    for (int p = l; p <= r; ++p) a[p] = tmp[p];
}

int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf ("%d", &a[i]);
        sa[i] = a[i];
    }
    for (int i = 1; i <= n; ++i) {
        scanf ("%d", &b[i]);
        sb[i] = b[i];
    }
    sort(sa + 1, sa + n + 1);
    sort(sb + 1, sb + n + 1);
    for (int i = 1; i <= n; ++i) {
        a[i] = lower_bound(sa + 1, sa + n + 1, a[i]) - sa;
        b[i] = lower_bound(sb + 1, sb + n + 1, b[i]) - sb;
    }
    for (int i = 1; i <= n; ++i) c[b[i]] = i;
    for (int i = 1; i <= n; ++i) a[i] = c[a[i]];

    solve(1, n);
    printf ("%d\n", ans);
    return 0;
}