#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

int n, x, y, z;

int main () {
    n = I();
    while (n--) {
        x = I(); y = I(); z = I();
        printf ("%d %d %d\n", x, y, z);
        if (x > y) swap(x, y);
        if (x > z) swap(x, z);
        if (y > z) swap(y, z);
        if (z < 10) puts("zilch");
        else if (y < 10 && z >= 10) puts("double");
        else if (x < 10 && y >= 10) puts("double-double");
        else puts("triple-double");
        puts("");
    }
    return 0;
}