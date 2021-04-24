#include <iostream>
using namespace std;

int T, n, a[100];

int main () {
    scanf ("%d", &T);
    while (T--) {
        bool flag = true;
        scanf ("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf ("%d", &a[i]);
            if (i != 1) {
                if (a[i] == a[i - 1])
                    flag = false;
            }
        }
        if (flag) puts("YES");
        else puts("NO");
    }
    return 0;
}