#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

int T, n, k, t1, t2, t3;
long long ans;

int main () {
    T = I();
    while (T--) {
        n = I(); k = I(); k = n - k;
        ans = 1ll * n * (n + 1) / 2;
        n = n - k + 1;
        t1 = k / n;
        t2 = k % n;
        t3 = n - t2;
        ans -= 1ll * t3 * (1ll * t1 * (t1 + 1) / 2) + 1ll * t2 * (1ll * (t1 + 1) * (t1 + 2 ) / 2);
        printf ("%I64d\n", ans);
    }
    return 0;
}