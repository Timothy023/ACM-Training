#include <bits/stdc++.h>
using namespace std;

int T;
string s;

int main () {
    scanf ("%d", &T);
    while (T--) {
        cin >>s;
        int len = s.size();
        int minn = 0;
        for (int i = 1; i < len; ++i)
            if (s[i] - 'a' < s[minn] - 'a') minn = i;
        putchar(s[minn]);
        putchar(' ');
        for (int i = 0; i < len; ++i)
            if (i != minn) putchar(s[i]);
        puts("");
    }
    return 0;
}