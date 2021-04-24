#include <bits/stdc++.h>
using namespace std;

const int n = 25;
char ch[30][30], f;
int fx[8] = {1, 0, 1, 1};
int fy[8] = {0, 1, -1, 1};
int s1, s2;

bool check(int x, int y) {
    for (int k = 0; k < 4; ++k) {
        int nx = x, ny = y, sum = 0;
        if (ch[x][y] != '.') return false;
        while (1) {
            nx += fx[k]; ny += fy[k];
            if (nx < 1 || nx > n || ny < 1 || ny > n || ch[nx][ny] != f) break;
            else sum++;
        }
        nx = x; ny = y;
        while (1) {
            nx -= fx[k]; ny -= fy[k];
            if (nx < 1 || nx > n || ny < 1 || ny > n || ch[nx][ny] != f) break;
            else sum++;
        }
        sum++;
        if (sum >= 5) return true;
    }
    return false;
}

int main () {
    for (int i = 1; i <= n; ++i) {
        scanf ("%s", ch[i] + 1);
        for (int j = 1; j <= n; ++j) {
            if (ch[i][j] == 'o') s1++;
            if (ch[i][j] == 'x') s2++;
        }
    }
    if (s1 == s2) f = 'x';
    else f = 'o';
    bool ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            bool flag = check(i, j);
            if (flag) {
                printf ("%d %d\n", i - 1, j - 1);
                ans = 1;
            }
        }
    }
    if (!ans) puts("tie");
    return 0;
}