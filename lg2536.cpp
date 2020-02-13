#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<bitset>
using namespace std;
const int N=1005;
const int L=250005;
char ch[N],s[N];
int ne[L][4],cnt,root,ans,n,sum[L],len;
bitset<N>vis[L];
struct Queue{
	#define maxn 100000
	int que[100005],tot,tow;
	void clear(){
		tot=tow=0;
		memset(que,0,sizeof(que));
	}
	bool empty(){
		return (tot==tow);
	}
	int top(){
		return que[tot];
	}
	void pop(){
		++tot;
		if (tot==maxn)tot=0;
	}
	void push(int x){
		que[tow]=x;
		++tow;
		if (tow==maxn)tow=0;
	}
}q1,q2;
int c(char ch){
	if (ch=='A')return 0;
	else if (ch=='G')return 1;
	else if (ch=='C')return 2;
	else return 3;
}
void insert(){
	int now=root,x,len=strlen(ch+1);
	for (int i=1;i<=len;++i){
		x=c(ch[i]);
		if (!ne[now][x])
			ne[now][x]=++cnt;
		now=ne[now][x];
	}
	sum[now]++;
}
void update(int x1,int x2){
	if (ne[x1][0] && !vis[ne[x1][0]][x2]){
		q1.push(ne[x1][0]);q2.push(x2);
		vis[ne[x1][0]][x2]=1;
	}
	if (ne[x1][1] && !vis[ne[x1][1]][x2]){
		q1.push(ne[x1][1]);q2.push(x2);
		vis[ne[x1][1]][x2]=1;
	}
	if (ne[x1][2] && !vis[ne[x1][2]][x2]){
		q1.push(ne[x1][2]);q2.push(x2);
		vis[ne[x1][2]][x2]=1;
	}
	if (ne[x1][3] && !vis[ne[x1][3]][x2]){
		q1.push(ne[x1][3]);q2.push(x2);
		vis[ne[x1][3]][x2]=1;
	}
}
void solve(){
	int x1,x2;ans=n;
	q1.push(root);q2.push(0);
	vis[root][0]=1;
	while (!q1.empty()){
		x1=q1.top();x2=q2.top()+1;
//		cout <<x1<<"  "<<x2-1<<"  "<<vis[x1][x2]<<"  "<<x2<<"  "<<s[x2]<<endl;
		q1.pop();q2.pop();
		if (x2>len){
			ans-=sum[x1];sum[x1]=0;
			continue;
		}
		if (s[x2]!='?' && s[x2]!='*'){
			if (ne[x1][c(s[x2])] && !vis[ne[x1][c(s[x2])]][x2]){
				q1.push(ne[x1][c(s[x2])]);
				q2.push(x2);
				vis[ne[x1][c(s[x2])]][x2]=1;
			}
		}
		else if (s[x2]=='?')update(x1,x2);
		else if (s[x2]=='*'){
			if (!vis[x1][x2]){
				q1.push(x1);
				q2.push(x2);
				vis[x1][x2]=1;
			}
			update(x1,x2-1);
		}
	}
}
int main (){
	scanf ("%s%d",s+1,&n);
	len=strlen(s+1);
	for (int i=1;i<=n;++i){
		scanf ("%s",ch+1);
		insert();
	}
	solve();
	printf ("%d\n",ans);
	return 0;
}
