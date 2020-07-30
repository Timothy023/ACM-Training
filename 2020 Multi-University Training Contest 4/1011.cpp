#include <bits/stdc++.h>
using namespace std;

const double G = 6.67430e-11;

int T;
double a, b, d, t0;

int main () {
	scanf ("%d", &T);
	while (T--) {
		cin >>a >>b >>d >>t0;
		printf ("%.6lf\n", d);
	}
	return 0;
}
