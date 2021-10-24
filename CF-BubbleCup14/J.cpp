#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, m, a[N][N], sum;
bool flag[N][N];
vector <int> ans;

void dfs(int x, int y) {
    if (flag[x][y]) return;
    sum++;
    flag[x][y] = true;

    if ((a[x][y] & (1 << 3)) == 0) {
        if (x - 1 > 0) {
            if ((a[x - 1][y] & (1 << 1)) == 0) {
                dfs(x - 1, y);
            }
        }
    }

    if ((a[x][y] & (1 << 2)) == 0) {
        if (y + 1 <= m) {
            if ((a[x][y + 1] & (1)) == 0) {
                dfs(x, y + 1);
            }
        }
    }

    if ((a[x][y] & (1 << 1)) == 0) {
        if (x + 1 <= n) {
            if ((a[x + 1][y] & (1 << 3)) == 0) {
                dfs(x + 1, y);
            }
        }
    }

    if ((a[x][y] & (1)) == 0) {
        if (y - 1 > 0) {
            if ((a[x][y - 1] & (1 << 2)) == 0) {
                dfs(x, y - 1);
            }
        }
    }
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf ("%d", &a[i][j]);
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!flag[i][j]) {
                sum = 0;
                dfs(i, j);
                ans.push_back(sum);
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = ans.size() - 1; i >= 0; --i)
        printf ("%d ", ans[i]);

    return 0;
}