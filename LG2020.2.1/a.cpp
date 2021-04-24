#include <bits/stdc++.h>
using namespace std;

double x, y, r, ans;

int main () {
    cin >>x>>y>>r;
    ans = fabs(sqrt(x * x + y * y) - 2 * r);
    printf ("%.6lf\n", ans);
    if (x == 0 && y == 0) puts("0");
    else if (y == 0) puts("Error");
    else printf ("%.2lf\n", fabs(x / y));
    return 0;
}