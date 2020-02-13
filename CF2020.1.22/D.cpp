#include <bits\stdc++.h>
using namespace std;

const int N = 4e6 + 5;
int n, x, a[N << 1], t, ans, wz[N << 1];

int main () {
    scanf ("%d%d", &n, &x);
    for (int i = 1; i <= n; ++i) {
        scanf ("%d", &t);
        t %= x;
        if (wz[t] * x + t < N){
            a[wz[t] * x + t] = 1;
            wz[t]++;
        }
        for (; a[ans] && ans < N; ans++);
        printf ("%d\n", ans);
    }
    return 0;
}