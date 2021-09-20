#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int mod = 1e9 + 7;
int T;
int n, k;
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

int c(int n, int m) {
    return 1ll * jc[m] * ny[n] % mod * ny[m - n] % mod;
}

int main () {
    scanf ("%d", &T);
    jc[1] = jc[0] = ny[0] = 1;
    for (int i = 2; i < N; ++i) jc[i] = 1ll * jc[i - 1] * i % mod;
    for (int i = 1; i < N; ++i) ny[i] = ksm(jc[i], mod - 2);
    while (T--) {
        scanf ("%d%d", &n, &k);
        int ans = 0;
        int lst = 1;
        int sum = 0;
        for (int i = 0; i < n; i += 2)
            sum = (sum + c(i, n)) % mod;
        for (int i = k; i >= 1; --i) {
            int tmp = 0;
            // all one
            if (n % 2 == 0) {
                ans = (ans + 1ll * lst * ksm(ksm(2, i - 1), n) % mod) % mod;
            }
            else {tmp = 1;}

            // some zero
            tmp = (tmp + sum) % mod;

            lst = 1ll * lst * tmp % mod;
        }
        ans = (ans + lst) % mod;
        printf ("%d\n", ans);
    }
    return 0;
}