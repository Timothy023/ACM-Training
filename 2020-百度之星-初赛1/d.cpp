#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

int T;
int n, x, y;
int a[505][505];
int s[5];

int solve(int x, int y) {
    int sum = 0, d = 0, an = 0;
    s[1] = s[2] = s[3] = 0;
    for (int i = max(1, x - 3); i <= min(n, x + 3); ++i) {
        for (int j = max(1, y - 3); j <= min(n, y + 3); ++j) {
            int tmp = abs(x - i) + abs(y - j);
            if (tmp > 3 || tmp == 0) continue;
            s[a[i][j]]++;
        }
    }
    for (int human = 1, p = 3; human < 9; ++human) {
        int del = 8 * human * human - sum;
        if (human == 1) {
            d = a[x][y];
        }
        else {
            while (p >= 1 && s[p] == 0) p--;
            d += p; s[p]--;
        }
        int tmp = del / d;
        if (del % d != 0) tmp++;
        an += tmp;
        sum += d * tmp;
    }
    return an;
}

int main () {
    T = I();
    while (T--) {
        n = I(); x = I(); y = I();
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                a[i][j] = I();
        int ans = 2147483647;
        for (int i = 1; i <= n; ++i) 
            for (int j = 1; j <= n; ++j) {
                int tmp = solve(i, j);
                int len = abs(x - i) + abs(y - j);
                len = len / 2 + (len & 1);
                tmp += len;
                ans = min(ans , tmp);
            }
        printf ("%d\n", ans);
    }
    return 0;
}