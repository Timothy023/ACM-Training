#include <bits/stdc++.h>
using namespace std;

int T, n, k;
int a[15], l;

int main () {
    scanf ("%d", &T);
    while (T--) {
        scanf ("%d%d", &n, &k);
        l = 0;
        while (n) {
            a[l] = n % 10;
            n /= 10;
            l++;
        }
        if (k == 1) {
            int flag = 1;
            for (int i = l - 1; i > 0; --i)
                if (a[i] > a[i - 1]) {
                    flag = 1;
                    break;
                }
                else if (a[i] < a[i - 1]) {
                    flag = 2;
                    break;
                }

            if (flag == 1) {
                for (int i = l - 1; i >= 0; --i) printf ("%d", a[l - 1]);
                puts("");
            }
            else {
                if (a[l - 1] == 9) {
                    printf ("1");
                    for (int i = l - 1; i >= 0; --i) printf ("0");
                    puts("");
                }
                else {
                    for (int i = l - 1; i >= 0; --i) printf ("%d", a[l - 1] + 1);
                    puts("");
                }
            }
        }
        else {
            int change = -1;
            int ans[15], len = 0, co[15], pos[15];
            memset(co, 0, sizeof(co));
            for (int i = l - 1; i >= 0; --i) {
                bool flag = false;
                bool minn = false;
                for (int j = 1; j <= len; ++j) {
                    if (ans[j] == a[i]) {
                        flag = true;
                        break;
                    }
                    else if (ans[j] > a[i]) minn = true;
                }
                if (flag == true) continue;
                else {
                    if (len < k) {
                        ans[++len] = a[i];
                        pos[len] = i;
                        co[a[i]] = 1;
                    }
                    else if (minn == true) {
                        ans[k] += 1;
                        change = i;
                        break;
                    }
                    else {
                        bool tmp = false;
                        for (int p = i + 1; p < pos[k]; ++p) {
                            for (int j = 1; j <= len; ++j) {
                                if (ans[j] > a[p]) {
                                    tmp = true;
                                    change = p;
                                    break;
                                }
                            }
                            if (tmp) break;
                        }
                        if (tmp) break;
                        co[ans[k]] = 0;
                        change = pos[k];
                        if (co[ans[k] + 1]) {
                            co[0] = 1;
                        }
                        else co[ans[k] + 1] = 1;
                        break;
                    }
                }
            }
            
            len = 0;
            for (int i = 0; i <= 9; ++i) if (co[i]) ans[++len] = i;
            // cout <<change <<"  " <<pos[k] <<"  " <<len <<"  " <<l <<"  " <<ans[1] <<"  " <<ans[2] <<endl;
            for (int i = l - 1; i >= 0; --i) {
                if (i < change) printf ("%d", ans[1]);
                else {
                    for (int j = 1; j <= len; ++j) {
                        if (ans[j] > a[i]) {
                            // printf ("%d %d %d\n", i, ans[j], j);
                            printf ("%d", ans[j]);
                            break;
                        }
                        else if (ans[j] == a[i] && change != i) {
                            // printf ("%d %d %d\n", i, ans[j], j);
                            printf ("%d", ans[j]);
                            break;
                        }
                    }
                }
            }
            puts("");
        }
    }
    return 0;
}