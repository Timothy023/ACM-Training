#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

long long n, p, q;

int main () {
    n = I();
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            p = i;
            q = n / i;
            if ((p + q) % 2 == 0) {
                cout <<(p + q) / 2 <<" " <<(q - p) / 2 <<endl;
                exit(0);
            }
        }
    }
    puts("impossible");
    return 0;
}