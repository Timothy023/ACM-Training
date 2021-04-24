#include <bits/stdc++.h>
using namespace std;

int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}

const int N = 2005;
const int M = 4000005;
int n, r, l;
int x[N], y[N];
int fi[N], ne[M], j[M], step;
int low[N], dfn[N], sta[N], bel[N], cnt, top, sum;
//i: hang; i + l: lie

void addedge(int fr, int to) {
    j[++step] = to; ne[step] = fi[fr]; fi[fr] = step;
}

void tarjan(int ro) {
    low[ro] = dfn[ro] = ++cnt;
    sta[++top] = ro;
    for (int u = fi[ro]; u; u = ne[u]) {
        if (!dfn[j[u]]) {
            tarjan(j[u]);
            low[ro] = min(low[ro], low[j[u]]);
        }
        else if (!bel[j[u]])
            low[ro] = min(low[ro], dfn[j[u]]);
    }
    if (low[ro] == dfn[ro]) {
        ++sum;
        for (int now = 0; now != ro;) {
            now = sta[top--];
            bel[now] = sum;
        }
    }
}

int main () {
    // freopen ("test.in", "r", stdin);
    // freopen ("test.out", "w", stdout);
    n = I(); r = I(); l = I();
    for (int i = 1; i <= l; ++i) {
        x[i] = I(); y[i] = I();
    }
    for (int i = 1; i <= l; ++i) {
        for (int j = i + 1; j <= l; ++j) {
            if (abs(x[i] - x[j]) <= 2 * r - 1 && y[i] == y[j]) {
                addedge(i + l, j);
                addedge(j + l, i);
            }//bu neng tong shi xuan lie
            if (abs(y[i] - y[j]) <= 2 * r - 1 && x[i] == x[j]) {
                addedge(i, j + l);
                addedge(j, i + l);
            }//bu neng tong shi xuan hang
        }
    }
    for (int i = 1; i <= l * 2; ++i)
        if (!dfn[i]) tarjan(i);
    for (int i = 1; i <= l; ++i)
        if (bel[i] == bel[i + l]) {
            puts("NO");
            return 0;
        }
    puts("YES");
    return 0;
}