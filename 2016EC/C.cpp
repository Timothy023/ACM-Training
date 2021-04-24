#include <bits/stdc++.h>
using namespace std;

int T;
int n;
int a[1005];
bool flag[100005];

int main () {
    scanf ("%d", &T);
    for (int step = 1; step <= T; ++step) {
        int ans = 0;
        scanf ("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf ("%d", &a[i]);
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                int p1 = i, p2 = j;
                for (; p1 < j; ++p1) {
                    if (!flag[a[p1]]) flag[a[p1]] = 1;
                    else break;
                }
                p1--;
                for (; p2 <= n; ++p2) {
                    if (!flag[a[p2]]) flag[a[p2]] = 1;
                    else break;
                }
                p2--;
                ans = max(ans, (p1 - i + 1) + (p2 - j + 1));
                for (p2 = p2 + 1; p2 <= n && p1 >= i; ++p2) {
                    if (!flag[a[p2]]) flag[a[p2]] = 1;
                    else {
                        while (p1 >= i && flag[a[p2]]) {
                            flag[a[p1]] = 0;
                            p1--;
                        }
                        flag[a[p2]] = 1;
                    }
                    ans = max(ans, (p1 - i + 1) + (p2 - j + 1));
                }
                while (p1 >= i) {
                    flag[a[p1]] = 0;
                    p1--;
                }
                while (p2 >= j) {
                    flag[a[p2]] = 0;
                    p2--;
                }
            }
        }
        printf ("Case #%d: %d\n", step, ans);
    }
    return 0;
}