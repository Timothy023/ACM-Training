#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100005];

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf ("%d", &x);
        a[x]++;
    }
    if (a[1] >= 2) cout <<2 <<endl;
    else cout <<3 <<endl;
    return 0;
}