#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];
char b[1010][1010];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        scanf("%s", a[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%s", b[i]);
    }
    int tot = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            if(a[i][j] != b[i][j]) tot++;
    }
    if(tot <= n * m / 2){
        for(int i = 0; i < n; i++){
            printf("%s\n", a[i]);
        }
    }
    else{
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == 'X') putchar('.');
                else putchar('X');
            }
            puts("");
        }
    }
    return 0;
}