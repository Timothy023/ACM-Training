#include <bits/stdc++.h>
using namespace std;

int x[1000];

int main () {
    int a, P;
    cin >>P;
    for (a = 2; a < P; ++a) {
        int sum = 0;
        for (int i = 1; i < P; ++i) {
            x[i] = a * i % P;
            for (int j = 1; j < i; ++j)
                if (x[j] > x[i]) sum++;
        }
        cout <<a <<"  " <<P <<"  " <<sum <<"  " <<sum % 2 <<"  ";
        sum = 0;
        for (int i = P; i; i /= 2) {
            cout <<i % 2;
            if (i % 2 != 0) sum++;
        }
        cout <<"  " <<sum <<"  " <<sum % a <<endl;
    }
    return 0;
}