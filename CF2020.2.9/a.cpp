#include <bits/stdc++.h>
using namespace std;

int I() {
	int s = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
	return s * f;
}

const int N = 1e5 + 5;
int n, a[N], sum[35], ans = -1, wz;

int main () {
	n = I();
	for (int i = 1; i <= n; ++i) {
		a[i] = I();
		for (int j = 0; j <= 30; ++j) {
			if (a[i] & (1 << j)) sum[j]++;
		}
	}
	for (int i = 1; i <= n; ++i) {
		int tmp = 0;
		for (int j = 0; j <= 30; ++j) {
			if (a[i] & (1 << j)) {
				if (sum[j] == 1) tmp += (1 << j);
			}
		}
		if (tmp > ans) {
			ans = tmp;
			wz = i;
		}
	}
	printf ("%d", a[wz]);
	for (int i = 1; i <= n; ++i) {
		if (i == wz) continue;
		printf (" %d", a[i]);
	}
	return 0;
}