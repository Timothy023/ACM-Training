#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
int n, s1, s2;
char a[100005];
int main () {
    scanf ("%d", &n);
    scanf ("%s", a + 1);
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 'L') s1++;
        else s2++;
    }
    printf ("%d\n", s1+s2+1);
    return 0;
}