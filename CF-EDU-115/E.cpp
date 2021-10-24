#include <bits/stdc++.h>
using namespace std;

int n, m, q;
int fx[10][2];
int fy[10][2];
bool a[1005][1005];
long long ans;

int calc(int x, int y, int id) {
    int sum = 0;
    for (int step = 0; ; step++) {
        sum++;
        x = x + fx[id][step % 2];
        y = y + fy[id][step % 2];
        if (x < 1 || x > n || y < 1 || y > m) break;
        if (a[x][y]) break;
    }
    return sum;
}

int main () {
    fx[0][0] =  0; fy[0][0] =  1; fx[0][1] =  1; fy[0][1] =  0;
    fx[1][0] =  1; fy[1][0] =  0; fx[1][1] =  0; fy[1][1] =  1;

    fx[2][0] = -1; fy[2][0] =  0; fx[2][1] =  0; fy[2][1] = -1;
    fx[3][0] =  0; fy[3][0] = -1; fx[3][1] = -1; fy[3][1] =  0;


    scanf ("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int lx = n - i + 1;
            int ly = m - j + 1;
            if (lx == ly) {
                ans += (lx + lx - 1) * 2;
            }
            else if (lx < ly) {
                ans += (lx + lx - 1);
                ans += (lx + lx);
            }
            else {
                ans += (ly + ly - 1);
                ans += (ly + ly);
            }

            ans = ans - 1;
        }
    }
    
    for (int i = 1; i <= q; ++i) {
        int x, y;
        scanf ("%d%d", &x, &y);
        long long s1, s2;

        s1 = calc(x, y, 0);
        s2 = calc(x, y, 2);
        if (a[x][y]) ans += s1 * s2;
        else ans -= s1 * s2;

        s1 = calc(x, y, 1);
        s2 = calc(x, y, 3);
        if (a[x][y]) ans += s1 * s2 - 1;
        else ans -= s1 * s2 - 1;

        a[x][y] = !a[x][y];

        printf ("%I64d\n", ans);
    }
    return 0;
}