#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int N = 5e4 + 5;
const int maxn = 5e4;
int jc[N], ny[N];
int T, n, m, ans;

int ksm(int i, int j) {
    int s = 1;
    while (j) {
        if (j & 1)
            s = 1ll * s * i % mod;
        i = 1ll * i * i % mod;
        j >>= 1;
    }
    return s;
}
int c(int i, int j) {
    return 1ll * jc[j] * ny[j - i] %mod * ny[i] % mod;
}
int main () {
    jc[0] = 1; ny[0] = 1;
    for (int i = 1; i <= maxn; ++i) jc[i] = 1ll * jc[i - 1] * i % mod;
    for (int i = 1; i <= maxn; ++i) ny[i] = ksm(jc[i], mod - 2);
    scanf ("%d", &T);
    while (T--) {
        ans = 0;
        scanf ("%d%d", &n, &m);
        for (int i = 0; i <= m; ++i)
            ans = (ans + c(i, n)) % mod;
        printf ("%d\n", ans);
    }
    return 0;
}