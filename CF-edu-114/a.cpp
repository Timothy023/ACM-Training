#include <bits/stdc++.h>
using namespace std;

int n;
int sum;
char ch[1000];

void dfs(int x, int len) {
    if (sum == n) return;
    if (x == 0) {
        for (int i = 1; i <= len; ++i)
            putchar(ch[i]);
        puts("");
        sum++;
        return;
    }
    for (int i = 1; i <= x; ++i) {
        for (int j = 1; j <= i; ++j) {
            ch[len + j] = '(';
        }
        for (int j = i + 1; j <= 2 * i; ++j) {
            ch[len + j] = ')';
        }
        dfs(x - i, len + 2 * i);
    }
}

int main () {
    int T;
    scanf ("%d", &T);
    while (T--) {
        sum = 0;
        scanf ("%d", &n);
        dfs(n, 0);
    }
    return 0;
}