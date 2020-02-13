#include<bits/stdc++.h>
#define N 2010
using namespace std;
struct Row{
	int a[5],ma;
}r[N];
int t,n,m,z[5],da[5],ans;
inline bool cmp(Row a,Row b){
	return a.ma>b.ma;
}
void dfs(int p){
	if(p==n||p==m){
		memset(da,0,sizeof(da));
		for(int i=0;i<n;i++){
			for(int j=0;j<min(n,m);j++){
				da[(i+z[j])%n]=max(da[(i+z[j])%n],r[j].a[i]);
			}
		}
		int tot=0;
		for(int i=0;i<n;i++) tot+=da[i];
		ans=max(ans,tot);
		return;
	}
	for(int  i=0;i<n;i++){
		z[p]=i;
		dfs(p+1);
	}
}
int main(){
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++) r[i].ma=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&r[j].a[i]);
				r[j].ma=max(r[j].ma,r[j].a[i]);
			}
		}
		sort(r,r+m,cmp);
		dfs(0);
		cout<<ans<<"\n";
	}
	return 0;
}
