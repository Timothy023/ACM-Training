#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int a,b,x,T,q;
int pri[24]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83};
int ls[50],sum[50],step,an[500],len;
int gcd(int i,int j){
	if (!j)return i;
	else return gcd(j,i%j);
}
void dfs(int st,int ans){
	if (st>step){
		an[++len]=ans;
		return;
	}
	dfs(st+1,ans);
	for (int i=1;i<=sum[st];++i){
		ans=ans*ls[st];
		dfs(st+1,ans);
	}
}
int main (){
	scanf ("%d",&T);
	while (T--){
		scanf ("%d",&a);
		for (x=a,b=0;x;x/=10)b+=(x%10);
		q=gcd(a,b);step=0;len=0;
		for (int i=1;i<=23;++i){
			if (q%pri[i]==0){
				ls[++step]=pri[i];sum[step]=0;
				while (q%pri[i]==0){
					sum[step]++;
					q/=pri[i];
				}
			}
		}
		dfs(1,1);
		sort(an+1,an+len+1);
		printf ("%d\n",len);
		for (int i=1;i<len;++i)printf ("%d ",an[i]);
		printf ("%d\n",an[len]);
	}
	return 0;
}
