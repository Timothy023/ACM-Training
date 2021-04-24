#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	cin >> n;
	int ans=0;
	for(int k=1; k<=n; ++k)
		for(int i=0; i<=n-k; ++i)
			if((i&k)==0)
				++ans;
	cout << ans;
	return 0;
}