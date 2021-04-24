#include <bits/stdc++.h>
using namespace std;

int n;
int a[305][305];

void solve() {
    int fi = 0, pos = 0, ans;
    for (int i = n, s; i >= 2; --i) {
        s = 1;
        for (int j = 1; j <= fi; ++j) {
            a[i][j] = 0;
        }
        for (int j = fi + 1; j <= i - pos; ++j) {
            a[i][j] = 1;
        }
        a[i][i - pos + 1] = 0;
        for (int j = i - pos + 2; j <= i; ++j) {
            a[i][j] = 1;
        }
        pos++;
        if (fi + pos >= i - 1) {
            if (fi + pos == i && fi != 0) pos = 0;
            else pos = 1;
            fi++;
        }
        if (fi + pos > i - 1) {
            ans = i; break;
        }
    }
    printf ("%d\n", n - ans + 1);
    for (int i = ans; i <= n; ++i) {
        for (int j = 1; j <= i; ++j)
            printf("%d", a[i][j]);
        puts("");
    }
    
}

int main () {
    scanf ("%d", &n);
    if (n == 1) {
        puts("1");
        puts("1");
        return 0;
    }
    else if (n == 2) {
        puts("2");
        puts("1");
        puts("00");
        return 0;
    }
    solve();
    return 0;
}