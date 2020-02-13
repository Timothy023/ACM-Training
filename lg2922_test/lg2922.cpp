#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int N=50005;
int m,n;
int ne[500005][2],root,cnt,sum[500005],siz[500005];
char ch[N];
void dfs(int ro){
	siz[ro]=sum[ro];
	for (int i=0;i<=1;++i){
		if (!ne[ro][i])continue;
		dfs(ne[ro][i]);
		siz[ro]+=siz[ne[ro][i]];
	}
}
void insert(){
	int len,now=root,x;
	scanf ("%d",&len);
	for (int i=1;i<=len;++i){
		scanf ("%d",&x);
		if (!ne[now][x])
			ne[now][x]=++cnt;
		now=ne[now][x];
	}
	sum[now]++;
}
void query(){
	bool flag=1;
	int len,x,now=root,ans=0;
	scanf ("%d",&len);
	for (int i=1;i<=len;++i){
		scanf ("%d",&x);
		ans+=sum[now];
		if (!ne[now][x]){
			flag=0;
			for (int j=i+1;j<=len;++j)
				scanf ("%d",&x);
			break;
		}
		now=ne[now][x];
	}
	if (flag)ans+=siz[now];
	printf ("%d\n",ans);
}
int main (){
	scanf ("%d%d",&m,&n);
	for (int i=1;i<=m;++i)insert();
	dfs(root);
	for (int i=1;i<=n;++i)query();
	return 0;
}
