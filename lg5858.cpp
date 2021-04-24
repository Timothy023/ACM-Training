#include <bits/stdc++.h>
using namespace std;

const int N = 5505;

int n, w, s, a[N];
int que[N], tot, tow;
long long f[N][N], ans;

int main () {
    scanf ("%d%d%d", &n, &w, &s);
    for (int i = 1; i <= n; ++i) scanf ("%d", &a[i]);
    memset(f, 128,sizeof(f));
    ans = f[0][0]; 
    f[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        que[tot = tow = 1] = w;
        for (int j = w; j >= 1; --j) {
            for (; tot <= tow && f[i - 1][j - 1] > f[i - 1][que[tow]]; --tow);
            for (; tot <= tow && que[tot] > j + s - 1; ++tot);
            que[++tow] = j - 1;
            f[i][j] = f[i - 1][que[tot]] + 1ll * j * a[i];
        }
    }
    for (int j = 1; j <= w; ++j) ans = max(ans, f[n][j]);
    printf ("%lld\n", ans);
    return 0;
}