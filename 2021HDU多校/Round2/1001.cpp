#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int T;
long long n;
long long ans;

int main () {
    scanf ("%d", &T);
    while (T--) {
        scanf ("%lld", &n);
        ans = n % mod * 4 % mod * ((n - 1) % mod) % mod;
        printf ("%lld\n", ans);
    }
    return 0;
}