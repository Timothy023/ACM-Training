#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int T;
int n;
int ax[N], ay[N];
map <int, int> hang;
map <int, int> lie;

int main () {
    scanf ("%d", &T);
    while (T--) {
        long long ans = 0;
        hang.clear();
        lie.clear();
        scanf ("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf ("%d%d", &ax[i], &ay[i]);

            if (hang.find(ax[i]) == hang.end())
                hang[ax[i]] = 0;
            hang[ax[i]] = hang[ax[i]] + 1;

            if (lie.find(ay[i]) == lie.end())
                lie[ay[i]] = 0;
            lie[ay[i]] = lie[ay[i]] + 1;
        }
        ans = 1ll * n * (n - 1) * (n - 2) / 6;
        for (int i = 1; i <= n; ++i) {
            long long tmp = 1ll * (hang[ax[i]] - 1) * (lie[ay[i]] - 1);
            ans = ans - tmp;
        }
        printf ("%I64d\n", ans);
    }
    return 0;
}