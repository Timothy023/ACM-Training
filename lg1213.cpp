#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int a[10];
bool flag=1;
int main (){
	for (int i=1;i<=9;++i){
		scanf ("%d",&a[i]);
		a[i]/=3;
	}
	for (int a1=0;a1<=3 && flag;++a1)
	for (int a2=0;a2<=3 && flag;++a2)
	for (int a3=0;a3<=3 && flag;++a3)
	for (int a4=0;a4<=3 && flag;++a4)
	for (int a5=0;a5<=3 && flag;++a5)
	for (int a6=0;a6<=3 && flag;++a6)
	for (int a7=0;a7<=3 && flag;++a7)
	for (int a8=0;a8<=3 && flag;++a8)
	for (int a9=0;a9<=3 && flag;++a9)
		if ((a1+a2+a4)%4==(4-a[1])%4 &&
			(a1+a2+a3+a5)%4==(4-a[2])%4 &&
			(a2+a3+a6)%4==(4-a[3])%4 && 
			(a1+a4+a5+a7)%4==(4-a[4])%4 &&
			(a1+a3+a5+a7+a9)%4==(4-a[5])%4 &&
			(a3+a5+a6+a9)%4==(4-a[6])%4 &&
			(a4+a7+a8)%4==(4-a[7])%4 &&
			(a5+a7+a8+a9)%4==(4-a[8])%4 &&
			(a6+a8+a9)%4==(4-a[9])%4){
				for (int i=1;i<=a1;++i)cout <<1<<" ";
				for (int i=1;i<=a2;++i)cout <<2<<" ";
				for (int i=1;i<=a3;++i)cout <<3<<" ";
				for (int i=1;i<=a4;++i)cout <<4<<" ";
				for (int i=1;i<=a5;++i)cout <<5<<" ";
				for (int i=1;i<=a6;++i)cout <<6<<" ";
				for (int i=1;i<=a7;++i)cout <<7<<" ";
				for (int i=1;i<=a8;++i)cout <<8<<" ";
				for (int i=1;i<=a9;++i)cout <<9<<" ";
				flag=0;
			}
	return 0;
}
