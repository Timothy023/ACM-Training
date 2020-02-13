#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<iomanip>
using namespace std;
const int N=3e5+5;
char ch[N];
int n;
long double f[N],g[N];
int main (){
	scanf ("%d%s",&n,ch+1);
	for (int i=1;i<=n;++i){
		if (ch[i]=='o'){
			f[i]=f[i-1]+2*g[i-1]+1;
			g[i]=g[i-1]+1;
		}
		else if (ch[i]=='x'){
			f[i]=f[i-1];
			g[i]=0;
		}
		else {
			f[i]=f[i-1]*0.5+(f[i-1]+2*g[i-1]+1)*0.5;
			g[i]=(g[i-1]+1)*0.5;
		}
	}
	cout <<fixed<<setprecision(4)<<f[n]<<endl;
	return 0;
}
