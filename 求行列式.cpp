#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int maxn=105;
int n;
bool flag;
struct node{double x[maxn],sum;}func[maxn];
double sum = 1;
int main ()
{
	scanf ("%d",&n);
	for (int b=1;b<=n;++b)
	{
		for (int c=1;c<=n;++c)
			scanf ("%lf",&func[b].x[c]);
//		scanf ("%lf",&func[b].sum);
	}
	for (int i=1;i<=n;++i)
	{
		flag=true;
		for (int j=i;j<=n;++j)
			if (func[j].x[i])
			{
				node t;
				t=func[j];
				func[j]=func[i];
				func[i]=t;
				flag=false;
				sum *= (-1);
				break;
			}
		if (flag){puts("No Solution");return 0;}
		double u=func[i].x[i];
		func[i].x[i]/=u;
		sum *= u;
		for (int j=i+1;j<=n;++j)
			func[i].x[j]/=u;
		func[i].sum/=u;
		for (int j=1;j<=n;++j)
			if (j!=i && func[j].x[i]!=0)
			{
				u=func[j].x[i];
				func[j].x[i]-=u;
				for (int k=i+1;k<=n;++k)
					func[j].x[k]-=func[i].x[k]*u;
				func[j].sum-=func[i].sum*u;
			}
	}
	for (int i=1; i <= n; ++i)
		sum *= func[i].x[i];
	printf ("%.5lf\n",sum);
	return 0;
}
/*
2
1 -1 3
1 1 5
*/
