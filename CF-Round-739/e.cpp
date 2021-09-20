#include <bits/stdc++.h>
using namespace std;

int T;
char s[500005];
int co[30];
string ans;

int main () {
    scanf ("%d", &T);
    while (T--) {
        ans = "";
        memset(co, 0, sizeof(co));
        scanf ("%s", s);
        int len = strlen(s);
        for (int i = len - 1; i >= 0; --i) {
            int x = s[i] - 'a';
            if (co[x] == 0) ans = s[i] + ans;
            co[x]++;
        }
        bool flag = true;
        int rl = 0, l = ans.size();
        for (int i = 0; i < l; ++i) {
            int x = ans[i] - 'a';
            if (co[x] % (i + 1) != 0) {
                flag = false;
                break;
            }
            rl += co[x] / (i + 1);
        }
        int ansl = rl;
        int ls = 0, st = 0;
        for (int i = 0; i < l - 1 && flag; ++i) {
            st += rl;
            rl -= co[ans[i] - 'a'] / (i + 1);
            // cout <<ls <<"  " <<st <<"  " <<rl <<endl;
            for (int nxt = st; nxt < st + rl && flag; ++nxt, ++ls) {
                while (s[ls] == ans[i] && ls < st) ls++;
                if (ls == st) flag = false;
                if (s[ls] != s[nxt]) flag = false;
            }
            while (s[ls] == ans[i] && ls < st) ls++;
        }
        if (flag) {
            for (int i = 0; i < ansl; ++i) putchar(s[i]);
            putchar(' ');
            printf ("%s\n", ans.data());
        }
        else puts("-1");
    }
    return 0;
}