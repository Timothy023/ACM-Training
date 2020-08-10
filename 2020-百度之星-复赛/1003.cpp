#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9 + 5;
int T, n, l, k;
int a[N], b[N], s1, s2;
priority_queue < pair<int, int> > q1;
priority_queue < pair<int, int> , vector< pair<int, int> >, greater< pair<int, int> > > q2;

bool cmp(int i, int j) {
    return i > j;
}

long long solve() {
    int len = 1;
    long long ans = 0;
    for (int i = 1; i <= n; ++i) b[i] = inf;
    for (int i = l - k + 1; i <= n; i += (l - k)) {
        for (int j = 1; j <= k && i <= n; ++j) {
            b[i] = a[len];
            i++; len++;
        }
    }
    // for (int i = 1; i <= n; ++i) cout <<b[i] <<"  "; cout <<endl;
    s1 = 0; s2 = 0;
    while (!q1.empty()) q1.pop();
    while (!q2.empty()) q2.pop();
    
    for (int i = l - k; i < l; ++i) {
        if (s1 < k) {
            q1.push(make_pair(b[i], i));
            s1++;
        }
        else {
            if (q1.top().first > b[i]) {
                int id = q1.top().second;
                q1.pop();
                q1.push(make_pair(b[i], i));
                q2.push(make_pair(b[id], id));
            }
            else {
                q2.push(make_pair(b[i], i));
            }
            s2++;
        }
    }
    for (int i = l; i <= n; ++i) {
        while (!q1.empty() && q1.top().second <= i - l) {
            if (q1.top().second == i - l) s1--;
            q1.pop();
        }
        while (!q2.empty() && q2.top().second <= i - l) q2.pop();
        if (i - l != 0 && b[i - l] < q1.top().first) s1--;
        if (q1.top().first >= b[i]) {
            q1.push(make_pair(b[i], i));
            s1++;
        }
        else {
            q2.push(make_pair(b[i], i));
        }
        while (s1 > k) {
            int id = q1.top().second;
            s1--;
            q1.pop();
            while (q1.top().second <= i - l) q1.pop();
            // cout <<"id = " <<id <<"  ";
            q2.push(make_pair(b[id], id));
        }
        while (s1 < k) {
            int id = q2.top().second;
            s1++;
            q2.pop();
            while (q2.top().second <= i - l) q2.pop();
            q1.push(make_pair(b[id], id));
        }
        ans += q1.top().first;
    }
    return ans;
}

int main () {
    scanf ("%d", &T);
    while (T--) {
        scanf ("%d%d%d", &n, &l, &k);
        for (int i = 1; i <= n; ++i) {
            scanf ("%d", &a[i]);
            a[i] = a[i] * (-1);
        }
        long long ans1, ans2;
        sort(a + 1, a + n + 1);
        ans1 = solve();
        k = l - k + 1;
        for (int i = 1; i <= n; ++i) a[i] = a[i] * (-1);
        sort(a + 1, a + n + 1);
        ans2 = solve();
        printf ("%lld %lld\n", (-1) * ans1, ans2);
    }
    return 0;
}