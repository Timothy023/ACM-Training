#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, a[N], lb[N], rb[N];

bool dfs(int x, int y, int now) {
    if (a[x] <= now && a[y] <= now) return true;

    if (a[x] > a[y]) {
        if (lb[x] % 2 == 1) return false;
        else {
            if (a[y] <= now) return true;
            else return !dfs(x, y - 1, a[y]);
        }
    }
    else if (a[x] < a[y]) {
        if (rb[y] % 2 == 1) return false;
        else {
            if (a[x] <= now) return true;
            else return !dfs(x + 1, y, a[x]);
        }
    }
    else {
        if (a[x] <= now) return true;
        else if (lb[x] % 2 == 1 || rb[y] % 2 == 1) return false;
        else return true;
    }
}

int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf ("%d", &a[i]);
    }

    int tmp = 1;
    for (int i = 2; i <= n; ++i) {
        if (a[i] > a[i - 1]) tmp++;
        else break;
    }
    for (int i = 1; i <= tmp; ++i) lb[i] = tmp - i + 1;

    tmp = 1;
    for (int i = n - 1; i >= 1; --i) {
        if (a[i] > a[i + 1]) tmp++;
        else break;
    }
    for (int i = 0; i < tmp; ++i) rb[n - i] = tmp - i;
    // for (int i = 1; i <= n; ++i) cout <<lb[i] <<"  "; cout <<endl;
    // for (int i = 1; i <= n; ++i) cout <<rb[i] <<"  "; cout <<endl;
    bool ans = dfs(1, n, -1);
    if (!ans) puts("Alice");
    else puts("Bob");
    return 0;
}