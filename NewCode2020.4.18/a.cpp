#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

int a, b, c, d;
int s1, s2;

int main () {
    a = I(); b = I(); c = I(); d = I();
    s1 = a + b + c + d;
    s2 = max(a, max(b, max(c, d))) + min(a, min(b, min(c, d)));
    s1 -= s2;
    cout <<abs(s1 - s2) <<endl;
    return 0;
}