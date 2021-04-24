#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
char s[N], t[N];
int T, nx[N][26], wz[26], ls, lt, ans, p, las;

int main () {
    scanf ("%d", &T);
    while (T--) {
        scanf ("%s", s + 1); ls = strlen(s + 1);
        scanf ("%s", t + 1); lt = strlen(t + 1);
        memset(wz, -1, sizeof(wz));
        for (int i = ls; i >= 0; --i) {
            for (int j = 0; j <= 25; ++j)
                nx[i][j] = wz[j];
            if (i != 0) wz[s[i] - 'a'] = i;
        }
        ans = 0;
        for (int i = 1; i <= lt; ) {
            las = i;
            for (p = 0; nx[p][t[i] - 'a'] != -1 && i <= lt; ) {
                p = nx[p][t[i] - 'a'];
                i += 1;
            }
            if (i == las) {
                ans = -1;
                break;
            }
            ans++;
        }
        printf ("%d\n", ans);
    }
    return 0;
}