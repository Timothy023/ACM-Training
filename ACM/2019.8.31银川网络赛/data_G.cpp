#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;
int n=100000;
int k=100;
int main (){
	freopen ("G.in","w",stdout);
	srand(time(0));
	cout <<10<<endl;
	for (int i=1;i<=10;++i){
		cout <<n<<" "<<k<<endl;
		for (int j=2;j<=n;++j)
			cout <<(j/2)<<" "<<j<<" "<<5<<endl;
	}
	return 0;
}
