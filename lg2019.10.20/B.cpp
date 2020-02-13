#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
char s[1000005], a[1000005], b[1000005];
int len;
bool flag=1;
int main (){
	scanf ("%s",s);
	len=strlen(s);
	for (int i=len-1;i>=0;--i){
		if (s[i] == 'Z'){
			if (!flag){
				puts("-1");
				return 0;
			}
			else a[i]=b[i]='0';
		}
		else if (s[i]=='X'){
			a[i]='1';
			b[i]='0';
			flag=0;
		}
		else {
			a[i]='0';
			b[i]='1';
			flag=0;
		}
	}
	printf("%s\n%s", a, b);
	return 0;
}
