#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int N=2e5+5;
int n,s1,w1,s2,w2,ls;
char ch[N];
int main (){
	scanf ("%d%s",&n,ch+1);
	for (int i=1;i<=n/2;++i){
		if (ch[i]=='?')w1++;
		else s1+=ch[i]-'0';
	}
	for (int i=n/2+1;i<=n;++i){
		if (ch[i]=='?')w2++;
		else s2+=ch[i]-'0';
	}
	if (s1==s2 && w1==w2)puts("Bicarp");
	else if ((s1>=s2 && w1>=w2) || (s1<=s2 && w1<=w2))puts("Monocarp");
	else if (s1>=s2){
		ls=(w2-w1)/2;
		if (ls*9!=s1-s2)puts("Monocarp");
		else puts("Bicarp");
	}
	else {
		ls=(w1-w2)/2;
		if (ls*9!=s2-s1)puts("Monocarp");
		else puts("Bicarp");
	}
	return 0;
}
