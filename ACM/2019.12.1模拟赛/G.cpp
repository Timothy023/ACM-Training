#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N=1e6+5;
int T,n,m,k,as;
int b[N], c[N], lb, lc, sc[N];
char t[N];
vector<int>ans[N];
bool flag;
int main () {
	scanf ("%d",&T);
	while (T--) {
		scanf ("%d%d%d",&n,&m,&k);
		if (!(n%k==0 && n/k>=m)) {
			puts("No");
			continue;
		}
		scanf ("%s",t+1);
		sc[n+1]=0;as=lb=lc=0;flag=0;
		for (int step=1,i=1,j;step<=m;++step) {
			for (;i<=n;++i) {
				if (t[i]=='B') {
					for (j=i+1;j<=n;++j) {
						if (t[j]=='B')break;
					}
					if (j==n+1){
						flag=1;break;
					}
				}
			}
			if (flag)break;
		}
		if (flag){
			puts("No");
		}
		else {
			puts("Yes");
			for (int i=1;i<=as;++i){
				printf ("%d ", ans[as].size());
				for (int j=0;j<ans[as].size();++j)
					printf ("%d ", ans[as][j]);
				puts("");
			}
		}
		for (int i=1;i<=as;++i)ans[as].clear();
	}
	return 0;
}
