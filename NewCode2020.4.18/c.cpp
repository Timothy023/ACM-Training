#include <bits/stdc++.h>
using namespace std;

char a[5005];
char b[5005];
int la, lb;

int main () {
    scanf ("%s", a);
    scanf ("%s", b);
    la = strlen(a);
    lb = strlen(b);
    if (la != lb) cout <<max(la, lb) <<endl;
    else {
        bool flag = 0;
        for (int i = 0; i < la; ++i)
            if (a[i] != b[i]) {
                flag = 1;
                break;
            }
        if (flag) cout <<la <<endl;
        else cout <<-1 <<endl;
    }
    return 0;
}