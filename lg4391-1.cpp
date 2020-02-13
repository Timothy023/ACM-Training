#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int N=1e6+5;
int n,ans,s1,s2,mi;
char ch[N];
int main (){
	scanf ("%d%s",&n,ch+1);
	ans=n;mi=1;
	for (int i=1;i<n;++i){
		s1=s1*37+ch[i];
		s2=ch[n-i+1]*mi+s2;mi*=37;
		if (s1==s2)ans=n-i;
	}
	printf ("%d\n",ans);
	return 0;
}
