#include<bits/stdc++.h>

using namespace std;

const int N=10000; 

int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<int> a(n),b(n),l(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		l[i]=s[i]-'0';
	}
	int ans=0;
	for(int i=0;i<=N;i++)
	{
		for(int j=0;j<n;j++)
		{
			int x=i-b[j];
			if(x>=0&&x%a[j]==0) l[j]^=1;
		//	cout<<l[j]<<' ';
		}
	//	cout<<endl;
		int tot=0;
		for(int j=0;j<n;j++)
			tot+=l[j];
		ans=max(ans,tot);
	}
	cout<<ans<<endl;
    return 0;
}

