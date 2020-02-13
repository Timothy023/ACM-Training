#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

const int N = 1e5+5;
const int lim = 30;
int n, x;
int nx[N * 31][2], root, cnt;
int ans = 2147483647;

void insert(int x) {
    int now = root, tmp, k;
    for (int i = lim; i >= 0; --i) {
        tmp = x & (1 << i);
        k = tmp ? 1 : 0;
        if (nx[now][k] == 0)
            nx[now][k] = ++cnt;
        now = nx[now][k];
    }
}

void solve(int ro, int step, int sum) {
    if (!ro || sum >= ans) return;
    if (step == -1) return (void)(ans = sum);
    if (!nx[ro][0] || !nx[ro][1]) solve(nx[ro][0] + nx[ro][1], step - 1, sum);
    else {
        for (int k = 0; k <= 1; ++k)
            solve(nx[ro][k ^ 1], step - 1, sum + (1 << step));
    }
}

int main () {
    root = cnt = 1;
    scanf ("%d" ,&n);
    for (int i = 1; i <= n; ++i) {
        scanf ("%d", &x);
        insert(x);
    }
    solve(root, lim, 0);
    printf ("%d\n", ans);
    return 0;
}