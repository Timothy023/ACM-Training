#include<bits/stdc++.h>
#define N 200100
using namespace std;
int t,n,ans[N],mi[N];
char a[N];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%s",&n,a);
		mi[n]=100;
		for(int i=n-1;i>=0;i--) mi[i]=min(a[i]-'0',mi[i+1]);
		int flag=1;
		for(int B=0;B<=9;B++){
			int l=0,r=0;
			flag=1;
			for(int i=0;i<n;i++){
				if(a[i]-'0'<=B&&mi[i+1]>=a[i]-'0'){
					ans[i]=1;
					if(a[i]-'0'>=l) l=a[i]-'0';
					else flag=0;
				}
				else if(a[i]-'0'>=B){
					ans[i]=2;
					if(a[i]-'0'>=r) r=a[i]-'0';
					else flag=0;
				}
				else flag=0;
				if(!flag) break;
			}
			if(flag){
				for(int i=0;i<n;i++) cout<<ans[i];
				puts("");
				break;
			}
		}
		if(!flag) puts("-");
	}
	return 0;
}
