#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m;
long long a[N];
long long x, y, sum;

int find(long long x) {
    int l = 1, r = n, ans = n + 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (a[mid] < x) l = mid + 1;
        else {
            ans = mid;
            r = mid - 1;
        }
    }
    return ans;
}

int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf ("%I64d", &a[i]);
        sum += a[i];
    }
    sort(a + 1, a + n + 1);
    scanf ("%d", &m);
    for (int i = 1; i <= m; ++i) {
        scanf ("%I64d%I64d", &x, &y);
        int p = find(x);
        long long ans = -1;
        if (p != n + 1) ans = max(0ll, y - (sum - a[p])) + max(0ll, x - a[p]);
        p -= 1;
        if (p != 0) {
            long long tmp = max(0ll, y - (sum - a[p])) + max(0ll, x - a[p]);
            if (ans == -1) ans = tmp;
            else ans = min(ans, tmp);
        }
        printf ("%I64d\n", ans);
    }
    return 0;
}