#include <iostream>
using namespace std;

int a[100][100], n, k;

int main () {
    int T;
    scanf ("%d", &T);
    while (T--) {
        bool flag = true;
        scanf ("%d", &n);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                scanf ("%d", &a[i][j]);
            }
        }
        for (int i = 1; i <= 3; ++i) {
            for (int j = 1; j <= 3; ++j) {
                scanf ("%d", &k);
                if (i == 1 && j == 1 && !k) flag = false;
                if ((i != 1 || j != 1) && k) flag = false;
            }
        }
        if (flag) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    printf ("%d", a[i][j]);
                    if (j != n) printf (" ");
                    
                }
                puts("");
            }
        }
        else {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    printf ("%d", 0);
                    if (j != n) printf (" ");
                }
                puts("");
            }
        }
    }
    return 0;
}