#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int T, n;
int tim, d, a, mi, sum;

int main () {
	scanf ("%d", &T);
	while (T--) {
		mi = -1; sum = 0;
		scanf ("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf ("%d%d", &a, &d);
			tim = 100 / a;
			if (100 % a == 0) tim--;
			tim *= d;
			if (mi == -1 || tim < mi) {
				mi = tim; sum = 1;
			}
			else if (tim == mi) sum++;
		}
		double ans = 0.5 * sum / n + 1.0 * (n - sum) / n;
		printf ("%.6lf\n", ans);
	}
	return 0;
}
