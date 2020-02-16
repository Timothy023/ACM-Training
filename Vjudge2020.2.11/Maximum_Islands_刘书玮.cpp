#include<bits/stdc++.h>

const int INF=1008610086;
const int MAXN=10005;
const int MAXM=300005;

struct Queue
{
	int head, tail, q[MAXN];
	inline void push(int a){q[tail ++] = a;}
	inline int front(){return q[head ++];}
	inline bool empty(){return head == tail;}
	inline void clear(){head = tail = 0;}
};

Queue q;
int beg[MAXN], to[MAXM], ll[MAXM], nex[MAXM], dis[MAXN], sta[MAXN];
int n, m, s, t, len = 1;
int fx[4] = {0, 0, 1, -1}, fy[4] = {1, -1, 0, 0};
char dt[55][55];
int done[55][55];
int l, co;

inline void read(int & a)
{
    char c = getchar();
	bool f = 0;
    for( ; (c < '0' || c > '9') && c != '-'; c = getchar());
	if(c == '-'){f = 1; c = getchar();}
    for(a = 0; c >= '0' && c <= '9'; c = getchar()) a = a * 10 + c - '0';
    if(f == 1) a = -a;
}

inline void Add_edge(int a, int b, int c)
{
	nex[++len] = beg[a]; ll[len] = c; to[len] = b; beg[a] = len;
	nex[++len] = beg[b]; ll[len] = 0; to[len] = a; beg[b] = len;
}

int dfs(int p, int flo)
{
	int sum = flo, f;

	if(p == t) return flo;
	for(int &i = sta[p]; i; i = nex[i])
	{
		if(ll[i] && dis[to[i]] == dis[p] + 1)
		{
			int f=dfs(to[i], std::min(ll[i], sum));
			if(f > 0)
			{
				sum -= f;
				ll[i] -= f;
				ll[i ^ 1] += f;
				if(!sum) break;
			}
		}
	}
	return flo-sum;
}

inline bool bfs()
{
	for(int i = 0; i <= n * m + 2; i++) dis[i] = -1;
	dis[s] = 0;
	q.clear();
	q.push(s);
	while(!q.empty())
	{
		int st = q.front();
		for(int i = beg[st]; i; i = nex[i]){
			if(ll[i] && dis[to[i]] == -1){
				dis[to[i]] = dis[st] + 1;
				q.push(to[i]);
			}
		}
	}
	return dis[t] != -1;
}

int check(int x, int y)
{
	if(x < 0 || y < 0 || x >= n || y >= m) return 0;
	return 1;
}

void dfs2(int x, int y)
{
	done[x][y] = 1;
	for(int k = 0; k < 4; k ++)
	{
		int tx = fx[k] + x, ty = fy[k] + y;
		if(!check(tx, ty)) continue;
		if(done[tx][ty]) continue;
		if(dt[tx][ty] != 'L') continue;
		dfs2(tx,ty);
	}
}

void test()
{
	for(int i = 0; i < n; i ++)
	{
		for(int j = 0; j < m; j ++)
		{
			if(dt[i][j] != 'L') continue;
			for(int k = 0; k < 4; k ++)
			{
				int tx = fx[k] + i, ty = fy[k] + j;
				if(!check(tx, ty)) continue;
				if(dt[tx][ty] == 'C') dt[tx][ty] = 'W';
			}
		}
	}
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++)
			if(dt[i][j] == 'C') co ++;
}

int main()
{
	int f,ans = 0;
	read(n);read(m);s=n*m + 1,t=n *m +2;
	for(int i = 0; i < n; i ++)
	{
		std::cin>>dt[i];
	}
	for(int i = 0; i < n; i ++)
	{
		for(int j = 0; j < m; j ++)
		{
			if(dt[i][j] == 'L' && !done[i][j]){
				l ++;
				dfs2(i,j);
			}
		}
	}
	test();
	for(int i = 0; i < n; i ++)
	{
		for(int j = 0; j < m; j ++)
		{
			if(dt[i][j] != 'C') continue;
			if((i + j) & 1)
			{
				Add_edge(s, i * m + j + 1, 1);
				for(int k = 0; k < 4; k ++)
				{
					int tx = fx[k] + i, ty = fy[k] + j;
					if(!check(tx, ty)) continue;
					if(dt[tx][ty] == 'C') Add_edge(i * m + j + 1, tx * m + ty + 1, 1);
				}
			}
			else Add_edge(i * m + j + 1, t, 1);
		}
	}
	while(bfs())
	{
		for(int i=0;i<=n*m+2;i++) sta[i]=beg[i];
		while(f=dfs(s,INF)) ans+=f;
	}
	std::cout<< co - ans + l <<"\n";
	return 0;
}