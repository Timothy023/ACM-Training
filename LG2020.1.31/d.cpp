#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const double esp = 1e-13;
int n, w[N];
double a, b, c, ans;
double p[N], f[N][2], g[N][2];

int I(){
    int s = 0; char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s;
}

int main () {
    n = I();
    scanf ("%lf%lf", &a, &b);
    for (int i = 1; i <= n; ++i) w[i] = I();
    for (int i = 1; i <= n; ++i) scanf ("%lf", &p[i]);
    c = pow(a, b);
    g[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        double t1 = 1, t2 = 1; int s = 0;
        f[i][0] = (f[i - 1][0] + f[i - 1][1]) * (1 - p[i]);
        g[i][0] = (g[i - 1][0] + g[i - 1][1]) * (1 - p[i]);
        for (int j = i; j >= 1; --j) {
            t1 *= p[j];
            if (i != j) t2 *= c;
            if (t1 <=esp || (f[j - 1][0] * t1 <= esp && t2 <=esp)) break;
            s += w[j];
            g[i][1] += g[j - 1][0] * t1;
            f[i][1] += f[j - 1][0] * t1 + (t2 * s) * (g[j - 1][0] * t1);
        }
    }
    ans = f[n][0] + f[n][1];
    printf ("%.2lf", ans);
    return 0;
}