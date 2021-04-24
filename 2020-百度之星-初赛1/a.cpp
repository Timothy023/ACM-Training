#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

int T;
int n, m, x, y, ans;

int main () {
    T = I();
    while (T--) {
        n = I(); m = I();
        ans = 2147483647;
        for (int i = 1; i <= n; ++i) {
            x = I(); y = I();
            int tmp = m / x;
            if (m % x) tmp++;
            tmp *= y;
            ans = min(ans, tmp);
        }
        printf ("%d\n", ans);
    }
    return 0;
}