#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

const int N = 25;
int n, a[N];

int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i) scanf ("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        if (a[i] == 0) {
            if (i % 2 == 0) return puts("YES"), 0;
            else break;
        }
    for (int i = n; i >= 1; --i)
        if (a[i] == 0) {
            if ((n - i + 1) % 2 == 0) return puts("YES"), 0;
            else break;
        }
    puts("NO");
    return 0;
}