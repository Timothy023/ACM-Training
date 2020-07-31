#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

int T, x;
double g[15] = {0, 0, 1.0, 1.7, 2.0, 2.3, 2.7, 3.0, 3.3, 3.7, 4.0, 4.3};
int s[15] = {0, 0, 60, 62, 65, 67, 70, 75, 80, 85, 90, 95};
double f[105], h1[5][405];

void init() {
    for (int i = 0, p = 1; i <= 100; ++i) {
        if (i >= s[p + 1] && p < 11) p++;
        f[i] = g[p];
    }
    for (int i = 1; i <= 4; ++i) {
        for (int j = 0; j <= 400; ++j) {
            for (int k = 0; k <= j && k <= 100; ++k) {
                h1[i][j] = max(h1[i][j], h1[i - 1][j - k] + f[k]);
            }
        }
    }
}

int main () {
    T = I();
    init();
    while (T--) {
        x = I();
        printf ("%.1lf\n", h1[4][x]);
    }
    return 0;
}