#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int T, n;

char s[505][2005];
bool flag[505];
int len[505], nxt[505][2005];

bool check(int x, int y) {
    for (int i = 1, j = 0; i < len[y]; ++i) {
        while (j > 0 && s[x][j + 1] != s[y][i]) j = nxt[x][j];
        if (s[y][i] == s[x][j + 1]) j++;
        if (j == len[x] - 1) return true;
    }
    return false;
}

int main () {
    scanf ("%d", &T);
    for (int step = 1; step <= T; ++step) {
        scanf ("%d", &n);
        for (int i = 1; i <= n; ++i) {
            memset(nxt[i], 0, sizeof(nxt[i]));
            scanf ("%s", s[i] + 1);
            flag[i] = 0;
            len[i] = strlen(s[i] + 1) + 1;
            s[i][0] = ' ';
        }
        for (int p = 1; p <= n; ++p) {
            int i = 2, j = 0;
            for (; i < len[p]; ++i) {
                while (j > 0 && s[p][j + 1] != s[p][i]) j = nxt[p][j];
                if (s[p][j + 1] == s[p][i]) j++;
                nxt[p][i] = j;
            }
        }
        int ans = -1;
        for (int p = n; p >= 2; --p) {
            if (check(p - 1, p) == 0) {
                ans = p;
                for (int i = p + 1; i <= n; ++i) {
                    for (int j = 1; j < p; ++j) {
                        if (flag[j] == 1) continue;
                        if (check(j, i) == 1) flag[j] = 1;
                        else {
                            ans = i;
                            break;
                        }
                    }
                }
                break;
            }
        }
        printf ("Case #%d: %d\n", step, ans);
    }
    return 0;
}