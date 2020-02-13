#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int tim, siz, cnt, root, step, x[105], y[105];
int ls[105], rs[105], f[105][605];
int max ( int a, int b ) {
	if ( a >= b ) return a;
	else return b;
}
void dfs ( int &ro ) {
	ro = ++siz;
	if ( y[ro] != 0 ) {
		for (int j=1;j<=y[step];++j)
			for (int i=x[step]+5*j ; i <= tim ; ++i)
				f[ro][i] = j;
		return;
	}
	int u = 0, v=0, i, j, st=step;
	step++; dfs ( u );
	step++; dfs ( v );
//	cout <<ro<<"  "<<st<<"  "<<u<<"  "<<v<<"  "<<x[st]<<endl;
	for ( i = x[st]; i <= tim; ++i) {
		for ( j = 0; j <= i - x[st]; ++j) {
			f[ro][i] = max ( f[ro][i], f[u][j] + f[v][i-x[st]-j]);

		}
	}

}
int main ()
{
	scanf ("%d", &tim);
	tim--; cnt = 1;
	while ( scanf ("%d%d", &x[cnt], &y[cnt]) != EOF ) {
		x[cnt] = x[cnt] * 2;
		cnt++;
	}
	step = 1;
	dfs ( root );
	printf ("%d\n", f[root][tim]);
	return 0;
}
