#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

struct node {
    int val, pos;
    friend bool operator < (node i, node j) {
        return i.val < j.val;
    }
}a[N];

int T, n;

int main () {
    scanf ("%d", &T);
    while (T--) {
        scanf ("%d", &n);
        for (int i = 1; i <= n; ++i) {
            int x;
            scanf ("%d", &x);
            a[i].val = x;
            a[i].pos = i;
        }
        long long ans = 0;
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < i && 1ll * a[j].val * a[i].val < 2ll * n; ++j) {
                if (1ll * a[j].val * a[i].val == a[j].pos + a[i].pos) ans++;
            }
        }
        cout <<ans <<endl;
    }
    return 0;
}