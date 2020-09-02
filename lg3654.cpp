#include <bits/stdc++.h>
using namespace std;

int n, m, k, ans;
int fx[2] = {0, 1};
int fy[2] = {1, 0};
char ch[105][105];

int main () {
    scanf ("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) scanf ("%s", ch[i] + 1);
    
    for (int kin = 0; kin <= 1; ++kin) {
        if (k == 1 && kin == 1) break;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                bool flag = true;
                int nx = i, ny = j;
                for (int p = 1; p <= k && flag; ++p, nx += fx[kin], ny += fy[kin]) {
                    if (1 <= nx && nx <= n && 1 <= ny && ny <= m && ch[nx][ny] == '.') continue;
                    else flag = false;
                }
                if (flag) ans++;
            }
        }
    }
    printf ("%d\n", ans);
    return 0;
}