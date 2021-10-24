#include <bits/stdc++.h>
using namespace std;

int T;

int main () {
    scanf ("%d", &T);
    while (T--) {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c);
        printf ("%d\n", (1ll * a + 2ll * b + 3ll * c) % 2);
    }
    return 0;
}