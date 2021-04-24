#include<bits/stdc++.h>
#define eps 0
using namespace std;
double s[100000];
int main(){
    int t;
    scanf("%d\n",&t);
    for(int T = 1; T <= t; T++){
        int n;
        scanf("%d",&n);
        for(int i = 0; i < n; i++){
            double a, b;
            char c[1000];
            scanf("%s",c);
            for(int j = 0; j < strlen(c); j++){
                if(c[j] == ':'){
                    c[j] = 0;
                    a = atof(c);
                    b = atof(c+j+1);
                }
            }
            s[i] = 1.0/(1.0+b/a);
        }
        sort(s, s+n);
        double tot = 0;
        int f = 0;
        for(int i = 0; i < n; i++){
            tot += s[i];
            if(tot >= 1 - eps){
                cout << "Case #" << T << ": " << i << "\n";
                f = 1;
                break;
            }
        }
        if(!f){
            cout << "Case #" << T << ": " << n << "\n";
        }
    }
    return 0;
}