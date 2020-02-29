#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

struct point {
    int x, y;
    point() {}
    point(int _x, int _y) {
        x = _x, y = _y;
    }
    friend point operator - (point i, point j) {
        return (point(i.x - j.x, i.y - j.y));
    }
    friend int operator * (point i, point j) {
        return i.x * j.y - i.y * j.x;
    }
}p1, p2, tmp;

struct line {
    point st, en;
    line() {}
    line(point _st, point _en) {
        st = _st; en = _en;
    }
}q[10005];

int n, m, sum, x, y;

int main () {
    n = I();
    for (int i = 1; i <= n; ++i) {
        x = I(); y = I(); p1 = point(x, y);
        x = I(); y = I(); p2 = point(x, y);
        if (p1.y > p2.y) swap(p1, p2);
        q[i] = line(p1, p2);
    }
    m = I();
    for (int i = 1; i <= m; ++i) {
        sum = 0;
        x = I(); y = I(); tmp = point(x, y);
        for (int j = 1; j <= n; ++j) {
            if ((tmp - q[j].st) * (q[j].en - q[j].st) > 0) sum++;
        }
        x = I(); y = I(); tmp = point(x, y);
        for (int j = 1; j <= n; ++j) {
            if ((tmp - q[j].st) * (q[j].en - q[j].st) > 0) sum--;
        }
        sum = abs(sum);
        if (sum & 1) puts("different");
        else puts("same");
    }
    return 0;
}