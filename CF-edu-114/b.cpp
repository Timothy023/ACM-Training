#include <bits/stdc++.h>
using namespace std;

int T;
int a[5], m;

int main () {
    scanf ("%d", &T);
    while (T--) {
        scanf ("%d%d%d%d", &a[0], &a[1], &a[2], &m);
        sort(a, a + 3);
        int maxn = a[0] + a[1] + a[2] - 3;
        int minn = max(0, a[2] - a[0] - a[1] - 1);
        if (minn <= m && m <= maxn) puts("YES");
        else puts("NO");
    }
    return 0;
}