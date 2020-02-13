#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int x,y,c,cnt,n;
int fx1[5]={0,-1,0,-1,1};
int fy1[5]={0,0,-1,0,0};
int fx2[5]={0,0,1,0,0};
int fy2[5]={0,1,0,-1,1};
int map[2048][2048];
int change(int x){
	if (x==2)return 1;
	else if (x==3)return 2;
	else if (x==1)return 3;
	else if (x==4)return 4;
}
int main (){
	freopen ("ans.txt","r",stdin);
	while (scanf ("%d%d%d",&x,&y,&c)!=EOF){
		c=change(c);
		map[x][y]=map[x+fx1[c]][y+fy1[c]]=map[x+fx2[c]][y+fy2[c]]=++cnt;
		n=max(x,max(x+fx1[c],x+fx2[c]));
	}
	for (int i=1;i<=n;++i,puts(""))
		for (int j=1;j<=n;++j)
			printf ("%-4d",map[i][j]);
	return 0;
}
