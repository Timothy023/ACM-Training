#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

int n, m, k, q, ans;
int d[41][1001][1001];
int a[1005][1005], dis[45][45];
queue <int> qx, qy;
int x, y, nx, ny;
int fx[4] = {0, 1, 0, -1};
int fy[4] = {1, 0, -1, 0};

void init(int id) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            if (a[i][j] == id) {
                d[id][i][j] = 0;
                qx.push(i); qy.push(j);
            }
    }
    while (!qx.empty()) {
        x = qx.front(); y = qy.front();
        qx.pop(); qy.pop();
        for (int i = 0; i < 4; ++i) {
            nx = x + fx[i]; ny = y + fy[i];
            if (nx < 0 || nx > n || ny < 0 || ny > m || d[id][nx][ny] <= d[id][x][y] + 1) continue;
            d[id][nx][ny] = d[id][x][y] + 1;
            qx.push(nx); qy.push(ny);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dis[id][a[i][j]] = min(dis[id][a[i][j]], d[id][i][j]);
        }
    }
}

int main () {
    n = I(); m = I(); k = I();
    memset(d, 60, sizeof(d));
    memset(dis, 60, sizeof(dis));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            a[i][j] = I();
    for (int i = 1; i <= k; ++i)
        init(i);
    for (int p = 1; p <= k; ++p)
        for (int i = 1; i <= k; ++i)
            for (int j = 1; j <= k; ++j)
                dis[i][j] = min(dis[i][j], dis[i][p] + dis[p][j] + 1);
    
    q = I();
    for (int i = 1; i <= q; ++i) {
        x = I(); y = I(); nx = I(); ny = I();
        ans = abs(x - nx) + abs(y - ny);
        if (a[x][y] == a[nx][ny]) ans = min(ans, 1);
        else {
            ans = min(ans, dis[a[x][y]][a[nx][ny]] + 2);
        }
        printf ("%d\n", ans);
    }
    return 0;
}