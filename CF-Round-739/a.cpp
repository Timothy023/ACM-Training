#include <bits/stdc++.h>
using namespace std;

int T, n;
int a[20005], len;

int main () {
    cin >>T;
    for (int i = 1; i <= 20000; ++i) 
        if (i % 3 == 0 || i % 10 == 3) continue;
        else a[++len] = i;
    while (T--) {
        cin >>n;
        cout <<a[n] <<endl;
    }
    return 0;
}