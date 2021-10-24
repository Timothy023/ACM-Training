#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n;
int a[N];
int f[10000];
vector <int> nw[5005];

int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf ("%d", &a[i]);
    }
    for (int i = 0; i < 8192; ++i) f[i] = 5001;
    f[0] = 0;
    for (int i = 1; i <= 5000; ++i) nw[i].push_back(0);
    for (int i = 1; i <= n; ++i) {
        int sz = nw[a[i]].size();
        for (int j = 0; j < sz; ++j) {
            int tmp = nw[a[i]][j] ^ a[i];
            for (int k = a[i] + 1; k <= f[tmp]; ++k) {
                nw[k].push_back(tmp);
            }
            f[tmp] = min(f[tmp], a[i]);
        }
        nw[a[i]].clear();
    }
    int ans = 0;
    for (int i = 0; i < 8192; ++i)
        if (f[i] != 5001) ans++;
    printf ("%d\n", ans);
    for (int i = 0; i < 8192; ++i)
        if (f[i] != 5001) printf ("%d ", i);
    puts("");
    return 0;
}