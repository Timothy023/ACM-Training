#include <bits/stdc++.h>
using namespace std;

const long long maxx = 1e9;
const long long maxy = 1e9;

long long n, e, w, s;
long long sx, sy, ex, ey, md;
long long d1, d2;

int main () {

    sx = 1; sy = 1;
    ex = 1; ey = 1e9;
    cout <<"? " <<sx <<" " <<sy <<endl; fflush(stdout); cin >>d1;
    cout <<"? " <<ex <<" " <<ey <<endl; fflush(stdout); cin >>d2;
    if (d1 > d2) sy += (d1 - d2);
    else ey -= (d2 - d1);
    md = (sy + ey) / 2;
    cout <<"? " <<sx <<" " <<md <<endl; fflush(stdout); cin >>n;

    sx = 1e9; sy = 1;
    ex = 1e9; ey = 1e9;
    cout <<"? " <<sx <<" " <<sy <<endl; fflush(stdout); cin >>d1;
    cout <<"? " <<ex <<" " <<ey <<endl; fflush(stdout); cin >>d2;
    if (d1 > d2) sy += (d1 - d2);
    else ey -= (d2 - d1);
    md = (sy + ey) / 2;
    cout <<"? " <<sx <<" " <<md <<endl; fflush(stdout); cin >>s;

    sx = 1  ; sy = 1;
    ex = 1e9; ey = 1;
    cout <<"? " <<sx <<" " <<sy <<endl; fflush(stdout); cin >>d1;
    cout <<"? " <<ex <<" " <<ey <<endl; fflush(stdout); cin >>d2;
    if (d1 > d2) sx += (d1 - d2);
    else ex -= (d2 - d1);
    md = (sx + ex) / 2;
    cout <<"? " <<md <<" " <<sy <<endl; fflush(stdout); cin >>w;

    sx = 1  ; sy = 1e9;
    ex = 1e9; ey = 1e9;
    cout <<"? " <<sx <<" " <<sy <<endl; fflush(stdout); cin >>d1;
    cout <<"? " <<ex <<" " <<ey <<endl; fflush(stdout); cin >>d2;
    if (d1 > d2) sx += (d1 - d2);
    else ex -= (d2 - d1);
    md = (sx + ex) / 2;
    cout <<"? " <<md <<" " <<sy <<endl; fflush(stdout); cin >>e;

    cout <<"! " <<n + 1 <<" " <<w + 1 <<" " <<maxx - s <<" " <<maxy - e <<endl;

    return 0;
}