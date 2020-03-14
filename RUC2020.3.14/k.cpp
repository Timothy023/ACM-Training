#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

const int N = 1e6 + 5;
int n, maxn;
int a[N], b[N], m;
int ans[N], len;
map<int, int> sum;

int main () {
    n = I(); maxn = (1 << n);
    for (int i = 1; i <= maxn; ++i)
        a[i] = I();
    sort(a + 1, a + maxn + 1);
    if (a[1] != 0) {
        puts("impossible");
        return 0;
    }
    for (int i = 2; i <= maxn; ++i) {
        if (sum.find(a[i]) == sum.end()) {
            if (len == n) {
                puts("impossible");
                return 0;
            }
            ans[++len] = a[i];
            int tmp = m;
            b[++m] = a[i];
            for (int j = 1; j <= tmp; ++j) {
                m += 1;
                b[m] = b[j] + a[i];
                if (sum.find(b[m]) == sum.end()) sum.insert(make_pair(b[m], 1));
                else sum[b[m]] += 1;
            }
        }
        else {
            sum[a[i]]--;
            if (sum[a[i]] == 0)
                sum.erase(a[i]);
        }
    }
    if (len != n) {
        puts("impossible");
        return 0;
    }
    for (int i = 1; i <= len; ++i)
        printf ("%d\n", ans[i]);
    return 0;
}