#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int N=1e5+5;
int a[N],n,m,k,x,y;
int main (){
	scanf ("%d%d",&n,&m);
	for (int i=1;i<=m;++i){
		scanf ("%d%d%d",&k,&x,&y);
		if (k==1)a[x]=y;
		else {
			int ans=0;
			for (int j=x;j<=y;++j)
				ans+=a[j];
			printf ("%d\n",ans);
		}
	}
	return 0;
}
