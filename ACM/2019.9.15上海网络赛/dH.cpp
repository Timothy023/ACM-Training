#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;
const int n=50000;
const int t=5;
int s,w;
int main (){
	srand(time(0));
	freopen ("h.txt","w",stdout);
	cout <<t<<endl;
	for (int i=1;i<=t;++i){
		s=0;
		cout <<n<<endl;
		for (int j=1;j<=n;++j){
			if (s<=1){
				cout <<1<<" "<<rand()<<endl;
				++s;
			}
			else {
				w=rand()%2+1;
				if (w==1)cout <<w<<" "<<rand()<<endl;
				else cout <<"2 0\n";
				--s;
			}
		}
	}
	return 0;
}
