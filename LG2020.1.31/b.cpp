#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int ans;
long long n;

int main () {
    scanf ("%lld", &n);
    for (long long i = 0; i <= n; ++i)
        for (long long j = i + 1; j <= n; ++j) {
            if (i % (i ^ j) == j % (i ^ j)) {
                ans++;
                if (ans >= mod) ans -= mod;
            }
        }
    printf ("%d\n", ans);
    return 0;
}