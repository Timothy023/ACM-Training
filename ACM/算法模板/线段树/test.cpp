#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int N=1e5+5;
struct Seg_Tree{
	#define lson l,mid,rt<<1
	#define rson mid+1,r,rt<<1|1
	int sum[N<<2];
	void pushup(int rt){
		sum[rt]=sum[rt<<1]+sum[rt<<1|1];
	}
	void build(int l,int r,int rt){
		if (l==r){
			sum[rt]=0;
			return;
		}
		int mid=(l+r)>>1;
		build(lson);build(rson);
		pushup(rt);
	}
	void update(int l,int r,int rt,int wz,int val){
		if (l==r){
			sum[rt]=val;
			return;
		}
		int mid=(l+r)>>1;
		if (wz<=mid)update(lson,wz,val);
		else update(rson,wz,val);
		pushup(rt);
	}
	int query(int l,int r,int rt,int L,int R){
		if (L<=l && r<=R)return sum[rt];
		int mid=(l+r)>>1,s=0;
		if (L<=mid)s=query(lson,L,R);
		if (mid<R)s+=query(rson,L,R);
		return s;
	}
}t;
int n,m,x,y,k;
int main (){
	scanf ("%d%d",&n,&m);
	t.build(1,n,1);
	for (int i=1;i<=m;++i){
		scanf ("%d%d%d",&k,&x,&y);
		if (k==1)t.update(1,n,1,x,y);
		else printf ("%d\n",t.query(1,n,1,x,y));
	}
	return 0;
}
/*
1 x y  : 将位置x的值更新为y
2 x y  : 查询区间[x,y]的元素的和 
*/
