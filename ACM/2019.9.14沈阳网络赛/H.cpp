#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int N=1e5+5;
struct node{
	string name;
	int p[10],pa1,pa2,thr,fou,s;
}t[N];
char ch[20];
int n,l[10],a[10][N];
int check_four(int id){
	if (t[id].p[1]==t[id].p[4])return 1;
	if (t[id].p[2]==t[id].p[5])return 2;
	return -1;
}
int check_three(int id){
	if (t[id].p[1]==t[id].p[3])return 1;
	if (t[id].p[2]==t[id].p[4])return 2;
	if (t[id].p[3]==t[id].p[5])return 3;
	return -1;
}
int check_pair(int id){
	if (t[id].p[4]==t[id].p[5])return 4;
	if (t[id].p[3]==t[id].p[4])return 3;
	if (t[id].p[2]==t[id].p[3])return 2;
	if (t[id].p[1]==t[id].p[2])return 1;
	return -1;
}
bool check8(int id){
	if (t[id].p[1]==1 && t[id].p[2]==10 && t[id].p[3]==11 && t[id].p[4]==12 && t[id].p[5]==13)return true;
	else return false;
}
bool check7(int id){
	for (int i=1;i<=4;++i)
		if (t[id].p[i]+1!=t[id].p[i+1])return false;
	return true;
}
bool check6(int id){
	int ls=check_four(id);
	if (ls==-1)return false;
	else {
		t[id].fou=t[id].p[ls];
		if (ls==1)t[id].s=t[id].p[5];
		else t[id].s=t[id].p[1];
		return true;
	}
}
bool check5(int id){
	int ls=check_three(id);
	if (ls==-1 || ls==2)return false;
	if (ls==1 && t[id].p[4]==t[id].p[5]){
		t[id].thr=t[id].p[1];
		t[id].pa1=t[id].p[4];
		return true;
	}
	if (ls==3 && t[id].p[1]==t[id].p[2]){
		t[id].thr=t[id].p[3];
		t[id].pa1=t[id].p[1];
		return true;
	}
	return false;
}
bool check4(int id){
	int ls=check_three(id);
	if (ls==-1)return false;
	if (ls==1){
		t[id].thr=t[id].p[1];
		t[id].s=t[id].p[4]+t[id].p[5];
		return true;
	}
	if (ls==2){
		t[id].thr=t[id].p[2];
		t[id].s=t[id].p[1]+t[id].p[5];
		return true;
	}
	if (ls==3){
		t[id].thr=t[id].p[3];
		t[id].s=t[id].p[1]+t[id].p[2];
		return true;
	}
}
bool check3(int id){
	int ls=check_pair(id);
	if (ls<=2)return false;
	if (ls==4){
		if (t[id].p[2]==t[id].p[3]){
			t[id].pa1=t[id].p[4];
			t[id].pa2=t[id].p[2];
			t[id].s=t[id].p[1];
			return true;
		}
		if (t[id].p[1]==t[id].p[2]){
			t[id].pa1=t[id].p[4];
			t[id].pa2=t[id].p[1];
			t[id].s=t[id].p[3];
			return true;
		}
		return false;
	}
	if (ls==3){
		if (t[id].p[1]==t[id].p[2]){
			t[id].pa1=t[id].p[3];
			t[id].pa2=t[id].p[1];
			t[id].s=t[id].p[5];
			return true;
		}
		return false;
	}
}
bool check2(int id){
	int ls=check_pair(id);
	if (ls==-1)return false;
	t[id].s=0;t[id].pa1=t[id].p[ls];
	for (int i=1;i<=5;++i)
		if (i==ls || i==ls+1)continue;
		else t[id].s+=t[id].p[i];
	return true;
}
bool check1(int id){
	t[id].s=0;
	for (int i=1;i<=5;++i)
		t[id].s+=t[id].p[i];
	return true;
}
bool cmp8(int i,int j){
	return t[i].name<t[j].name;
}
bool cmp7(int i,int j){
	if (t[i].p[5]!=t[j].p[5])return t[i].p[5]>t[j].p[5];
	else return t[i].name<t[j].name;
}
bool cmp6(int i,int j){
	if (t[i].fou!=t[j].fou)return t[i].fou>t[j].fou;
	else if (t[i].s!=t[j].s)return t[i].s>t[j].s;
	else return t[i].name<t[j].name;
}
bool cmp5(int i,int j){
	if (t[i].thr!=t[j].thr)return t[i].thr>t[j].thr;
	else if (t[i].pa1!=t[j].pa1)return t[i].pa1>t[j].pa1;
	else return t[i].name<t[j].name;
}
bool cmp4(int i,int j){
	if (t[i].thr!=t[j].thr)return t[i].thr>t[j].thr;
	else if (t[i].s!=t[j].s)return t[i].s>t[j].s;
	else return t[i].name<t[j].name;
}
bool cmp3(int i,int j){
	if (t[i].pa1!=t[j].pa1)return t[i].pa1>t[j].pa1;
	else if (t[i].pa2!=t[j].pa2)return t[i].pa2>t[j].pa2;
	else if (t[i].s!=t[j].s)return t[i].s>t[j].s;
	else return t[i].name<t[j].name;
}
bool cmp2(int i,int j){
	if (t[i].pa1!=t[j].pa1)return t[i].pa1>t[j].pa1;
	else if (t[i].s!=t[j].s)return t[i].s>t[j].s;
	else return t[i].name<t[j].name;
}
bool cmp1(int i,int j){
	if (t[i].s!=t[j].s)return t[i].s>t[j].s;
	else return t[i].name<t[j].name;
}
int main (){
	while (scanf ("%d",&n)!=EOF){
		for (int i=1;i<=8;++i)l[i]=0;
		for (int i=1;i<=n;++i){
			t[i].pa1=t[i].pa2=t[i].thr=t[i].fou=t[i].s=0;
		}
		for (int i=1;i<=n;++i){
			cin >>t[i].name;
			scanf ("%s",ch+1);
			for (int j=1,s=1;s<=5;++s){
				if (ch[j]=='1'){t[i].p[s]=10;j+=2;}
				else if (ch[j]>'1' && ch[j]<='9'){t[i].p[s]=ch[j]-'0';j++;}
				else if (ch[j]=='A'){t[i].p[s]=1;j++;}
				else if (ch[j]=='J'){t[i].p[s]=11;j++;}
				else if (ch[j]=='Q'){t[i].p[s]=12;j++;}
				else if (ch[j]=='K'){t[i].p[s]=13;j++;}
			}
			sort(t[i].p+1,t[i].p+6);
			
			if (check8(i))a[8][++l[8]]=i;
			else if (check7(i))a[7][++l[7]]=i;
			else if (check6(i))a[6][++l[6]]=i;
			else if (check5(i))a[5][++l[5]]=i;
			else if (check4(i))a[4][++l[4]]=i;
			else if (check3(i))a[3][++l[3]]=i;
			else if (check2(i))a[2][++l[2]]=i;
			else if (check1(i))a[1][++l[1]]=i;
		}
		/*
		for (int i=1;i<=7;++i){
			cout <<i<<": ";
			for (int j=1;j<=l[i];++j)
				cout <<a[i][j]<<"  ";
			cout <<endl;
		}
//		cout <<"test_check: "<<check5(6)<<"  "<<t[6].name<<"  "<<t[6].p[4]<<"  "<<t[6].p[5]<<"  "<<((bool)(t[6].p[4]==t[6].p[5]))<<"  ";
//		cout <<check_three(6)<<endl;
		*/
		if (l[8])sort(a[8]+1,a[8]+l[8]+1,cmp8);
		if (l[7])sort(a[7]+1,a[7]+l[7]+1,cmp7);
		if (l[6])sort(a[6]+1,a[6]+l[6]+1,cmp6);
		if (l[5])sort(a[5]+1,a[5]+l[5]+1,cmp5);
		if (l[4])sort(a[4]+1,a[4]+l[4]+1,cmp4);
		if (l[3])sort(a[3]+1,a[3]+l[3]+1,cmp3);
		if (l[2])sort(a[2]+1,a[2]+l[2]+1,cmp2);
		if (l[1])sort(a[1]+1,a[1]+l[1]+1,cmp1);
		/*
		for (int i=1;i<=n;++i){
			cout <<t[i].name<<": ";
			for (int j=1;j<=5;++j)
				cout <<t[i].p[j]<<"  ";
			cout <<" | ";
			cout <<t[i].pa1<<"  "<<t[i].pa2<<"  "<<t[i].s<<endl;
		}
		for (int i=1;i<=7;++i)cout <<l[i]<<"  ";cout <<endl;
		*/
		for (int i=8;i>=1;--i){
			for (int j=1;j<=l[i];++j)
				cout <<t[a[i][j]].name<<endl;
		}
	}
	return 0;
}
