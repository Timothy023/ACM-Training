#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
int n, m, l, r, c, t, b[N], w[N], a[N];
long long ans, sb[N], sw[N], sa[N];

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf ("%d", &b[i]);
        sb[i] = sb[i - 1] + b[i];
    }
    for (int i = 1; i <= n; ++i) {
        scanf ("%d", &w[i]);
        sw[i] = sw[i - 1] + w[i];
    }
    for (int i = 1; i <= n; ++i) {
        a[i] = max(b[i], w[i]);
        sa[i] = sa[i - 1] + a[i];
    }
    ans = sa[n];
    for (int i = 1; i <= m; ++i) {
        scanf ("%d%d%d%d", &t, &l, &r, &c);
        ans -= sa[r] - sa[l - 1];
        if (t == 1) ans += max(sa[r] - sa[l - 1], sb[r] - sb[l - 1] + c);
        else ans += max(sa[r] - sa[l - 1], sw[r] - sw[l - 1] + c);
    }
    cout <<ans <<endl;
    return 0;
}