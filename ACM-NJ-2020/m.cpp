#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

int T;
vector < pair<int, int> > to[N];
int n;
long long f[N][N][2], g[N][N][2], sum[N];
int s[N], val[N], siz[N], fa[N];

void dfs(int ro) {
    sum[ro] = 0;
    s[ro] = 1;
    for (int i = 0; i < siz[ro]; ++i) {
        int son = to[ro][i].second;
        dfs(son);
        s[ro] += s[son];
        to[ro][i] = make_pair(s[son], son);
        sum[ro] += val[son];
    }
    sort(to[ro].begin(), to[ro].end());

    // cout <<ro<<": \n";
    int tot = 1;
    f[ro][0][1] = val[ro]; 
    for (int i = 0; i < siz[ro]; ++i) {
        int son = to[ro][i].second;
        for (int j = 1; j <= s[son]; ++j) {
            for (int k = 1; k <= tot; ++k) {
                g[ro][k + j][0] = max(g[ro][k+j][0], f[ro][k][0] + f[son][j][0]);
                // if (ro == 2) {
                    // cout <<"test: " <<ro <<"  " <<k <<"  " <<j <<"  " <<f[ro][k][0] <<"  " <<f[son][j][0] <<"  " <<g[ro][k + j][0] <<endl;
                // }
            }
            for (int k = 0; k <= tot - 1; ++k) {
                g[ro][k + j][1] = max(g[ro][k+j][1], f[ro][k][1] + f[son][j][0] + val[son]);
            }
        }
        for (int j = 0; j <= s[son] - 1; ++j) {
            for (int k = 1; k <= tot; ++k) {
                g[ro][k + j][0] = max(g[ro][k + j][0], f[ro][k][0] + f[son][j][1] + val[son]);
            }
            for (int k = 0; k <= tot - 1; ++k) {
                g[ro][k + j][1] = max(g[ro][k + j][1], f[ro][k][1] + f[son][j][1] + val[son]);
            }
        }
        tot += s[son];
        for (int j = 0; j <= tot; ++j) {
            f[ro][j][0] = max(f[ro][j][0], g[ro][j][0]); g[ro][j][0] = 0;
            f[ro][j][1] = max(f[ro][j][1], g[ro][j][1]); g[ro][j][1] = 0;
        }
        // for (int p = 0; p <= tot; ++p) cout <<f[ro][p][0] <<"  "; cout <<endl;
    }
    // for (int i = 0; i <= tot; ++i) cout <<f[ro][i][0] <<"  "; cout <<endl;
    // for (int i = 0; i <= tot; ++i) cout <<f[ro][i][1] <<"  "; cout <<endl;
    // puts("--------------------------------------");
}

int main () {
    scanf ("%d", &T);
    while (T--) {
        scanf ("%d", &n);
        for (int i = 1; i <= n; ++i) {
            to[i].clear();
            siz[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                f[i][j][0] = f[i][j][1] = 0;
            }
        }
        for (int i = 2; i <= n; ++i) {
            int x;
            scanf ("%d", &fa[i]);
            siz[fa[i]] += 1;
        }
        for (int i = 2; i <= n; ++i) {
            to[fa[i]].push_back(make_pair(siz[i], i));
        }
        for (int i = 1; i <= n; ++i) {
            scanf ("%d", &val[i]);
        }
        dfs(1);
        long long ans = 0;
        for (int i = 1; i <= n; ++i)
            ans = ans + val[i] + sum[i];
        for (int i = n; i >= 0; --i) {
            printf ("%lld", ans - max(f[1][i][0], f[1][i][1]));
            if (i != 0) printf (" ");
            else puts("");
        }
    }
    return 0;
}