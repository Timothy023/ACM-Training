#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	vector<vector<int> > G(n);
	vector<bool> used(n,false); 
	for(int i=0;i<k;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--;y--;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	int ans=k;
	for(int i=0;i<n;i++)
		if(!used[i]&&G[i].size()>0)
		{
			ans++; 
			queue<int> q;
			q.push(i);
			while(!q.empty())
			{
				int v=q.front();q.pop();
				used[v]=true;
				for(int j=0;j<G[v].size();j++)
					if(!used[G[v][j]])
					{
						used[G[v][j]]=true;
						q.push(G[v][j]);
					}
			}
		}
	for(int i=0;i<n;i++)
		if(used[i]) ans--;
	printf("%d\n",ans);
    return 0;
}

