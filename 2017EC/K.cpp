#include<bits/stdc++.h>
using namespace std;
int t;
int A, B, N;
long long tot[100100];
long long sum[100100];
int main(){
    scanf("%d",&t);
    for(int T=1; T<=t; T++){
        scanf("%d%d%d", &A, &B, &N);
        for(int i = 1; i <= A; i++){
            scanf("%lld", &tot[i]);
            sum[i] = sum[i-1] + tot[i];
        }
        int preA;
        for(int i = 0; i < N; i++){
            preA = A;
            for(int j = A+1; j >= 1; j--){
                if(sum[j-1] < A){
                    B = A - sum[j-1];
                    A = j;
                    break;
                }
            }
            if(preA == A) break;
        }
        printf("Case #%d: %d-%d\n", T, A, B);
    }
    return 0;
}