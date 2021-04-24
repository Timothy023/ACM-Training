#include <bits/stdc++.h>
using namespace std;

int T;
long long l, r, ans;

int main () {
    scanf ("%d", &T);
    while (T--) {
        scanf ("%lld%lld", &l, &r);
        ans = (l + r) % 9 * (r - l + 1) % 9 * 5 % 9;
        printf ("%lld\n", ans);
    }
    return 0;
}