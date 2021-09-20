#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e9;

int T, n;
int mi[105][25], len[100];
int a[15], l;

int main () {
    mi[0][len[0] = 0] = 1;
    for (int i = 1; i <= 100; ++i) {
        int x = 0;
        for (int j = 0; j <= len[i - 1]; ++j) {
            mi[i][j] = mi[i - 1][j] * 2 + x;
            x = mi[i][j] / 10;
            mi[i][j] %= 10;
        }
        len[i] = len[i - 1];
        if (x != 0) {
            len[i] ++;
            mi[i][len[i]] = x;
        }
    }
    scanf ("%d", &T);
    while (T--) {
        scanf ("%d", &n);
        l = 0;
        while (n) {
            a[l] = n % 10;
            n /= 10;
            l++;
        }
        int ans = 100;
        for (int i = 0; i <= 100; ++i) {
            int p = len[i];
            int sum = 0;
            for (int j = l - 1; j >= 0; --j) {
                if (p >= 0 && a[j] == mi[i][p]) p--;
                else sum++;
            }
            sum += (p + 1);
            ans = min(ans, sum);
        }
        printf ("%d\n", ans);
    }
    return 0;
}