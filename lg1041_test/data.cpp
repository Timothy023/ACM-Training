#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;
int n=120;
int main (){
	freopen ("data.in","w",stdout);
	srand(time(0));
	cout <<n<<" "<<n-1<<endl;
	for (int i=2;i<=n;++i)
		cout <<rand()%(i-1)+1<<" "<<i<<endl;
	return 0;
}
