#include <bits/stdc++.h>
using namespace std;

int n, m, cnt, ans;
int ansid[15], tmpid[15];
int len[15];
vector <int> a[15];
map <int, int> nxt[2000005];

void insert() {
    int x, now = 0;
    for (int i = 1; i <= n; ++i) {
        scanf ("%d", &x);
        if (nxt[now].find(x) == nxt[now].end()) {
            cnt += 1;
            nxt[now][x] = cnt;
        }
        now = nxt[now][x];
    }
}

void dfs(int ro, int step, int sum) {
    // cout <<"dfs: " <<ro <<"  " <<sum <<endl;
    if (step == n + 1) return;
    int maxid = 0, lst = 0;
    for (auto it : nxt[ro]) {
        // cout <<ro <<"  " <<it.first <<"  " <<it.second <<endl;
        tmpid[step] = it.first;
        dfs(it.second, step + 1, sum + a[step][it.first]);
        if (it.first - 1 != lst) maxid = it.first - 1;
        lst = it.first;
    }
    if (len[step] != lst) maxid = len[step];
    if (maxid == 0) return;
    int tmp = a[step][maxid];
    tmpid[step] = maxid;
    for (int i = step + 1; i <= n; ++i) {
        tmp += a[i][len[i]];
        tmpid[i] = len[i];
    }
    if (sum + tmp > ans) {
        ans = sum + tmp;
        for (int i = 1; i <= n; ++i)
            ansid[i] = tmpid[i];
    }
}

int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf ("%d", &len[i]);
        a[i].push_back(0);
        for (int j = 1; j <= len[i]; ++j) {
            scanf ("%d", &x);
            a[i].push_back(x);
        }
    }
    scanf ("%d", &m);
    for (int i = 1; i <= m; ++i) {
        insert();
    }
    dfs(0, 1, 0);
    // printf ("%d\n", ans);
    for (int i = 1; i <= n; ++i)
        printf ("%d ", ansid[i]);
    return 0;
}