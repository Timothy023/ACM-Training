#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int I(){
	int s=0,f=1;char ch=getchar();
	while (ch<'0' || ch>'9'){if (ch=='-')f=-1;ch=getchar();}
	while (ch>='0' && ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*f;
}
int n,x,y,a[2048][2048];
void dfs(int x1,int y1,int x2,int y2,int X,int Y){
	if (x2-x1==1){
		if (X==x1 && Y==y1)a[x2][y2]=1;
		else if (X==x1 && Y==y2)a[x2][y1]=2;
		else if (X==x2 && Y==y1)a[x1][y2]=3;
		else if (X==x2 && Y==y2)a[x1][y1]=4;
		return;
	}
	int mx=(x1+x2)>>1,my=(y1+y2)>>1;
	if (X<=mx && Y<=my){
		dfs(x1,y1,mx,my,X,Y);
		dfs(mx+1,y1,x2,my,mx+1,my);
		dfs(x1,my+1,mx,y2,mx,my+1);
		dfs(mx+1,my+1,x2,y2,mx+1,my+1);
		a[mx+1][my+1]=1;
	}
	else if (X>mx && Y<=my){
		dfs(x1,y1,mx,my,mx,my);
		dfs(mx+1,y1,x2,my,X,Y);
		dfs(x1,my+1,mx,y2,mx,my+1);
		dfs(mx+1,my+1,x2,y2,mx+1,my+1);
		a[mx][my+1]=3;
	}
	else if (X<=mx && Y>my){
		dfs(x1,y1,mx,my,mx,my);
		dfs(mx+1,y1,x2,my,mx+1,my);
		dfs(x1,my+1,mx,y2,X,Y);
		dfs(mx+1,my+1,x2,y2,mx+1,my+1);
		a[mx+1][my]=2;
	}
	else if (X>mx && Y>my){
		dfs(x1,y1,mx,my,mx,my);
		dfs(mx+1,y1,x2,my,mx+1,my);
		dfs(x1,my+1,mx,y2,mx,my+1);
		dfs(mx+1,my+1,x2,y2,X,Y);
		a[mx][my]=4;
	}
}
int main (){
	freopen ("in.txt","r",stdin);
	freopen ("ans.txt","w",stdout);
	n=I();x=I();y=I();n=(1<<n);
	memset(a,0,sizeof(a));
	dfs(1,1,n,n,x,y);
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
			if (a[i][j]!=0)printf ("%d %d %d\n",i,j,a[i][j]);
	return 0;
}
