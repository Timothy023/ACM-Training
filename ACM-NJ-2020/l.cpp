#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

const int N = 1e5 + 5;
int T, ans, n, m;
int a[N], b[N];

int main () {
    scanf ("%d", &T);
    while (T--) {
        scanf ("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            scanf ("%d", &a[i]);
        }
        for (int j = 1; j <= m; ++j) {
            scanf ("%d", &b[j]);
        }
        ans = 0;
        sort(a + 1, a + n + 1);
        sort(b + 1, b + m + 1);
        int p = 1, q = 1;
        b[0] = 0; b[m + 1] = 1e9 + 5;
        for (int i = 1; i <= m + 1; ++i) {
            p = upper_bound(a + 1, a + n + 1, b[i - 1]) - a;
            q = lower_bound(a + 1, a + n + 1, b[i]) - a;
            ans = max(ans, q - 1 - p + 1);
        }
        if (ans) printf ("%d\n", ans);
        else puts("Impossible");
    }
    return 0;
}