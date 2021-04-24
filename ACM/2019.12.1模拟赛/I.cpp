#include<bits/stdc++.h>
using namespace std;
long long dp[2][105][5050];
long long a[105],b[105],c[105];
long long ans;
int n;
int t;
void solve(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
	dp[((n-1)&1)^1][0][0]=0;
	for(int i=n-1;i>=0;i--){
		memset(dp[i&1],-1,sizeof(dp[i&1]));
		for(int j=0;j<=n-i;j++){
			for(int k=j;k<=(n-i)*(n-i+1)/2;k++){
				if(j){
					if(dp[(i&1)^1][j-1][k-j]>=0) dp[i&1][j][k]=max(dp[i&1][j][k],dp[(i&1)^1][j-1][k-j]+a[i]);
				}
				if(dp[(i&1)^1][j][k-j]>=0) dp[i&1][j][k]=max(dp[i&1][j][k],dp[(i&1)^1][j][k-j]+(k-j)*b[i]);
				if(dp[(i&1)^1][j][k-j]>=0) dp[i&1][j][k]=max(dp[i&1][j][k],dp[(i&1)^1][j][k-j]+j*c[i]);
				ans=max(ans,dp[i&1][j][k]);
			}
		}
	}
	cout<<ans<<"\n";
}
int main(){
	scanf("%d",&t);
	while(t--){
		ans=0;
		memset(dp,-1,sizeof(dp));
		solve();
	}
	return 0;
}
