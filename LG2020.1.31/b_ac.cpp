#include <bits/stdc++.h>
using namespace std;

int mod=1000000007;
long long n;
int ans;
int fac[105];
int invfac[105];
int cnt[105];

int Pow(int a, int b) {
	int r=1;
	while(b>0) {
		if(b&1) r=(long long)r*a%mod;
		a=(long long)a*a%mod;
		b>>=1;
	}
	return r;
}

int main() {
	fac[0]=1; for(int i=1; i<=63; ++i) fac[i]=(long long)fac[i-1]*i%mod;
	invfac[63]=Pow(fac[63], mod-2); for(int i=62; i>=0; --i) invfac[i]=(long long)invfac[i+1]*(i+1)%mod;
	cin >> n;
	++n;
	for(int i=63, b=0; i>=0; --i) {
		if((n>>i)&1) {
			for(int j=i; j>=0; --j) cnt[b+j]=(cnt[b+j]+(long long)fac[i]*invfac[j]%mod*invfac[i-j])%mod;
			++b;
		}
	}
	for(int i=1; i<=63; ++i)
		ans=(ans+((1ULL<<i)-1)%mod*cnt[i])%mod;
	printf("%d\n", ans);
	return 0;
}