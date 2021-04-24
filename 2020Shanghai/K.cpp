#include<bits/stdc++.h>
using namespace std;
char s[200100];
vector<int> to[200100];
int done[200100];
int t;
int ans = 0;
void dfs(int p, int fr){
    for(int i= 0; i < to[p].size(); i++){
        if(to[p][i] == fr) continue;
        if(!done[to[p][i]]){
            done[to[p][i]]=1;
            dfs(to[p][i], p);
        }
        else{
            if(s[p] == s[to[p][i]]) ans = 1;
        }
    }
}
int main(){
    cin >> t;
    for(int T = 0; T < t; T++){
        int n,m;
        ans=0;
        scanf("%d%d%s", &n, &m, s);   
        for(int i = 0; i < m; i++){
            int a, b;
            scanf("%d%d",&a,&b);
            to[a].push_back(b);
            to[b].push_back(a);
        }
        dfs(0, -1);
        for(int i = 0; i < n; i++){
            to[i].clear();
            done[i] = 0;
        }
        if(ans) puts("yes");
        else puts("no");
    }
    return 0;
}