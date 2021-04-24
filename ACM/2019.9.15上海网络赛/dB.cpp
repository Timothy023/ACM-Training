#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;
int T=20;
int n=100;
int m=50;
int main (){
	srand(time(0));
	cout <<T<<endl;
	for (int i=1;i<=T;++i){
		cout <<n<<" "<<m<<endl;
		for (int j=1;j<=m;++j){
			int x=rand()%(n/2)+1;
			int y=rand()%n/2+x;
			cout <<x<<" "<<y<<endl;
		}
	}
	return 0;
}
