#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int T;
char s[N];
int n;

int main () {
    scanf ("%d", &T);
    while (T--) {
        int ans = -1;
        scanf ("%d", &n);
        scanf ("%s", s);
        for (int i = 0; i < 26; ++i) {
            int l = 0, r = n - 1, sum = 0;
            while (l < r) {
                if (s[l] == s[r]) {
                    l += 1; r -= 1;
                }
                else {
                    if (s[l] - 'a' == i) {
                        l += 1;
                        sum++;
                    }
                    else if (s[r] - 'a' == i) {
                        r -= 1;
                        sum++;
                    }
                    else {
                        sum = -1;
                        break;
                    }
                }
            }
            if (sum != -1) {
                if (ans == -1) ans = sum;
                else ans = min(ans, sum);
            }
        }
        printf ("%d\n", ans);
    }
    return 0;
}