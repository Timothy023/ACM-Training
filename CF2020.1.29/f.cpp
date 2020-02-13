#include <bits/stdc++.h>
using namespace std;

const int N = 55;
struct node{
    int l, r;
}a[N];
int n;


int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf ("%d%d", &a[i].l, &a[i].r);
    return 0;
}