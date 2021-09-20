#include<bits/stdc++.h>
#define N 100100
using namespace std;
int n, m, T;
int l[N];
vector<int> e[N];
int main(){
    cin >> T;
    for(int t = 1; t <= T; t++){
        printf("Case #%d:\n", t);
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            cin >> l[i];
            e[i].clear();
            for(int j = 0; j < l[i]; j++){
                int a;
                cin >> a;
                e[i].push_back(a);
            }
        }
        for(int i = 0; i < m; i++){
            int s, L, op;
            cin >> s >> L;
            for(int j = 0; j < L; j++){
                cin >> op;
                if(op > l[s]){
                    s = 0;
                }
                else if(s != 0){
                    s = e[s][op - 1];
                }
            }
            if(s != 0){
                cout << s << "\n";
            }
            else{
                cout << "Packet Loss\n";
            }
        }
    }
}