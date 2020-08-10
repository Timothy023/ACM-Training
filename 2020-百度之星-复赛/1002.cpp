#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int inf = 1e6;
int T, n, ans, a[N];
char s[N], t[N];

int main () {
    scanf ("%d", &T);
    while (T--) {
        scanf ("%d", &n);
        scanf ("%s", s + 1);
        scanf ("%s", t + 1);
        s[n + 1] = '0'; t[n + 1] = '0';
        ans = inf;
        int tmp = 0;
        a[n + 1] = a[n + 2] = 0;
        for (int i = n; i >= 1; --i) {
            if (s[i] != t[i]) a[i] = a[i + 1] + 1;
            else a[i] = a[i + 1];
        }
        int s0 = 0, s1 = 0, t0 = 0, t1 = 0;
        ans = a[1];
        for (int i = 1; i <= n + 1; ++i) {
            if (s[i] == '0') {
                tmp = a[i + 1] + s0 + t1 + 1;
                if (t[i] == '0') tmp++;
                // cout <<i <<": " <<tmp <<"  " <<s0 <<"  " <<t1 <<"  " <<a[i + 1] <<endl;
                ans = min(ans, tmp);
            }
            else {
                tmp = a[i + 1] + s0 + t1 + 2;
                if (t[i] == '0') tmp++;
                // cout <<i <<": " <<tmp <<"  " <<s0 <<"  " <<t1 <<"  " <<a[i + 1] <<endl;
                ans = min(ans, tmp);
            }
            if (s[i] == '0') s0++;
            if (t[i] == '1') t1++;
        }
        printf ("%d\n", ans);
    }
    return 0;
}