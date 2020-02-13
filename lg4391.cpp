#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int N=1e6+5;
int n,ne[N];
char ch[N];
int main (){
	scanf ("%d",&n);
	scanf ("%s",ch+1);
	ch[0]=' ';
	for (int i=2,j=0;i<=n;++i){
		while (j>0 && ch[j+1]!=ch[i])j=ne[j];
		if (ch[j+1]==ch[i])++j;
		ne[i]=j;
	}
	printf ("%d\n",n-ne[n]);
	return 0;
}
