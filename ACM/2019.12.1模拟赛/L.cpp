#include<bits/stdc++.h>
#define N 100100
using namespace std;
int a[N];
int tj[N];
int col[2];
int ljl[N];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		col[a[i]]++;
	}
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(a[x]!=a[y]){
			tj[x]++;
			tj[y]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(tj[i]==0) ljl[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(tj[i]==0){
			printf("%d ",col[a[i]]-1+col[a[i]^1]*2+ljl[a[i]^1]);
		}
		else{
			printf("%d ",col[a[i]]-1+col[a[i]^1]*2-tj[i]);
		}
	}
	return 0;
}
