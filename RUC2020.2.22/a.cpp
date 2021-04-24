#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

const int N = 1005;
const int mod = 1e9 + 7;
int a, b, k, c;
int jc[N], ny[N];

int ksm(int i, int j) {
    int sum = 1;
    while (j) {
        if (j & 1)
            sum = 1ll * sum * i % mod;
        i = 1ll * i * i % mod;
        j >>= 1;
    }
    return  sum;
}

int C(int i, int j) {
    return 1ll * jc[i] * ny[j] % mod * ny[i-j] % mod;
}

int main () {
    a = I(); b = I(); k = I(); c = I();
    if (!k) {
        puts("0");
        return 0;
    }
    jc[0] = ny[0] = 1;
    for (int i = 1; i <= k; ++i) jc[i] = 1ll * jc[i - 1] * i % mod;
    for (int i = 1; i <= k; ++i) ny[i] = ksm(jc[i], mod - 2);
    if (a != c && b != c) puts("0");
    else if (a == c && b == c) printf ("%d\n", k);
    else {
        int ans = 0;
        for (int i = 1; i <= k; ++i) {
            ans = (ans + 1ll * i * C(k, i) % mod) % mod;
        }
        printf ("%d\n", ans);
    }
    return 0;
}
