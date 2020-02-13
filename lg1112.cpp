#include<iostream>
#include<cstdlib>
#include<cstdio>
#define ll long long
using namespace std;
int l,r,x,y,st;
int sum[10000005];
void solve(int i,int j,int k){
	ll num=0,step=0;
	while (num<=y){
		sum[num]++;
		if (step%2==0)num=num*i+j;
		else num=num*i+k;
		step++;
	}
}
int main (){
	scanf ("%d%d%d%d%d",&l,&r,&x,&y,&st);
	for (int i=l;i<=r;++i)
		for (int j=1;j<i;++j)
			for (int k=0;k<i;++k)
				if (j!=k)solve(i,j,k);
	for (int i=x;i<=y;++i)
		if (sum[i]==st)
			printf ("%d\n",i);
	return 0;
} 
