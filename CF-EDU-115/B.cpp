#include <bits/stdc++.h>
using namespace std;

int T;
int n;
int a[1005][10];

int main () {
    scanf ("%d", &T);
    while (T--) {
        scanf ("%d", &n);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= 5; ++j) {
                scanf ("%d", &a[i][j]);
            }
        }
        bool flag = false;
        for (int i = 1; i <= 5 && !flag; ++i) {
            for (int j = i + 1; j <= 5 && !flag; ++j) {
                int s1, s2, s3;
                s1 = s2 = s3 = 0;
                flag = true;
                for (int p = 1; p <= n && flag; ++p) {
                    if (a[p][i] == 1 && a[p][j] == 1) s3++;
                    else if (a[p][i] == 1) s1++;
                    else if (a[p][j] == 1) s2++;
                    else flag = false;
                }
                if (max(s1, s2) * 2 > n) flag = false;
                if (flag) puts("YES");
            }
        }
        if (!flag) puts("NO");
    }
    return 0;
}