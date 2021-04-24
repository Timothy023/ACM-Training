#include <bits/stdc++.h>
using namespace std;

int n;
int a[505][505];

int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf ("%d", &a[i][i]);
    
    bool flag = true;
    for (int i = n; i >= 1 && flag; --i) {
        int x = i;
        int y = i;
        int sum = a[i][i] - 1;
        int num = a[i][i];
        while (sum > 0) {
            if (x + 1 <= n && a[x + 1][y] == 0) {
                a[x + 1][y] = num;
                x += 1;
                sum--;
            }
            else if (y - 1 >= 1 && a[x][y - 1] == 0) {
                a[x][y - 1] = num;
                y -= 1;
                sum--;
            }
            else {
                flag = false;
                break;
            }
        }
    }
    if (!flag) puts("-1");
    else {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j)
                printf ("%d ", a[i][j]);
            printf ("\n");
        }
    }
    return 0;
}