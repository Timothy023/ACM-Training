#include <bits/stdc++.h>
using namespace std;

int T, a, b, c;

int main () {
    scanf ("%d", &T);
    while (T--) {
        scanf ("%d%d%d", &a, &b, &c);
        if (b < a) swap(a, b);
        int n = b - a;
        n *= 2;
        if (n < b || n < c) puts("-1");
        else {
            int ans = (c + (n / 2) - 1) % n + 1;
            printf ("%d\n", ans);
        }
    }
    return 0;
}