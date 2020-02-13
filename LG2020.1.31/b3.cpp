#include <bits/stdc++.h>
using namespace std;

int n;

int cnt(int x) {
	int r=0;
	while(x>0) {
		++r;
		x-=x&(-x);
	}
	return r;
}

int main() {
	cin >> n;
	int ans=0;
	for(int b=1; b<=n; ++b)
		ans+=(1<<cnt(b))-1;
	cout << ans;
	return 0;
}