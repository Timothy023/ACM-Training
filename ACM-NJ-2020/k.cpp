#include<bits/stdc++.h>
using namespace std;
priority_queue<long long> q;
vector<int> to[100100];
int v[100100];
int fa[100100];
long long sum[100100];
bool done[2100];
long long ans;
int T, n;
void dfs(int p, int fa){
    sum[p] = 0;
    for(int i = 0; i < to[p].size(); i++){
        if(to[p][i] != fa){
            sum[p] += v[to[p][i]];
            dfs(to[p][i], p);
        }
    }
    ans += sum[p] + v[p];
}
int main(){
    cin >> T;
    while(T--){
        memset(done, 0, sizeof(done));
        ans = 0;
        cin >> n;
        for(int i = 1; i <= n;i ++){
            to[i].clear();
        }
        for(int i = 2; i <= n;i ++){
            cin >> fa[i];
            to[fa[i]].push_back(i);
        }
        for(int i=1;i<=n;i++) cin >> v[i];
        done[0] = 1;
        dfs(1, 0);
        cout << ans;
        for(int i = 1; i <= n; i++){
            long long zd = 0, bes = -1;
            for(int j = 1; j <= n; j++){
                if(done[j] == 1) continue;
                if(sum[j] + v[j] + ((done[fa[j]] != 1) * v[j]) > zd){
                    zd = sum[j] + v[j] +  ((done[fa[j]] != 1) * v[j]);
                    bes = j;
                }
            }
            done[bes] = 1;
            sum[fa[bes]] -= v[bes];
            ans -= zd;
            cout << " " << ans;
        }
        puts("");
    }
    return 0;
}