#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
int n, a[N], T, sum;
bool flag1, flag2;

int main () {
    scanf ("%d", &T);
    while (T--) {
        sum = flag1 = flag2 = 0;
        scanf ("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf ("%d", &a[i]);
            sum += a[i];
            if (a[i] & 1) flag1 = 1;
            else flag2 = 1;
        }
        if (sum % 2 == 1 || (sum % 2 == 0 && flag1 && flag2)) puts("YES");
        else puts("NO");
    }
    return 0;
}