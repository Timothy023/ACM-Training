#include <bits/stdc++.h>
using namespace std;

int T;
char s[100005];
char ch[50];

const int p1 = 131;
const int p2 = 233;

map < pair<int, int>, pair<int, int> > mp;

int main () {
    scanf ("%d", &T);
    while (T--) {
        scanf ("%s", s);
        int len = strlen(s);
        mp.clear();
        for (int i = 0; i < len; ++i) {
            int x1 = 0, x2 = 0;
            for (int l = 0; i + l < len && l < 30; ++l) {
                x1 = x1 * p1 + s[i + l];
                x2 = x2 * p2 + s[i + l];
                pair <int, int> x = make_pair(x1, x2);
                if (mp.find(x) == mp.end()) {
                    mp[x] = make_pair(1, i + l + 1);
                }
                else {
                    pair <int, int> tmp = mp[x];
                    if (tmp.second <= i)
                        mp[x] = make_pair(tmp.first + 1, i + l + 1);
                }
            }
        }
        int n;
        scanf ("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf ("%s", ch);
            int x1 = 0, x2 = 0;
            int ll = strlen(ch);
            for (int j = 0; j < ll; ++j) {
                x1 = x1 * p1 + ch[j];
                x2 = x2 * p2 + ch[j];
            }
            pair <int, int> x = make_pair(x1, x2);
            if (mp.find(x) == mp.end()) {
                printf ("%d\n", 0);
            }
            else {
                pair <int, int> tmp = mp[x];
                printf ("%d\n", tmp.first);
            }
        }
    }
    return 0;
}