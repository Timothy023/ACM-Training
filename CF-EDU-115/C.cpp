#include <bits/stdc++.h>
using namespace std;

int T;
int n;
map <int, int> s;
long long ans = 0;

int main () {
    scanf ("%d", &T);
    while (T--) {
        ans = 0;
        s.clear();
        scanf ("%d", &n);
        long long sum = 0;
        for (int i = 1; i <= n; ++i) {
            int x;
            scanf ("%d", &x);
            if (s.find(x) == s.end())
                s[x] = 0;
            s[x] = s[x] + 1;
            sum += x;
        }
        sum = sum * 2;
        if (sum % n != 0) {
            puts("0");
            continue;
        }
        sum /= n;
        for (auto it : s) {
            int nxt = sum - it.first;
            if (s.find(nxt) == s.end()) continue;
            if (nxt < it.first) break;
            else if (nxt == it.first) ans = ans + 1ll * it.second * (it.second - 1) / 2;
            else ans = ans + 1ll * it.second * s[nxt];
        }
        printf ("%I64d\n", ans);
    }
    return 0;
}