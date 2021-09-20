#include <bits/stdc++.h>
using namespace std;

int T, k;

int main () {
    scanf ("%d", &T);
    while (T--) {
        scanf ("%d", &k);
        int n = sqrt(k);
        while (n * n >= k) n = n - 1;
        int delta = k - n * n;
        if (delta <= n) {
            printf ("%d %d\n", delta, n + 1);
        }
        else {
            printf ("%d %d\n", n + 1, 2 * n + 2 - delta);
        }
    }
    return 0;
}