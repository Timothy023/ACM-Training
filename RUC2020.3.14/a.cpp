#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

const int N = 205;
const int M = 10005;
int n, m;
int r[N], c[N], a[N][N];

int main () {
    n = I(); m = I();
    for (int i = 1; i <= n; ++i) r[i] = I();
    for (int i = 1; i <= m; ++i) c[i] = I();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            a[i][j] = min(r[i], c[j]);
    bool flag = 1;
    for (int i = 1; i <= n; ++i) {
        int maxn = 0;
        for (int j = 1; j <= m; ++j) maxn = max(maxn, a[i][j]);
        if (maxn != r[i]) flag = 0;
    }
    for (int j = 1; j <= m; ++j) {
        int maxn = 0;
        for (int i = 1; i <= n; ++i) maxn = max(maxn, a[i][j]);
        if (maxn != c[j]) flag = 0;
    }
    if (flag) puts("possible");
    else puts("impossible");
    return 0;
}