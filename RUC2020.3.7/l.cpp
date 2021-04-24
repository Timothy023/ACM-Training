#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

const int N = 3e5 + 5;
int T;
int n, m, a[N];
long long sum[N], ans, s;

inline bool cmp (int i, int j) {
    return i > j;
}

inline bool check(long long k) {
    int l = 1, r = m, wz = m + 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (a[mid] < k) {
            wz = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    if (s < 1ll * k * (m - wz + 1) - (sum[m] - sum[wz - 1])) return false;
    else return true;
}

int main () {
    T = I();
    while (T--) {
        n = I(); m = I();
        for (int i = 1; i <= n; ++i) a[i] = I();
        if (n < m) {
            puts("0");
            continue;
        }
        sort(a + 1, a + n, cmp);
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + a[i];
        }
        s = sum[n] - sum[m];
        ans = 0;
        long long l = 1, r = sum[n];
        while (l <= r) {
            long long mid = (l + r) >> 1;
            if (check(mid)) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        printf ("%lld\n", ans);
    }
    return 0;
}