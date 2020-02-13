#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;
int n=5000;
int m=100000;
int k,x,y;
int main (){
	srand(time(0));
	cout <<n<<" "<<m<<endl;
	for (int i=1;i<=m;++i){
		k=rand()%2+1;
		if (k==1){
			x=rand()%n+1;
			y=rand();
		}
		else {
			x=rand()%(n/2)+1;
			y=rand()%(n/2)+x;
		}
		cout <<k<<" "<<x<<" "<<y<<endl;
	}
	return 0;
}
