#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

const int N = 1e5 + 5;
int a[N];
int n;
long long ans;

int main () {
    n = I();
    for (int i = 1; i <= n; ++i) {
        a[i] = I();
        ans += a[i];
        ans -= (i - 1);
    }
    cout <<ans <<endl;
    return 0;
}