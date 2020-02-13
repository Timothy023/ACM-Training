#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
int n, m, k, x, sum;
bool ans[1005][1005];
int main () {
	scanf ("%d%d%d", &n, &m, &k);
	for (int i=1;i<=n;++i){
		for (int j=1;j<=m;++j){
			scanf ("%d",&x);
			ans[x][j]=1;
		}
	}
	for (int i=1;i<=k;++i){
		sum=0;
		for (int j=1;j<=m;++j)
			if (ans[i][j])sum++;
		printf ("%d ",sum);
	}
	return 0;
}
