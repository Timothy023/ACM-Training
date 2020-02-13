#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int N=1e5+5;
const int maxn=1e5;
struct node{
	int atk,hp,cs;
	friend bool operator < (node i,node j){
		if (i.atk*j.cs!=j.atk*i.cs)
			return i.atk*j.cs>j.atk*i.cs;
		else return i.atk>j.atk;
	}
}a[N];
int T,n,s[N];
long long ans,sa;
void solve(int step){
	scanf ("%d",&n);ans=0;sa=0;
	for (int i=1;i<=n;++i){
		scanf ("%d%d",&a[i].hp,&a[i].atk);
		a[i].cs=s[a[i].hp];
		sa+=a[i].atk;
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;++i){
		ans+=sa*a[i].cs;
		sa-=a[i].atk;
	}
	printf ("Case #%d: %lld\n",step,ans);
}
void pre(){
	for (int i=1,sum=1,j=1;i<=maxn;){
		for (int k=i;k<=min(maxn,i+j-1);++k)s[k]=sum;
		i=i+j;j++;sum++;
	}
}
int main (){
	pre();
	scanf ("%d",&T);
	for (int i=1;i<=T;++i)
		solve(i);
	return 0;
}
