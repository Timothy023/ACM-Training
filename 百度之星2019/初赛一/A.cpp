#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int T,n,a1,a2,b1,b2,x,q;
int asdf(int i,int j){
	if (!j)return i;
	else return asdf(j,i%j);
}
int main (){
	scanf ("%d",&T);
	while (T--){
		scanf ("%d",&n);
		a1=a2=b1=b2=0;
		for (int i=0;i<n;++i){
			scanf ("%d",&x);
			if (x){a1=i;a2=x;}
		}
		for (int i=0;i<n;++i){
			scanf ("%d",&x);
			if (x){b1=i;b2=x;}
		}
		if (a1>b1)puts("1/0");
		else if (a1<b1)puts("0/1");
		else {
			q=asdf(a2,b2);
			printf ("%d",a2/q);
			putchar('/');
			printf ("%d\n",b2/q);
		}
	}
	return 0;
}
