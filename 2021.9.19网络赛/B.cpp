#include <bits/stdc++.h>
using namespace std;

string s;
int len;
int n;
int st = 0;

void err() {
    puts("ERROR");
    exit(0);
}

struct node{
    int x, y;
    node(){}
    node(int _x, int _y) {
        x = _x; y = _y;
    }
    friend node operator - (node i, node j) {
        return node(i.x - j.x, i.y - j.y);
    }
}a[100000];

int cj(node i, node j) {
    return i.x * j.y - i.y*j.x;
}

bool cmp(node i, node j) {
    int t = cj(i - a[0], j - a[0]);
    if (t == 0) err();
    return t < 0;
}

int change() {
    if (st == len) err();
    int fh = 1, num = 0;
    if (s[st] < '0' || s[st] > '9') {
        if (s[st] == '+') fh = 1;
        else if (s[st] == '-') fh = -1;
        else err();
        st++;
    }
    while (1) {
        if (s[st] < '0' || s[st] > '9') err();
        num = num * 10 + s[st] - '0';
        st++;
        if (s[st] == ',' || st == len) break;
    }
    st++;
    // cout <<st <<"  " <<fh <<"  " <<num <<endl;
    return fh * num;
}

int main () {
    cin >>s;
    len = s.size();
    n = -1;
    while (1) {
        if (st >= len) break;
        ++n;
        a[n].x = change();
        a[n].y = change();
    }
    n++;
    for (int i = 1; i < n; ++i) {
        if (a[i].x < a[0].x || (a[i].x == a[0].x && a[i].y < a[0].y)) swap(a[0], a[i]);
    }
    sort(a + 1, a + n, cmp);
    for (int i = 0; i < n; ++i) {
        if (cj(a[(i + 1) % n] - a[i], a[(i + 2) % n] - a[i]) >= 0) err();
    }
    int sp = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i].x * a[i].x + a[i].y * a[i].y < a[sp].x * a[sp].x + a[sp].y * a[sp].y)
            sp = i;
    }
    for (int i = 0; i < n; ++i) {
        cout <<a[(i + sp) % n].x <<',' <<a[(i + sp) % n].y;
        if (i + 1 != n) cout <<",";
    }
    puts("");
    return 0;
}