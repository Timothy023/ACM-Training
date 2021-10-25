#include <bits/stdc++.h>
using namespace std;

int T;
int n;
int a[2005][2005];
int sum[2005];

int main () {
    scanf ("%d", &T);
    while (T--) {
        scanf ("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf ("%d", &a[0][i]);
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) sum[j] = 0;
            for (int j = 1; j <= n; ++j) sum[a[i - 1][j]]++;
            for (int j = 1; j <= n; ++j) a[i][j] = sum[a[i - 1][j]];
        }
        int q, x, y;
        scanf ("%d", &q);
        for (int i = 1; i <= q; ++i) {
            scanf ("%d%d", &x, &y);
            if (y > n) y = n;
            printf ("%d\n", a[y][x]);
        }
    }
    return 0;
}