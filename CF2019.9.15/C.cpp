#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int N=2e5+5;
char s[N],t[N];
int n,ans,ax[N],ay[N],ls;
int main (){
	scanf ("%d",&n);
	scanf ("%s%s",s+1,t+1);
	for (int i=1;i<=n;++i)if (s[i]=='a')ls++;
	for (int i=1;i<=n;++i)if (t[i]=='a')ls++;
	if (ls&1){
		puts("-1");
		return 0;
	}
	for (int i=1,j=2;i<=n;++i){
		if (s[i]==t[i] || (s[i]=='b' && t[i]=='a'))continue;
		if (j<=i)j=i+1;
		while ((!(s[j]==s[i] && t[j]==t[i])) && j<=n)++j;
		if (j<=n){
			swap(s[j],t[i]);
			++ans;
			ax[ans]=j;ay[ans]=i;
		}
		else {
			swap(s[i],t[i]);
			++ans;
			ax[ans]=ay[ans]=i;
			break;
		}
	}
	for (int i=1,j=2;i<=n;++i){
		if (s[i]==t[i])continue;
		if (j<=i)j=i+1;
		while ((!(s[j]==s[i] && t[j]==t[i])) && j<=n)++j;
		if (j<=n){
			swap(s[j],t[i]);
			++ans;
			ax[ans]=j;ay[ans]=i;
		}
		else {
			swap(s[i],t[i]);
			++ans;
			ax[ans]=ay[ans]=i;
			break;
		}
	}
	
	printf ("%d\n",ans);
	for (int i=1;i<=ans;++i)
		printf ("%d %d\n",ax[i],ay[i]);
	return 0;
}
