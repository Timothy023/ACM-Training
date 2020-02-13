#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int a1,a2,k1,k2,n;
int sum;
int main (){
	cin >>a1>>a2>>k1>>k2>>n;
	sum=a1*(k1-1)+a2*(k2-1);
	if (sum>=n)printf ("%d ",0);
	else printf ("%d ",n-sum);
	if (k1<k2){
		if (n<=a1*k1)printf ("%d\n",n/k1);
		else printf ("%d\n",a1+(n-a1*k1)/k2);
	}
	else {
		if (n<=a2*k2)printf ("%d\n",n/k2);
		else printf ("%d\n",a2+(n-a2*k2)/k1);
	}
	return 0;
}
