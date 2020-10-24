#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
long long l;

struct node{
    char nam[55];
    long long v;
    friend bool operator < (node i, node j) {
        return i.v < j.v;
    }
}a[N];

int main () {
    scanf ("%d%lld", &n ,&l);
    for (int i = 1; i <= n; ++i) {
        scanf ("%s", a[i].nam);
        scanf ("%lld", &a[i].v);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i < n; ++i) {
        printf ("%s ", a[i].nam);
        printf ("%lld ", a[i].v * i / l);
        long long tmp = a[i].v * i / l;
        tmp = (tmp + 1) * l;
        tmp = (tmp - a[i].v * i) % l;
        printf ("%lld\n", tmp);
    }
    printf ("%s", a[n].nam);
    return 0;
}