#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

int a[1000006];
int s[10000006];
int n, T, maxn;
long long ans, tmp;

int main () {
    T = I();
    for (int step = 1; step <= T; ++step) {
        n = I();
        ans = tmp = maxn = 0;
        for (int i = 1; i <= n; ++i) {
            a[i] = I();
            s[a[i]]++;
            maxn = max(maxn, a[i]);
            if (a[i] == 0) tmp++;
        }
        sort(a + 1, a + n + 1);
        ans = tmp * (n - tmp); tmp = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] == 0) continue;
            if (a[i] == a[i - 1]) {
                ans += tmp;
                continue;
            }
            tmp = 0;
            for (int j = 2; a[i] * j <= maxn; ++j) {
                tmp += s[a[i] * j];
            }
            ans += tmp;
        }
        for (int i = 1; i <= n; ++i) {
            s[a[i]] = 0;
        }
        printf ("Test case #%d: %lld\n\n", step, ans);
    }
    return 0;
}