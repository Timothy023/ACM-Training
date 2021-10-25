#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
const int inf = 1e9;

int n;
int a[N], b[N];
bool flag[N], vis[N];
pair <int, int> pos[N];
int len, st = 1;
int f[N], g[N];
queue <pair <int, int> > que;

void dfs(int ro) {
    if (ro == n) return;
    dfs(g[ro]);
    printf ("%d ", ro);
}

int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf ("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf ("%d", &b[i]);
    }
    for (int i = n; i >= 0; --i) {
        if (flag[i + b[i]] == false) {
            flag[i + b[i]] = true;
            pos[++len] = make_pair(i, i + b[i]);
        }
    }
    que.push(make_pair(n, n));
    vis[n] = 1;
    for (int i = 0; i <= n; ++i) f[i] = inf;
    f[n] = 0;
    while (!que.empty()) {
        int now = que.front().first;
        int gun = que.front().second;
        int lst = now - a[now];
        // cout <<now <<"  " <<gun <<"  " <<lst <<"  " <<f[now] <<"  " <<g[gun] <<endl;
        que.pop();
        while (st <= len && pos[st].first >= lst) {
            if (f[now] + 1 < f[pos[st].second]) {
                f[pos[st].second] = f[now] + 1;
                g[pos[st].first] = gun;
                if (vis[pos[st].second] == false) {
                    vis[pos[st].second] = true;
                    que.push(make_pair(pos[st].second, pos[st].first));
                }
            }
            st += 1;
        }
    }
    if (f[0] == inf) puts("-1");
    else {
        printf ("%d\n", f[0]);
        dfs(0);
    }
    return 0;
}