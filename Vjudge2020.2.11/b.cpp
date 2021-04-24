#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

const int N = 15;
int n, m, all;
long long sum[1 << N], a[N], b[N];
set <long long> s, ans;

int main () {
    n = I(); m = I();
    for (int i = 1; i <= n; ++i) a[i] = I();
    for (int i = 1; i <= m; ++i) b[i] = I();
    all = (1 << m) - 1;
    for (int i = 0; i <= all; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i & (1 << (j - 1)))
                sum[i] += b[j];
        }
    }
    s.insert(0);
    for (int i = 1; i <= all; ++i) {
        for (int j = (i - 1) & i; j; j = (j - 1) & i) {
            if (sum[j] * 2 == sum[i]) {
                if (s.find(sum[i]) == s.end()) {
                    s.insert(sum[i]);
                    break;
                }
            }
        }
    }
    for (int j = 1; j <= n; ++j)
        for (auto i: s) {
            if (ans.find(a[j] + i) == ans.end()) {
                ans.insert(a[j] + i);
            }
        }
    for (auto i: ans) printf ("%I64d\n", i);
    return 0;
}b.