#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int T, n, k;
int a[N], b[N];

int main () {
    scanf ("%d", &T);
    while (T--) {
        scanf ("%d%d", &n, &k);
        for (int i = 1; i <= n; ++i) {
            scanf ("%d", &a[i]);
            b[i] = a[i];
        }
        sort(b + 1, b + n + 1);
        int lst, wz, sum = 1;
        for (int i = 1; i <= n; ++i) {
            wz = lower_bound(b + 1, b + n + 1, a[i]) - b;
            if (i == 1) lst = wz;
            else {
                if (lst + 1 != wz) sum++;
                lst = wz;
            }
        }
        if (sum > k) puts("No");
        else puts("Yes");
    }
    return 0;
}