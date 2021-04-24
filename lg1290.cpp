#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int T, x, y, tmp;

int solve(int i, int j) {
    int sum = 0;
    while (i && j) {
        if (i < j) swap(i, j);
        if (i / j > 1) return sum + 1;
        else {
            i -= j;
            sum++;
        }
    }
    return sum;
}

int main () {
    scanf ("%d", &T);
    while (T--) {
        scanf ("%d%d", &x, &y);
        tmp = solve(x, y);
        if (tmp & 1) puts("Stan wins");
        else puts("Ollie wins");
    }
    return 0;
}