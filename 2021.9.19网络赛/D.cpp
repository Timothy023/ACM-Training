#include<bits/stdc++.h>
using namespace std;
#define N 100100
priority_queue<int> q, e;
int T, t, n, m;
long long ans;
vector<int> add[N], del[N];
int getint()
{
    char c;
    while(!isdigit(c = getchar()));
    int x = 0;
    while(isdigit(c))
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}
int main(){
    cin >> T;
    for(int t = 1; t <= T; t++){
        printf("Case #%d: ", t);
        n = getint(); m = getint();
        while(!q.empty()) q.pop();
        while(!e.empty()) e.pop();
        for(int i = 1; i <= n; i++){
            add[i].clear();
            del[i].clear();
        }
        ans = 0;
        for(int i = 0; i < m; i++){
            long long l, r, w;
            l = getint(); r = getint(); w = getint();
            ans += (r - l + 1) * (r - l) / 2 * w;
            add[l].push_back(w);
            del[r].push_back(w);
        }
        long long real_ans = 0;
        int f = 0;
        for(int i = 1; i < n; i++){
            for(int j = add[i].size() - 1; j >= 0; j--) q.push(-add[i][j]);
            for(int j = del[i].size() - 1; j >= 0; j--) e.push(-del[i][j]);
            if(!q.empty() && !e.empty()){
                while(q.top() == e.top()){
                    q.pop();
                    e.pop();
                    if(q.empty() || e.empty()) break;
                }
            }
            if(q.empty()) f = 1;
            real_ans += -q.top();
        }
        if(f) cout << "Gotta prepare a lesson\n";
        else cout << ans - real_ans << "\n";
    }
    
    return 0;
}