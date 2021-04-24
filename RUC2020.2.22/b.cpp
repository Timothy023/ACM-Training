#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

long long ans, x;
char c[1005];

int main () {
    // freopen ("test.in", "r", stdin);
    while (scanf ("%s", c) != EOF) {
        x = 0;
        if (c[0] == 124) {
            x = 42 * strlen(c);
        } else {
            int i;
            for (i = 0; c[i] != ','; ++i)
                x = x * 10 + c[i] - '0';
            if (strlen(c) - i - 2 > 0)
                x *= (strlen(c) - i - 2);
        }
        ans += x;
    }
    ans = (ans + 9) / 10 * 10;
    cout <<ans <<",-" <<endl;
    return 0;
}
