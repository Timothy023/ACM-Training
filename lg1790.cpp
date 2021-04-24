#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int n,m,ans;
int fx[4]={0,1,0,-1};
int fy[4]={1,0,-1,0};
bool vis[10][10];
void dfs(int x,int y){
	if (vis[x][y])return;
	if (x==1 || x==n || y==1 || y==m){
		ans++;
		return;
	}
	vis[x][y]=1;
	for (int i=0;i<4;++i)
		dfs(x+fx[i],y+fy[i]);
	vis[x][y]=0;
}
int main (){
	scanf ("%d%d",&n,&m);
	n++;m++;
	for (int i=2;i<n;++i){
		vis[i][1]=1;
		dfs(i,2);
		vis[i][1]=0;
	}
	for (int i=2;i<m;++i){
		vis[1][i]=1;
		dfs(2,i);
		vis[1][i]=0;
	}
	printf ("%d\n",ans);
	return 0;
}
