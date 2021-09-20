#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int T;
int n, a[N];

int main () {
    scanf ("%d", &T);
    while (T--) {
        scanf ("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf ("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        long long sum = a[1];
        long long ans = 0;
        for (int i = 3; i <= n; ++i) {
            ans += 1ll * a[i] * (i - 2) - sum;
            sum += a[i - 1];
        }
        cout <<-ans <<endl;
    }
    return 0;
}