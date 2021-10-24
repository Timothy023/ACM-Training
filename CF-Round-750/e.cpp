#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int T;
int n, a[N];
long long sum[N];
long long vali[2][N], ll[2];

int main () {
    scanf ("%d", &T);
    while (T--) {
        scanf ("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf ("%d", &a[i]);
        }
        sum[n + 1] = 0;
        for (int i = n; i >= 1; --i) sum[i] = sum[i + 1] + a[i];
        ll[1] = 0;
        for (int i = n; i >= 1; --i) {
            ll[1] += 1;
            vali[1][ll[1]] = i;
        }
        for (int l = 2; l <= 500; ++l) {
            int nw = l & 1;
            int lt = nw ^ 1;
            ll[nw] = 0;
            long long maxn = 0;
            int lstid = 1;
            for (int i = n - l + 1; i >= 1; --i) {
                while (lstid <= ll[lt] && vali[lt][lstid] > i + l - 1) {
                    maxn = max(maxn, sum[vali[lt][lstid]] - sum[vali[lt][lstid] + l - 1]);
                    lstid += 1;
                }
                if (sum[i] - sum[i + l] < maxn) {
                    ll[nw] += 1;
                    vali[nw][ll[nw]] = i;
                }
            }
            if (ll[nw] == 0) {
                printf ("%d\n", l - 1);
                break;
            }
        }
    }
    return 0;
}