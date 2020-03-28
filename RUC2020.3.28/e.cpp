#include <bits/stdc++.h>
using namespace std;

int T, n, m, q;
char a[50][50];
char s[105];
int fx[4] = {0, 1, 0, -1};
int fy[4] = {1, 0, -1, 0};
char ki[4] = {'R', 'D', 'L', 'U'};

int main () {
    scanf ("%d", &T);
    for (int step = 1; step <= T; ++step) {
        printf ("Word search puzzle #%d:\n", step);
        scanf ("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
            scanf ("%s", a[i] + 1);
        scanf ("%d", &q);
        while (q--) {
            scanf ("%s", s);
            int len = strlen(s);
            bool flag = 1;
            for (int i = 1; i <= n && flag; ++i)
                for (int j = 1; j <= m && flag; ++j) {
                    int nx, ny;
                    for (int k = 0; k < 4 && flag; ++k) {
                        nx = i; ny = j;
                        for (int l = 0; l < len; ++l) {
                            if (a[nx][ny] != s[l]) break;

                            nx += fx[k]; ny += fy[k];

                            if (nx < 1) nx = n;
                            else if (nx > n) nx = 1;

                            if (ny < 1) ny = m;
                            else if (ny > m) ny = 1;

                            if (l + 1 == len) {
                                flag = 0;
                                printf ("%c %d %d %s\n", ki[k], i, j, s);
                            }
                        }
                    }
                }
        }
        puts("");
    }
    return 0;
}