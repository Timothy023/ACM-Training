#include <bits/stdc++.h>
using namespace std;

int n;
struct node {
    string s;
    int len, ls, rs, gx;
}a[25];

int main () {
    cin >>n;
    for (int i = 1; i <= n; ++i) {
        cin >>a[i].s;
        a[i].len = a[i].s.size();
        int l = 0, r = 0;
        int lsl = -1, lsr = -1;
        for (int j = 0; j < a[i].len; ++j) {
            if (a[i].s[j] == '(') {
                if (lsr == -1) lsr = j;
                r++;
            }
            else {
                if (r != 0) {
                    r--;
                    if (r == 0) lsr = -1;
                }
                else {
                    l++;
                    lsl = j;
                }
            }
        }
        a[i].ls = l; a[i].rs = r;
        int stp = a[i].len - 1;
        if (lsr != -1) stp = lsr;
        int tr = 0, g = 0;
        for (int j = max(lsl, 0); j <= stp; ++j) {
            if (a[i].s[j] == '(') tr++;
            else tr--;
            if (tr == 0) g++;
        }
        a[i].gx = g;
        cout <<l <<"  " <<r <<"  " <<g <<"  " <<lsl <<"  " <<lsr <<endl;
    }
    return 0;
}