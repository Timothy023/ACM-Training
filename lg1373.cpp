#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

const int mod = 1000000007;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <='9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

int n, m, k, ans;
int f[805][805][20][2];
int a[805][805];

int main () {
#ifdef debug
	freopen ("P1373_6.in", "r", stdin);
#endif
	scanf ("%d%d%d", &n, &m, &k); ++k;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			scanf ("%d", &a[i][j]);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			f[i][j][(a[i][j] % k + k) % k][0] = 1;
			for (int p = 0; p < k; ++p){
					if (i - 1 >= 1) {
						f[i][j][p][0] = (f[i][j][p][0] + f[i - 1][j][((p - a[i][j]) % k + k) % k][1]) % mod;
						f[i][j][p][1] = (f[i][j][p][1] + f[i - 1][j][((p + a[i][j]) % k + k) % k][0]) % mod;
					}
					if (j - 1 >= 1) {
						f[i][j][p][0] = (f[i][j][p][0] + f[i][j - 1][((p - a[i][j]) % k + k) % k][1]) % mod;
						f[i][j][p][1] = (f[i][j][p][1] + f[i][j - 1][((p + a[i][j]) % k + k) % k][0]) % mod;
					}
				}
			}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			ans = (ans + f[i][j][0][1]) % mod;
	printf ("%d\n", ans);
    return 0;
}