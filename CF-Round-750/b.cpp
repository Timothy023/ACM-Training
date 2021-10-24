#include <bits/stdc++.h>
using namespace std;

int T;

int main () {
    scanf ("%d", &T);
    while (T--) {
        int n, s0, s1, x;
        s0 = s1 = 0;
        scanf ("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf ("%d", &x);
            if (x == 0) s0 += 1;
            else if (x == 1) s1 += 1;
        }
        printf ("%I64d\n", 1ll * s1 * (1ll << s0));
    }
    return 0;
}