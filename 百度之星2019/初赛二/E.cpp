#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<queue>
using namespace std;
const int N=5e5+5;
int T,n,a[N],st;
int l[N],r[N],le[N],ri[N];
int ne[N<<1],fi[N<<1],step,t[N<<1],du[N<<1],lj[N<<1];
bool flag[N],pd;
priority_queue<int>que;
void addedge(int fr,int to){
//	cout <<"Add: "<<fr<<"  "<<to<<endl;
	t[++step]=to;ne[step]=fi[fr];fi[fr]=step;du[to]++;
}
int main (){
	scanf ("%d",&T);
	while (T--){
		scanf ("%d",&n);
		st=-1;step=0;pd=0;
		flag[0]=flag[n+1]=1;
		for (int i=1;i<=n;++i)fi[i]=0;
		for (int i=1;i<=n;++i){
			scanf ("%d",&a[i]);
			le[i]=ri[i]=i;lj[i]=0;du[i]=0;
			l[i]=i-1;r[i]=i+1;flag[i]=0;
			if (i!=1 && a[i]==a[i-1] && st==-1)st=i-1;
		}
		if (st==-1){
			puts("Impossible");
			continue;
		}
		for (int i=1;i<n;++i){
			addedge(ri[st],lj[st]);
			addedge(ri[st],lj[r[st]]);
			lj[st]=ri[st];
			ri[st]=ri[r[st]];
			r[st]=r[r[st]];
			l[r[st]]=st;
			a[st]--;
//			cout <<"st: "<<st<<"  "<<l[st]<<"  "<<r[st]<<"  "<<le[st]<<"  "<<ri[st]<<"  "<<a[st]<<"  "<<lj[st]<<endl;
			if (i==n-1)break;
			if (a[st]==0){
				puts("Impossible");
				pd=1;break;
			}
			if (!flag[l[st]] && a[l[st]]==a[st])st=l[st];
			else {
				for (;!flag[r[st]] && a[st]!=a[r[st]];st=r[st]);
				if (flag[r[st]]){
				}
			}
		}
		if (pd)continue;
		puts("Possible");
		while (!que.empty())que.pop();
		for (int i=1;i<n;++i)
			if (du[i]==0){
				que.push(-i);
				flag[i]=1;
			}
		for (int i=1;i<n;++i){
			st=-que.top();que.pop();
			cout <<st;
			if (i==n-1)puts("");
			else putchar(' ');
			for (int u=fi[st];u;u=ne[u]){
				du[t[u]]--;
				if (du[t[u]]==0 && !flag[t[u]]){
					que.push(-t[u]);
					flag[t[u]]=1;
				}
			}
		}
	}
	return 0;
}
