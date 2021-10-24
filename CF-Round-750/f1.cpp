#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
int a[N];
int f[512], g[512];

int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf ("%d", &a[i]);
    }
    for (int i = 0; i < 512; ++i) f[i] = 1000;
    f[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 512; ++j) g[j] = 1000;
        for (int j = 0; j < 512; ++j) {
            if (f[j] < a[i]) {
                g[j ^ a[i]] = a[i];
            }
        }
        for (int j = 0; j < 512; ++j) f[j] = min(f[j], g[j]);
    }
    int ans = 0;
    for (int i = 0; i < 512; ++i)
        if (f[i] != 1000) ans++;
    printf ("%d\n", ans);
    for (int i = 0; i < 512; ++i)
        if (f[i] != 1000) printf ("%d ", i);
    puts("");
    return 0;
}