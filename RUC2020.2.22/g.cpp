#include <bits/stdc++.h>
using namespace std;

const int N = 3e5;
const int M = 1 << 20;
char ch[N];
int sum[50], n, ans;
int wz[M];

int main () {
    scanf ("%d", &n);
    scanf ("%s", ch + 1);
    memset(wz, 60, sizeof(wz));
    wz[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int x = 0;
        sum[ch[i] - 'a']++;
        for (int j = 0; j < 20; ++j) {
            if (sum[j] & 1) {
                x += (1 << j);
            }
        }
        ans = max(i - wz[x], ans);
        for (int j = 0; j < 20; ++j) {
            ans = max(i - wz[x ^ (1 << j)], ans);
        }
        wz[x] = min(wz[x], i);
    }
    printf ("%d\n", ans);
    return 0;
}