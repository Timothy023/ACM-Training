#include <bits\stdc++.h>
using namespace std;
struct node{
    int x, y;
    friend bool operator < (node i, node j) {
        if (i.x == j.x) return i.y < j.y;
        else return i.x < j.x;
    }
}a[1005];
int T, n;
bool flag;
int main () {
    scanf ("%d", &T);
    while (T--) {
        flag = 1;
        scanf ("%d", &n);
        a[0].x = a[0].y = 0;
        for (int i = 1; i <= n; ++i)
            scanf ("%d%d", &a[i].x, &a[i].y);
        sort(a + 1, a + n + 1);
        flag = 0;
        for (int i = 2; i <= n; ++i)
            if (a[i].y < a[i - 1].y){
                flag = 1; break;
            }
        if (flag){
            puts("NO");
            continue;
        }
        puts("YES");
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= a[i].x - a[i - 1].x; ++j) putchar('R');
            for (int j = 1; j <= a[i].y - a[i - 1].y; ++j) putchar('U');
        }
        puts("");
    }
    return 0;
}