#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

vector <int> sta[2000];
int T, n, k, tmp[N], len;

int main () {
    scanf ("%d", &T);
    while (T--) {
        scanf ("%d%d", &n, &k);
        int tn = n; n = 2 * n * (1 << k);
        for (int i = 1; i <= n; ++i) {
            scanf ("%d", &tmp[i]);
        }
        for (int i = n; i >= 1; --i) {
            sta[1].push_back(tmp[i]);
        }
        for (int step = 1; step <= k; ++step) {
            int all = (1 << (step - 1));
            for (int i = 1; i <= all; ++i) {
                len = sta[i].size();
                // cout <<"test: " <<i <<"  " <<sta[i].size() <<"  " <<len - 1 <<"  " <<len - (1 << (k - step + 2)) <<endl;
                for (int j = len - 1; j >= len - (1 << (k - step + 1)) * tn; --j) {
                    int x = sta[i][j];
                    sta[i].pop_back();
                    sta[all * 2 - i + 1].push_back(x);
                }
            }
            /*
            all = 1 << step;
            for (int j = 1; j <= all; ++j) {
                for (int i = 0; i < n / all; ++i){
                    printf ("%d ", sta[j][i]);
                }
                puts("");
            }
            puts("-------------------------");
            */
        }
        int all = 1 << k;
        for (int i = tn * 2 - 1; i >= 0; --i) {
            for (int j = all; j >= 1; --j) {
                if (i != 0 || j != 1) printf ("%d ", sta[j][i]);
                else printf ("%d", sta[j][i]);
            }
        }
        puts("");
        for (int i = 1; i <= all; ++i) sta[i].clear();
    }
    return 0;
}