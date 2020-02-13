#include<bits/stdc++.h>
#define M 2000010
#define N 1510
using namespace std;
int beg[N],dis[N],sav[N];
int nex[M],to[M],ll[M];
int n,m,k,S,S1,S2,T,len=1;
queue<int> q;
inline void Add(int a,int b,int c){
	nex[++len]=beg[a],beg[a]=len,to[len]=b,ll[len]=c;
	nex[++len]=beg[b],beg[b]=len,to[len]=a,ll[len]=0;
}
int dfs(int p,int flo){
	if(p==T) return flo;
	int tot=0;
	for(int &i=sav[p];i;i=nex[i]){
		if(dis[to[i]]==dis[p]+1&&ll[i]){
			int f=dfs(to[i],min(flo,ll[i]));
			if(f){
				ll[i]-=f;
				ll[i^1]+=f;
				tot+=f;
				flo-=f;
			}
		}
	}
	return tot;
}
int bfs(){
	while(!q.empty()) q.pop();
	memset(dis,-1,sizeof(dis));
	dis[S]=0;q.push(S);
	while(!q.empty()){
		int p=q.front();q.pop();
		for(int i=beg[p];i;i=nex[i]){
			if(dis[to[i]]==-1&&ll[i]){
				dis[to[i]]=dis[p]+1;
				q.push(to[i]);
			}
		}
	}
	return dis[T]!=-1;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	S=n*2+m+1,S1=n*2+m+2,S2=n*2+m+3,T=n*2+m+4;
	Add(S,S1,n);Add(S,S2,k);
	for(int i=1;i<=n;i++){
		Add(S1,i,1);
		Add(S2,i+n,1);
	}
	for(int i=1;i<=m;i++){
		Add(i+2*n,T,1);
	}
	for(int i=1;i<=n;i++){
		int t;
		scanf("%d",&t);
		for(int j=0;j<t;j++){
			int a;
			scanf("%d",&a);
			Add(i,a+n*2,1);
			Add(i+n,a+n*2,1);
		}
	}
	int ans=0,f;
	while(bfs()){
		for(int i=1;i<=T;i++) sav[i]=beg[i];
		while(f=dfs(S,1008610086)) ans+=f;
	}
	printf("%d\n",ans);
	return 0;
}
