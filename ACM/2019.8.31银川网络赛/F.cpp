#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
struct node{
	int x,y,p,id;
	friend bool operator < (node i,node j){
		return i.p<j.p;
	}
}q[20005];
int T,n,m,a[205],dis[205][205],ans[20005];
bool flag[205];
void solve(){
	memset(flag,0,sizeof(flag));
	memset(dis,127,sizeof(dis));
	scanf ("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		scanf ("%d",&a[i]);
		dis[i][i]=0;
	}
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
			scanf ("%d",&dis[i][j]);
	for (int i=1;i<=m;++i){
		scanf ("%d%d%d",&q[i].x,&q[i].y,&q[i].p);
		q[i].id=i;
	}
	sort(q+1,q+m+1);
	for (int t=1;t<=m;++t){
		for (int k=1;k<=n;++k){
			if (flag[k] || a[k]>q[t].p)continue;
			flag[k]=1;
			for (int i=1;i<=n;++i)
				for (int j=1;j<=n;++j)
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
		ans[q[t].id]=dis[q[t].x][q[t].y];
	}
	for (int i=1;i<=m;++i)
		printf ("%d\n",ans[i]);
}
int main (){
	scanf ("%d",&T);
	for (int i=1;i<=T;++i){
		printf ("Case #%d:\n",i);
		solve();
	}
	return 0;
}
