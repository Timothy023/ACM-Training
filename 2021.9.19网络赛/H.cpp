#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int, set<int> > > A(m);
    for(int i=0;i<n;i++)
    {
        int id;
        double x,y,z;
        cin>>id>>x>>y>>z;
    }
    for(int i = 0; i < m; i++)
    {
        cin>>A[i].first;
        int c;
        cin>>c;
        for(int j = 0; j < c % 10; j++)
        {
            int x;
            cin>>x;
            A[i].second.insert(x);
        }
    }
    int L;
    cin>>L;
    for(int i=0;i<L;i++)
    {
        int id;
        cin>>id;
        cout<<id<<endl;
        set<int> nb, el;
        for(auto x:A)
            if(x.second.count(id))
            {
                el.insert(x.first);
                for(auto y:x.second)
                    if(y!=id)
                        nb.insert(y);
            }
        if(el.empty())
            cout<<"[]\n[]\n";
        else
        {
            bool left = false;
            for(auto x:nb)
                if(left)
                    cout<<','<<x;
                else
                {
                    cout<<'['<<x;
                    left = true;
                }
            cout<<']'<<endl;
            left = false;
            for(auto x:el)
                if(left)
                    cout<<','<<x;
                else
                {
                    cout<<'['<<x;
                    left = true;
                }
            cout<<']'<<endl;
        }
    }
}
/*
8 6
1 0.0 1.1 0.0
2 1.5e1 2.1e1 0.0
3 2.3 0.1 0.0
4 3.0 1.8 0.0
5 3.4 0.2 0.0
6 4.2 2.3 0.0
7 5.5 -0.1 0.0
8 6.1 1.9 0.0
1 203 1 2 3
2 203 2 3 4
3 203 3 4 5
4 203 4 5 6
5 203 5 6 7
6 102 5 8
2
5
9
*/