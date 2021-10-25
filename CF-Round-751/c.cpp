#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int T;
int n, a[N];
int s[30];

int gcd(int i, int j) {
    if (j == 0) return i;
    else return gcd(j, i % j);
}

int main () {
    scanf ("%d", &T);
    while (T--) {
        scanf ("%d", &n);
        memset(s, 0, sizeof(s));
        for (int i = 1; i <= n; ++i) {
            scanf ("%d", &a[i]);
            for (int j = 0; j < 30; ++j) {
                if ((a[i] & (1 << j)) != 0)
                    s[j] += 1;
            }
        }
        int ans = 0;
        for (int j = 0; j < 30; ++j)
            ans = gcd(ans, s[j]);
        for (int i = 1; i <= n; ++i) {
            if (ans % i == 0) printf ("%d ", i);
        }
        puts("");
    }
    return 0;
}