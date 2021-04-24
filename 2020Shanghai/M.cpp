#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int T;
map <string, int> mp;
int n, m, cnt;
char ch[N];
int fi[N], nxt[N], to[N], step;
int flag[N];
int sum[N];

void addedge(int f, int t) {
    to[++step] = t; nxt[step] = fi[f]; fi[f] = step;
}

void dfs(int ro) {
    if (flag[ro] != 0) {
        if (flag[ro] == 1) sum[ro] = 1;
        else sum[ro] = 0;
        // cout <<ro <<"  " <<sum[ro] <<endl;
        return;
    }

    sum[ro] = 0;
    for (int u = fi[ro]; u; u = nxt[u]) {
        dfs(to[u]);
    }
    for (int u = fi[ro]; u; u = nxt[u]) {
        if (flag[to[u]] == -1)
            flag[ro] = -1;
        sum[ro] += sum[to[u]];
    }
    if (flag[ro] == 0) {
        flag[ro] = 1;
        if (ro != 1) sum[ro] = 1;
    }
    // cout <<ro <<"  " <<sum[ro] <<endl;
}

int main () {
    scanf ("%d", &T);
    while (T--) {
        scanf ("%d%d", &n, &m);
        step = 0;
        mp.clear();
        mp[""] = cnt = 1;
        flag[1] = fi[1] = 0;
        for (int i = 1; i <= n; ++i) {
            scanf ("%s", ch);
            int len = strlen(ch);
            string s = "", la = "";
            for (int j = 0; j < len; ++j) {
                s = s + ch[j];
                if (ch[j] == '/' || j == len - 1) {
                    if (mp.find(s) == mp.end()) {
                        mp[s] = ++cnt;
                        flag[cnt] = fi[cnt] = 0;
                        addedge(mp[la], cnt);
                        if (j == len - 1) flag[cnt] = 1;
                    }
                    la = s;
                }
            }
        }
        for (int i = 1; i <= m; ++i) {
            scanf ("%s", ch);
            int len = strlen(ch);
            string s = "", la = "";
            for (int j = 0; j < len; ++j) {
                s = s + ch[j];
                if (ch[j] == '/' || j == len - 1) {
                    if (mp.find(s) == mp.end()) {
                        mp[s] = ++cnt;
                        flag[cnt] = fi[cnt] = 0;
                        addedge(mp[la], cnt);
                        if (j == len - 1) flag[cnt] = -1;
                    }
                    la = s;
                }
            }
        }
        dfs(1);
        printf ("%d\n", sum[1]);
    }
    return 0;
}