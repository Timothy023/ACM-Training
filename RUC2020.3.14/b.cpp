#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int n, num;

int dfs(int k) {
    int sum = k, tmp;
    while (num != n) {
        char ch = getchar();
        num++;
        if (ch == ')') {
            ch = getchar();
            break;
        }
        else if (ch == '(') {
            ch = getchar();
            tmp = dfs(k ^ 1);
        }
        else {
            tmp = 0;
            while (ch >= '0' && ch <= '9') {
                tmp = tmp * 10 + ch - '0';
                ch = getchar();
            }
        }

        if (k == 0) sum = (sum + tmp) % mod;
        else sum = 1ll * sum * tmp % mod;
    }
    return sum % mod;
}

int main () {
    scanf ("%d\n", &n);
    cout <<dfs(0) <<endl;
    return 0;
}