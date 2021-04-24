#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int I() {
    int s = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {s = s * 10 + ch - '0'; ch = getchar();}
    return s * f;
}
int mat[10][10];
bool test(int x, int y){
for(int x1=0;x1<x;x1++)
    for(int y1=0;y1<y;y1++)
                if((mat[x1][y1]==mat[x1][y]&&mat[x][y1]==mat[x][y])||(mat[x1][y1]==mat[x][y1]&&mat[x1][y]==mat[x][y]))
                {
                    return 0;
                }
    return 1;
}
int n, m;
long long ans = 0;
void dfs(int x, int y){
    if(y >= m) x++, y = 0;
    if(x >= n){
        ans++;
        return ;
    }
    for(int i = 0; i < 3; i++){
        mat[x][y] = i;
        if(test(x,y)) dfs(x, y+1);
    }
}
long long ksm(long long a, long long b){
    long long res = 1;
    while(b){
        if(b&1) res =  res * a % MOD;
        b >>= 1;
        a = a*a%MOD;
    }  
    return res;
}
int tot[10][10];
int main () {
    memset(tot, 0, sizeof(tot));
    for(n = 2; n<=9; n++){
        for(m = n; m <=9;m++){
            ans = 0;
            dfs(0, 0);
            if(ans == 0) break;
            tot[n][m] = ans;
        }
    }
    int T;
    cin>>T;
    while(T--){
        int a, b;
        cin >> a >> b;
        if(a == 1 || b==1) cout << "0\n";
        else if(a < 9 && b < 9) cout << (ksm(3, a*b) - tot[min(a,b)][max(a,b)] + MOD) %MOD << "\n";
        else cout << ksm(3, a * b) << "\n";
    }
    return 0;
}