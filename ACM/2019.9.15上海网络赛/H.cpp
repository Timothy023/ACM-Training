#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
unsigned int I(){
	unsigned int s=0;char ch=getchar();
	while (ch<'0' || ch>'9')ch=getchar();
	while (ch>='0' && ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s;
}
void O(unsigned int x){
	if (!x)return;
	O(x/10);
	putchar(x%10+'0');
}
int pr[140000];
const int N=5e4+5;
struct Matrix{
	bool a[16][16];
	friend Matrix operator * (Matrix p,Matrix q){
		Matrix t;
		int l1[16],l2[16];
		for (int i=0;i<16;++i){
			l1[i]=0;
			for (int j=0;j<16;++j)
				l1[i]=((l1[i]<<1)+p.a[i][j]);
		}
		for (int i=0;i<16;++i){
			l2[i]=0;
			for (int j=0;j<16;++j)
				l2[i]=((l2[i]<<1)+q.a[j][i]);
		}
		for (int i=0;i<16;++i){
			for (int j=0;j<16;++j){
				t.a[i][j]=(pr[l1[i]&l2[j]]&1);
			}
		}
		return t;
	}
	void clear(){
		memset(a,0,sizeof(a));
	}
	void print(){
		for (int i=0;i<16;++i,puts(""))
			for (int j=0;j<16;++j)
				cout <<a[i][j]<<" ";
	}
	void make(unsigned int seed,unsigned lastans){
		seed^=lastans;
		for (int i=0;i<16;++i){
			seed^=seed*seed+15;
			for (int j=0;j<16;++j){
				a[i][j]=(seed>>j)&1;
			}
		}
	}
	unsigned int calc(){
		unsigned int s=0,c1,c2;
		for (int i=0;i<16;++i){
			if (i==0)c1=1;
			else c1*=17;
			c2=1;
			for (int j=0;j<16;++j,c2*=19)
				s+=a[i][j]*c1*c2;
		}
		return s;
	}
}t[N<<2],l;
void pre(){
	for (int i=1;i<=65536;++i)pr[i]=pr[i>>1]+(i&1);
}
void update(int l,int r,int rt,int wz,unsigned int seed,unsigned int lastans){
	if (l==r){
		t[rt].make(seed,lastans);
		return;
	}
	int mid=(l+r)>>1;
	if (wz<=mid)update(lson,wz,seed,lastans);
	else update(rson,wz,seed,lastans);
	t[rt]=t[rt<<1|1]*t[rt<<1];
}
Matrix query(int l,int r,int rt,int L,int R){
	if (L<=l && r<=R)return t[rt];
	int mid=(l+r)>>1;
	if (R<=mid)return query(lson,L,R);
	else if (mid<L)return query(rson,L,R);
	else {
		Matrix l1=query(rson,L,R);
		Matrix l2=query(lson,L,R);
		return l1*l2;
	}
}
int T,n,le,ri,k[50005],ss;
unsigned int x[50005],ans;
int main (){
//	freopen ("h.txt","r",stdin);
//	freopen ("hout.txt","w",stdout);
	pre();T=I();
	while (T--){
		n=I();le=1;ans=ri=0;ss=0;
		for (int i=1;i<=n;++i){
			k[i]=I();x[i]=I();
			if (k[i]==1)ss++;
		}
		for (int i=1;i<=n;++i){
			if (k[i]==1){
				update(1,ss,1,++ri,x[i],ans);
			}
			else le++;
			if (le>ri){
				ans=0;
				puts("0");
			}
			else {
				l=query(1,ss,1,le,ri);
				ans=l.calc();
				if (ans){O(ans);puts("");}
				else puts("0");
			}
		}
	}
	return 0;
}
