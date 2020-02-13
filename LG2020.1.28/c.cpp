#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

const int N = 1e6 + 5;
int n, a[N], k, p, q, ans[N], sum, s[N];
bool flag;

bool check(int st, int en, int val) {
    if (s[en] - s[st] <= val) return true;
    else return false;
}

int main () {
    n = I();
    for (int i = 1; i <= n; ++i) {
        a[i] = I();
        s[i] = a[i] + s[i - 1];
    }
    k = I();
    p = q = 0;
    for (int i = 1; i <= k; ++i) {
        flag = 0;
        for (;;) {
            for (; check(p, q + 1, i) && q + 1 <= n; ++q);
            if (s[p] - s[0] > s[q] - s[p]) {
                flag = 1; break;
            }
            if (flag) break;
            if (check(0, p + 1, i) && p + 1 <= n) ++p;
            else break;
        }
        if (flag) ans[++sum] = i;
    }
    printf ("%d\n", sum);
    for (int i = 1; i <= sum; ++i)
        printf ("%d ", ans[i]);
    return 0;
}