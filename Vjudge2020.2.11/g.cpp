#include <bits/stdc++.h>
#define max(a, b) (a) > (b) ? (a) : (b)
#define min(a, b) (a) < (b) ? (a) : (b)


int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}
void O(long long x) {
    if (x < 10) {
        putchar(x + '0');
        return;
    }
    O(x / 10);
    putchar(x % 10 + '0');
}

const int N = 1e5 + 5;
struct node {
    long long x, y;
    node(){}
    node(long long _x, long long _y) {
        x = _x; y = _y;
    }
    friend bool operator < (node i, node j) {
        if (i.x == j.x) return i.y < j.y;
        else return i.x < j.x;
    }
    friend node operator - (node i, node j) {
        return node(i.x - j.x, i.y - j.y);
    }
    friend long long operator * (node i, node j) {
        return i.x * j.y - i.y * j.x;
    }
}a[N], tmp, p[N], b[N];
int n, k, top;
long long ans, sum[N], all;

long long Abs(long long x) {
    if (x < 0) return -x;
    else return x;
}
bool cmp(node i, node j) {
    long long t = (i - a[1]) * (j - a[1]);
    return t > 0;
}
void tubao() {
    top = 2;
    for (int i = 3; i <= k; ++i) {
        while (top >= 2 && (a[i] - a[top - 1]) * (a[top] - a[top - 1]) > 0) top--;
        a[++top] = a[i];
    }
    for (int i = 3; i <= top; ++i) {
        sum[i] = sum[i - 1] + Abs((a[i] - a[1]) * (a[i - 1] - a[1]));
    }
    ans = sum[top];
}
int ef(int l, int r, node x) {
    int ans = 1, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if ((x - a[1]) * (a[mid] - a[1]) <= 0) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return ans;
}
int fl(int l, int r, node x) {
    int ans = 1, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if ((x - a[mid - 1]) * (a[mid] - a[mid - 1]) < 0) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return ans;
}
int fr(int l, int r, node x) {
    int ans = top + 1, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if ((a[mid % top + 1] - x) * (a[mid] - x) < 0) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return ans;
}
void solve2(node p) {
    int wz = ef(2, top, p);
    if ((p - a[wz]) * (a[wz % top + 1] - a[wz]) < 0) return;
    int l = fl(2, wz, p);
    int r = fr(wz + 1, top, p);
    long long tmp = sum[top];
    tmp -= max(sum[min(r, top)] - sum[l], (long long)0);
    tmp += Abs((p - a[1]) * (a[l] - a[1]));
    tmp += Abs((a[(r - 1) % top + 1] - a[1]) * (p - a[1]));
    ans = max(ans, tmp);
}
void solve() {
    for (int i = 1; i <= n - k; ++i) {
        p[i].x = I(); p[i].y = I();
        if (p[i].x < a[1].x || (p[i].x == a[1].x && p[i].y < a[1].y))continue;
        else solve2(p[i]);
    }
}
void _solve() {
    for (int i = 1; i <= n - k; ++i) {
        p[i].x = -p[i].x; p[i].y = -p[i].y;
        if (p[i].x < a[1].x || (p[i].x == a[1].x && p[i].y < a[1].y))continue;
        else solve2(p[i]);
    }
}
int main () {
    n = I(); k = I();
    for (int i = 1; i <= k; ++i) {
        a[i].x = I(); a[i].y = I();
        b[i] = a[i];
        if (i > 1) {
            if (a[i] < a[1]) {
                tmp = a[1]; a[1] = a[i]; a[i] = tmp;
            }
        }
    }
    std::sort(a + 2, a + k + 1, cmp);
    tubao();
    solve();
    all = ans;

    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= k; ++i) {
        a[i].x = -b[i].x; a[i].y = -b[i].y;
        if (i > 1) {
            if (a[i] < a[1]) {
                tmp = a[1]; a[1] = a[i]; a[i] = tmp;
            }
        }
    }
    std::sort(a + 2, a + k + 1, cmp);
    tubao();
    _solve();
    all = max(all, ans);

    O(all / 2);
    if (all & 1) puts(".5");
    else puts(".0");
    return 0;
}