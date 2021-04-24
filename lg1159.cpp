#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int n,lu,ld,ls,a[105];
string p,u[105],d[105],s[105],ch;
int main (){
	cin >>n;
	for (int i=1;i<=n;++i){
		cin >>p>>ch;
		if (ch[0]=='U')u[++lu]=p;
		else if (ch[0]=='D')d[++ld]=p;
		else {s[++ls]=p;a[ls]=i;}
	}
	for (int t=1,i=1,j=1,k=1;t<=n;++t){
		if (a[k]==t)cout <<s[k++]<<endl;
		else if (j<=ld)cout <<d[j++]<<endl;
		else if (i<=lu)cout <<u[i++]<<endl;
	}
	return 0;
}
