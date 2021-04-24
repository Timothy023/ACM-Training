#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int ans, n, T, x, y;

int sg(int x) {
    for (int i = 0; ; ++i)
        if ((x & (1LL << i)) == 0) return i;
    return -1;
}

int main () {
    scanf ("%d", &T);
    while (T--) {
        ans = 0;
        scanf ("%d", &n);
        for (int i = 1; i <= n; i += 2) {
            scanf ("%d%d", &x, &y);
            ans ^= sg((x - 1) | (y - 1));
        }
        if (ans) puts("YES");
        else puts("NO");
    }
    return 0;
}