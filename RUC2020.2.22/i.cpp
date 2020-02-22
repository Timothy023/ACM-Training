#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

const int mod = 1e9 + 7;
int n, kk, m;
int x, y, v;
int maxn[3], minn[3], val[3], s[3];
int a[2][100005];
int ans;

int ksm(int i, int j) {
    // cout <<"ksm: " <<i <<"  " <<j <<endl;
    int sum = 1;
    while (j) {
        if (j & 1)
            sum = 1ll * sum * i % mod;
        i = 1ll * i * i % mod;
        j >>= 1;
    }
    return sum;
}

int main () {
    // freopen ("test.in", "r", stdin);
    // freopen ("test.out", "w", stdout);
    val[0] = val[1] = val[2] = -1;
    maxn[0] = maxn[1] = maxn[2] = 0;
    minn[0] = minn[1] = minn[2] = 9;
    memset(a, -1, sizeof(a));
    n = I(); kk = I(); m = I();
    for (int i = 1; i <= m; ++i ) {
        y = I() + 1; x = I(); v = I();
        a[x][y] = v;
    }
    for (int i = 1; i <= n; ++i) {
        int ki = i % 3;
        if (a[0][i] != -1 && a[1][i] != -1) {
            if (val[ki] != -1 && val[ki] != a[0][i] + a[1][i]) {
                puts("0");
                return 0;
            }
            else val[ki] = a[0][i] + a[1][i];
        }
        else if (a[0][i] != -1 || a[1][i] != -1) {
            maxn[ki] = max(maxn[ki], a[0][i] + a[1][i] + 1);
            minn[ki] = min(minn[ki], a[0][i] + a[1][i] + 1);
        }
        else s[ki]++;
    }
    // cout <<s[0] <<"  " <<s[1] <<"  " <<s[2] <<endl;
    for (int i = 0; i <= kk; ++i) {
        for (int j = 0; j <= kk - i; ++j) {
            int tmp = ans;
            int z = kk - i - j;
            if ((val[0] != i && val[0] != -1) ||
                (val[1] != j && val[1] != -1) ||
                (val[2] != z && val[2] != -1)) continue;
            if ((maxn[0] > i || i - minn[0] > 9) ||
                (maxn[1] > j || j - minn[1] > 9) ||
                (maxn[2] > z || z - minn[2] > 9)) continue;
            if (i > 18 || j > 18 || z > 18) continue;
            ans = (ans + 1ll * ksm(min(9, i) - max(0, i - 9) + 1, s[0]) 
                             * ksm(min(9, j) - max(0, j - 9) + 1, s[1]) % mod 
                             * ksm(min(9, z) - max(0, z - 9) + 1, s[2]) % mod) % mod;
            // cout <<i <<"  " <<j <<"  " <<z <<"  " <<ans - tmp <<endl;
        }
    }
    cout <<ans <<endl;
    return 0;
}
