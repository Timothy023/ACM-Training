#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;
int n;
int main (){
	freopen ("in.txt","w",stdout);
	srand(time(0));
	n=rand()%3+2;
	cout <<n<<endl<<(rand()%n+1)<<" "<<(rand()%n+1)<<endl;
	return 0;
}
