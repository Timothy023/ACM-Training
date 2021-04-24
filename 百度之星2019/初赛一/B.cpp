#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int N=1005;
int T,l[N],r[N],n,le,ri,wz,ans;
bool judge(int l1,int r1,int l2,int r2){
	if ((l1<=l2 && l2<=r1) || (l1<=r2 && r2<=r1) || (l2<=l1 && r1<=r2))return true;
	else return false;
}
void change(int &l1,int &r1,int l2,int r2){
	if (l1<=l2 && r2<=r1){l1=l2;r1=r2;}
	else if (l1<=l2)l1=l2;
	else if (r2<=r1)r2=r1;
}
void move_ri(int &st,int &i){
	ans+=(l[i]+1-st)/2;
	if (i==n)return;
	if ((l[i]-st)%2==0)st=l[i];
	else {
		if (l[i]==r[i])st=l[i];
		else {
			int ol=i;i++;
			while (i<=n && r[i]>=l[ol]+1 && l[i]<=l[ol])++i;
			if (i==n+1)return;
			if (r[i]<=l[ol])st=l[ol];
			else st=l[ol]+1;
			--i;
		}
	}
}
void move_le(int &st,int &i){
	ans+=(st+1-r[i])/2;
	if (i==n)return;
	if ((st-r[i])%2==0)st=r[i];
	else {
		if (l[i]==r[i])st=r[i];
		else {
			int ol=i;i++;
			while (i<=n && r[i]>=r[ol] && l[i]<=r[ol]-1)++i;
			if (i==n+1)return;
			if (l[i]>=r[ol])st=r[ol];
			else st=r[ol]-1;
			--i;
		}
	}
}
void start(int st){
	ans=0;
	for (int i=wz;i<=n;++i){
		if (l[i]<=st && st<=r[i])continue;
		if (l[i]>st)move_ri(st,i);
		else move_le(st,i);
	}
	printf ("%I64d\n",ans);
}
void solve(){
	le=l[1],ri=r[1];wz=-1;
	for (int i=2;i<=n;++i){
		if (judge(le,ri,l[i],r[i]))
			change(le,ri,l[i],r[i]);
		else {
			wz=i;break;
		}
	}
	int st;
	if (wz==-1){puts("0");return;}
	if (l[wz]>ri)st=ri;
	else st=le;
	start(st);
}
int main (){
	scanf ("%d",&T);
	while (T--){
		scanf ("%d",&n);
		for (int i=1;i<=n;++i)scanf ("%d%d",&l[i],&r[i]);
		solve();
	}
	return 0;
}
