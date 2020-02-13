#include <bits/stdc++.h>
using namespace std;

int T, n, x;

int main () {
    scanf ("%d", &T);
    while (T--) {
        scanf ("%d", &n);
        x = n & 1;
        n /= 2;
        if (x) putchar('7');
        else putchar('1');
        for (int i = 1; i < n; ++i)
            putchar('1');
        puts("");
    }
    return 0;
}