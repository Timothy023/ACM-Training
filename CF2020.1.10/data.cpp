#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;

const int n = 50;

int main () {
    srand(time(0));
    cout <<n<<endl;
    for (int i = 1; i <= n; ++i)
        cout <<rand() <<" ";

    return 0;
}