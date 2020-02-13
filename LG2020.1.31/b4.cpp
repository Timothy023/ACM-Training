#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, c[65][65];
int a[100], len;

int get_c() {
    for (int i = 1; i <= 63; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= 63; ++j)
            c[i][j] = c[i - 1][j] + c[i][j - 1];
    }
    for (int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= 5; ++j)
            cout <<c[i][j]<<" ";
        cout <<endl;
    }
}
void dp() {
    ;
}
int main () {
    scanf ("%lld", &n);
    for (ll x = n; x; x >>= 1)
        a[++len] = x & 1;
    get_c(); dp();
    return 0;
}