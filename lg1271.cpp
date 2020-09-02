#include <bits/stdc++.h>
using namespace std;

int s[1000];
int n, m, x;

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf ("%d", &x);
        s[x] += 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= s[i]; ++j) printf ("%d ", i);
    }
    return 0;
}