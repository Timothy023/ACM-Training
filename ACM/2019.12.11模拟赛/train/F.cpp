#include<bits/stdc++.h>
using namespace std;
int t;
char s[1000100];
void solve(){
	scanf("%s",s);
	char c=s[0];
	int r=1,i=0,gb=0,len=strlen(s);
	int f=0;
	while(1){
		if(r+i==len){
			gb=r;
			break;
		}
		f=1;
		if(s[i]<s[r+i]){
			gb=r;
			break;
		}
		else if(s[i]==s[r+i]){
			i++;
		}
		else{
			r+=i+1;
			i=0;
		}
	}
	if(gb==0) gb=len;
	for(i=0;i+gb<=len;i+=gb){
		for(int j=0;j<gb;j++) putchar(s[j]);
	}
	f=0;
	for(int j=i;j<len;j++){
		if(j==i) putchar(s[0]-1);
		else if(s[j-i]>=s[0]&&j!=len-1) putchar(s[j-i]);
		else putchar(s[0]-1);
	}
	puts("");
}
int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}
