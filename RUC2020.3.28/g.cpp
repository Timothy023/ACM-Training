#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

int T, n, m, a[1005], x, y;
int f[2][105][105];

int solve1() {
    int sum = 0, las = -1000;
    for (int i = 1; i <= n; ++i) {
        if (las + x <= a[i]) {
            las = a[i];
        }
        else sum++;
    }
    return sum;
}

int solve2() {
    memset(f, 60, sizeof(f));
    int inf = f[0][0][0];
    f[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
        int now = i & 1;
        int nxt = now ^ 1;
        for (int j = 0; j <= x; ++j)
            for (int k = 0; k <= y; ++k)
                f[nxt][j][k] = inf;
        for (int j = 0; j <= x; ++j) {
            for (int k = 0; k <= y; ++k) {
                int nj = max(0, j - (a[i + 1] - a[i]));
                int nk = max(0, k - (a[i + 1] - a[i]));
                f[nxt][nj][nk] = min(f[nxt][nj][nk], f[now][j][k] + 1);
                if (nj == 0) {
                    f[nxt][ x][nk] = min(f[nxt][ x][nk], f[now][j][k]);
                }
                if (nk == 0) {
                    f[nxt][nj][ y] = min(f[nxt][nj][ y], f[now][j][k]);
                }
            }
        }
    }
    int sum = inf;
    for (int i = 0; i <= x; ++i)
        for (int j = 0; j <= y; ++j)
            sum = min(sum, f[n & 1][i][j]);
    return sum;
}

int main () {
    T = I();
    for (int step = 1; step <= T; ++step) {
        n = I();
        for (int i = 1; i <= n; ++i) {
            scanf ("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        m = I();
        if (m == 1) {
            x = I();
            printf ("Mission #%d: %d\n\n", step, solve1());
        }
        else {
            x = I(); y = I();
            printf ("Mission #%d: %d\n\n", step, solve2());
        }
    }
    return 0;
}