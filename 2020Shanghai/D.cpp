#include<bits/stdc++.h>
using namespace std;
double N, L,vl, R,vr;
int t;
int main(){
    cin >> t;
    while(t--){
        cin>>N>>L>>vl>>R>>vr;
        if(L>R){
            swap(L,R);
            swap(vl,vr);
        }
        double ans = max(R/vr, (N-L)/vl);
        ans = min(ans, min((L+N)/vl, (2*N-L)/vl));
        ans = min(ans, min((R+N)/vr, (2*N-R)/vr));
        ans = min(ans, max((L/vl), (2*N-R-L)/vr));
        ans = min(ans, max((N-R)/vr, (L+R)/vl));
        ans = min(ans, (2*N+L-R)/(vl+vr));
        ans = min(ans, max(L/vl, (R-L+N-L)/vr));
        ans = min(ans, max((N-R)/vr, (R-L+R)/vl));
        if(((R+N)*vl-vr*L)/(vr+2*vl) <= R && ((R+N)*vl-vr*L)/(vr+2*vl) >= L)
            ans = min(ans, (((R+N)*vl-vr*L)/(vr+2*vl)+L)/vl);
        if(((R+N)*vl+vr*L)/(2*vr+2*vl) <= R && ((R+N)*vl+vr*L)/(2*vr+2*vl) >= L)
            ans = min(ans, (2*((R+N)*vl+vr*L)/(2*vr+2*vl)-L)/vl);
        if(((2*N-R)*vl+vr*L)/(2*vr+vl) <= R && ((2*N-R)*vl+vr*L)/(2*vr+vl) >= L)
            ans = min(ans, (((2*N-R)*vl+vr*L)/(2*vr+vl)*2-L)/vl);
        if(((2*N-R)*vl-vr*L)/(vl+vr) <= R && ((2*N-R)*vl-vr*L)/(vl+vr) >= L)
            ans = min(ans, (((2*N-R)*vl-vr*L)/(vl+vr)+L)/vl);
        printf("%.10lf\n", ans);
    }
    return 0;
}