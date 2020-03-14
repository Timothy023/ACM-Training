#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

string s;

int main () {
    cin >>s;
    int len = s.size();
    cout <<"h";
    for (int i = 1; i <= 2 * (len - 2); ++i)
        cout <<"e";
    cout <<"y";
    return 0;
}