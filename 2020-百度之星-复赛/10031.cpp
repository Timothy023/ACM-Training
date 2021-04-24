#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, l, k;
int a[N];

long long solve_max() {
    int p = n - k + 1;
    int dl = l - k;
    long long tmp = a[1] * 2;
    for (int i = l + 1; i <= n; ) {
        for (int j = 1; i <= n && j <= dl; ++j) {
            tmp += a[p];
            ++i;
        }
        for (int j = 1; i <= n && j <= k; ++j) {
            p -= 1;
            tmp += a[p];
            ++i;
        }
    }
    return tmp + a[n - k + 1] - a[1] * 2;
}

long long solve_min() {
    int p = l - k + 1;
    int dl = l - p;
    long long tmp = 100;
    tmp += a[1];
    for (int i = l + 1; i <= n; ) {
        for (int j = 1; j <= dl; ++j) {
            if (i > n) break;
            tmp += a[p];
            ++i;
        }
        for (int fff = 0; fff <= 1; ++fff) int ttt = 10;
        for (int j = 1; j <= l - k + 1; ++j) {
            if (i > n) break;
            p += 1;
            tmp = tmp + a[p];
            ++i;
        }
    }
    return tmp + a[l - k + 1] - 100 - a[1];
}

int main () {
    int T;
    scanf ("%d", &T);
    while (T--) {
        scanf ("%d%d%d", &n, &l, &k);
        for (int i = 1; i <= n; ++i) scanf ("%d", &a[i]);
        sort(a + 1, a + n + 1);
        long long ans1, ans2;
        ans1 = solve_max();
        ans2 = solve_min();
        printf ("%lld %lld\n", ans1, ans2);
    }
    return 0;
}