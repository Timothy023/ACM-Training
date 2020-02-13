#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int N=1e6+5;
int s[2005],n,m,T,ans,x,y;
int sor[2005],len;
int main (){
	scanf ("%d",&T);
	for (int step=1;step<=T;++step){
		ans=0;
		memset(s,0,sizeof(s));
		scanf ("%d%d",&n,&m);
		for (int i=1;i<=m;++i){
			scanf ("%d%d",&x,&y);
			for (int j=x;j<=y;++j)
				s[j]++;
		}
		for (int i=1;i<=n;++i)
			if (s[i]&1)ans++;
		printf ("Case #%d: %d\n",step,ans);
	}
	return 0;
}
