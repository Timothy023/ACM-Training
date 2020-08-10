#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int ksm(int i, int j) {
    int sum = 1;
    while (j != 0 ){ 
        if (j & 1)
            sum = 1ll * sum * i % mod;
        i = 1ll * i * i % mod;
        j >>= 1;
    }
    return sum;
}

int main () {
    int T;
    scanf ("%d", &T);
    while (T--) {
        int m, p, q;
        scanf ("%d%d%d", &m, &p, &q);
        p = 1ll * ksm(100, mod - 2) * p % mod;
        q = 1ll * ksm(100, mod - 2) * q % mod;
        cout <<(1ll * m - (1ll * m * ksm(p, mod - 2) % mod - 1 + mod) * q % mod + mod) % mod <<endl;
    }
    return 0;
}