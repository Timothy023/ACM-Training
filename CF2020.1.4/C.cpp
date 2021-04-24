#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int n, ans;
int a[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int main () {
    scanf ("%d", &n);
    do {
        int maxn, minn;
        for (int i = 0; i < n; ++i)
            for (int j = i; j < n; ++j) {
                if (i == j) maxn = minn = a[i];
                maxn = max(maxn, a[j]);
                minn = min(minn, a[j]);
                if (maxn - minn == j - i) ans++;
            }
/*
        for (int i = 0; i < n; ++i)
            printf ("%d ", a[i]);
        printf ("; %d\n", ans);
*/
    }while (next_permutation(a, a + n));
    printf ("%d\n", ans);
    return 0;
}