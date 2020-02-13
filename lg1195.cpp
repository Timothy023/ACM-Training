#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int N=1005;
const int M=10005;
struct node{
	int x,y,z;
	friend bool operator < (node i,node j){
		return i.z<j.z;
	}
}e[M];
int n,m,k,sum,t1,t2;
int fa[N],ans;
int get_fa(int x){
	return (fa[x]==x)?(fa[x]):(fa[x]=get_fa(fa[x]));
}
int main (){
	scanf ("%d%d%d",&n,&m,&k);sum=n;
	for (int i=1;i<=m;++i)
		scanf ("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
	for (int i=1;i<=n;++i)fa[i]=i;
	sort(e+1,e+m+1);
	for (int i=1;i<=m && sum>k;++i){
		t1=get_fa(e[i].x);
		t2=get_fa(e[i].y);
		if (t1!=t2){
			fa[t1]=t2;
			ans+=e[i].z;
			sum--;
		}
	}
	if (sum!=k)puts("No Answer");
	else printf ("%d\n",ans);
	return 0;
}
