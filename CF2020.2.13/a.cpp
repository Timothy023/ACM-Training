#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

char a[200], b[200], c[200];
int n, len;
bool flag;

int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf ("%s%s%s", a, b, c);
        len = strlen(c);
        flag = 1;
        for (int j =0; j < len; ++j)
            if (a[j] != c[j] && b[j] != c[j]) {
                flag = 0;
                break;
            }
        if (flag) puts("YES");
        else puts("NO");
    }
    return 0;
}