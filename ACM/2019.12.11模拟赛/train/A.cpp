#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int mod = 1000000007;
const int N = 1e5+5;
int T, n, k;
int c[N], jc[N], ny[N], ans, tmp;

int ksm(int i, int j) {
	int s = 1;
	while (j) {
		if (j & 1)
			s = 1ll * s * i % mod;
		i = 1ll * i * i %mod;
		j >>= 1;
	}
	return s;
}

int main () {
	scanf ("%d", &T);
	jc[1] = 1;
	for (int i = 2; i <= N - 5; ++i) jc[i] = 1ll * jc[i-1] * i %mod;
	for (int i = 1; i <=N - 5; ++i) ny[i] = ksm(jc[i], mod-2);
	for (int step = 1; step <= T; ++step) {
		scanf ("%d%d", &n, &k);
		ans = ksm(2,n); tmp = 1; ans = (ans - 1) %mod;
		for (int i = 1; i < k; ++i) {
			tmp = 1ll * tmp * (n - i + 1) % mod;
			ans = (ans - (1ll * tmp * ny[i]) % mod) % mod;
		}
		ans = (ans + mod) % mod;
		printf ("Case #%d: %d\n", step, ans);
	}
	return 0;
}
