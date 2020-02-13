#include <iostream>
int T, a, b, n, m;
int main () {
	scanf ("%d",&T);
	while (T--) {
		scanf ("%d%d",&n,&m);
		for (int i=1; i<=n;++i)scanf ("%d",&a);
		for (int i=1; i<=m;++i)scanf ("%d",&a);
		puts(n>m?"No":"Yes");
	}
	return 0;
}
