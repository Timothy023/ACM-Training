#include <bits/stdc++.h>
using namespace std;

int n, k, d, x, tp, Seed;
long long q[10000005];
int t[10000005], head, tail;

inline int I() {
	int x=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) { x=x*10+c-'0'; c=getchar(); }
	return x;
}

inline int rnd() {
	static const int MOD=1e9;
	return Seed=(1LL*Seed*0x66CCFF%MOD+20120712)%MOD;
}

int main() {
	n=I(); k=I(); d=I(); x=I(); tp=I();
	if(tp==1) Seed=I();
	head=1; tail=0;
	for(int i=1; i<=n; ++i) {
		int a;
		if(tp==0) a=I();
		else a=rnd();
		long long f;
		if(i==1) {
			f=a;
		} else {
			while(head<=tail && t[head]<i-x) ++head;
			f=q[head]+(long long)d*(i-1)+a+k;
		}
		if(i==n) cout << f << '\n';
		else {
			long long k=f-(long long)d*i;
			while(head<=tail && q[tail]>=k) --tail;
			++tail; q[tail]=k; t[tail]=i;
		}
	}
	return 0;
}