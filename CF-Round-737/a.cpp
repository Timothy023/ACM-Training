#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int T;
int a[N], n;

int main () {
    scanf ("%d", &T);
    while (T--) {
        double ans = -1e12;
        long long s1, s2;
        s1 = s2 = 0;
        scanf ("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf ("%d", &a[i]);
            s2 += a[i];
            if (i == 1) s1 = a[1];
            else s1 = max(s1, 1ll * a[i]);
        }
        s2 -= s1;
        ans = 1.0 * s1 + 1.0 * s2 / (n - 1);
        printf ("%.10lf\n", ans);
    }
    return 0;
}