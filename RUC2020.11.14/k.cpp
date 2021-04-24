#include <bits/stdc++.h>
using namespace std;

int l[1005], r[1005];
int n, m, ans, s, x, z, y, sx, sy;
char a[1005][1005];

void solve(int x, int y, int lie) {
    int tl = y, tr = y;
    char c = a[x][y] - 'A' + 'a';
    if (lie != 0) {
        tl = lie;
    }
    for (; tr < m && a[x][tr + 1] == '.'; tr++);

    // cout <<x <<"  " <<y <<"  " <<lie <<"  " <<tl <<"  " <<tr <<endl;

    for (int j = tl; j <= tr; ++j) 
        if (a[x][j] == '.')
            a[x][j] = c;
}

void solve1(int ll, int rr) {
    for (int i = ll + 1; i <= rr; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i][j] == '.') {
                a[i][j] = a[i - 1][j];
                if (a[i][j] >= 'A' && a[i][j] <= 'Z')
                    a[i][j] = a[i][j] - 'A' + 'a';
            }
    
    for (int i = rr - 1; i >= ll; --i)
        for (int j = 1; j <= m; ++j)
            if (a[i][j] == '.') {
                a[i][j] = a[i + 1][j];
                if (a[i][j] >= 'A' && a[i][j] <= 'Z')
                    a[i][j] = a[i][j] - 'A' + 'a';
            }
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf ("%s", a[i] + 1);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == 'A') {
                sx = i; sy = j;
            }
        }
    }

    int tl = 1, tr = m;
    for (int i = sx; i >= 1; --i) {
        if ((a[i][sy] == 'A' || a[i][sy] == '.') && tl <= sy && tr >= sy) {
            for (l[i] = sy; l[i] > tl && a[i][l[i] - 1] == '.'; l[i]--);
            for (r[i] = sy; r[i] < tr && a[i][r[i] + 1] == '.'; r[i]++);
        }
        else {
            l[i] = sy + 1;
            r[i] = sy - 1;
        }
        tl = l[i]; tr = r[i];
    }

    tl = 1, tr = m;
    for (int i = sx; i <= n; ++i) {
        if ((a[i][sy] == 'A' || a[i][sy] == '.') && tl <= sy && tr >= sy) {
            for (l[i] = sy; l[i] > tl && a[i][l[i] - 1] == '.'; l[i]--);
            for (r[i] = sy; r[i] < tr && a[i][r[i] + 1] == '.'; r[i]++);
        }
        else {
            l[i] = sy + 1;
            r[i] = sy - 1;
        }
        tl = l[i]; tr = r[i];
    }

    for (int i = sx; i >= 1; --i) {
        for (int j = sx; j <= n; ++j) {
            if (r[i] < sy || r[j] < sy || l[i] > sy || l[j] > sy) continue;
            int sum = (j - i + 1) * (min(r[i], r[j]) - max(l[i], l[j]) + 1);
            if (sum > ans) {
                ans = sum;
                s = i; x = j;
                z = max(l[i], l[j]); y = min(r[i], r[j]);
            }
        }
    }

    for (int i = s; i <= x; ++i) {
        for (int j = z; j <= y; ++j) {
            if (a[i][j] == '.')
                a[i][j] = 'a';
        }
    }   

    int lie = 1;
    for (int i = 1; i <= n; ++i) {
        lie = 1;
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == 'a' || a[i][j] == 'A') lie = j + 1;
            // cout <<"solve: " <<i <<"  " <<j <<"  " <<lie <<endl;
            if (a[i][j] <= 'A' || a[i][j] > 'Z') continue;
            // cout <<"solve: " <<i <<"  " <<j <<"  " <<lie <<"  " <<a[i][j] <<endl;
            solve(i, j, lie);
            lie = 0;
        }
    }

    solve1(1, s - 1);
    solve1(s, x);
    solve1(x + 1, n);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            printf ("%c", a[i][j]);
        puts("");
    }
    return 0;
}