#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = 5e3 + 5;
const int mod = 1e9 + 7;
int n, maxn, ans, a[N], s[M];

int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf ("%d", &a[i]);
        s[a[i]]++;
        maxn = max(maxn, a[i]);
    }
    for (int i = 1; i <= maxn; ++i) {
        if (s[i] < 2) continue;
        for (int j = 1; j <= i; ++j) {
            if (i - j < j) break;
            if (i - j == j) {
                long long t1 = 1ll * s[i] * (s[i] - 1) / 2 % mod;
                long long t2 = 1ll * s[j] * (s[j] - 1) / 2 % mod;
                ans = (ans + t1 * t2 % mod) % mod;
            }
            if (i - j > j) {
                if (s[j] && s[i - j]) {
                    long long t1 = 1ll * s[i] * (s[i] - 1) / 2 % mod;
                    long long t2 = 1ll * s[j] * s[i - j] % mod;
                    ans = (ans + t1 * t2 % mod) % mod;
                }
            }
        }
    }
    printf ("%d\n", ans);
    return 0;
}