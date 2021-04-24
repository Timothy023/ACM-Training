#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

const int N = 1e6 + 5;
int n;
long long a[N], s[N], tmp, ans;

int main () {
    n = I();
    for (int i = 1; i <= n; ++i) {
        a[i] = I();
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1; i < n; ++i) {
        tmp += a[i] * a[i];
        ans = max(ans, tmp * (s[n] - s[i]));
    }
    cout <<ans <<endl;
    return 0;
}