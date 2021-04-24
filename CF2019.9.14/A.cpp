#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
using namespace std;
int n,a[105],ans;
bool b[105];
int main (){
	scanf ("%d",&n);
	for (int i=1;i<=n;++i)
		scanf ("%d",&a[i]);
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-(a+1);
	for (int i=1;i<=n;++i){
		if (b[i])continue;
		for (int j=a[i];j<=a[n];j+=a[i]){
			for (int k=1;k<=n;++k)
				if (a[k]==j)b[k]=1;
		}
		ans++;
	}
	printf ("%d\n",ans);
	return 0;
}
