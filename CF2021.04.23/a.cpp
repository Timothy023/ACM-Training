#include <bits/stdc++.h>
using namespace std;

long long num[50];

int main () {
    num[1] = 2050;
    for (int i = 2; i <= 15; ++i)
        num[i] = num[i - 1] * 10;
    int T;
    long long n;
    scanf ("%d", &T);
    while (T--) {
        scanf ("%I64d", &n);
        int sum = 0;
        for (int i = 15; i >= 1; --i)
            while (n >= num[i]) {
                n -= num[i];
                sum++;
            }
        if (n != 0) sum = -1;
        printf ("%d\n", sum);
    }
    return 0;
}