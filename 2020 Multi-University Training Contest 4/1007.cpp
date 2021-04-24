#include<bits/stdc++.h>
#define EMP 2008610086
#define DON -2008610086
#define N 100100
using namespace std;
int T, n;
int a[N], b[N];
int t[N];
map<int, int> s[2];
int main(){
    scanf("%d", &T);
    while(T--){
        s[0].clear();
        s[1].clear();
        scanf("%d", &n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            scanf("%d %d", &a[i], &b[i]);
            s[0][a[i]-b[i]] = EMP;
            s[1][a[i]+b[i]] = EMP;
        }
        for(int i = 0; i < n; i++){
            if(s[0][a[i]-b[i]] == DON) continue;
            if(s[1][a[i]+b[i]] == DON) continue;
            if(s[0][a[i] - b[i]] == EMP && s[1][a[i] + b[i]] == EMP){
                s[0][a[i] - b[i]] = a[i] + b[i];
                s[1][a[i] + b[i]] = a[i] - b[i];
                ans++;
            }
            else if(s[0][a[i] - b[i]] != EMP){
                s[1][s[0][a[i] - b[i]]] = EMP;
                s[0][a[i] - b[i]] = DON;
            }
            else if(s[1][a[i] + b[i]] != EMP){
                s[0][s[1][a[i] + b[i]]] = EMP;
                s[1][a[i] + b[i]] = DON;
            }
            else{
                t[-1] = 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
