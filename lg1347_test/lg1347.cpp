#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int N=1e5+5;
int n,m;
char ch[10];
struct Topo{
	int ans[N];
	int fi[N],ne[N<<1],j[N<<1],step,du[N],ls[N],tot,tow,tmp;
	void addedge(int fr,int to){
		j[++step]=to;ne[step]=fi[fr];fi[fr]=step;du[to]++;
	}
	void print(int wz){
		if (ans[0]==-1)
			printf ("Inconsistency found after %d relations.\n",wz);
		else {
			printf ("Sorted sequence determined after %d relations: ",wz);
			for (int i=1;i<=n;++i)
				putchar((char)(ans[i]-1+'A'));
			putchar('.');
		}
	}
	bool test(){
		bool flag=1;
		for (int i=1;i<=n;++i)
			ls[i]=du[i];
		tmp=0;tot=1;tow=0;
		for (int i=1;i<=n;++i){
			if (ls[i]==0){
				ans[++tow]=i;
				tmp++;
			}
		}
		if (tmp>1)flag=0;
		while (tot<=tow){
			tmp=0;
			for (int u=fi[ans[tot]];u;u=ne[u]){
				ls[j[u]]--;
				if (!ls[j[u]]){
					tmp++;
					ans[++tow]=j[u];
				}
			}
			if (tmp>1)flag=0;
			++tot;
		}
		if (tow!=n){
			ans[0]=-1;
			return 1;
		}
		return flag;
	}
}t;
int main (){
	scanf ("%d%d",&n,&m);
	for (int i=1;i<=m;++i){
		scanf ("%s",ch);
		t.addedge(ch[0]-'A'+1,ch[2]-'A'+1);
		if (t.test()){
			t.print(i);
			return 0;
		}
	}
	puts("Sorted sequence cannot be determined.");
	return 0;
}
