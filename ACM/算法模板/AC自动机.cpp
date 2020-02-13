#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int N=1e6+5;
int n;
struct AC_Machine{
	char ch[N];
	int Next[N][26],Fail[N],flag[N],root,cnt;
	int que[N],tot,tow;
	void clear(){
		root=cnt=1;
		for (int i=0;i<=25;++i){
			Next[0][i]=0;
			Next[root][i]=0;
		}
	}
	void update(char *s){
		int len=strlen(s),x,now=root;
		for (int i=0;i<len;++i){
			x=s[i]-'a';
			if (!Next[now][x])
				Next[now][x]=++cnt;
			now=Next[now][x];
		}
		flag[now]++;
	}
	void build(){
		int now;
		Fail[root]=0;
		que[tot=tow=1]=root;
		for (int i=0;i<=25;++i)
			Next[Fail[root]][i]=root;
		while (tot<=tow){
			now=que[tot];
			for (int i=0;i<=25;++i){
				if (Next[now][i]){
					Fail[Next[now][i]]=Next[Fail[now]][i];
					que[++tow]=Next[now][i];
				}
				else Next[now][i]=Next[Fail[now]][i];
			}
			++tot;
		}
	}
	int calc(char *s){
		int now=root,sum=0,len=strlen(s),x;
		for (int i=0;i<len;++i){
			x=s[i]-'a';
			now=Next[now][x];
			sum+=flag[now];
			flag[now]=0;
		}
		return sum;
	}
}t;
char s[N];
int main (){
	t.clear();
	scanf ("%d",&n);
	for (int i=1;i<=n;++i){
		scanf ("%s",s);
		t.update(s);
	}
	t.build();
	scanf ("%s",s);
	printf ("%d\n",t.calc(s));
	return 0;
}
