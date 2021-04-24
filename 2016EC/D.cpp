#include<bits/stdc++.h>
using namespace std;
int t;
int n,k;
long long a[300100];
int ans;
long long tot[300100], pla;
bool pc(int mid){
    int cnt = pla = 0;
    for(int i = 0; i < mid; i++){
        tot[i] = a[i];
    }
    for(int i = mid; i < n; i++){
        if(a[i] / 2 >= tot[pla]){
            tot[pla] = a[i];
            pla++;
        }
        if(pla == mid){
            pla = 0;
            cnt ++;
        }
    }
    return cnt >= k - 1;
}
int main(){
    cin >> t;
    for(int T = 1; T <= t; T++){
        cin >> n >> k;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a, a+n);
        int l = 1, r = n/k, ans = 0;
        while(l<=r){
            int mid = l + r >> 1;
            if(pc(mid)) l = mid + 1, ans = mid;
            else r = mid - 1;
        }
        cout << "Case #" << T << ": " << ans << "\n";
    }
    return 0;
}