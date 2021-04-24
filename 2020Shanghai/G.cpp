#include <bits/stdc++.h>
using namespace std;

long long ans, n;

int main () {
    cin >>n;
    ans = (n - n / 3) * (n / 3) + (n / 3) * (n / 3 - 1) / 2;
    cout <<ans <<endl;
    return 0;
}