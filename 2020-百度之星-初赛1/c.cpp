#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

int f[1005][1005];

int gcd(int i, int j) {
    if (!j) return i;
    else return gcd(j, i % j);
}

int T, a, b;

void init() {
    f[1][1] = 1;
    for (int i = 1; i <= 1000; ++i) {
        for (int j = 1; j <= 1000; ++j) {
            if (i == 1 && j == 1) continue;
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if (gcd(i, j) == 1) f[i][j]++;
        }
    }
}

int main () {
    T = I();
    init();
    while (T--) {
        a = I(); b = I();
        printf ("%d\n", f[a][b]);
    }
    return 0;
}