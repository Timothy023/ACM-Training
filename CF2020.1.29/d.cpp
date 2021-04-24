#include <bits/stdc++.h>
#define int long long
using namespace std;

int T, a, m, l, r, len, pri[100], g, ans;

int gcd(int i, int j) {
    if (j == 0) return i;
    else return gcd(j, i % j);
}
void get_pri(int x) {
    int q; len = 0;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i ==0) {
            q = 1;
            while (x % i == 0) {
                x /= i; q *= i;
            }
            if (g % q != 0) pri[++len] = i;
        }
    }
    if (x != 1) {
        if (g % x != 0) pri[++len] = x;
    }
}
void solve(int step, int f, int num) {
    if (step > len) {
        ans += f * (r / num - l / num);
        return;
    }
    solve(step + 1, -f, num * pri[step]);
    solve(step + 1,  f, num);

}
main () {
    scanf ("%d", &T);
    while (T--) {
        scanf ("%I64d%I64d", &a, &m);
        g = gcd(a, m);
        l = a - 1; r = a + m - 1;
        get_pri(m);
        ans = 0;
        solve(1, 1, g);
        printf ("%I64d\n", ans);
    }
    return 0;
}