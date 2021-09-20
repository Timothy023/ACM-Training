#include<bits/stdc++.h>

using namespace std;

unsigned int convert(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    return (a<<24)|(b<<16)|(c<<8)|d;
}

void print(unsigned int x)
{
    printf("%u.%u.%u.%u\n", (x >> 24) & 255, (x >> 16) & 255, (x >> 8) & 255, x & 255);
}

int getint()
{
    char c;
    while(!isdigit(c = getchar()));
    int x = 0;
    while(isdigit(c))
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

struct node
{
    int son[2];
    unsigned int y;
    bool f;
    node()
    {
        son[0] = son[1] = -1;
        f = false;
    }
};

vector<node> A;

void insert(int u, unsigned int x, int s, int t, unsigned int y)
{
    if(s == t)
    {
        A[u].f = true;
        A[u].y = y;
        return ;
    }
    int ts = (x >> (31 - s)) & 1;
    if(A[u].son[ts] < 0)
    {
        A[u].son[ts] = A.size();
        A.push_back(node());
    }
    insert(A[u].son[ts], x, s+1, t, y);
}

int main()
{
    A.clear();
    A.push_back(node());
    int n = getint();
    for(int i = 0; i < n; i++)
    {
        int a = getint(), b = getint(), c = getint(), d = getint();
        unsigned int x = convert(a,b,c,d);
        int t = getint();
        a = getint(), b = getint(), c = getint(), d = getint();
        unsigned int y = convert(a,b,c,d);
        insert(0, x, 0, t, y);
    }
    int q = getint();
    for(int i = 0; i < q; i++)
    {
        int a = getint(), b = getint(), c = getint(), d = getint();
        unsigned int x = convert(a,b,c,d);
        int t = 31;
        unsigned int y = 0;
        int u = 0;
        while(u >= 0)
        {
            if(A[u].f)
                y = A[u].y;
            u = A[u].son[(x >> t) & 1];
            t--;
        }
        print(y);
    }
}