#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int M = 1e6 + 5;
const long long inf = 1ll << 60;

int T, n, m, s, t, step, delta;
bool flag[N];
long long dis[N];
int i[M], j[M], k[M], fi[N], nxt[M];
char ch[N];

priority_queue < pair<long long, int>, vector< pair<long long, int> >, greater< pair<long long, int> > > q;

void addedge(int fr, int to, int cst) {
	j[++step] = to; k[step] = cst; nxt[step] = fi[fr]; fi[fr] = step;
}

long long dij(int start) {
	for (int i = 1; i <= n * 2; ++i) {
		dis[i] = inf;
		flag[i] = 0;
	}
	while (!q.empty()) q.pop();
	dis[start] = 0;
	q.push(make_pair(0, start));
	while (!q.empty()) {
		pair <int, int > tmp = q.top(); q.pop();
		if (flag[tmp.second]) continue;
		flag[tmp.second] = 1;
		for (int u = fi[tmp.second]; u; u = nxt[u]) {
			if (dis[j[u]] > dis[tmp.second] + k[u]) {
				dis[j[u]] = dis[tmp.second] + k[u];
				q.push(make_pair(dis[j[u]], j[u]));
			}
		}
	}
	if (ch[t] == 'M') return min(dis[t], dis[t + n]);
	else return dis[t];
}

int main ()
{
	scanf ("%d", &T);
	while (T--) {
		step = 0;
		for (int b=1;b<=n * 2;++b) fi[b] = 0;
		scanf ("%d%d%d%d%d", &n, &m, &s, &t, &delta);
		scanf ("%s", ch + 1);
		for (int b=1;b<=m;++b)
		{
			int x, y, z;
			scanf ("%d%d%d", &x, &y, &z);
			if (ch[x] == ch[y]){
				if (ch[x] != 'M') {
					addedge(x, y, z);
					addedge(y, x, z);
				}
				else {
					addedge(x, y, z); addedge(y, x, z);
					addedge(x + n, y + n, z); addedge(y + n, x + n, z); 
				}
			}
			else {
				if (ch[x] != 'M' && ch[y] != 'M') {
					addedge(x, y, z + delta);
					addedge(y, x, z + delta);
				}
				else {
					if (ch[x] == 'M') swap(x, y);
					if (ch[x] == 'L') {
						addedge(x, y, z);
						addedge(y, x, z);
						addedge(y + n, x, z + delta);
						addedge(x, y + n, z + delta);
					}
					else {
						addedge(x, y + n, z);
						addedge(y + n, x, z);
						addedge(y, x, z + delta);
						addedge(x, y, z + delta);
					}
				}
			}
		}
		
		long long ans = dij(s);
		if (ch[s] == 'M') ans = min(ans, dij(s + n));
		printf ("%lld\n", ans);
	}
	return 0;
}
