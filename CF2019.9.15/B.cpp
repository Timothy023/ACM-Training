#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int N=2e5+5;
long long n,a[N],fs,zs,now,fa,za;
int main (){
	scanf ("%I64d",&n);
	now=1;zs=1;
	for (int i=1;i<=n;++i){
		scanf ("%I64d",&a[i]);
		if (a[i]<0)now=-now;
		if (now<0){
			fa+=zs;
			za+=fs;
		}
		else {
			fa+=fs;
			za+=zs;
		}
		if (now<0)fs++;
		else zs++;
	}
	printf ("%I64d %I64d\n",fa,za);
	return 0;
}
