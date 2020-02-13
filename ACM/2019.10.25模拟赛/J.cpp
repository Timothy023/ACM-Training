#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int N=1e6+5;
const int maxn=1e6;
int n,a[N],pri[N],p[N],len;
int le[N];
bool flag[N];
long long ans,sum,s;
void init() {
	for (int i=2;i<=maxn;++i) {
		if (!flag[i]){
			p[++len]=i;
			pri[i]=i;
		}
		for (int j=1;j<=len && i*p[j]<=maxn;++j){
			flag[i*p[j]]=1;
			pri[i*p[j]]=p[j];
			if (i%p[j]==0)break;
		}
	}
}
int main (){
	init();
	scanf ("%d",&n);
	for (int i=1;i<=n;++i)scanf ("%d",&a[i]);
	for (int i=1,x,lp;i<=n;++i){
		s=0;
		if (a[i]==1){
			ans+=sum;
			continue;
		}
		for (x=a[i];x>1;) {
			lp=pri[x];
			while (pri[x]==lp)x/=lp;
			sum+=(i-le[lp]);
			le[lp]=i;
		}
		ans+=sum;
	}
	cout <<ans<<endl;
	return 0;
}
