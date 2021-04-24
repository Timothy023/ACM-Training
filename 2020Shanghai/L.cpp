#include<bits/stdc++.h>
using namespace std;

int g(int x, int y)
{
    if(x < y) return g(y , x);
    if(y == 0) 
        return x;
    return g(y, x%y);
}
int main(){
    int t;
    long long n, m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        double ans = 1e18;
        if(g(n,m) == 1)
            ans = sqrt(n*n+m*m);
        for(long long x = -10 ; x <= n + 10; x++){
            for(long long y = 1.0*m/n*x - 2; y <= 1.0*m/n*x+2; y++){
                if(x < 0 || y < 0 || x > n || y > m) continue;
                if(g(abs(x),abs(y)) == 1 && g(abs(x-n),abs(y-m)) == 1 && abs(x*(y-m))!=abs(y*(x-n)))
                    ans = min(ans, sqrt(x * x + y * y) + sqrt((x - n) * (x - n) + (y - m) * (y - m)));
            }
        }
        if(ans == 1e18)
            return 1;
        printf("%.15lf\n", ans);
    }
}