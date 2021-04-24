#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

int n, sum, a[15], x, y, ans;

int main () {
    n = I();
    for (int i = 1; i <= n; ++i) {
        x = I();
        a[x]++;
        sum += x;
    }
    for (int i = 1; i <= 10; ++i) {
        if (a[i] >= 2 && (sum - 2 * i) % 10 == 0)
            ans = max(ans, (i * 2 - 1) % 10 + 1);
        for (int j = i + 1; j <= 10; ++j) {
            if (a[i] && a[j] && (sum - i - j) % 10 == 0)
                ans = max(ans, (i + j - 1) % 10 + 1);
        }
    }
    printf ("%d\n", ans);
    return 0;
}