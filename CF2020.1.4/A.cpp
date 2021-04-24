#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

string s[5][25];
int n,m,l,x;

int main () {
    scanf ("%d%d",&n,&m);
    for (int i =0; i<n;++i)cin >>s[1][i];
    for (int i =0; i<m;++i)cin >>s[2][i];
    scanf ("%d", &l);
    for (int i = 1; i <= l; ++i) {
        scanf ("%d", &x);
        x--;
        cout <<s[1][x%n]<<s[2][x%m]<<endl;
    }
    return 0;
}