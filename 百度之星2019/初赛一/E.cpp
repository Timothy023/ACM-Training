#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int T;
long long n;
long long a[6]={3,4,3,1,6,1};
long long b[6]={3,1,1,0,3,0};
int main (){
	scanf ("%d",&T);
	while (T--){
		scanf ("%I64d",&n);
		if (n!=1)printf ("%I64d\n",(b[n%6]+a[n%6]*((n-1)/6))%n);
		else puts("1");
	}
	return 0;
}
