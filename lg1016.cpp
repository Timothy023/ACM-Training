#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
double d1,c,d2,p[10],dis[10],ans=1e9;
int n;
void dfs(int step,double y,double cost){
	if (cost>=ans)return;
	if (step==n){
		ans=cost;
		return;
	}
	double ls=0.0,tmp;
	for (int i=step+1;i<=n;++i){
		tmp=(dis[i]-dis[step])/d2;
		if (tmp>c)break;
		ls=max(0.0,tmp-y);
		dfs(step+1,y+ls-(dis[step+1]-dis[step])/d2,cost+ls*p[step]);
	}
	dfs(step+1,c-(dis[step+1]-dis[step])/d2,cost+(c-y)*p[step]);
}
int main (){
	scanf ("%lf%lf%lf%lf%d",&d1,&c,&d2,&p[0],&n);
	for (int i=1;i<=n;++i){
		scanf ("%lf%lf",&dis[i],&p[i]);
		if (dis[i]-dis[i-1]>c*d2){
			puts("No Solution");
			return 0;
		}
	}
	dis[++n]=d1;
	if (dis[n]-dis[n-1]>c*d2){
		puts("No Solution");
		return 0;
	}
	dfs(0,0,0);
	printf ("%.2lf\n",ans);
	return 0;
}
