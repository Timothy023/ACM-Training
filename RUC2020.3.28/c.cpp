#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

int T, a[55][55],n, x, y, ans;
bool l[55],r[55];

int main () {
    T = I();
    for (int s = 1; s <= T; ++s) {
        n = I(); n = I();
        ans = 0;
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        for (int i = 1; i <= n; ++i) {
            x = I(); y = I();
            if (r[x] && l[y]) ans++;
            else r[x] = l[y] = 1;
        }
        printf ("Strategy #%d: %d\n\n", s, ans);
    }
    return 0;
}