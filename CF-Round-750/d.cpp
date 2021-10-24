#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int minn = 1e4;
int T;
int n;
int a[N];
int ans[N];
vector <int> p[minn + 5];
vector <int> s;

int main () {
    scanf ("%d", &T);
    while (T--) {
        s.clear();
        for (int i = 0; i <= minn; ++i)
            p[i].clear();

        scanf ("%d", &n);
        for (int i = 1; i <= n; ++i) {
            ans[i] = 0;
            scanf ("%d", &a[i]);
            if (i <= 2) s.push_back(i);
            else p[abs(a[i])].push_back(i);
        }

        for (int i = 0; i <= minn; ++i) {
            int sz = p[i].size();
            for (int j = 0; j + 1 < sz; j += 2) {
                ans[p[i][j]] = 1;
                ans[p[i][j + 1]] = -1;
            }
            if (sz % 2 == 1) s.push_back(p[i][sz - 1]);
        }
        
        int sz = s.size();
        if (sz % 2 == 0) {
            for (int i = 0; i < sz; i += 2) {
                ans[s[i]] = -abs(a[s[i + 1]]);
                ans[s[i + 1]] = abs(a[s[i]]);
            }
        }
        else {
            for (int i = 0; i < sz; i += 2) {
                if (i + 3 < sz) {
                    ans[s[i]] = -abs(a[s[i + 1]]);
                    ans[s[i + 1]] = abs(a[s[i]]);
                }
                else {
                    ans[s[i]] = -abs(a[s[i + 1]]) - abs(a[s[i + 2]]);
                    ans[s[i + 1]] = abs(a[s[i]]);
                    ans[s[i + 2]] = abs(a[s[i]]);
                    break;
                }
            }
        }
        
        for (int i = 1; i <= n; ++i)
            if (a[i] > 0) printf ("%d ", ans[i]);
            else printf ("%d ", -ans[i]);
        puts("");
    }
    return 0;
}