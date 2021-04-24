#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int N=100005;
struct ZX_Tree{
	#define lim (N-5)
	#define maxn (N*20)
	int root[N],id[maxn],ls[maxn],rs[maxn],now,cnt,sum[maxn];
	char c[maxn];
	void clear(){
		now=cnt=0;
		memset(id,0,sizeof(id));
		memset(ls,0,sizeof(ls));
		memset(rs,0,sizeof(rs));
		memset(sum,0,sizeof(sum));
	}
	void change_root(int wz){
		root[now+1]=root[now-wz];
		now++;
	}
	char Query(int l,int r,int rt,int wz){
		if (l==r)return c[rt];
		int mid=(l+r)>>1;
		if (wz<=mid)return Query(l,mid,ls[rt],wz);
		else return Query(mid+1,r,rs[rt],wz);
	}
	char query(int wz){
		return Query(1,lim,root[now],wz);
	}
	void Update(int l,int r,int oro,int &nro,char key){
		if (!nro)nro=++cnt;
		sum[nro]=sum[oro]+1;
		if (l==r){
			c[nro]=key;
			return;
		}
		int mid=(l+r)>>1;
		if (sum[ls[oro]]<mid-l+1)Update(l,mid,ls[oro],ls[nro],key);
		else {
			ls[nro]=ls[oro];
			Update(mid+1,r,rs[oro],rs[nro],key);
		}
	}
	void update(char key){
		Update(1,lim,root[now],root[now+1],key);
		now++;
	}
};
ZX_Tree t;
int n,x;
char c1[10],c2[10];
int main (){
	scanf ("%d",&n);
	t.clear();
	for (int i=1;i<=n;++i){
		scanf ("%s",c1);
		if (c1[0]=='T'){
			scanf ("%s",c2);
			t.update(c2[0]);
		}
		else if (c1[0]=='U'){
			scanf ("%d",&x);
			t.change_root(x);
		}
		else {
			scanf ("%d",&x);
			putchar(t.query(x));
			puts("");
		}
	}
	return 0;
}
