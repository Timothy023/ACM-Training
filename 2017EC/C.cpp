#include <bits/stdc++.h>
using namespace std;

int T;

int n;
double ans, s, x;

int main () {
    scanf ("%d", &T);
    for (int step = 1; step <= T; ++step) {
        ans = 0; x = 0;
        scanf ("%d", &n);
        for (int i = 0; i <= n; ++i) {
            scanf ("%lf", &s);
            ans += s;
        }
        s = 0;
        for (int i = 1; i <= n; ++i) {
            scanf ("%lf", &x);
            scanf ("%lf", &x);
            s = max(s, x);
        }
        ans += s;
        printf ("Case #%d: %.8lf\n", step, ans);
    }
    return 0;
}