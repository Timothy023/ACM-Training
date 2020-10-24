#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
const int mod = 998244353;
int n, m, ans;
int jc[N], ny[N];

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

int c(int i, int j) {
    return 1ll * jc[i] * ny[j] % mod * ny[i - j] % mod;
}

int main () {
    scanf ("%d%d", &n, &m);
    jc[0] = 1;
    for (int i = 1; i <= 2 * n; ++i) jc[i] = 1ll * jc[i - 1] * i % mod;
    ny[2 * n] = ksm(jc[2 * n], mod - 2);
    for (int i = 2 * n - 1; i >= 0; --i) ny[i] = 1ll * ny[i + 1] * (i + 1) % mod;

    for (int i = 1; i <= n; ++i) {
        ans = (ans + c((i - 1) + m - 1, i - 1) ) % mod;
    }

    printf ("%d\n", ans);
    return 0;
}