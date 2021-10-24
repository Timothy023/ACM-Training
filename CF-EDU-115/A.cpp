#include <bits/stdc++.h>
using namespace std;

int T;
int n;
char s[2][105];
bool ans[2][105];

void dfs(int x, int y) {
    if (ans[x][y]) return;
    if (s[x][y] == '0')
        ans[x][y] = true;
    else return;
    if (x + 1 <= 1 && s[x + 1][y] == '0') dfs(x + 1, y);
    if (x - 1 >= 0 && s[x - 1][y] == '0') dfs(x - 1, y);
    if (y + 1 <= n && s[x][y + 1] == '0') dfs(x, y + 1);
    if (x + 1 <= 1 && y + 1 <= n && s[x + 1][y + 1] == '0') dfs(x + 1, y + 1);
    if (x - 1 >= 0 && y + 1 <= n && s[x - 1][y + 1] == '0') dfs(x - 1, y + 1);
}

int main () {
    scanf ("%d", &T);
    while (T--) {
        scanf ("%d", &n);
        n -= 1;
        scanf ("%s", s[0]);
        scanf ("%s", s[1]);
        memset(ans, 0, sizeof(ans));
        dfs(0, 0);
        if (ans[1][n]) puts("YES");
        else puts("NO");
    }
    return 0;
}