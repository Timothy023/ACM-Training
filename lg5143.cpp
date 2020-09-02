#include <bits/stdc++.h>
using namespace std;

const int N = 50005;
struct node {
    int x, y, z;
    friend bool operator < (node i, node j) {
        return i.z < j.z;
    }
}a[N];
int n;

int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf ("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
    }
    sort(a + 1, a + n + 1);
    double ans = 0.0;
    for (int i = 1; i < n; ++i) {
        ans += sqrt(1.0 * (a[i].x - a[i + 1].x) * (a[i].x - a[i + 1].x) + 
                    1.0 * (a[i].y - a[i + 1].y) * (a[i].y - a[i + 1].y) + 
                    1.0 * (a[i].z - a[i + 1].z) * (a[i].z - a[i + 1].z));
    }
    printf ("%.3lf\n", ans);
    return 0;
}