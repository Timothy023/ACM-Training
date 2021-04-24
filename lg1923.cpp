#include <bits/stdc++.h>
using namespace std;

const int N = 5000005;
int n, k, a[N];

int solve(int l, int r, int id) {
    int i = l, j = r, x = a[(l + r) / 2];
    while (i <= j) {
        while (a[i] < x) ++i;
        while (x < a[j]) --j;
        if (i <= j) {
            swap(a[i], a[j]);
            i++; j--;
        }
    }
    if (id <= j) return solve(l, j, id);
    else if (i <= id) return solve(i, r, id);
    else return a[j + 1];
}

int main () {
    scanf ("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf ("%d", &a[i]);
    printf ("%d\n", solve(1, n, k + 1));
    return 0;
}