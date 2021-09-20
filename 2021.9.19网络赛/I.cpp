#include<bits/stdc++.h>
using namespace std;
vector<long long> input, ans;
int main(){
    long long a, r;
    while(scanf("%lld", &a) != EOF){
        input.push_back(a);
    }
    a = input[input.size() - 2], r = input[input.size() - 1];
    for(int i = input.size() - 3; i >= 0; i--){
        if(a - r <= input[i] && input[i] <= a + r) ans.push_back(input[i]);
    }
    if(ans.empty()){
        cout << "\n";
    }
    else{`
        sort(ans.begin(), ans.end());
        for(int i = ans.size() - 1; i >= 0; i--){
            cout << ans[i] << " ";
        }
    }
    return 0;
}