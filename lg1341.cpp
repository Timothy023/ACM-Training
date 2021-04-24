#include <bits/stdc++.h>
using namespace std;

char ch[2], ans[1000000];
int d[200][200], fa[200], n, deg[200];

int get_fa(int x) {
    if (fa[x] != x) fa[x] = get_fa(fa[x]);
    return fa[x];
}

void dfs(int ro) {
    for (int i = 1; i <= 128; ++i)
        if (d[ro][i]) {
            d[ro][i] = d[i][ro] = 0;
            dfs(i);
        }
    ans[n--] = (char)ro;
}

int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= 128; ++i) fa[i] = i;
    for (int i = 1; i <= n; ++i) {
        scanf ("%s", ch);
        int t1 = get_fa(ch[0]);
        int t2 = get_fa(ch[1]);
        d[ch[0]][ch[1]] = d[ch[1]][ch[0]] = 1;
        fa[t1] = t2;
        deg[ch[0]]++; deg[ch[1]]++;
    }
    int sum = 0, wz = -1;
    for (int i = 1; i <= 128; ++i)
        if (fa[i] == i && deg[i]) sum++;
    if (sum != 1) {
        puts ("No Solution");
        return 0;
    }
    sum = 0;
    for (int i = 1; i <= 128; ++i)
        if (deg[i] % 2) {
            sum++;
            if (wz == -1) wz = i;
        }
    if (sum > 2) {
        puts ("No Solution");
        return 0;
    }
    if (sum == 0) {
        for (int i = 1; i <= 128; ++i) {
            if (deg[i]) {
                wz = i;
                break;
            }
        }
    }
    dfs(wz);
    puts(ans);
    return 0;
}