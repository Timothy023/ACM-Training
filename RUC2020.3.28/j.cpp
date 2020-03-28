#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

int T, n, m, maxn;
int fx[4] = {0, 1, 0, -1};
int fy[4] = {1, 0, -1, 0};
int a[505][505], dis[505][505];
queue <pair <int, int> > que;

bool check(int lim) {
    memset(dis, -1, sizeof(dis));
    dis[1][1] = 0;
    if (a[1][1] <= dis[1][1] + lim) return false;
    que.push(make_pair(1, 1));
    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        for (int k = 0; k < 4; ++k) {
            int nx = x + fx[k];
            int ny = y + fy[k];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (dis[nx][ny] != -1 || dis[x][y] + 1 + lim >= a[nx][ny]) continue;
            dis[nx][ny] = dis[x][y] + 1;
            que.push(make_pair(nx, ny));
        }
    }
    if (dis[n][m] != -1) return true;
    else return false;
}

int main () {
    T = I();
    for (int step = 1; step <= T; ++step) {
        n = I(); m = I();
        maxn = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                a[i][j] = I();
                maxn = max(a[i][j], maxn);
            }
        int l = 0, r = maxn, ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        ans += 1;
        if (ans == 0) puts("impossible");
        else printf ("%d\n", ans);
    }
    return 0;
}