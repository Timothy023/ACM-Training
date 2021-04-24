#include <bits/stdc++.h>
using namespace std;

int T, n;

int main () {
    scanf ("%d", &T);
    for (int step = 1; step <= T; ++step) {
        scanf ("%d", &n);
        int s = 2, ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (s == 1) ans++;
            s = s * 2 % 7;
        }
        printf ("Case #%d: %d\n", step, ans);
    }
    return 0;
}