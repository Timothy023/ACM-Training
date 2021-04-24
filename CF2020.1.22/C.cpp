#include <bits\stdc++.h>
using namespace std;
int T, n, ans[5], sum;
void solve() {
    for (int i = 2; i * i <= n && sum < 2; ++i) {
        if (n % i ==0) {
            n /= i;
            ans[++sum] = i;
        }
    }
    if (n != 1 && n != ans[sum]) ans[++sum] = n;
}
int main () {
    scanf ("%d", &T);
    while (T--) {
        sum = 0;
        scanf ("%d", &n);
        solve();
        if (sum == 3){
            puts("YES");
            printf ("%d %d %d\n", ans[1], ans[2], ans[3]);
        }
        else puts("NO");
    }
    return 0;
}