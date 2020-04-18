#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

struct node{
    int da, num;
    double temp;
    node() = default;
    node (int d, int id, double t) {
        da = d; num = id; temp = t;
    }
    friend bool operator < (node i, node j) {
        if (i.da != j.da) return i.da > j.da;
        else if (i.temp != j.temp) return i.temp > j.temp;
        else return i.num < j.num;
    }
}a[105];

int n, len;
int d, id;
double t;

int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf ("%d%d%lf", &d, &id, &t);
        if (t < 38.0) continue;
        a[++len] = node(d, id, t);
    }
    sort(a + 1, a + len + 1);
    printf ("%d\n", len);
    for (int i = 1; i <= len; ++i) {
        printf ("%d %d %.1lf\n", a[i].da, a[i].num, a[i].temp);
    }
    return 0;
}