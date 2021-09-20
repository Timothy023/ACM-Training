#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int T;
int n;
int a[N];

int main () {
    scanf ("%d", &T);
    while (T--) {
        scanf ("%d", &n);
        for (int i = 1; i <= n; ++i) a[i] = i;
        for (int i = 1; i <= n; i += 2) {
            if (i + 2 == n) {
                swap(a[i], a[i + 2]);
                swap(a[i + 1], a[i + 2]);
                break;
            }
            else {
                swap(a[i], a[i + 1]);
            }
        }
        for (int i = 1; i <= n; ++i)
            printf ("%d ", a[i]);
        puts("");
    }
    return 0;
}