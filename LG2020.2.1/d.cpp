#include <bits/stdc++.h>
using namespace std;

const int mod=10086001;
const int MAXN=1000000;
int T, n, k, ans;
int fac[1<<20];
int pre1[1<<20];
int pre2[1<<20];
int pre3[1<<20];

inline int I() {
	int x=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) { x=x*10+c-'0'; c=getchar(); }
	return x;
}

const int MXB=10000000;
char buff[10000000];
int sz;

inline void Print(char c) {
	buff[sz++]=c;
}

inline void Print(int x) {
	if(x==0) buff[sz++]='0';
	else {
		static char b[35];
		int top=0;
		while(x>0) { b[++top]=x%10+'0'; x/=10; }
		while(top>0) buff[sz++]=b[top--];
	}
}

inline void Flush() {
	buff[sz]='\0'; puts(buff); sz=0;
}

int main() {
	fac[0]=1; for(int i=1; i<=MAXN; ++i) fac[i]=(long long)fac[i-1]*i%mod;
	int sum=pre1[0]=fac[0]; for(int i=1; i<=MAXN; ++i) sum=pre1[i]=(sum+fac[i])%mod;
	sum=0; for(int i=1; i<=MAXN; ++i) sum=pre2[i]=(sum+(long long)i*fac[i]%mod)%mod;
	sum=0; for(int i=1; i<=MAXN; ++i) sum=pre3[i]=(sum+(long long)i*i%mod*fac[i]%mod)%mod;
	T=I();
	while(T--) {
		n=I();
		Print((int)((((long long)n*pre1[n/2]%mod+4*(mod-pre2[n/2]))*n+4*pre3[n/2])%mod)); Print('\n');
	}
	Flush();
	return 0;
}