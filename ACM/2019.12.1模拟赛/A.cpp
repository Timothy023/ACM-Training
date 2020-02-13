#include<bits/stdc++.h>
#define N 200100
using namespace std;
struct Edge{
	int x,y,v;
}e[N*70],src[N];
bool cmp(Edge a,Edge b){
	return a.v<b.v;
}
int a[N],b[N],c[N];
long long ans[N];
int fa[N*70];
int n,M,m,len;
int find_fa(int p){
	if(fa[p]==p) return p;
	return fa[p]=find_fa(fa[p]);
}
long long kru(int t){
	for(int i=1;i<=t;i++) fa[i]=i;
	long long tot=0;
	for(int i=0;i<len;i++){
		int l=find_fa(e[i].x),r=find_fa(e[i].y);
		if(l==r) continue;
		tot+=e[i].v;
		fa[l]=r;
	}
	return tot;
}
int main(){
	scanf("%d%d%d",&n,&M,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		src[i]=(Edge){a[i],b[i],c[i]};
	}
	sort(src,src+m,cmp);
	for(int i=1;i<=70;i++){
		for(int j=m-1;j>=0;j--){
			for(int k=0;k<i;k++){
				e[j*i+k]=(Edge){src[j].x+k*n,src[j].y+k*n+n,src[j].v};
			}
		}
		len=i*m;
		ans[i]=kru(i*n+n);
	}
	for(int i=1;i<=M;i++){
		if(i<=70) cout<<ans[i]<<"\n";
		else cout<<(ans[70]-ans[69])*(i-70)+ans[70]<<"\n";
	}
	return 0;
}
