#include <bits/stdc++.h>
using namespace std;

long long a, b, n;

int main () {
    cin >>a >>b >>n;
    long long s = b - a;
    long long t = n - b;
    long long ans = (t / s);
    if (t % s) ans++;
    cout <<ans * 2 + 1 <<endl;
    return 0;
}