#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int T;
int ny[N], jc[N];

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

void init() {
    jc[1] = ny[0] = 1;
    for (int i = 2; i < N; ++i)
        jc[i] = 1ll * jc[i - 1] * i % mod;
    for (int i = 1; i < N; ++i)
        ny[i] = ksm(jc[i], mod - 2);
}

int main () {
    scanf ("%d", &T);
    init();
    for (int step = 1; step <= T; ++step) {
        int n, k, x;
        int ans, sum = 0;
        scanf ("%d%d", &n, &k);
        ans = ksm(2, n);
        x = 1;
        for (int i = 0; i < k; ++i) {
            sum = (sum + 1ll * x * ny[i] % mod) % mod;
            x = 1ll * x * (n - i) % mod;
        }
        ans = (ans - sum + mod) % mod;
        printf ("Case #%d: %d\n", step, ans);
    }
    return 0;
}