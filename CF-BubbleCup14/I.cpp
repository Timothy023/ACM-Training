#include <bits/stdc++.h>
using namespace std;

// const long double eps = 1e-10;

long double fc(int m, int n) {
    long double s = 1;
    for (int i = 0; i < n; ++i)
        s = s * (1.0 * (n - i) / (m - i));
    return s;
}

int main () {
    int n;
    long double p;
    cin >>n >>p;
    for (int i = 0; i <= n; ++i) {
        long double tmp = 0.0;
        if (n - i >= 3) {
            long double fm = 1.0 * (n - i) * (n - i - 1) * (n - i - 2) / ((n) * (n - 1) * (n - 2));
            tmp = tmp + fm;
        }
        if (n - i >= 2 && i >= 1) {
            long double fm = 1.0 * (n - i) * (n - i - 1) / 2 * i / ((n) * (n - 1) * (n - 2) / 6);
            tmp = tmp + fm * (0 + 1 + 0.5) / 3;
        }

        if (1 - tmp >= p) {
            cout <<i <<endl;
            break;
        }
    }
    return 0;
}