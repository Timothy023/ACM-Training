#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

const int N = 1e5 + 5;
const double esp = 1e-10;
const double pi = acos(-1);
int n, x[N], y[N];
bool flag;

int main () {
    n = I();
    for (int i = 1; i <= n; ++i) {
        x[i] = I(); y[i] = I();
    }
    if (n & 1) {
        puts("NO");
        return 0;
    }
    flag = 1;
    for (int i = 1; i <= n / 2; ++i) {
        double x1 = x[i + 1] - x[i], y1 = y[i + 1] - y[i];
        double x2 = x[(i + n / 2) % n + 1] - x[i + n / 2], y2 = y[(i + n / 2) % n + 1] - y[i + n / 2];
        double t1 = atan2(y1, x1);
        double t2 = atan2(y2, x2);
        if (fabs(t1 - t2) >= esp && fabs(fabs(t1 - t2) - pi) >= esp) flag = 0;
        t1 = sqrt(x1 * x1 + y1 * y1);
        t2 = sqrt(x2 * x2 + y2 * y2);
        if (fabs(t1 - t2) >= esp) flag = 0;
    }
    if (flag) puts("YES");
    else puts("NO");
    return 0;
}