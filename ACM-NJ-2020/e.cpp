#include<bits/stdc++.h>
using namespace std;
char s[100100];
int n, T, mx, my;
int fx[4] = {-1, 1, 0, 0};
int fy[4] = {0, 0, 1, -1};
bool bet(int a, int x, int d){
    if(x > d) swap(x, d);
    return x <= a && a <= d;
}
bool pd(int o[4], int ch[4]){
    int x = 0, y = 0;
    for(int i = 0; i < 4; i++){
        int tox = x + fx[o[i]] * ch[o[i]];
        int toy = y + fy[o[i]] * ch[o[i]];
        //cout << y << " " << toy << " " << my << "\n";
        if(bet(mx, x, tox) && bet(my, y, toy)) return 0;
        x = tox;
        y = toy;
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < ch[o[i]]; j++){
            if(o[i] == 0) putchar('L');
            if(o[i] == 1) putchar('R');
            if(o[i] == 2) putchar('U');
            if(o[i] == 3) putchar('D');
        }
    }
    puts("");
    return 1;
}
int main(){
    cin >> T;
    while(T--){
        cin >> mx >> my;
        cin >> s;
        n = strlen(s);
        int ch[4] = {0, 0, 0, 0};
        int o[4] = {0, 1, 2, 3};
        ch[0] = ch[1] = ch[2] = ch[3];
        for(int i = 0; i < n; i++){
            if(s[i] == 'L') ch[0]++;
            if(s[i] == 'R') ch[1]++;
            if(s[i] == 'U') ch[2]++;
            if(s[i] == 'D') ch[3]++;
        }
        int f = 0;
        do{
            f = pd(o, ch);
            if(f) break;
        }while(next_permutation(o, o+4));
        if(!f) cout << "Impossible\n";
    }
    return 0;
}