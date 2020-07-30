#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int T, len[N], f[N], n;
char ch[N][15];

bool judge(int i, int j) {
	if (len[i] != len[j]) return false;
	for (int k = 0; k < len[i]; ++k)
		if (ch[i][k] != ch[j][k]) return false;
	return true;
}

int main () {
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d", &n);
		for (int i = 1; i <= n; ++i) f[i] = 0;
		for (int i = 1; i <= n; ++i) {
			scanf ("%s", ch[i]);
			len[i] = strlen(ch[i]);
		}
		f[0] = 1;
		for (int i = 0; i <= n; ++i) {
			f[i + 1] = (f[i + 1] + f[i]) % mod;
			if (i + 2 <= n && !judge(i + 1, i + 2))
				f[i + 2] = (f[i + 2] + f[i]) % mod;
		}
		printf ("%d\n", f[n]);
	}
	return 0;
}
