#include <bits\stdc++.h>
using namespace std;

int T, a, b, c, n, tmp;

int main () {
    scanf ("%d", &T);
    while (T--) {
        scanf ("%d%d%d%d", &a, &b, &c, &n);
        tmp = max(max(a, b), c);
        n -= tmp * 3 - a - b - c;
        if (n >=0 && n % 3 ==0) puts("YES");
        else puts("NO");
    }
    return 0;
}