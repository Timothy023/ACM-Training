#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

const int N = 1e5 + 5;
int n, x, y;
int sum[N], ans;

int main () {
    n = I();
    for (int i = 1; i < n; ++i) {
        x = I(); y = I();
        sum[x]++; sum[y]++;
        if (sum[x] == 1) ans++;
        if (sum[y] == 1) ans++;
        if (sum[x] == 2) ans--;
        if (sum[y] == 2) ans--;
    }
    cout <<ans <<endl;
    return 0;
}