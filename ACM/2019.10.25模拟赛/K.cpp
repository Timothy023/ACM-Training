#include<bits/stdc++.h>
#define NN 1001000
using namespace std;
char a[NN],b[NN];
int Next[NN],ret[NN],len[NN];
int n,m;
long long ans,sum[NN],qz[NN];
void ExtendedKMP(){
	int i,j,k;
	for(j=0;1+j<m&&a[j]==a[1+j];j++);
	Next[1]=j;
	k=1;
	for(i=2;i<m;i++){
		int Len=k+Next[k],L=Next[i-k];
		if(L<Len-i){
			Next[i]=L;
		}
		else{
			for(j=max(0,Len-i);i+j<m&&a[j]==a[i+j];j++);
			Next[i]=j;
			k=i;
		}
	}
	for(j=0;j<n&&j<m&&a[j]==b[j];j++);
	ret[0]=j;
	k=0;
	for(i=1;i<n;i++){
		int Len=k+ret[k],L=Next[i-k];
		if(L<Len-i){
			ret[i]=L;
		}
		else{
			for(j=max(0,Len-i);j<m&&i+j<n&&a[j]==b[i+j];j++);
			ret[i]==j;
			k=i;
		}
	}
}
void manacher(){
	len[0] = 1;
	for(int i = 1,j = 0;i < (n << 1) - 1; i++){
		int p = i >> 1, q = i - p, r = ((j + 1) >> 1) + len[j] - 1;
		len[i] = r < q ? 0 : min(r - q + 1, len[(j << 1) - i]);
		while(p > len[i] - 1 && q + len[i] < n && a[p - len[i]] == a[q + len[i]]) ++len[i];
		if(q + len[i] - 1 > r) j = i;
	}
}
long long cnt(int l,int r){
	if(r<0) return 0;
	if(!l) return sum[r];
	return sum[r]-sum[l-1];
}
int main(){
	scanf("%s%s",a,b);
	n=strlen(a),m=strlen(b);
	for(int i=0;i<n/2;i++) swap(a[i],a[n-i-1]);
	ExtendedKMP();
	manacher();
	for(int i=0;i<n;i++){
		qz[i]++;
		qz[i+len[i*2]]--;
		
	}
	int tot=0;
	for(int i=0;i<n;i++){
		tot+=qz[i];
		sum[i]=tot;
		if(i) sum[i]+=sum[i-1];
	}
	for(int i=0;i<n;i++){
		printf("%d %d\n",i+ret[i]-1, ret[i]);
		ans+=cnt(i,i+ret[i]-1);
	}
	printf("%I64d\n",ans);
	return 0;
}
