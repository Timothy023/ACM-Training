#include <bits/stdc++.h>
using namespace std;

inline int I() {
    int s = 0; char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s;
}

const int N = 1e6 + 5;
int n, k, x, y, ans;
long long sum[N], mon;

int main () {
    n = I();
    for (int i = 1; i <= n; ++i) {
        k = I();
        mon += sum[i];
        if (k == 1) {
            x = I();
            mon += x;
        }
        else if (k == 2) {
            x = I();
            if (x > mon) ans++;
            else mon -= x;
        }
        else {
            x = I(); y = I();
            sum[y] += x;
            mon -= x;
        }
    }
    printf ("%d\n", ans);
    return 0;
}