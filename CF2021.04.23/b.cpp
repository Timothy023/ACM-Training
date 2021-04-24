#include <bits/stdc++.h>
using namespace std;

int T, n, m;
int b[105][105], ans[105][105];
int step;
pair <int, int> sor[10005];
bool pd[105][105];


int main () {
    scanf ("%d", &T);
    while (T--) {
        step = 0;
        scanf ("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                pd[i][j] = false;
                ans[i][j] = 0;
                scanf ("%d", &b[i][j]);
                sor[++step] = make_pair(b[i][j], i * m + j);
            }
        }
        sort(sor + 1, sor + step + 1);
        for (int i = 1; i <= m ; ++i) {
            int x = sor[i].second / m;
            int y = sor[i].second % m;
            pd[x][y] = true;
            ans[x][i - 1] = b[x][y];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (pd[i][j]) continue;
                for (int k = 0; k < m; ++k) {
                    if (ans[i][k] == 0) {
                        ans[i][k] = b[i][j];
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                printf ("%d ", ans[i][j]);
            printf ("\n");
        }
    }
    return 0;
}