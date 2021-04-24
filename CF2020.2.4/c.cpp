#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int inf = 1e9;
int T, n, s1[N], s2[N], ans, ax, ay;
char ch[N];
map <int, int> be[N << 1];

int main () {
    scanf ("%d", &T);
    while (T--) {
        scanf ("%d", &n);
        scanf ("%s", ch + 1);
        ans = inf; s1[0] = n;
        for (int i = 1; i <= n; ++i) {
            s1[i] = s1[i - 1];
            s2[i] = s2[i - 1];
            if (ch[i] == 'U') s1[i]++;
            else if (ch[i] == 'D') s1[i]--;
            else if (ch[i] == 'L') s2[i]++;
            else s2[i]--;
        }

        be[n][0] = 0;
        for (int i = 1; i <= n; ++i) {
            if (be[s1[i]].find(s2[i]) != be[s1[i]].end()) {
                int wz = be[s1[i]][s2[i]];
                if (i - wz < ans) {
                    ans = i - wz;
                    ax = wz + 1;
                    ay = i;
                }
            }
            be[s1[i]][s2[i]] = i;
        }
        be[n].clear();
        for (int i = 1; i <= n; ++i) be[s1[i]].clear();

        if (ans == inf) puts("-1");
        else printf ("%d %d\n", ax, ay);
    }
    return 0;
}