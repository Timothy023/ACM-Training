#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;
const int N=2e5 + 5;
struct node {
	int val;
	int pos;
}a[N], b[N];
int T, n, p[N], x, la, lb;
bool flag;
int main () {
	scanf ("%d", &T);
	for (int step = 1; step <= T; ++step){
		scanf ("%d", &n);
		la = lb = 0; p[n + 1] = 0;
		for (int i = 1; i <= n + 1; ++i) {
			if (i <= n) scanf ("%d", &p[i]);
			x = p[i] - p[i - 1];
			if (x > 0) {
				la++;
				a[la].val=x; a[la].pos=i;
			}
			else if (x < 0) {
				lb++;
				b[lb].val=-x; b[lb].pos=i - 1;
			}
		}
		flag = 1;
		int i, j;
		for (i = 1, j = 1; i <= la && j <= lb;) {
			if (a[i].pos + 1 >= b[j].pos) {
				flag = 0; break;
			}
			if (a[i].val>b[j].val){
				a[i].val -= b[j].val;
				++j;
			}
			else if (a[i].val < b[j].val) {
				b[j].val -= a[i].val;
				++i;
			}
			else {
				++i; ++j;
			}
		}
		if (i <= la || j <= lb) flag = 0;
		if (flag) printf ("Case #%d: Yes\n", step);
		else printf ("Case #%d: No\n", step);
	}
	return 0;
}
