#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int N=1e6+5;
int s[2005],n,m,T,ans,x[2005],y[2005];
int sor[2005],len;
int main (){
	scanf ("%d",&T);
	for (int step=1;step<=T;++step){
		ans=len=0;
		memset(s,0,sizeof(s));
		scanf ("%d%d",&n,&m);
		for (int i=1;i<=m;++i){
			scanf ("%d%d",&x[i],&y[i]);
			x[i]++;y[i]++;
			sor[++len]=x[i];sor[++len]=y[i]+1;
		}
		sor[++len]=n+1;
		sort(sor+1,sor+len+1);
//		for (int i=1;i<=len;++i)cout <<sor[i]<<"  ";cout <<endl;
		len=unique(sor+1,sor+len+1)-(sor+1);
//		for (int i=1;i<=len;++i)cout <<sor[i]<<"  ";cout <<endl;
		for (int i=1;i<=m;++i){
			x[i]=lower_bound(sor+1,sor+len+1,x[i])-sor;
			y[i]=lower_bound(sor+1,sor+len+1,y[i]+1)-sor;
		}
		for (int i=1;i<=m;++i){
//			cout <<x[i]<<"  "<<y[i]<<endl;
			s[x[i]]++;s[y[i]]--;
		}
		for (int i=2;i<=len;++i){
			s[i]+=s[i-1];
			if (s[i-1]%2)ans+=(sor[i]-sor[i-1]);
		}
//		for (int i=1;i<=len;++i)cout <<s[i]<<"  ";cout <<endl;
//		for (int i=1;i<=len;++i)cout <<sor[i]<<"  ";cout <<endl;
		printf ("Case #%d: %d\n",step,ans);
	}
	return 0;
}
