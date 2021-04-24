#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	if(k==1)
	{
		if(n&1) cout<<"Adrien\n";
		else cout<<"Austin\n";
	}
	else if(n==0) cout<<"Austin\n";
	else cout<<"Adrien\n";
	return 0;
}
