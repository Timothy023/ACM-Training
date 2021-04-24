#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
const int VAL = 2e4;
const int mod = 998244353;

int n, a[N + 5];
int f[N + 5][VAL * 2 + 5];

int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf ("%d", &a[i]);
    }
    int ans = n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            f[i][a[i] - a[j] + VAL] = (f[i][a[i] - a[j] + VAL] + f[j][a[i] - a[j] + VAL] + 1) % mod;
            ans = (ans + f[j][a[i] - a[j] + VAL] + 1) % mod;
        }
    }
    printf ("%d\n", ans);
    return 0;
}