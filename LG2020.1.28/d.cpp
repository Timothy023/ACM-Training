#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const int mod = 998244353;
int n, t, f[N][2], x, k, siz[N], now, las, ans;
vector <int> fri[N];

int ksm(int i, int j) {
    int sum = 1;
    while (j) {
        if (j & 1)
            sum = 1ll * sum * i % mod;
        i = 1ll * i * i % mod;
        j >>= 1;
    }
    return sum;
}

int main () {
#ifdef debug
    freopen ("test.out", "w", stdout);
#endif
    scanf ("%d%d", &n, &t);
    for (int i = 1; i <= n; ++i) {
        scanf ("%d", &x);
        f[i][0] = (1 - x + mod) % mod;
        scanf ("%d", &k);
        for (int j = 1; j <= k; ++j) {
            scanf ("%d", &x);
            fri[i].push_back(x);
            siz[i]++;
        }
    }
    printf ("%d: ", 0);
    for (int j = 1; j <= n; ++j)
        printf ("%d ", f[j][0]);
    puts("");

    for (int i = 1; i <= t; ++i) {
        now = i & 1; las = now ^ 1;
        for (int j = 1; j <= n; ++j) {
            f[j][now] = 1;
            for (int k = 0; k < siz[j]; ++k) {
                f[j][now] = 1ll * f[j][now] *f[fri[j][k]][las] % mod;
            }
        }
        printf ("%d: ", i);
        for (int j = 1; j <= n; ++j)
            printf ("%d ", f[j][now]);
        puts("");
    }
    now = t & 1;
    for (int i = 1; i <= n; ++i)
        ans = (ans + 1 - f[i][t] + mod) %mod;
    printf ("%d\n", ans);
    return 0;
}