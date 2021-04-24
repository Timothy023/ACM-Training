#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
char ch[105],que[105],ls[105],q;
int n,top;
int main (){
	scanf ("%s",ch+1);
	n=strlen(ch+1);
	for (int i=1;i<=n;++i){
		if (ch[i]=='('){que[++top]=i;ls[i]=')';}
		else if (ch[i]=='['){que[++top]=i;ls[i]=']';}
		else {
			q=(ch[i]==')')?('('):('[');
			if (top && ch[que[top]]==q)ls[que[top--]]=' ';
			else ls[i]=q;
		}
	}
	for (int i=1;i<=n;++i){
		if (ls[i]=='(' || ls[i]=='[')putchar(ls[i]);
		putchar(ch[i]);
		if (ls[i]==')' || ls[i]==']')putchar(ls[i]);
	}
	return 0;
}
