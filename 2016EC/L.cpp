#include<bits/stdc++.h>

using namespace std;

typedef pair<pair<int,int>,pair<int,int> > pi4;

map<pi4,int> sco; 

pi4 mp(int A,int B,int C,int D)
{
    return make_pair(make_pair(A,B),make_pair(C,D));
}

int main()
{
    int s[4][4];
    for(int i=0;i<pow(3,6);i++)
    {
        int st[6],t=i;
        for(int j=0;j<6;t/=3,j++)
            st[j]=t%3;
        memset(s,0,sizeof(s));
        s[0][1]=st[0];
        s[0][2]=st[1];
        s[0][3]=st[2];
        s[1][2]=st[3];
        s[1][3]=st[4];
        s[2][3]=st[5];
        for(int x=1;x<4;x++)
           for(int y=0;y<x;y++)
                s[x][y]=2-s[y][x];
        for(int x=0;x<4;x++)
            for(int y=0;y<4;y++)
                if(s[x][y]==2)
                    s[x][y]++;
        int sc[4];
        for(int x=0;x<4;x++)
        {
            sc[x]=0;
            for(int y=0;y<4;y++)
                sc[x]+=s[x][y];
        }
        sco[mp(sc[0],sc[1],sc[2],sc[3])]++;
    }
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        int A,B,C,D;
        scanf("%d%d%d%d",&A,&B,&C,&D);
        pi4 p=mp(A,B,C,D);
        if(sco[p] == 1)
            printf("Case #%d: Yes\n",i);
        else if(sco[p] > 1)
            printf("Case #%d: No\n", i);
        else
            printf("Case #%d: Wrong Scoreboard\n", i);
    }
    return 0;
}